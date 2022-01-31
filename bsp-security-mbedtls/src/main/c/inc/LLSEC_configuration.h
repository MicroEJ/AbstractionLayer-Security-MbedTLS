/*
 * C
 *
 * Copyright 2021-2022 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */
 
/**
 * @file
 * @brief Security natives configuration.
 * @author MicroEJ Developer Team
 * @version 1.0.0
 */

#include "microej_allocator.h"

#define LLSEC_calloc microej_calloc
#define LLSEC_free microej_free

/*
* Used for private and public key generation
*/
#define LLSEC_PRIVATE_KEY_LOCAL_BUFFER_SIZE 3072
#define LLSEC_PUBLIC_KEY_LOCAL_BUFFER_SIZE  3072
