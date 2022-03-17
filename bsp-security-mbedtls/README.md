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
- MbedTLS versions:
    - MbedTLS v2.16.5 and v2.16.11

# MISRA Compliance

MISRA compliance is still a work in progress.
This implementation will be made fully compliant for 1.0.0 release.

# Dependencies

- MicroEJ Architecture `7.x` or higher.
- MbedTLS `v2.16.5` or higher.

# Source

N/A

# Restrictions

None.

	
---
_Copyright 2021-2022 MicroEJ Corp. All rights reserved._
_Use of this source code is governed by a BSD-style license that can be found with this software._