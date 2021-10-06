/*
 * C
 *
 * Copyright 2021 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */
 
/**
 * @file
 * @brief Random natives implementation.
 * @author @CCO_AUTHOR@
 * @version @CCO_VERSION@
 * @date @CCO_DATE@
 */

#include <stdint.h>
#include <stdio.h>
#include <LLSEC_RANDOM_impl.h>
#include <LLSEC_ERRORS.h>
#include <LLSEC_configuration.h>
#include <sni.h>

#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"

typedef struct LLSEC_RANDOM_mbedtls_context {
	mbedtls_entropy_context entropy_context;
	mbedtls_ctr_drbg_context ctr_drbg_context;
} LLSEC_RANDOM_mbedtls_context_t;

static void LLSEC_RANDOM_IMPL_free_context(void* context) {
	LLSEC_RANDOM_mbedtls_context_t* ctx = (LLSEC_RANDOM_mbedtls_context_t*) context;
	mbedtls_ctr_drbg_free(&ctx->ctr_drbg_context);
	mbedtls_entropy_free(&ctx->entropy_context);
	LLSEC_free(ctx);
}

static void LLSEC_RANDOM_IMPL_close_native(void* resource) {
	LLSEC_RANDOM_IMPL_free_context(resource);
}

/**
 * @brief Initializes a Random resource.
 *
 * @return The native ID of the resource.
 *
 * @note Throws NativeException on error.
 */
int32_t LLSEC_RANDOM_IMPL_init() {
	LLSEC_RANDOM_mbedtls_context_t* context = (LLSEC_RANDOM_mbedtls_context_t*) LLSEC_calloc(1, sizeof(LLSEC_RANDOM_mbedtls_context_t));

	mbedtls_ctr_drbg_init(&context->ctr_drbg_context);
	mbedtls_entropy_init(&context->entropy_context);
	
	int result = mbedtls_ctr_drbg_seed(&context->ctr_drbg_context, mbedtls_entropy_func, &context->entropy_context, NULL, 0);
	if (0 != result) {
		SNI_throwNativeException(result, "mbedtls_ctr_drbg_seed failed.");
		LLSEC_RANDOM_IMPL_close((int32_t) context);
		return -1;
	}
	int32_t sni_status = SNI_registerResource((void*) context, LLSEC_RANDOM_IMPL_close_native, NULL);
	if (SNI_OK != sni_status) {
		SNI_throwNativeException(sni_status, "Cannot register SNI native resource.");
		LLSEC_RANDOM_IMPL_close((int32_t) context);
		return -1;
	}
	
	return (int32_t) context;
}

/**
 * @brief Closes the resource related to the nativeId.
 *
 * @param[in] native_id					The native ID.
 *
 * @note Throws NativeException on error.
 */
void LLSEC_RANDOM_IMPL_close(int32_t native_id) {
	SNI_unregisterResource((void*) native_id, LLSEC_RANDOM_IMPL_close_native);
	LLSEC_RANDOM_IMPL_free_context((void*) native_id);
}

/**
 * @brief Generates random bytes.
 *
 * @param[in] native_id					The native ID.
 * @param[out] rnd						The buffer to fill with random bytes.
 * @param[in] size						The size of rnd.
 *
 * @note Throws NativeException on error.
 */
void LLSEC_RANDOM_IMPL_next_bytes(int32_t native_id, uint8_t* rnd, int32_t size) {
	LLSEC_RANDOM_mbedtls_context_t* context = (LLSEC_RANDOM_mbedtls_context_t*) native_id;
	int result = mbedtls_ctr_drbg_random(&context->ctr_drbg_context, rnd, size);
	if (0 != result) {
		SNI_throwNativeException(result, "mbedtls_ctr_drbg_random failed.");
	}
}

/**
 * @brief Sets the seed of the PRNG.
 *
 * @param[in] native_id					The native ID.
 * @param[in] seed						The array of bytes used as a seed.
 * @param[in] size						The size of seed.
 *
 * @note Throws NativeException on error.
 */
void LLSEC_RANDOM_IMPL_set_seed(int32_t native_id, uint8_t* seed, int32_t size) {
	LLSEC_RANDOM_mbedtls_context_t* context = (LLSEC_RANDOM_mbedtls_context_t*) native_id;
	int result = mbedtls_ctr_drbg_reseed(&context->ctr_drbg_context, seed, size);
	if (0 != result) {
		SNI_throwNativeException(result, "mbedtls_ctr_drbg_seed failed.");
	}
}

/**
 * @brief Generates a new seed.
 *
 * @param[in] native_id					The native ID.
 * @param[out] seed						The array to fill with the seed.
 * @param[in] size						The size of seed.
 *
 * @note Throws NativeException on error.
 */
void LLSEC_RANDOM_IMPL_generate_seed(int32_t native_id, uint8_t* seed, int32_t size) {
	LLSEC_RANDOM_IMPL_next_bytes(native_id, seed, size);
}
