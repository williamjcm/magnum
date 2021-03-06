#ifndef Magnum_PixelFormat_h
#define Magnum_PixelFormat_h
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

/** @file
 * @brief Enum @ref Magnum::PixelFormat, @ref Magnum::CompressedPixelFormat, function @ref Magnum::pixelSize(), @ref Magnum::isPixelFormatImplementationSpecific(), @ref Magnum::pixelFormatWrap(), @ref Magnum::pixelFormatUnwrap(), @ref Magnum::isCompressedPixelFormatImplementationSpecific(), @ref Magnum::compressedPixelFormatWrap(), @ref Magnum::compressedPixelFormatUnwrap()
 */

#include <Corrade/Utility/Assert.h>

#include "Magnum/Magnum.h"
#include "Magnum/visibility.h"

namespace Magnum {

/**
@brief Format of pixel data

Can act also as a wrapper for implementation-specific pixel format values using
@ref pixelFormatWrap() and @ref pixelFormatUnwrap(). Distinction between
generic and implementation-specific formats can be done using
@ref isPixelFormatImplementationSpecific().

In case of OpenGL, corresponds to @ref GL::PixelFormat and @ref GL::PixelType
and is convertible to them using @ref GL::pixelFormat() and
@ref GL::pixelType(). See documentation of each value for more information
about the mapping. Note that not every format is available on all targets, use
@ref GL::hasPixelFormat() to check for its presence.

In case of Vulkan, corresponds to @type_vk_keyword{Format} and is convertible
to it using @ref Vk::vkFormat(Magnum::PixelFormat). See documentation of each
value for more information about the mapping. Note that not every format may be
available, use @ref Vk::hasVkFormat(Magnum::PixelFormat) to check for its
presence.
@see @ref pixelSize(), @ref CompressedPixelFormat, @ref Image, @ref ImageView
*/
enum class PixelFormat: UnsignedInt {
    /* Zero reserved for an invalid format (but not being a named value) */

    /**
     * Red component, normalized unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::Red and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::R8 /
     * @def_vk_keyword{FORMAT_R8_UNORM,Format}.
     */
    R8Unorm = 1,

    /**
     * Red and green component, normalized unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::RG and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::RG8 /
     * @def_vk_keyword{FORMAT_R8G8_UNORM,Format}.
     */
    RG8Unorm,

    /**
     * RGB, normalized unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGB and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::RGB8 /
     * @def_vk_keyword{FORMAT_R8G8B8_UNORM,Format}.
     */
    RGB8Unorm,

    /**
     * RGBA, normalized unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGBA and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::RGBA8 /
     * @def_vk_keyword{FORMAT_R8G8B8A8_UNORM,Format}.
     */
    RGBA8Unorm,

    /**
     * Red component, normalized signed byte.
     *
     * Corresponds to @ref GL::PixelFormat::Red and
     * @ref GL::PixelType::Byte, @ref GL::TextureFormat::R8Snorm /
     * @def_vk_keyword{FORMAT_R8_SNORM,Format}.
     */
    R8Snorm,

    /**
     * Red and green component, normalized signed byte.
     *
     * Corresponds to @ref GL::PixelFormat::RG and
     * @ref GL::PixelType::Byte, @ref GL::TextureFormat::RG8Snorm /
     * @def_vk_keyword{FORMAT_R8G8_SNORM,Format}.
     */
    RG8Snorm,

    /**
     * RGB, normalized signed byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGB and
     * @ref GL::PixelType::Byte, @ref GL::TextureFormat::RGB8Snorm /
     * @def_vk_keyword{FORMAT_R8G8B8_SNORM,Format}.
     */
    RGB8Snorm,

    /**
     * RGBA, normalized signed byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGBA and
     * @ref GL::PixelType::Byte, @ref GL::TextureFormat::RGBA8Snorm /
     * @def_vk_keyword{FORMAT_R8G8B8A8_SNORM,Format}.
     */
    RGBA8Snorm,

    /**
     * sRGB-encoded red component, normalized unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::Red and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::SR8 /
     * @def_vk_keyword{FORMAT_R8_SRGB,Format}.
     */
    R8Srgb,

    /**
     * sRGB-encoded red and green component, normalized unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::RG and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::SRG8 /
     * @def_vk_keyword{FORMAT_R8G8_SRGB,Format}.
     */
    RG8Srgb,

    /**
     * sRGB, normalized unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGB and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::SRGB8 /
     * @def_vk_keyword{FORMAT_R8G8B8_SRGB,Format}.
     */
    RGB8Srgb,

    /**
     * sRGB + linear alpha, normalized unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGBA and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::SRGB8Alpha8 /
     * @def_vk_keyword{FORMAT_R8G8B8A8_SRGB,Format}.
     */
    RGBA8Srgb,

    /**
     * Red component, integral unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::RedInteger and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::R8UI /
     * @def_vk_keyword{FORMAT_R8_UINT,Format}.
     */
    R8UI,

    /**
     * Red and green component, integral unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGInteger and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::RG8UI /
     * @def_vk_keyword{FORMAT_R8G8_UINT,Format}.
     */
    RG8UI,

    /**
     * RGB, integral unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGBInteger and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::RGB8UI /
     * @def_vk_keyword{FORMAT_R8G8B8_UINT,Format}.
     */
    RGB8UI,

    /**
     * RGBA, integral unsigned byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGBAInteger and
     * @ref GL::PixelType::UnsignedByte, @ref GL::TextureFormat::RGBA8UI /
     * @def_vk_keyword{FORMAT_R8G8B8A8_UINT,Format}.
     */
    RGBA8UI,

