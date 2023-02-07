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
    - MbedTLS v2.16.5, v2.16.11 and v2.28.0

# MISRA Compliance

This Abstraction Layer implementation is MISRA-compliant (MISRA C:2012) with some noted exception. 
It has been verified with Cppcheck v2.8.0. Here is the list of deviations from MISRA standard:

| Deviation  | Category | Justification                                                      |
|:----------:|:--------:|:------------------------------------------------------------------ |
|  Rule 8.4  | Required | The Cppcheck analysis is made only on this LL code                 |
|  Rule 8.7  | Advisory | The Cppcheck analysis is made only on this LL code                 |
|  Rule 8.9  | Advisory | Global variable or for code readability                            |
| Rule 10.8  | Required | Boundries of the value is controlled                               |
| Rule 11.1  | Required | Abstract data type for SNI usage                                   |
| Rule 11.3  | Required | Cast for matching MbedTLS function signature                       |
| Rule 11.4  | Advisory | Abstract data type for SNI usage                                   |
| Rule 11.5  | Advisory | Abstract data type for SNI usage                                   |
| Rule 11.6  | Required | Abstract data type for SNI usage                                   |
| Rule 11.8  | Required | Cast to match used generic library function ```mbedtls_free```     |
| Rule 17.8  | Advisory | Used as an output parameter                                        |
| Rule 21.6  | Required | Used for debug purpose only                                        |
| Rule 21.10 | Required | Type defined in library used in MbedTLS                            |

# Dependencies

- MicroEJ Architecture `7.x` or higher.
- MbedTLS `v2.16.5` or higher.
- Foundation library Security `v1.3.1`

# Source

N/A

# Restrictions

None.

	
---
_Copyright 2021-2023 MicroEJ Corp. All rights reserved._
_Use of this source code is governed by a BSD-style license that can be found with this software._