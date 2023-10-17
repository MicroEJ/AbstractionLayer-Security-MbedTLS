/*
 * C
 *
 * Copyright 2021-2023 MicroEJ Corp. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be found with this software.
 */

/**
 * @file
 * @brief MicroEJ Security low level API implementation for MbedTLS Library.
 * @author @CCO_AUTHOR@
 * @version @CCO_VERSION@
 * @date @CCO_DATE@
 */

#include <LLSEC_ERRORS.h>
#include <LLSEC_PRIVATE_KEY_impl.h>
#include <LLSEC_mbedtls.h>
#include <LLSEC_configuration.h>

#include <sni.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "mbedtls/platform.h"
#include "mbedtls/pk.h"

/**
 * @brief return the max size of the encoded key.
 *
 * @param[in] native_id the C structure pointer holding the key data
 *
 * @return max encoded size for the private key in DER format
 *
 * @note Throws NativeException on error.
 */
int32_t LLSEC_PRIVATE_KEY_IMPL_get_encoded_max_size(int32_t native_id) {
    LLSEC_PRIVATE_KEY_DEBUG_TRACE("%s \n", __func__);
    int return_code = LLSEC_ERROR;
    int mbedtls_rc = LLSEC_MBEDTLS_SUCCESS;

    LLSEC_priv_key* key = (LLSEC_priv_key*)native_id;
    mbedtls_pk_context pk;
    mbedtls_pk_type_t pk_type;

    if (TYPE_RSA == key->type) {
        pk_type = MBEDTLS_PK_RSA;
    } else {
        pk_type = MBEDTLS_PK_ECKEY;
    }

    mbedtls_pk_init(&pk);
    mbedtls_rc = mbedtls_pk_setup(&pk, mbedtls_pk_info_from_type(pk_type));
    if(LLSEC_MBEDTLS_SUCCESS != mbedtls_rc) {
        (void)SNI_throwNativeException(mbedtls_rc, "Private key context setup failed");
    } else {
        pk.pk_ctx = (void*)key->key;

        char buf_local[LLSEC_PRIVATE_KEY_LOCAL_BUFFER_SIZE];
        int length = mbedtls_pk_write_key_der(&pk, (unsigned char*)(&buf_local), sizeof(buf_local));
        if (0 > length) {
            (void)SNI_throwNativeException(-length, "Encoded max size get failed");
        } else {
            return_code = length;
        }
    }

    return return_code;
}

/**
 * @brief encode the private key into DER format.
 *
 * @param[in]  native_id                   the C structure pointer holding the key data
 * @param[out] output                      a byte array to hold the encoded key data
 * @pram[in]   outputLength                the length of the output array
 *
 * @return the reel size of the encoded key.
 *
 * @note Throws NativeException on error.
 */
int32_t LLSEC_PRIVATE_KEY_IMPL_get_encode(int32_t native_id, uint8_t* output, int32_t outputLength) {
    LLSEC_PRIVATE_KEY_DEBUG_TRACE("%s \n", __func__);
    int return_code = LLSEC_ERROR;
    int mbedtls_rc = LLSEC_MBEDTLS_SUCCESS;

    LLSEC_priv_key* key = (LLSEC_priv_key*)native_id;
    mbedtls_pk_context pk;
    mbedtls_pk_type_t pk_type;

    if (TYPE_RSA == key->type) {
        pk_type = MBEDTLS_PK_RSA;
    } else {
        pk_type = MBEDTLS_PK_ECKEY;
    }

    mbedtls_pk_init(&pk);
    return_code = mbedtls_pk_setup(&pk, mbedtls_pk_info_from_type(pk_type));
    if(LLSEC_MBEDTLS_SUCCESS != mbedtls_rc) {
           (void)SNI_throwNativeException(mbedtls_rc, "Private key context setup failed");
    } else {
        pk.pk_ctx = (void*)key->key;

        //Write a private key to a PKCS#1 or SEC1 DER structure
        int length = mbedtls_pk_write_key_der(&pk, output, outputLength);
        if (0 > length) {
            (void)SNI_throwNativeException(LLSEC_ERROR, "DER encoding failed");
        } else {
            return_code = length;
        }
    }

    return return_code;
}

/**
 * @brief return the output size in bytes that an output buffer would need in order to hold the result of a decryption
 *        operation with this private key.
 *
 * @param[in] native_id the C structure pointer holding the key data
 *
 * @return the output size.
 *
 * @note Throws NativeException on error.
 */
int32_t LLSEC_PRIVATE_KEY_IMPL_get_output_size(int32_t native_id) {
    LLSEC_PRIVATE_KEY_DEBUG_TRACE("%s \n", __func__);

    LLSEC_priv_key* key = (LLSEC_priv_key*)native_id;
    int32_t return_code = LLSEC_SUCCESS;

    if (TYPE_RSA == key->type) {
        return_code = mbedtls_rsa_get_len((mbedtls_rsa_context*)key->key);
    } else {
        //No limit from EC point of view, return a big enough buffer
        return_code = LLSEC_PRIVATE_KEY_LOCAL_BUFFER_SIZE;
    }

    return return_code;
}