    /**
     * Red component, integral signed byte.
     *
     * Corresponds to @ref GL::PixelFormat::RedInteger and
     * @ref GL::PixelType::Byte, @ref GL::TextureFormat::R8I /
     * @def_vk_keyword{FORMAT_R8_SINT,Format}.
     */
    R8I,

    /**
     * Red and green component, integral signed byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGInteger and
     * @ref GL::PixelType::Byte, @ref GL::TextureFormat::RG8I /
     * @def_vk_keyword{FORMAT_R8G8_SINT,Format}.
     */
    RG8I,

    /**
     * RGB, integral signed byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGBInteger and
     * @ref GL::PixelType::Byte, @ref GL::TextureFormat::RGB8I /
     * @def_vk_keyword{FORMAT_R8G8B8_SINT,Format}.
     */
    RGB8I,

    /**
     * RGBA, integral signed byte.
     *
     * Corresponds to @ref GL::PixelFormat::RGBAInteger and
     * @ref GL::PixelType::Byte, @ref GL::TextureFormat::RGBA8I /
     * @def_vk_keyword{FORMAT_R8G8B8A8_SINT,Format}.
     */
    RGBA8I,

    /**
     * Red component, normalized unsigned short.
     *
     * Corresponds to @ref GL::PixelFormat::Red and
     * @ref GL::PixelType::UnsignedShort, @ref GL::TextureFormat::R16 /
     * @def_vk_keyword{FORMAT_R16_UNORM,Format}.
     */
    R16Unorm,

    /**
     * Red and green component, normalized unsigned short.
     *
     * Corresponds to @ref GL::PixelFormat::RG and
     * @ref GL::PixelType::UnsignedShort, @ref GL::TextureFormat::RG16 /
     * @def_vk_keyword{FORMAT_R16G16_UNORM,Format}.
     */
    RG16Unorm,

    /**
     * RGB, normalized unsigned short.
     *
     * Corresponds to @ref GL::PixelFormat::RGB and
     * @ref GL::PixelType::UnsignedShort, @ref GL::TextureFormat::RGB16 /
     * @def_vk_keyword{FORMAT_R16G16B16_UNORM,Format}.
     */
    RGB16Unorm,

    /**
     * RGBA, normalized unsigned short.
     *
     * Corresponds to @ref GL::PixelFormat::RGBA and
     * @ref GL::PixelType::UnsignedShort, @ref GL::TextureFormat::RGBA16 /
     * @def_vk_keyword{FORMAT_R16G16B16A16_UNORM,Format}.
     */
    RGBA16Unorm,

    /**
     * Red component, normalized signed short.
     *
     * Corresponds to @ref GL::PixelFormat::Red and
     * @ref GL::PixelType::Short, @ref GL::TextureFormat::R16Snorm /
     * @def_vk_keyword{FORMAT_R16_SNORM,Format}.
     */
    R16Snorm,

    /**
     * Red and green component, normalized signed short.
     *
     * Corresponds to @ref GL::PixelFormat::RG and
     * @ref GL::PixelType::Short, @ref GL::TextureFormat::RG16Snorm /
     * @def_vk_keyword{FORMAT_R16G16_SNORM,Format}.
     */
    RG16Snorm,

    /**
     * RGB, normalized signed short.
     *
     * Corresponds to @ref GL::PixelFormat::RGB and
     * @ref GL::PixelType::Short, @ref GL::TextureFormat::RGB16Snorm /
     * @def_vk_keyword{FORMAT_R16G16B16_SNORM,Format}.
     */
    RGB16Snorm,

    /**
     * RGBA, normalized signed short.
     *
     * Corresponds to @ref GL::PixelFormat::RGBA and
     * @ref GL::PixelType::Short, @ref GL::TextureFormat::RGBA16Snorm /
     * @def_vk_keyword{FORMAT_R16G16B16A16_SNORM,Format}.
     */
    RGBA16Snorm,

    /**
     * Red component, integral unsigned short.
     *
     * Corresponds to @ref GL::PixelFormat::RedInteger and
     * @ref GL::PixelType::UnsignedShort, @ref GL::TextureFormat::R16UI /
     * @def_vk_keyword{FORMAT_R16_UINT,Format}.
     */
    R16UI,

    /**
     * Red and green component, integral unsigned short.
     *
     * Corresponds to @ref GL::PixelFormat::RGInteger and
     * @ref GL::PixelType::UnsignedShort, @ref GL::TextureFormat::RG16UI /
     * @def_vk_keyword{FORMAT_R16G16_UINT,Format}.
     */
    RG16UI,

    /**
     * RGB, integral unsigned short.
     *
     * Corresponds to @ref GL::PixelFormat::RGBInteger and
     * @ref GL::PixelType::UnsignedShort, @ref GL::TextureFormat::RGB16UI /
     * @def_vk_keyword{FORMAT_R16G16B16_UINT,Format}.
     */
    RGB16UI,

    /**
     * RGBA, integral unsigned short.
     *
     * Corresponds to @ref GL::PixelFormat::RGBAInteger and
     * @ref GL::PixelType::UnsignedShort, @ref GL::TextureFormat::RGBA16UI /
     * @def_vk_keyword{FORMAT_R16G16B16A16_UINT,Format}.
     */
    RGBA16UI,

    /**
     * Red component, integral signed short.
     *
     * Corresponds to @ref GL::PixelFormat::RedInteger and
     * @ref GL::PixelType::Short, @ref GL::TextureFormat::R16I /
     * @def_vk_keyword{FORMAT_R16_SINT,Format}.
     */
    R16I,

