![SDK](https://shields.microej.com/endpoint?url=https://repository.microej.com/packages/badges/sdk_6.0.json)
![ARCH](https://shields.microej.com/endpoint?url=https://repository.microej.com/packages/badges/arch_8.3.json)

# Overview

Low Level MicroEJ Security API implementation for MbedTLS.

This component implements the `LLSEC` Low Level API for MicroEJ platforms connected to a Board Support Package based on MbedTLS.

# Usage

These sources can be included in the VEE Port with the method you prefer, by using this repository as a submodule or by doing a copy of the sources in the VEE Port repository.

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
    - MbedTLS v2.16.5, v2.16.11, v2.28.0, v2.28.1 and v3.2.1

# MISRA Compliance

This Abstraction Layer implementation is MISRA-compliant (MISRA C:2012) with some noted exception. 
It has been verified with Cppcheck v2.10. Here is the list of deviations from MISRA standard:

| Deviation  | Category | Justification                                                       |
|:----------:|:--------:|:------------------------------------------------------------------- |
|  Rule 2.3  | Advisory | A type can be defined at API level and not used by the application  |
|  Rule 2.4  | Advisory | A tag can be defined at API level and not used by the application   |
|  Rule 2.5  | Advisory | A macro can be defined at API level and not used by the application |
|  Rule 8.4  | Required | The Cppcheck analysis is made only on this LL code                  |
| Rule 11.3  | Required | Cast for matching MbedTLS function signature                        |
| Rule 11.4  | Advisory | Abstract data type for SNI usage                                    |
| Rule 11.5  | Advisory | Abstract data type for SNI usage                                    |
| Rule 19.2  | Advisory | Using union is useful for C library design                          |
| Rule 21.3  | Required | Usage forced by MbedTLS library (mbedtls_calloc / mbedtls_free)     |

# Dependencies

- MbedTLS `v2.16.5` or higher.

# Source

N/A

# Restrictions

None.

	
---
_Copyright 2021-2025 MicroEJ Corp. All rights reserved._
_Use of this source code is governed by a BSD-style license that can be found with this software._