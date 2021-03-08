/*
 * C
 *
 * Copyright 2021 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */
 
/**
 * @file
 * @brief Message digest natives implementation.
 * @author @CCO_AUTHOR@
 * @version @CCO_VERSION@
 * @date @CCO_DATE@
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "mbedtls/md5.h"
#include "mbedtls/sha1.h"
#include "mbedtls/sha256.h"
#include "mbedtls/sha512.h"

#include "LLSEC_DIGEST_impl.h"

#define LLSEC_DIGEST_NB_OF_ALGORITHMS 4
#define LLSEC_DIGEST_MD5    0
#define LLSEC_DIGEST_SHA1   1
#define LLSEC_DIGEST_SHA256 2
#define LLSEC_DIGEST_SHA512 3

typedef struct {
	char* name;
	uint8_t value;
	LLSEC_DIGEST_algorithm_desc description;
} LLSEC_DIGEST_algorithm;

mbedtls_md5_context    LLSEC_DIGEST_Md5_ctx;
mbedtls_sha1_context   LLSEC_DIGEST_Sha1_ctx;
mbedtls_sha256_context LLSEC_DIGEST_Sha256_ctx;
mbedtls_sha512_context LLSEC_DIGEST_Sha512_ctx;

static LLSEC_DIGEST_algorithm available_algorithms[LLSEC_DIGEST_NB_OF_ALGORITHMS] = {
	{
		.name = "MD5",
		.value = LLSEC_DIGEST_MD5,
		{
			.digest_length = 16
		}
	},
	{
		.name = "SHA-1",
		.value = LLSEC_DIGEST_SHA1,
		{
			.digest_length = 20
		}
	},
	{
		.name = "SHA-256",
		.value = LLSEC_DIGEST_SHA256,
		{
			.digest_length = 32
		}
	},
	{
		.name = "SHA-512",
		.value = LLSEC_DIGEST_SHA512,
		{
			.digest_length = 64
		}
	}
};


int32_t LLSEC_DIGEST_IMPL_get_algorithm_description(uint8_t* algorithm_name, LLSEC_DIGEST_algorithm_desc* algorithm_desc) {
	int32_t nb_algorithms = LLSEC_DIGEST_NB_OF_ALGORITHMS;
	LLSEC_DIGEST_algorithm* algorithm = &available_algorithms[0];

	while(--nb_algorithms >= 0){
		if(strcmp((char *)algorithm_name, algorithm->name) == 0){
			memcpy(algorithm_desc, &(algorithm->description), sizeof(LLSEC_DIGEST_algorithm_desc));
			return (int32_t)algorithm;
		}
		algorithm++;
	}

	// Algorithm not found.
	return -1;
}

int32_t LLSEC_DIGEST_IMPL_init(int32_t algorithm_id) {
	int32_t native_id = -1;
	uint8_t algorithm_value = ((LLSEC_DIGEST_algorithm *)algorithm_id)->value;

	switch(algorithm_value) {
		case LLSEC_DIGEST_MD5: {
			mbedtls_md5_init(&LLSEC_DIGEST_Md5_ctx);
			mbedtls_md5_starts_ret(&LLSEC_DIGEST_Md5_ctx);
			native_id = (int32_t)(&LLSEC_DIGEST_Md5_ctx);
			break;
		}
		case LLSEC_DIGEST_SHA1: {
			mbedtls_sha1_init(&LLSEC_DIGEST_Sha1_ctx);
			mbedtls_sha1_starts_ret(&LLSEC_DIGEST_Sha1_ctx);
			native_id = (int32_t)(&LLSEC_DIGEST_Sha1_ctx);
			break;
		}
		case LLSEC_DIGEST_SHA256: {
			mbedtls_sha256_init(&LLSEC_DIGEST_Sha256_ctx);
			mbedtls_sha256_starts_ret(&LLSEC_DIGEST_Sha256_ctx, 0);
			native_id = (int32_t)(&LLSEC_DIGEST_Sha256_ctx);
			break;
		}
		case LLSEC_DIGEST_SHA512: {
			mbedtls_sha512_init(&LLSEC_DIGEST_Sha512_ctx);
			mbedtls_sha512_starts_ret(&LLSEC_DIGEST_Sha512_ctx, 0);
			native_id = (int32_t)(&LLSEC_DIGEST_Sha512_ctx);
			break;
		}
		default: {
			printf("%s - algorithm_id is %ld\n", __func__, algorithm_id);
			SNI_throwNativeException(0, NULL);
			break;
		}
	}

	return native_id;
}

void LLSEC_DIGEST_IMPL_close(int32_t algorithm_id, int32_t native_id) {
	uint8_t algorithm_value = ((LLSEC_DIGEST_algorithm *)algorithm_id)->value;

	switch(algorithm_value) {
		case LLSEC_DIGEST_MD5: {
			mbedtls_md5_free((mbedtls_md5_context *)native_id);
			break;
		}
		case LLSEC_DIGEST_SHA1: {
			mbedtls_sha1_free((mbedtls_sha1_context *)native_id);
			break;
		}
		case LLSEC_DIGEST_SHA256: {
			mbedtls_sha256_free((mbedtls_sha256_context *)native_id);
			break;
		}
		case LLSEC_DIGEST_SHA512: {
			mbedtls_sha512_free((mbedtls_sha512_context *)native_id);
			break;
		}
		default: {
			printf("%s - algorithm_id is %ld\n", __func__, algorithm_id);
			SNI_throwNativeException(0, NULL);
			break;
		}
	}
}

void LLSEC_DIGEST_IMPL_update(int32_t algorithm_id, int32_t native_id, uint8_t* buffer, int32_t buffer_offset, int32_t buffer_length) {
	uint8_t algorithm_value = ((LLSEC_DIGEST_algorithm *)algorithm_id)->value;

	switch(algorithm_value) {
		case LLSEC_DIGEST_MD5: {
			mbedtls_md5_update_ret((mbedtls_md5_context *)native_id, &buffer[buffer_offset], buffer_length);
			break;
		}
		case LLSEC_DIGEST_SHA1: {
			mbedtls_sha1_update_ret((mbedtls_sha1_context *)native_id, &buffer[buffer_offset], buffer_length);
			break;
		}
		case LLSEC_DIGEST_SHA256: {
			mbedtls_sha256_update_ret((mbedtls_sha256_context *)native_id, &buffer[buffer_offset], buffer_length);
			break;
		}
		case LLSEC_DIGEST_SHA512: {
			mbedtls_sha512_update_ret((mbedtls_sha512_context *)native_id, &buffer[buffer_offset], buffer_length);
			break;
		}
		default: {
			printf("%s - algorithm_id is %ld\n", __func__, algorithm_id);
			SNI_throwNativeException(0, NULL);
			break;
		}
	}
}

void LLSEC_DIGEST_IMPL_digest(int32_t algorithm_id, int32_t native_id, uint8_t* out, int32_t out_offset, int32_t out_length) {
	uint8_t algorithm_value = ((LLSEC_DIGEST_algorithm *)algorithm_id)->value;

	switch(algorithm_value) {
		case LLSEC_DIGEST_MD5: {
			mbedtls_md5_finish_ret((mbedtls_md5_context *)native_id, &out[out_offset]);
			break;
		}
		case LLSEC_DIGEST_SHA1: {
			mbedtls_sha1_finish_ret((mbedtls_sha1_context *)native_id, &out[out_offset]);
			break;
		}
		case LLSEC_DIGEST_SHA256: {
			mbedtls_sha256_finish_ret((mbedtls_sha256_context *)native_id, &out[out_offset]);
			break;
		}
		case LLSEC_DIGEST_SHA512: {
			mbedtls_sha512_finish_ret((mbedtls_sha512_context *)native_id, &out[out_offset]);
			break;
		}
		default: {
			printf("%s - algorithm_id is %ld\n", __func__, algorithm_id);
			SNI_throwNativeException(0, NULL);
			break;
		}
	}
}