    /**
     * Red and green component, integral signed short.
     *
     * Corresponds to @ref GL::PixelFormat::RGInteger and
     * @ref GL::PixelType::Short, @ref GL::TextureFormat::RG16I /
     * @def_vk_keyword{FORMAT_R16G16_SINT,Format}.
     */
    RG16I,

    /**
     * RGB, integral signed short.
     *
     * Corresponds to @ref GL::PixelFormat::RGBInteger and
     * @ref GL::PixelType::Short, @ref GL::TextureFormat::RGB16I /
     * @def_vk_keyword{FORMAT_R16G16B16_SINT,Format}.
     */
    RGB16I,

    /**
     * RGBA, integral signed short.
     *
     * Corresponds to @ref GL::PixelFormat::RGBAInteger and
     * @ref GL::PixelType::Short, @ref GL::TextureFormat::RGBA16I /
     * @def_vk_keyword{FORMAT_R16G16B16A16_SINT,Format}.
     */
    RGBA16I,

    /**
     * Red component, integral unsigned int.
     *
     * Corresponds to @ref GL::PixelFormat::RedInteger and
     * @ref GL::PixelType::UnsignedInt, @ref GL::TextureFormat::R32UI /
     * @def_vk_keyword{FORMAT_R32_UINT,Format}.
     */
    R32UI,

    /**
     * Red and green component, integral unsigned int.
     *
     * Corresponds to @ref GL::PixelFormat::RGInteger and
     * @ref GL::PixelType::UnsignedInt, @ref GL::TextureFormat::RG32UI /
     * @def_vk_keyword{FORMAT_R32G32_UINT,Format}.
     */
    RG32UI,

    /**
     * RGB, integral unsigned int.
     *
     * Corresponds to @ref GL::PixelFormat::RGBInteger and
     * @ref GL::PixelType::UnsignedInt, @ref GL::TextureFormat::RGB32UI /
     * @def_vk_keyword{FORMAT_R32G32B32_UINT,Format}.
     */
    RGB32UI,

    /**
     * RGBA, integral unsigned int.
     *
     * Corresponds to @ref GL::PixelFormat::RGBAInteger and
     * @ref GL::PixelType::UnsignedInt, @ref GL::TextureFormat::RGBA32UI /
     * @def_vk_keyword{FORMAT_R32G32B32A32_UINT,Format}.
     */
    RGBA32UI,

    /**
     * Red component, integral signed int.
     *
     * Corresponds to @ref GL::PixelFormat::RedInteger and
     * @ref GL::PixelType::Int, @ref GL::TextureFormat::R32I /
     * @def_vk_keyword{FORMAT_R32_SINT,Format}.
     */
    R32I,

    /**
     * Red and green component, integral signed int.
     *
     * Corresponds to @ref GL::PixelFormat::RGInteger and
     * @ref GL::PixelType::Int, @ref GL::TextureFormat::RG32I /
     * @def_vk_keyword{FORMAT_R32G32_SINT,Format}.
     */
    RG32I,

    /**
     * RGB, integral signed int.
     *
     * Corresponds to @ref GL::PixelFormat::RGBInteger and
     * @ref GL::PixelType::Int, @ref GL::TextureFormat::RGB32I /
     * @def_vk_keyword{FORMAT_R32G32B32_SINT,Format}.
     */
    RGB32I,

    /**
     * RGBA, integral signed int.
     *
     * Corresponds to @ref GL::PixelFormat::RGBAInteger and
     * @ref GL::PixelType::Int, @ref GL::TextureFormat::RGBA32I /
     * @def_vk_keyword{FORMAT_R32G32B32A32_SINT,Format}.
     */
    RGBA32I,

    /**
     * Red component, half float.
     *
     * Corresponds to @ref GL::PixelFormat::Red and
     * @ref GL::PixelType::HalfFloat, @ref GL::TextureFormat::R16F /
     * @def_vk_keyword{FORMAT_R16_SFLOAT,Format}.
     * @see @ref Half, @ref Math::packHalf(), @ref Math::unpackHalf()
     */
    R16F,

    /**
     * Red and green component, half float.
     *
     * Corresponds to @ref GL::PixelFormat::RG and
     * @ref GL::PixelType::HalfFloat, @ref GL::TextureFormat::RG16F /
     * @def_vk_keyword{FORMAT_R16G16_SFLOAT,Format}.
     * @see @ref Half, @ref Math::packHalf(), @ref Math::unpackHalf()
     */
    RG16F,

    /**
     * RGB, half float.
     *
     * Corresponds to @ref GL::PixelFormat::RGB and
     * @ref GL::PixelType::HalfFloat, @ref GL::TextureFormat::RGB16F /
     * @def_vk_keyword{FORMAT_R16G16B16_SFLOAT,Format}.
     * @see @ref Half, @ref Math::packHalf(), @ref Math::unpackHalf()
     */
    RGB16F,

    /**
     * RGBA, half float.
     *
     * Corresponds to @ref GL::PixelFormat::RGBA and
     * @ref GL::PixelType::HalfFloat, @ref GL::TextureFormat::RGBA16F /
     * @def_vk_keyword{FORMAT_R16G16B16A16_SFLOAT,Format}.
     * @see @ref Half, @ref Math::packHalf(), @ref Math::unpackHalf()
     */
    RGBA16F,

    /**
     * Red component, half float.
     *
     * Corresponds to @ref GL::PixelFormat::Red and
     * @ref GL::PixelType::Float, @ref GL::TextureFormat::R32F /
     * @def_vk_keyword{FORMAT_R32_SFLOAT,Format}.
     */
    R32F,

    /**
     * Red and green component, half float.
     *
     * Corresponds to @ref GL::PixelFormat::RG and
     * @ref GL::PixelType::Float, @ref GL::TextureFormat::RG32F /
     * @def_vk_keyword{FORMAT_R32G32_SFLOAT,Format}.
     */
    RG32F,

