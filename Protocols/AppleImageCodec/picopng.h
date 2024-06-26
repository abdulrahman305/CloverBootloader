/*
 * Copyright (c) 2000 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 * 
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef _PICOPNG_H
#define _PICOPNG_H

#include <Library/UefiLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Protocol/UgaDraw.h>

typedef struct {

	UINT32 *data;
	UINT32 size;
	UINT32 allocsize;

} VECTOR_32;

typedef struct {

	UINT8 *data;
	UINT32 size;
	UINT32 allocsize;

} VECTOR_8;

typedef struct {

	UINT32 width, height;
	UINT32 colorType, bitDepth;
	UINT32 compressionMethod, filterMethod, interlaceMethod;
	UINT32 key_r, key_g, key_b;
	BOOLEAN key_defined;
	VECTOR_8 *palette;
	VECTOR_8 *image;

} PNG_INFO;


/****************************************************/

typedef struct {
    INTN            Width;
    INTN            Height;
    BOOLEAN         HasAlpha;
    EFI_UGA_PIXEL   *PixelData;
} EG_IMAGE;

EG_IMAGE *egDecodePNG(IN UINT8 *FileData, IN UINTN FileDataLength, IN BOOLEAN WantAlpha);
EG_IMAGE *egDecodeICNS(IN UINT8 *FileData, IN UINTN FileDataLength, IN UINTN IconSize, IN BOOLEAN WantAlpha);
EG_IMAGE *egDecodeBMP(IN UINT8 *FileData, IN UINTN FileDataLength, IN BOOLEAN WantAlpha);

VOID      egFreeImage(IN EG_IMAGE *Image);
EG_IMAGE *egCreateImage(IN INTN Width, IN INTN Height, IN BOOLEAN HasAlpha);

#endif
