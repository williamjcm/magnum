/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

/* See Magnum/Vk/Enums.cpp and Magnum/Vk/Test/EnumsTest.cpp */
#ifdef _c
_c(Bc1RGBUnorm, BC1_RGB_UNORM_BLOCK)
_c(Bc1RGBSrgb, BC1_RGB_SRGB_BLOCK)
_c(Bc1RGBAUnorm, BC1_RGBA_UNORM_BLOCK)
_c(Bc1RGBASrgb, BC1_RGBA_SRGB_BLOCK)
_c(Bc2RGBAUnorm, BC2_UNORM_BLOCK)
_c(Bc2RGBASrgb, BC2_SRGB_BLOCK)
_c(Bc3RGBAUnorm, BC3_UNORM_BLOCK)
_c(Bc3RGBASrgb, BC3_SRGB_BLOCK)
_c(Bc4RUnorm, BC4_UNORM_BLOCK)
_c(Bc4RSnorm, BC4_SNORM_BLOCK)
_c(Bc5RGUnorm, BC5_UNORM_BLOCK)
_c(Bc5RGSnorm, BC5_SNORM_BLOCK)
_c(Bc6hRGBUfloat, BC6H_UFLOAT_BLOCK)
_c(Bc6hRGBSfloat, BC6H_SFLOAT_BLOCK)
_c(Bc7RGBAUnorm, BC7_UNORM_BLOCK)
_c(Bc7RGBASrgb, BC7_SRGB_BLOCK)
_c(EacR11Unorm, EAC_R11_UNORM_BLOCK)
_c(EacR11Snorm, EAC_R11_SNORM_BLOCK)
_c(EacRG11Unorm, EAC_R11G11_UNORM_BLOCK)
_c(EacRG11Snorm, EAC_R11G11_SNORM_BLOCK)
_c(Etc2RGB8Unorm, ETC2_R8G8B8_UNORM_BLOCK)
_c(Etc2RGB8Srgb, ETC2_R8G8B8_SRGB_BLOCK)
_c(Etc2RGB8A1Unorm, ETC2_R8G8B8A1_UNORM_BLOCK)
_c(Etc2RGB8A1Srgb, ETC2_R8G8B8A1_SRGB_BLOCK)
_c(Etc2RGBA8Unorm, ETC2_R8G8B8A8_UNORM_BLOCK)
_c(Etc2RGBA8Srgb, ETC2_R8G8B8A8_SRGB_BLOCK)
_c(Astc4x4RGBAUnorm, ASTC_4x4_UNORM_BLOCK)
_c(Astc4x4RGBASrgb, ASTC_4x4_SRGB_BLOCK)
_c(Astc5x4RGBAUnorm, ASTC_5x4_UNORM_BLOCK)
_c(Astc5x4RGBASrgb, ASTC_5x4_SRGB_BLOCK)
_c(Astc5x5RGBAUnorm, ASTC_5x5_UNORM_BLOCK)
_c(Astc5x5RGBASrgb, ASTC_5x5_SRGB_BLOCK)
_c(Astc6x5RGBAUnorm, ASTC_6x5_UNORM_BLOCK)
_c(Astc6x5RGBASrgb, ASTC_6x5_SRGB_BLOCK)
_c(Astc6x6RGBAUnorm, ASTC_6x6_UNORM_BLOCK)
_c(Astc6x6RGBASrgb, ASTC_6x6_SRGB_BLOCK)
_c(Astc8x5RGBAUnorm, ASTC_8x5_UNORM_BLOCK)
_c(Astc8x5RGBASrgb, ASTC_8x5_SRGB_BLOCK)
_c(Astc8x6RGBAUnorm, ASTC_8x6_UNORM_BLOCK)
_c(Astc8x6RGBASrgb, ASTC_8x6_SRGB_BLOCK)
_c(Astc8x8RGBAUnorm, ASTC_8x8_UNORM_BLOCK)
_c(Astc8x8RGBASrgb, ASTC_8x8_SRGB_BLOCK)
_c(Astc10x5RGBAUnorm, ASTC_10x5_UNORM_BLOCK)
_c(Astc10x5RGBASrgb, ASTC_10x5_SRGB_BLOCK)
_c(Astc10x6RGBAUnorm, ASTC_10x6_UNORM_BLOCK)
_c(Astc10x6RGBASrgb, ASTC_10x6_SRGB_BLOCK)
_c(Astc10x8RGBAUnorm, ASTC_10x8_UNORM_BLOCK)
_c(Astc10x8RGBASrgb, ASTC_10x8_SRGB_BLOCK)
_c(Astc10x10RGBAUnorm, ASTC_10x10_UNORM_BLOCK)
_c(Astc10x10RGBASrgb, ASTC_10x10_SRGB_BLOCK)
_c(Astc12x10RGBAUnorm, ASTC_12x10_UNORM_BLOCK)
_c(Astc12x10RGBASrgb, ASTC_12x10_SRGB_BLOCK)
_c(Astc12x12RGBAUnorm, ASTC_12x12_UNORM_BLOCK)
_c(Astc12x12RGBASrgb, ASTC_12x12_SRGB_BLOCK)
/* https://github.com/KhronosGroup/Vulkan-Docs/issues/512 */
_c(PvrtcRGB2bppUnorm, PVRTC1_2BPP_UNORM_BLOCK_IMG)
_c(PvrtcRGB2bppSrgb, PVRTC1_2BPP_SRGB_BLOCK_IMG)
_c(PvrtcRGBA2bppUnorm, PVRTC1_2BPP_UNORM_BLOCK_IMG)
_c(PvrtcRGBA2bppSrgb, PVRTC1_2BPP_SRGB_BLOCK_IMG)
_c(PvrtcRGB4bppUnorm, PVRTC1_4BPP_UNORM_BLOCK_IMG)
_c(PvrtcRGB4bppSrgb, PVRTC1_4BPP_SRGB_BLOCK_IMG)
_c(PvrtcRGBA4bppUnorm, PVRTC1_4BPP_UNORM_BLOCK_IMG)
_c(PvrtcRGBA4bppSrgb, PVRTC1_4BPP_SRGB_BLOCK_IMG)
#endif