    /**
     * RGB, half float.
     *
     * Corresponds to @ref GL::PixelFormat::RGB and
     * @ref GL::PixelType::Float, @ref GL::TextureFormat::RGB32F /
     * @def_vk_keyword{FORMAT_R32G32B32_SFLOAT,Format}.
     */
    RGB32F,

    /**
     * RGBA, half float.
     *
     * Corresponds to @ref GL::PixelFormat::RGBA and
     * @ref GL::PixelType::Float, @ref GL::TextureFormat::RGBA32F /
     * @def_vk_keyword{FORMAT_R32G32B32A32_SFLOAT,Format}.
     */
    RGBA32F
};

/**
@brief Pixel size

Expects that the pixel format is *not* implementation-specific.
@see @ref isPixelFormatImplementationSpecific(), @ref GL::pixelSize()
*/
MAGNUM_EXPORT UnsignedInt pixelSize(PixelFormat format);

/** @debugoperatorenum{PixelFormat} */
MAGNUM_EXPORT Debug& operator<<(Debug& debug, PixelFormat value);

/**
@brief Whether a @ref PixelFormat value wraps an implementation-specific identifier

Returns @cpp true @ce if value of @p format has its highest bit set, @cpp false @ce
otherwise. Use @ref pixelFormatWrap() and @ref pixelFormatUnwrap() to
wrap/unwrap an implementation-specific indentifier to/from @ref PixelFormat.
@see @ref isCompressedPixelFormatImplementationSpecific()
*/
constexpr bool isPixelFormatImplementationSpecific(PixelFormat format) {
    return UnsignedInt(format) & (1u << 31);
}

/**
@brief Wrap an implementation-specific pixel format identifier in @ref PixelFormat

Sets the highest bit on @p format to mark it as implementation-specific.
Expects that @p format fits into the remaining bits. Use @ref pixelFormatUnwrap()
for the inverse operation.
@see @ref isPixelFormatImplementationSpecific(), @ref compressedPixelFormatWrap()
*/
template<class T> constexpr PixelFormat pixelFormatWrap(T implementationSpecific) {
    static_assert(sizeof(T) <= 4,
        "format types larger than 32bits are not supported");
    return CORRADE_CONSTEXPR_ASSERT(!(UnsignedInt(implementationSpecific) & (1u << 31)),
        "pixelFormatWrap(): implementation-specific value already wrapped or too large"),
        PixelFormat((1u << 31)|UnsignedInt(implementationSpecific));
}

/**
@brief Unwrap an implementation-specific pixel format identifier from @ref PixelFormat

Unsets the highest bit from @p format to extract the implementation-specific
value. Expects that @p format has it set. Use @ref pixelFormatWrap() for the
inverse operation.
@see @ref isPixelFormatImplementationSpecific(), @ref compressedPixelFormatUnwrap()
*/
template<class T = UnsignedInt> constexpr T pixelFormatUnwrap(PixelFormat format) {
    return CORRADE_CONSTEXPR_ASSERT(UnsignedInt(format) & (1u << 31),
        "pixelFormatUnwrap(): format doesn't contain a wrapped implementation-specific value"),
        T(UnsignedInt(format) & ~(1u << 31));
}

/**
@brief Format of compressed pixel data

Can act also as a wrapper for implementation-specific pixel format values using
@ref compressedPixelFormatWrap() and @ref compressedPixelFormatUnwrap().
Distinction between generic and implementation-specific formats can be done
using @ref isCompressedPixelFormatImplementationSpecific().

In case of OpenGL, corresponds to @ref GL::CompressedPixelFormat and is
convertible to it using @ref GL::compressedPixelFormat(). See documentation of
each value for more information about the mapping. Note that not every format
is available on all targets, use @ref GL::hasCompressedPixelFormat() to check
for its presence.

In case of Vulkan, corresponds to @type_vk_keyword{Format} and is convertible
to it using @ref Vk::vkFormat(Magnum::CompressedPixelFormat). See documentation
of each value for more information about the mapping. Note that not every
format may be available, use @ref Vk::hasVkFormat(Magnum::CompressedPixelFormat)
to check for its presence.
@see @ref PixelFormat, @ref CompressedImage, @ref CompressedImageView
*/
enum class CompressedPixelFormat: UnsignedInt {
    /* Zero reserved for an invalid format (but not being a named value) */

    /**
     * [S3TC](https://en.wikipedia.org/wiki/S3_Texture_Compression) BC1
     * compressed RGB, normalized unsigned byte (DXT1).
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBS3tcDxt1,
     * @ref GL::TextureFormat::CompressedRGBS3tcDxt1 /
     * @def_vk_keyword{FORMAT_BC1_RGB_UNORM_BLOCK,Format}.
     */
    Bc1RGBUnorm = 1,

    /**
     * [S3TC](https://en.wikipedia.org/wiki/S3_Texture_Compression) BC1
     * compressed sRGB, normalized unsigned byte (DXT1).
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGBS3tcDxt1,
     * @ref GL::TextureFormat::CompressedSRGBS3tcDxt1 /
     * @def_vk_keyword{FORMAT_BC1_RGB_SRGB_BLOCK,Format}.
     */
    Bc1RGBSrgb,

    /**
     * [S3TC](https://en.wikipedia.org/wiki/S3_Texture_Compression) BC1
     * compressed RGBA, normalized unsigned byte (DXT1).
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAS3tcDxt1,
     * @ref GL::TextureFormat::CompressedRGBAS3tcDxt1 /
     * @def_vk_keyword{FORMAT_BC1_RGBA_UNORM_BLOCK,Format}.
     */
    Bc1RGBAUnorm,

