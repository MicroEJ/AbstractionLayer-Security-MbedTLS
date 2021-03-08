/*
 * C
 *
 * Copyright 2021 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */
 
/**
 * @file
 * @brief X509 certificate parsing implementation.
 * @author @CCO_AUTHOR@
 * @version @CCO_VERSION@
 * @date @CCO_DATE@
 */

#include <LLSEC_X509_CERT_impl.h>
#include <LLNET_SSL_CONSTANTS.h>
#include <LLNET_SSL_ERRORS.h>
#include <LLNET_SSL_utils_mbedtls.h>
#include <stdlib.h>
#include <sni.h>

#include "mbedtls/ssl.h"
#include "mbedtls/platform.h"

#ifdef __cplusplus
	extern "C" {
#endif

int32_t LLSEC_X509_CERT_IMPL_parse(int8_t* cert, int32_t off, int32_t len){
	LLNET_SSL_DEBUG_TRACE("%s(cert=%d, off=%d, len=%d)\n", __func__, (int)cert, (int)off, (int)len);

	int32_t format = J_CERT_PARSE_ERROR;

	mbedtls_x509_crt * tmp_cert = NULL;

	do {
		int ret;

		/* Check parameters */
		if (((uint8_t *)(cert + off) == NULL) || (len == 0)) {
			format = J_BAD_FUNC_ARG;
			break;
		}

		/* Allocate a new X509 certificate */
		tmp_cert = (mbedtls_x509_crt *) mbedtls_calloc(1, sizeof(*tmp_cert));
		if (tmp_cert == NULL) {
			format = J_MEMORY_ERROR;
			break;
		}

		/* Initialize the X509 certificate */
		mbedtls_x509_crt_init(tmp_cert);

		/* Parse the X509 DER certificate */
		ret = mbedtls_x509_crt_parse_der(tmp_cert, (const uint8_t *) (cert + off), len);
		if (ret == 0) {
			/* Encoded DER certificate */
			format = CERT_DER_FORMAT;
			break;
		}

		/* Free the X509 certificate */
		mbedtls_x509_crt_free(tmp_cert);

		/* Initialize the X509 certificate */
		mbedtls_x509_crt_init(tmp_cert);

		/* Parse the X509 PEM certificate */
		ret = LLNET_SSL_utils_mbedtls_x509_crt_parse(tmp_cert, (uint8_t *)cert, off, len);
		if (ret == 0) {
			/* Encoded PEM certificate */
			format = CERT_PEM_FORMAT;
			break;
		}

		LLNET_SSL_DEBUG_TRACE("%s : return format=%d\n", __func__, format);
	} while (0);

	/* Free the X509 certificate */
	if (tmp_cert != NULL) {
		mbedtls_x509_crt_free(tmp_cert);
		mbedtls_free((void *) tmp_cert);
	}

	return format;
}

int32_t LLSEC_X509_CERT_IMPL_get_key(int8_t* cert_data, int32_t cert_data_length, uint8_t* key, int32_t key_length) {
	// TODO not implemented yet
	SNI_throwNativeException(J_UNKNOWN_ERROR, "Native not implemented yet");
	return -1;
}

int32_t LLSEC_X509_CERT_IMPL_verify(int8_t* cert_data, int32_t cert_data_length, uint8_t* key, int32_t key_length) {
	// TODO not implemented yet
	SNI_throwNativeException(J_UNKNOWN_ERROR, "Native not implemented yet");
	return -1;
}

int32_t LLSEC_X509_CERT_IMPL_get_x500_principal_data(int8_t* cert_data, int32_t cert_data_length, uint8_t* principal_data, int32_t principal_data_length, uint8_t get_issuer) {
	// TODO not implemented yet
	SNI_throwNativeException(J_UNKNOWN_ERROR, "Native not implemented yet");
	return -1;
}

#ifdef __cplusplus
	}
#endif
