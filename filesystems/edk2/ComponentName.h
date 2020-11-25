/** @file
  EFI Component Name Protocol as defined in the EFI 1.1 specification.
  This protocol is used to retrieve user readable names of EFI Drivers 
  and controllers managed by EFI Drivers.

Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials are licensed and made available under 
the terms and conditions of the BSD License that accompanies this distribution.  
The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.                                          
    
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

/*
 * rEFInd NOTE: This file is included only when compiling with GNU-EFI,
 * which has not traditionally provided the definitions supplied here.
 * Unfortunately, recent (ca. 3.0.4) versions of GNU-EFI have added
 * SOME of these functions to an existing header file, creating problems
 * when trying to maintain compatibility with multiple GNU-EFI versions.
 * I've therefore renamed the relevant defines, types, and functions,
 * both here and in fsw_efi.c; and included a define to match the only
 * used name (REFIND_EFI_COMPONENT_NAME_PROTOCOL) to the traditional
 * name (EFI_COMPONENT_NAME_PROTOCOL) in fsw_efi.c for compiling with
 * TianoCore.
 */

#ifndef __REFIND_EFI_COMPONENT_NAME_H__
#define __REFIND_EFI_COMPONENT_NAME_H__

///
/// The global ID for the Component Name Protocol.
///
#define REFIND_EFI_COMPONENT_NAME_PROTOCOL_GUID \
  { \
    0x107a772c, 0xd5e1, 0x11d4, {0x9a, 0x46, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \
  }

typedef struct _REFIND_EFI_COMPONENT_NAME_PROTOCOL  REFIND_EFI_COMPONENT_NAME_PROTOCOL;


/**
  Retrieves a Unicode string that is the user-readable name of the EFI Driver.

  @param  This       A pointer to the REFIND_EFI_COMPONENT_NAME_PROTOCOL instance.
  @param  Language   A pointer to a three-character ISO 639-2 language identifier.
                     This is the language of the driver name that that the caller
                     is requesting, and it must match one of the languages specified
                     in SupportedLanguages.  The number of languages supported by a
                     driver is up to the driver writer.
  @param  DriverName A pointer to the Unicode string to return.  This Unicode string
                     is the name of the driver specified by This in the language
                     specified by Language.

  @retval EFI_SUCCESS           The Unicode string for the Driver specified by This
                                and the language specified by Language was returned
                                in DriverName.
  @retval EFI_INVALID_PARAMETER Language is NULL.
  @retval EFI_INVALID_PARAMETER DriverName is NULL.
  @retval EFI_UNSUPPORTED       The driver specified by This does not support the
                                language specified by Language.

**/
typedef
EFI_STATUS
(EFI_FUNCTION EFIAPI *REFIND_EFI_COMPONENT_NAME_GET_DRIVER_NAME)(
  IN REFIND_EFI_COMPONENT_NAME_PROTOCOL    *This,
  IN  CHAR8                                *Language,
  OUT CHAR16                               **DriverName
  );


/**
  Retrieves a Unicode string that is the user readable name of the controller
  that is being managed by an EFI Driver.

  @param  This             A pointer to the REFIND_EFI_COMPONENT_NAME_PROTOCOL instance.
  @param  ControllerHandle The handle of a controller that the driver specified by
                           This is managing.  This handle specifies the controller
                           whose name is to be returned.
  @param  ChildHandle      The handle of the child controller to retrieve the name
                           of.  This is an optional parameter that may be NULL.  It
                           will be NULL for device drivers.  It will also be NULL
                           for a bus drivers that wish to retrieve the name of the
                           bus controller.  It will not be NULL for a bus driver
                           that wishes to retrieve the name of a child controller.
  @param  Language         A pointer to a three character ISO 639-2 language
                           identifier.  This is the language of the controller name
                           that the caller is requesting, and it must match one
                           of the languages specified in SupportedLanguages.  The
                           number of languages supported by a driver is up to the
                           driver writer.
  @param  ControllerName   A pointer to the Unicode string to return.  This Unicode
                           string is the name of the controller specified by
                           ControllerHandle and ChildHandle in the language specified
                           by Language, from the point of view of the driver specified
                           by This.

  @retval EFI_SUCCESS           The Unicode string for the user-readable name in the
                                language specified by Language for the driver
                                specified by This was returned in DriverName.
  @retval EFI_INVALID_PARAMETER ControllerHandle is NULL.
  @retval EFI_INVALID_PARAMETER ChildHandle is not NULL and it is not a valid EFI_HANDLE.
  @retval EFI_INVALID_PARAMETER Language is NULL.
  @retval EFI_INVALID_PARAMETER ControllerName is NULL.
  @retval EFI_UNSUPPORTED       The driver specified by This is not currently managing
                                the controller specified by ControllerHandle and
                                ChildHandle.
  @retval EFI_UNSUPPORTED       The driver specified by This does not support the
                                language specified by Language.

**/
typedef
EFI_STATUS
(EFI_FUNCTION EFIAPI *REFIND_EFI_COMPONENT_NAME_GET_CONTROLLER_NAME)(
  IN  REFIND_EFI_COMPONENT_NAME_PROTOCOL                      *This,
  IN  EFI_HANDLE                                              ControllerHandle,
  IN  EFI_HANDLE                                              ChildHandle        OPTIONAL,
  IN  CHAR8                                                   *Language,
  OUT CHAR16                                                  **ControllerName
  );

///
/// This protocol is used to retrieve user readable names of drivers 
/// and controllers managed by UEFI Drivers.
///
struct _REFIND_EFI_COMPONENT_NAME_PROTOCOL {
  REFIND_EFI_COMPONENT_NAME_GET_DRIVER_NAME      GetDriverName;
  REFIND_EFI_COMPONENT_NAME_GET_CONTROLLER_NAME  GetControllerName;
  ///
  /// A Null-terminated ASCII string that contains one or more
  /// ISO 639-2 language codes. This is the list of language codes
  /// that this protocol supports.  
  ///
  CHAR8                                   *SupportedLanguages;
};

extern EFI_GUID gEfiComponentNameProtocolGuid;

#endif