    /**
     * [S3TC](https://en.wikipedia.org/wiki/S3_Texture_Compression) BC1
     * compressed sRGB + linear alpha, normalized unsigned byte (DXT1).
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGBAlphaS3tcDxt1,
     * @ref GL::TextureFormat::CompressedSRGBAlphaS3tcDxt1 /
     * @def_vk_keyword{FORMAT_BC1_RGBA_SRGB_BLOCK,Format}.
     */
    Bc1RGBASrgb,

    /**
     * [S3TC](https://en.wikipedia.org/wiki/S3_Texture_Compression) BC2
     * compressed RGBA, normalized unsigned byte (DXT3).
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAS3tcDxt3,
     * @ref GL::TextureFormat::CompressedRGBAS3tcDxt3 /
     * @def_vk_keyword{FORMAT_BC2_UNORM_BLOCK,Format}.
     */
    Bc2RGBAUnorm,

    /**
     * [S3TC](https://en.wikipedia.org/wiki/S3_Texture_Compression) BC2
     * compressed sRGB + linear alpha, normalized unsigned byte (DXT3).
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGBAlphaS3tcDxt3,
     * @ref GL::TextureFormat::CompressedSRGBAlphaS3tcDxt3 /
     * @def_vk_keyword{FORMAT_BC2_SRGB_BLOCK,Format}.
     */
    Bc2RGBASrgb,

    /**
     * [S3TC](https://en.wikipedia.org/wiki/S3_Texture_Compression) BC3
     * compressed RGBA, normalized unsigned byte (DXT5).
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAS3tcDxt5,
     * @ref GL::TextureFormat::CompressedRGBAS3tcDxt5 /
     * @def_vk_keyword{FORMAT_BC3_UNORM_BLOCK,Format}.
     */
    Bc3RGBAUnorm,

    /**
     * [S3TC](https://en.wikipedia.org/wiki/S3_Texture_Compression) BC3
     * compressed sRGB + linear alpha, normalized unsigned byte (DXT5).
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGBAlphaS3tcDxt5,
     * @ref GL::TextureFormat::CompressedSRGBAlphaS3tcDxt5 /
     * @def_vk_keyword{FORMAT_BC3_SRGB_BLOCK,Format}.
     */
    Bc3RGBASrgb,

    /**
     * [3Dc+](https://en.wikipedia.org/wiki/3Dc#3Dc+) BC4 compressed red
     * component, unsigned normalized. Also known as RGTC1 or LATC1.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RedRgtc1 /
     * @ref GL::TextureFormat::CompressedRedRgtc1 /
     * @def_vk_keyword{FORMAT_BC4_UNORM_BLOCK,Format}.
     */
    Bc4RUnorm,

    /**
     * [3Dc+](https://en.wikipedia.org/wiki/3Dc#3Dc+) BC4 compressed red
     * component, signed normalized. Also known as RGTC1 or LATC1.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SignedRedRgtc1 /
     * @ref GL::TextureFormat::CompressedSignedRedRgtc1 /
     * @def_vk_keyword{FORMAT_BC4_SNORM_BLOCK,Format}.
     */
    Bc4RSnorm,

    /**
     * [3Dc](https://en.wikipedia.org/wiki/3Dc) BC5 compressed red and green
     * component, unsigned normalized. Also known as RGTC2 or LATC2.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGRgtc2 /
     * @ref GL::TextureFormat::CompressedRGRgtc2 /
     * @def_vk_keyword{FORMAT_BC5_UNORM_BLOCK,Format}.
     */
    Bc5RGUnorm,

    /**
     * [3Dc](https://en.wikipedia.org/wiki/3Dc) BC5 compressed red and green
     * component, signed normalized. Also known as RGTC2 or LATC2.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SignedRGRgtc2 /
     * @ref GL::TextureFormat::CompressedSignedRGRgtc2 /
     * @def_vk_keyword{FORMAT_BC5_SNORM_BLOCK,Format}.
     */
    Bc5RGSnorm,

    /**
     * [BC6H](https://docs.microsoft.com/en-us/windows/win32/direct3d11/bc6h-format)
     * compressed RGB, unsigned float. Also known as BPTC.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBBptcUnsignedFloat /
     * @ref GL::TextureFormat::CompressedRGBBptcUnsignedFloat /
     * @def_vk_keyword{FORMAT_BC6H_UFLOAT_BLOCK,Format}.
     */
    Bc6hRGBUfloat,

    /**
     * [BC6H](https://docs.microsoft.com/en-us/windows/win32/direct3d11/bc6h-format)
     * compressed RGB, signed float. Also known as BPTC.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBBptcSignedFloat /
     * @ref GL::TextureFormat::CompressedRGBBptcSignedFloat /
     * @def_vk_keyword{FORMAT_BC6H_SFLOAT_BLOCK,Format}.
     */
    Bc6hRGBSfloat,

    /**
     * [BC7](https://docs.microsoft.com/en-us/windows/win32/direct3d11/bc7-format),
     * compressed RGBA, unsigned normalized. Also known as BPTC.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBABptcUnorm /
     * @ref GL::TextureFormat::CompressedRGBABptcUnorm /
     * @def_vk_keyword{FORMAT_BC7_UNORM_BLOCK,Format}.
     */
    Bc7RGBAUnorm,

    /**
     * [BC7](https://docs.microsoft.com/en-us/windows/win32/direct3d11/bc7-format),
     * compressed sRGB + linear alpha, unsigned normalized. Also known as BPTC.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGBAlphaBptcUnorm /
     * @ref GL::TextureFormat::CompressedSRGBAlphaBptcUnorm /
     * @def_vk_keyword{FORMAT_BC7_SRGB_BLOCK,Format}.
     */
    Bc7RGBASrgb,

