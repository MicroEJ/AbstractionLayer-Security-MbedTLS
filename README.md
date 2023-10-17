![SDK](https://shields.microej.com/endpoint?url=https://repository.microej.com/packages/badges/sdk_5.6.json)
![ARCH](https://shields.microej.com/endpoint?url=https://repository.microej.com/packages/badges/arch_7.18.json)

# Overview

Low Level MicroEJ Security API implementation for MbedTLS.

This component implements the `LLSEC` Low Level API for MicroEJ platforms connected to a Board Support Package based on MbedTLS.

# Usage

Add the following line to your `module.ivy` file:
> `<dependency org="com.microej.clibrary.llimpl" name="security-mbedtls" rev="..."/>`

# Requirements

N/A

# Validation

Here is a non exhaustive list of tested environments:
- Hardware
    - Espressif ESP-WROVER-KIT V4.1
- Compilers / Integrated Development Environments:
    - Espressif IoT Development Framework (``esp-idf``) v3.3.4 and v4.3.2 (using GNU GCC toolchain)
    - IAR Embedded Workbench 9.30.1
- MbedTLS versions:
    - MbedTLS v2.16.5, v2.16.11, v2.28.0 and v2.28.1

# MISRA Compliance

This Abstraction Layer implementation is MISRA-compliant (MISRA C:2012) with some noted exception. 
It has been verified with Cppcheck v2.10. Here is the list of deviations from MISRA standard:

| Deviation  | Category | Justification                                                      |
|:----------:|:--------:|:------------------------------------------------------------------ |
|  Rule 8.4  | Required | The Cppcheck analysis is made only on this LL code                 |
| Rule 11.3  | Required | Cast for matching MbedTLS function signature                       |
| Rule 11.4  | Advisory | Abstract data type for SNI usage                                   |
| Rule 11.5  | Advisory | Abstract data type for SNI usage                                   |
| Rule 21.3  | Advisory | Usage forced by MbedTLS library (mbedtls_calloc / mbedtls_free)    |

# Dependencies

- MicroEJ Architecture `7.x` or higher.
- MbedTLS `v2.16.5` or higher.
- Foundation library Security `v1.5.0`

# Source

N/A

# Restrictions

None.

	
---
_Copyright 2021-2023 MicroEJ Corp. All rights reserved._
_Use of this source code is governed by a BSD-style license that can be found with this software._