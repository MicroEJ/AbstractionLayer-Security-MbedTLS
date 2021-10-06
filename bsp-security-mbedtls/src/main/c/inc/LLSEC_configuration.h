/*
 * C
 *
 * Copyright 2021 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */
 
/**
 * @file
 * @brief Security natives configuration.
 * @author @CCO_AUTHOR@
 * @version @CCO_VERSION@
 * @date @CCO_DATE@
 */

#include "microej_allocator.h"

#define LLSEC_calloc microej_calloc
#define LLSEC_free microej_free