    /**
     * [EAC](https://en.wikipedia.org/wiki/Ericsson_Texture_Compression#ETC2_and_EAC)
     * compressed red component, normalized unsigned 11-bit.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::R11Eac,
     * @ref GL::TextureFormat::CompressedR11Eac /
     * @def_vk_keyword{FORMAT_EAC_R11_UNORM_BLOCK,Format}.
     */
    EacR11Unorm,

    /**
     * [EAC](https://en.wikipedia.org/wiki/Ericsson_Texture_Compression#ETC2_and_EAC)
     * compressed red component, normalized signed 11-bit.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SignedR11Eac,
     * @ref GL::TextureFormat::CompressedSignedR11Eac /
     * @def_vk_keyword{FORMAT_EAC_R11_SNORM_BLOCK,Format}.
     */
    EacR11Snorm,

    /**
     * [EAC](https://en.wikipedia.org/wiki/Ericsson_Texture_Compression#ETC2_and_EAC)
     * compressed red and green component, normalized unsigned 11-bit.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RG11Eac,
     * @ref GL::TextureFormat::CompressedRG11Eac /
     * @def_vk_keyword{FORMAT_EAC_R11G11_UNORM_BLOCK,Format}.
     */
    EacRG11Unorm,

    /**
     * [EAC](https://en.wikipedia.org/wiki/Ericsson_Texture_Compression#ETC2_and_EAC)
     * compressed red and green component, normalized signed 11-bit.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SignedRG11Eac,
     * @ref GL::TextureFormat::CompressedSignedRG11Eac /
     * @def_vk_keyword{FORMAT_EAC_R11G11_SNORM_BLOCK,Format}.
     */
    EacRG11Snorm,

    /**
     * [ETC2](https://en.wikipedia.org/wiki/Ericsson_Texture_Compression#ETC2_and_EAC)
     * compressed RGB, normalized unsigned byte.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGB8Etc2,
     * @ref GL::TextureFormat::CompressedRGB8Etc2 /
     * @def_vk_keyword{FORMAT_ETC2_R8G8B8_UNORM_BLOCK,Format}.
     */
    Etc2RGB8Unorm,

    /**
     * [ETC2](https://en.wikipedia.org/wiki/Ericsson_Texture_Compression#ETC2_and_EAC)
     * compressed sRGB, normalized unsigned byte.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Etc2,
     * @ref GL::TextureFormat::CompressedSRGB8Etc2 /
     * @def_vk_keyword{FORMAT_ETC2_R8G8B8_SRGB_BLOCK,Format}.
     */
    Etc2RGB8Srgb,

    /**
     * [ETC2](https://en.wikipedia.org/wiki/Ericsson_Texture_Compression#ETC2_and_EAC)
     * compressed RGB, normalized unsigned byte + a single-bit alpha.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGB8PunchthroughAlpha1Etc2,
     * @ref GL::TextureFormat::CompressedRGB8PunchthroughAlpha1Etc2 /
     * @def_vk_keyword{FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK,Format}.
     */
    Etc2RGB8A1Unorm,

    /**
     * [ETC2](https://en.wikipedia.org/wiki/Ericsson_Texture_Compression#ETC2_and_EAC)
     * compressed sRGB, normalized unsigned byte + a single-bit alpha.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8PunchthroughAlpha1Etc2,
     * @ref GL::TextureFormat::CompressedSRGB8PunchthroughAlpha1Etc2 /
     * @def_vk_keyword{FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK,Format}.
     */
    Etc2RGB8A1Srgb,

    /**
     * [ETC2](https://en.wikipedia.org/wiki/Ericsson_Texture_Compression#ETC2_and_EAC)
     * compressed RGBA, normalized unsigned byte (EAC).
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBA8Etc2Eac,
     * @ref GL::TextureFormat::CompressedRGBA8Etc2Eac /
     * @def_vk_keyword{FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK,Format}.
     */
    Etc2RGBA8Unorm,

