# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.6.1] - 2025-01-16

### Fixed

- Missing parenthesis arround definition of MBEDTLS_VERSION_OVER_3_5

## [1.6.0] - 2024-12-10

### Added

- Support for HMAC with MD5 and SHA1.

### Changed

- Uncrustify: apply MicroEJ coding style

### Fixed

- `mbedtls_pkcs5_pbkdf2_hmac_ext` called instead of `mbedtls_pkcs5_pbkdf2_hmac` for MbedTLS versions >= 3.5.0 and HMAC context is not setup anymore because it is not needed.

## [1.5.0] - 2024-03-08

### Added

- Add support for `DESede/CBC/NoPadding` cipher.

### Fixed

- Fix `LLSEC_PRIVATE_KEY_IMPL_get_encode` returning now the private key in PKCS#8 DER structure instead or PKCS#1 or SEC1 DER structure.
- Fix a potential memory retention in cryptographic components.
- Fixing a problem where using the same initialization vector (IV) for symmetric ciphers during next doFinal caused issues in cipher operations.

### Changed

- Generate RSA keypair with PKCS#1 v1.5 padding.

## [1.4.0] - 2023-11-15

### Changed

- Update CCO for mbedTLS v3.x.

### Added

- Add support for X509 certificate validity check.

## [1.3.0] - 2023-10-17

### Changed

- Move debug log activations in LLSEC_configuration.h.
- Rework error management.

### Fixed

- Make the CCO MISRA C:2012 compliant.

### Added

- Add Secret key implementation.

## [1.2.0] - 2023-04-11

### Added

- Add RSA ciphers.
- Fix all MISRA C:2012 warnings.

## [1.1.1] - 2023-02-06

### Fixed

- Project structure and format.

### Added

- Badges.

## [1.1.0] - 2023-01-16

### Fixed

- Seed errors.

### Added

- Support for MD5 and SHA01 digest algorithms.

## [1.0.1] - 2022-08-09

### Fixed

- Updated readme to specify Security Fondation library dependencies.

## [1.0.0] - 2022-07-04

### Changed

- Refactor code for MISRA C:2012 coding rules.

### Added

- Added cppcheck justification for MISRA C:2012 compliancy.
- MISRA C:2012 information into README.md.

## [0.10.0] - 2022-03-17

### Changed

- Move to BSD license.

### Fixed

- Typos in C files documentation.

## [0.9.0] - 2022-01-31

### Added

- Cipher implementation.
- Key factory implementation.
- Key pair generation implementation.
- MAC implementation.
- Private key implementation.
- Public key implementation.
- Signature implementation.

## [0.2.0] - 2021-10-06

### Added

- Secure random implementation.

## [0.1.0] - 2021-02-24

### Added

- Initial revision.

---
_Copyright 2021-2025 MicroEJ Corp. All rights reserved._
_Use of this source code is governed by a BSD-style license that can be found with this software._  
