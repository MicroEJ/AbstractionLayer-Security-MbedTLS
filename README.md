![SDK](https://shields.microej.com/endpoint?url=https://repository.microej.com/packages/badges/sdk_6.0.json)
![ARCH](https://shields.microej.com/endpoint?url=https://repository.microej.com/packages/badges/arch_8.3.json)
![NET_10](https://shields.microej.com/endpoint?url=https://repository.microej.com/packages/badges/net_10.json)
![NET_11](https://shields.microej.com/endpoint?url=https://repository.microej.com/packages/badges/net_11.json)

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
    - NXP MIMXRT1170-EVKB
    - Espressif ESP32-S3-DevKitC-1
- Compilers / Integrated Development Environments:
    - NXP MCUXpresso (GNU Arm Embedded Toolchain 10.3-2021.10)
    - Espressif IoT Development Framework (``esp-idf``) v5.0.1 (using GNU GCC toolchain)
- MbedTLS versions:
    - MbedTLS v2.28.5 and v3.2.1

# MISRA Compliance

This Abstraction Layer implementation is MISRA-compliant (MISRA C:2012) with some noted exception. 
It has been verified with Cppcheck v2.16. Here is the list of deviations from MISRA standard:

| Deviation  | Category | Justification                                                                          |
|:----------:|:--------:|:--------------------------------------------------------------------------------------:|
| Rule 2.3   | Advisory | A type can be defined at API level and not used by the application                     |
| Rule 2.4   | Advisory | A tag can be defined at API level and not used by the application                      |
| Rule 2.5   | Advisory | A macro can be defined at API level and not used by the application                    |
| Rule 8.7   | Advisory | LLAPI functions require external linkage but invocation cannot be detected by cppcheck |
| Rule 8.9   | Advisory | Some static globals are defined file wide for readability                              |
| Rule 11.1  | Required | The LLAPI expects function pointers to be passed as integer                            |
| Rule 11.3  | Required | Cast for matching MbedTLS function signature                                           |
| Rule 11.4  | Advisory | Abstract data type for SNI usage                                                       |
| Rule 11.5  | Advisory | Abstract data type for SNI usage                                                       |
| Rule 11.6  | Required | Conversion from function pointer to integer is sometimes detected as void* to integer conversion |
| Rule 11.8  | Required | Const attribute removed from pointer to function when passed as callbacks              |
| Rule 18.4  | Advisory | Used in SNI_getArrayLength() macro, part of the SNI API                                |
| Rule 19.2  | Advisory | Using union is useful for C library design                                             |
| Rule 20.10 | Advisory | Used by stringify macro to throw insightful exceptions                                 |
| Rule 21.3  | Required | MbedTLS provides configurable memory management macros (mbedtls_calloc / mbedtls_free) which may be redirected to stdlib's implementation |
| Rule 21.10 | Required | MbedTLS has a dependency on <time.h>                                                   |

# Dependencies

- MbedTLS v2.x or v3.x

# Source

N/A

# Restrictions

None.

	
---
_Copyright 2021-2025 MicroEJ Corp. All rights reserved._
_Use of this source code is governed by a BSD-style license that can be found with this software._