    /**
     * [ETC2](https://en.wikipedia.org/wiki/Ericsson_Texture_Compression#ETC2_and_EAC)
     * compressed sRGB + linear alpha, normalized unsigned byte (EAC).
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Etc2Eac,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Etc2Eac /
     * @def_vk_keyword{FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK,Format}.
     */
    Etc2RGBA8Srgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 4x4 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc4x4,
     * @ref GL::TextureFormat::CompressedRGBAAstc4x4 /
     * @def_vk_keyword{FORMAT_ASTC_4x4_UNORM_BLOCK,Format}.
     */
    Astc4x4RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 4x4
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc4x4,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc4x4 /
     * @def_vk_keyword{FORMAT_ASTC_4x4_SRGB_BLOCK,Format}.
     */
    Astc4x4RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 5x4 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc5x4,
     * @ref GL::TextureFormat::CompressedRGBAAstc5x4 /
     * @def_vk_keyword{FORMAT_ASTC_5x4_UNORM_BLOCK,Format}.
     */
    Astc5x4RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 5x4
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc5x4,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc5x4 /
     * @def_vk_keyword{FORMAT_ASTC_5x4_SRGB_BLOCK,Format}.
     */
    Astc5x4RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 5x5 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc5x5,
     * @ref GL::TextureFormat::CompressedRGBAAstc5x5 /
     * @def_vk_keyword{FORMAT_ASTC_5x5_UNORM_BLOCK,Format}.
     */
    Astc5x5RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 5x5
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc5x5,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc5x5 /
     * @def_vk_keyword{FORMAT_ASTC_5x5_SRGB_BLOCK,Format}.
     */
    Astc5x5RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 6x5 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc6x5,
     * @ref GL::TextureFormat::CompressedRGBAAstc6x5 /
     * @def_vk_keyword{FORMAT_ASTC_6x5_UNORM_BLOCK,Format}.
     */
    Astc6x5RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 6x5
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc6x5,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc6x5 /
     * @def_vk_keyword{FORMAT_ASTC_6x5_SRGB_BLOCK,Format}.
     */
    Astc6x5RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 6x6 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc6x6,
     * @ref GL::TextureFormat::CompressedRGBAAstc6x6 /
     * @def_vk_keyword{FORMAT_ASTC_6x6_UNORM_BLOCK,Format}.
     */
    Astc6x6RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 6x6
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc6x6,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc6x6 /
     * @def_vk_keyword{FORMAT_ASTC_6x6_SRGB_BLOCK,Format}.
     */
    Astc6x6RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 8x5 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc8x5,
     * @ref GL::TextureFormat::CompressedRGBAAstc8x5 /
     * @def_vk_keyword{FORMAT_ASTC_8x5_UNORM_BLOCK,Format}.
     */
    Astc8x5RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 8x5
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc8x5,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc8x5 /
     * @def_vk_keyword{FORMAT_ASTC_8x5_SRGB_BLOCK,Format}.
     */
    Astc8x5RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 8x6 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc8x6,
     * @ref GL::TextureFormat::CompressedRGBAAstc8x6 /
     * @def_vk_keyword{FORMAT_ASTC_8x6_UNORM_BLOCK,Format}.
     */
    Astc8x6RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 8x6
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc8x6,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc8x6 /
     * @def_vk_keyword{FORMAT_ASTC_8x6_SRGB_BLOCK,Format}.
     */
    Astc8x6RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 8x8 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc8x8,
     * @ref GL::TextureFormat::CompressedRGBAAstc8x8 /
     * @def_vk_keyword{FORMAT_ASTC_8x8_UNORM_BLOCK,Format}.
     */
    Astc8x8RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 8x8
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc8x8,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc8x8 /
     * @def_vk_keyword{FORMAT_ASTC_8x8_SRGB_BLOCK,Format}.
     */
    Astc8x8RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 10x5 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc10x5,
     * @ref GL::TextureFormat::CompressedRGBAAstc10x5 /
     * @def_vk_keyword{FORMAT_ASTC_10x5_UNORM_BLOCK,Format}.
     */
    Astc10x5RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 10x5
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc10x5,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc10x5 /
     * @def_vk_keyword{FORMAT_ASTC_10x5_SRGB_BLOCK,Format}.
     */
    Astc10x5RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 10x6 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc10x6,
     * @ref GL::TextureFormat::CompressedRGBAAstc10x6 /
     * @def_vk_keyword{FORMAT_ASTC_10x6_UNORM_BLOCK,Format}.
     */
    Astc10x6RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 10x6
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc10x6,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc10x6 /
     * @def_vk_keyword{FORMAT_ASTC_10x6_SRGB_BLOCK,Format}.
     */
    Astc10x6RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 10x8 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc10x8,
     * @ref GL::TextureFormat::CompressedRGBAAstc10x8 /
     * @def_vk_keyword{FORMAT_ASTC_10x8_UNORM_BLOCK,Format}.
     */
    Astc10x8RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 10x8
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc10x8,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc10x8 /
     * @def_vk_keyword{FORMAT_ASTC_10x8_SRGB_BLOCK,Format}.
     */
    Astc10x8RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 10x10 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc10x10,
     * @ref GL::TextureFormat::CompressedRGBAAstc10x10 /
     * @def_vk_keyword{FORMAT_ASTC_10x10_UNORM_BLOCK,Format}.
     */
    Astc10x10RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 10x10
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc10x10,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc10x10 /
     * @def_vk_keyword{FORMAT_ASTC_10x10_SRGB_BLOCK,Format}.
     */
    Astc10x10RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 12x10 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc12x10,
     * @ref GL::TextureFormat::CompressedRGBAAstc12x10 /
     * @def_vk_keyword{FORMAT_ASTC_12x10_UNORM_BLOCK,Format}.
     */
    Astc12x10RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 12x10
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc12x10,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc12x10 /
     * @def_vk_keyword{FORMAT_ASTC_12x10_SRGB_BLOCK,Format}.
     */
    Astc12x10RGBASrgb,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed RGBA, normalized unsigned byte with 12x12 blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAAstc12x12,
     * @ref GL::TextureFormat::CompressedRGBAAstc12x12 /
     * @def_vk_keyword{FORMAT_ASTC_12x12_UNORM_BLOCK,Format}.
     */
    Astc12x12RGBAUnorm,

    /**
     * [ASTC](https://en.wikipedia.org/wiki/Adaptive_Scalable_Texture_Compression)
     * compressed sRGB + linear alpha, normalized unsigned byte with 12x12
     * blocks.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGB8Alpha8Astc12x12,
     * @ref GL::TextureFormat::CompressedSRGB8Alpha8Astc12x12 /
     * @def_vk_keyword{FORMAT_ASTC_12x12_SRGB_BLOCK,Format}.
     */
    Astc12x12RGBASrgb,

    /* See https://github.com/KhronosGroup/Vulkan-Docs/issues/512#issuecomment-307768667
       for Vulkan mapping. Ugh. */

    /**
     * [PVRTC](https://en.wikipedia.org/wiki/PVRTC) compressed RGB, normalized
     * unsigned byte with 2 bits per pixel.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBPvrtc2bppV1,
     * @ref GL::TextureFormat::CompressedRGBPvrtc2bppV1 /
     * @def_vk_keyword{FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG,Format}.
     */
    PvrtcRGB2bppUnorm,

    /**
     * [PVRTC](https://en.wikipedia.org/wiki/PVRTC) compressed sRGB, normalized
     * unsigned byte with 2 bits per pixel.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGBPvrtc2bppV1,
     * @ref GL::TextureFormat::CompressedSRGBPvrtc2bppV1 /
     * @def_vk_keyword{FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG,Format}.
     */
    PvrtcRGB2bppSrgb,

    /**
     * [PVRTC](https://en.wikipedia.org/wiki/PVRTC) compressed RGBA, normalized
     * unsigned byte with 2 bits per pixel.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAPvrtc2bppV1,
     * @ref GL::TextureFormat::CompressedRGBAPvrtc2bppV1 /
     * @def_vk_keyword{FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG,Format}.
     */
    PvrtcRGBA2bppUnorm,

    /**
     * [PVRTC](https://en.wikipedia.org/wiki/PVRTC) compressed sRGB + linear
     * alpha, normalized unsigned byte with 2 bits per pixel.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGBAlphaPvrtc2bppV1,
     * @ref GL::TextureFormat::CompressedSRGBAlphaPvrtc2bppV1 /
     * @def_vk_keyword{FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG,Format}.
     */
    PvrtcRGBA2bppSrgb,

    /**
     * [PVRTC](https://en.wikipedia.org/wiki/PVRTC) compressed RGB, normalized
     * unsigned byte with 4 bits per pixel.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBPvrtc4bppV1,
     * @ref GL::TextureFormat::CompressedRGBPvrtc4bppV1 /
     * @def_vk_keyword{FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG,Format}.
     */
    PvrtcRGB4bppUnorm,

    /**
     * [PVRTC](https://en.wikipedia.org/wiki/PVRTC) compressed sRGB, normalized
     * unsigned byte with 4 bits per pixel.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGBPvrtc4bppV1,
     * @ref GL::TextureFormat::CompressedSRGBPvrtc4bppV1 /
     * @def_vk_keyword{FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG,Format}.
     */
    PvrtcRGB4bppSrgb,

    /**
     * [PVRTC](https://en.wikipedia.org/wiki/PVRTC) compressed RGBA, normalized
     * unsigned byte with 4 bits per pixel.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::RGBAPvrtc4bppV1,
     * @ref GL::TextureFormat::CompressedRGBAPvrtc4bppV1 /
     * @def_vk_keyword{FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG,Format}.
     */
    PvrtcRGBA4bppUnorm,

    /**
     * [PVRTC](https://en.wikipedia.org/wiki/PVRTC) compressed sRGB + linear
     * alpha, normalized unsigned byte with 4 bits per pixel.
     *
     * Corresponds to @ref GL::CompressedPixelFormat::SRGBAlphaPvrtc4bppV1,
     * @ref GL::TextureFormat::CompressedSRGBAlphaPvrtc4bppV1 /
     * @def_vk_keyword{FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG,Format}.
     */
    PvrtcRGBA4bppSrgb

    /* PVRTC2 variants not listed as PVRTC is mainly on Apple hardware but
       Metal doesn't support it and it doesn't have a WebGL equiv either. */
};

/** @debugoperatorenum{CompressedPixelFormat} */
MAGNUM_EXPORT Debug& operator<<(Debug& debug, CompressedPixelFormat value);

/**
@brief Whether a @ref CompressedPixelFormat value wraps an implementation-specific identifier

Returns @cpp true @ce if value of @p format has its highest bit set, @cpp false @ce
otherwise. Use @ref compressedPixelFormatWrap() and @ref compressedPixelFormatUnwrap()
to wrap/unwrap an implementation-specific indentifier to/from @ref CompressedPixelFormat.
@see @ref isPixelFormatImplementationSpecific()
*/
constexpr bool isCompressedPixelFormatImplementationSpecific(CompressedPixelFormat format) {
    return UnsignedInt(format) & (1u << 31);
}

/**
@brief Wrap an implementation-specific pixel format identifier in a @ref CompressedPixelFormat

Sets the highest bit on @p format to mark it as implementation-specific.
Expects that @p format fits into the remaining bits. Use @ref compressedPixelFormatUnwrap()
for the inverse operation.
@see @ref isCompressedPixelFormatImplementationSpecific(), @ref pixelFormatWrap()
*/
template<class T> constexpr CompressedPixelFormat compressedPixelFormatWrap(T implementationSpecific) {
    static_assert(sizeof(T) <= 4,
        "format types larger than 32bits are not supported");
    return CORRADE_CONSTEXPR_ASSERT(!(UnsignedInt(implementationSpecific) & (1u << 31)),
        "compressedPixelFormatWrap(): implementation-specific value already wrapped or too large"),
        CompressedPixelFormat((1u << 31)|UnsignedInt(implementationSpecific));
}

/**
@brief Unwrap an implementation-specific pixel format identifier from a @ref CompressedPixelFormat

Unsets the highest bit from @p format to extract the implementation-specific
value. Expects that @p format has it set. Use @ref compressedPixelFormatWrap() for the
inverse operation.
@see @ref isCompressedPixelFormatImplementationSpecific(), @ref pixelFormatUnwrap()
*/
template<class T = UnsignedInt> constexpr T compressedPixelFormatUnwrap(CompressedPixelFormat format) {
    return CORRADE_CONSTEXPR_ASSERT(UnsignedInt(format) & (1u << 31),
        "compressedPixelFormatUnwrap(): format doesn't contain a wrapped implementation-specific value"),
        T(UnsignedInt(format) & ~(1u << 31));
}

}

#endif
