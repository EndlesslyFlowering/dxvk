#include "dxgi_format.h"

#include <array>

namespace dxvk {
  
  const std::array<DXGI_VK_FORMAT_MAPPING, 133> g_dxgiFormats = {{
    // DXGI_FORMAT_UNKNOWN
    { },
    // DXGI_FORMAT_R32G32B32A32_TYPELESS
    { VK_FORMAT_R32G32B32A32_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32B32A32_UINT },
    // DXGI_FORMAT_R32G32B32A32_FLOAT
    { VK_FORMAT_R32G32B32A32_SFLOAT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32B32A32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32B32A32_UINT
    { VK_FORMAT_R32G32B32A32_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32B32A32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32B32A32_SINT
    { VK_FORMAT_R32G32B32A32_SINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32B32A32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32B32_TYPELESS
    { VK_FORMAT_R32G32B32_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32B32_UINT },
    // DXGI_FORMAT_R32G32B32_FLOAT
    { VK_FORMAT_R32G32B32_SFLOAT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32B32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32B32_UINT
    { VK_FORMAT_R32G32B32_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32B32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32B32_SINT
    { VK_FORMAT_R32G32B32_SINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32B32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16B16A16_TYPELESS
    { VK_FORMAT_R16G16B16A16_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16B16A16_UINT },
    // DXGI_FORMAT_R16G16B16A16_FLOAT
    { VK_FORMAT_R16G16B16A16_SFLOAT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16B16A16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16B16A16_UNORM
    { VK_FORMAT_R16G16B16A16_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16B16A16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16B16A16_UINT
    { VK_FORMAT_R16G16B16A16_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16B16A16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16B16A16_SNORM
    { VK_FORMAT_R16G16B16A16_SNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16B16A16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16B16A16_SINT
    { VK_FORMAT_R16G16B16A16_SINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16B16A16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32_TYPELESS
    { VK_FORMAT_R32G32_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32_UINT },
    // DXGI_FORMAT_R32G32_FLOAT
    { VK_FORMAT_R32G32_SFLOAT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32_UINT
    { VK_FORMAT_R32G32_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32_SINT
    { VK_FORMAT_R32G32_SINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32G32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G8X24_TYPELESS
    { VK_FORMAT_UNDEFINED,
      VK_FORMAT_D32_SFLOAT_S8_UINT,
      VK_FORMAT_UNDEFINED },
    // DXGI_FORMAT_D32_FLOAT_S8X24_UINT
    { VK_FORMAT_UNDEFINED,
      VK_FORMAT_D32_SFLOAT_S8_UINT,
      VK_FORMAT_UNDEFINED,
      0, VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT },
    // DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS
    { VK_FORMAT_UNDEFINED,
      VK_FORMAT_D32_SFLOAT_S8_UINT,
      VK_FORMAT_UNDEFINED,
      0, VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_X32_TYPELESS_G8X24_UINT
    { VK_FORMAT_UNDEFINED,
      VK_FORMAT_D32_SFLOAT_S8_UINT,
      VK_FORMAT_UNDEFINED,
      0, VK_IMAGE_ASPECT_STENCIL_BIT },
    // DXGI_FORMAT_R10G10B10A2_TYPELESS
    { VK_FORMAT_A2B10G10R10_UNORM_PACK32,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_A2B10G10R10_UINT_PACK32 },
    // DXGI_FORMAT_R10G10B10A2_UNORM
    { VK_FORMAT_A2B10G10R10_UNORM_PACK32,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_A2B10G10R10_UINT_PACK32,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R10G10B10A2_UINT
    { VK_FORMAT_A2B10G10R10_UINT_PACK32,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_A2B10G10R10_UINT_PACK32,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R11G11B10_FLOAT
    { VK_FORMAT_B10G11R11_UFLOAT_PACK32,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8B8A8_TYPELESS
    { VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8B8A8_UINT },
    // DXGI_FORMAT_R8G8B8A8_UNORM
    { VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8B8A8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8B8A8_UNORM_SRGB
    { VK_FORMAT_R8G8B8A8_SRGB,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8B8A8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8B8A8_UINT
    { VK_FORMAT_R8G8B8A8_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8B8A8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8B8A8_SNORM
    { VK_FORMAT_R8G8B8A8_SNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8B8A8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8B8A8_SINT
    { VK_FORMAT_R8G8B8A8_SINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8B8A8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16_TYPELESS
    { VK_FORMAT_R16G16_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16_UINT },
    // DXGI_FORMAT_R16G16_FLOAT
    { VK_FORMAT_R16G16_SFLOAT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16_UNORM
    { VK_FORMAT_R16G16_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16_UINT
    { VK_FORMAT_R16G16_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16_SNORM
    { VK_FORMAT_R16G16_SNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16_SINT
    { VK_FORMAT_R16G16_SINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16G16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32_TYPELESS
    { VK_FORMAT_R32_UINT,
      VK_FORMAT_D32_SFLOAT,
      VK_FORMAT_R32_UINT },
    // DXGI_FORMAT_D32_FLOAT
    { VK_FORMAT_UNDEFINED,
      VK_FORMAT_D32_SFLOAT,
      VK_FORMAT_UNDEFINED,
      0, VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_R32_FLOAT
    { VK_FORMAT_R32_SFLOAT,
      VK_FORMAT_D32_SFLOAT,
      VK_FORMAT_R32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT,
      VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_R32_UINT
    { VK_FORMAT_R32_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32_SINT
    { VK_FORMAT_R32_SINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R32_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R24G8_TYPELESS
    { VK_FORMAT_UNDEFINED,
      VK_FORMAT_D24_UNORM_S8_UINT,
      VK_FORMAT_UNDEFINED },
    // DXGI_FORMAT_D24_UNORM_S8_UINT
    { VK_FORMAT_UNDEFINED,
      VK_FORMAT_D24_UNORM_S8_UINT,
      VK_FORMAT_UNDEFINED,
      0, VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT },
    // DXGI_FORMAT_R24_UNORM_X8_TYPELESS
    { VK_FORMAT_UNDEFINED,
      VK_FORMAT_D24_UNORM_S8_UINT,
      VK_FORMAT_UNDEFINED,
      0, VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_X24_TYPELESS_G8_UINT
    { VK_FORMAT_UNDEFINED,
      VK_FORMAT_D24_UNORM_S8_UINT,
      VK_FORMAT_UNDEFINED,
      0, VK_IMAGE_ASPECT_STENCIL_BIT },
    // DXGI_FORMAT_R8G8_TYPELESS
    { VK_FORMAT_R8G8_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8_UINT },
    // DXGI_FORMAT_R8G8_UNORM
    { VK_FORMAT_R8G8_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8_UINT
    { VK_FORMAT_R8G8_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8_SNORM
    { VK_FORMAT_R8G8_SNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8_SINT
    { VK_FORMAT_R8G8_SINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16_TYPELESS
    { VK_FORMAT_R16_UNORM,
      VK_FORMAT_D16_UNORM,
      VK_FORMAT_R16_UINT },
    // DXGI_FORMAT_R16_FLOAT
    { VK_FORMAT_R16_SFLOAT,
      VK_FORMAT_D16_UNORM,
      VK_FORMAT_R16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT,
      VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_D16_UNORM
    { VK_FORMAT_UNDEFINED,
      VK_FORMAT_D16_UNORM,
      VK_FORMAT_UNDEFINED,
      0, VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_R16_UNORM
    { VK_FORMAT_R16_UNORM,
      VK_FORMAT_D16_UNORM,
      VK_FORMAT_R16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT,
      VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_R16_UINT
    { VK_FORMAT_R16_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16_SNORM
    { VK_FORMAT_R16_SNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16_SINT
    { VK_FORMAT_R16_SINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R16_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8_TYPELESS
    { VK_FORMAT_R8_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8_UINT },
    // DXGI_FORMAT_R8_UNORM
    { VK_FORMAT_R8_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8_UINT
    { VK_FORMAT_R8_UINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8_SNORM
    { VK_FORMAT_R8_SNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8_SINT
    { VK_FORMAT_R8_SINT,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_A8_UNORM
    { VK_FORMAT_A8_UNORM_KHR,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R1_UNORM
    { }, // Unsupported
    // DXGI_FORMAT_R9G9B9E5_SHAREDEXP
    { VK_FORMAT_E5B9G9R9_UFLOAT_PACK32,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8_B8G8_UNORM
    { VK_FORMAT_B8G8R8G8_422_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_G8R8_G8B8_UNORM
    { VK_FORMAT_G8B8G8R8_422_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC1_TYPELESS
    { VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED },
    // DXGI_FORMAT_BC1_UNORM
    { VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC1_UNORM_SRGB
    { VK_FORMAT_BC1_RGBA_SRGB_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC2_TYPELESS
    { VK_FORMAT_BC2_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED },
    // DXGI_FORMAT_BC2_UNORM
    { VK_FORMAT_BC2_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC2_UNORM_SRGB
    { VK_FORMAT_BC2_SRGB_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC3_TYPELESS
    { VK_FORMAT_BC3_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED },
    // DXGI_FORMAT_BC3_UNORM
    { VK_FORMAT_BC3_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC3_UNORM_SRGB
    { VK_FORMAT_BC3_SRGB_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC4_TYPELESS
    { VK_FORMAT_BC4_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED },
    // DXGI_FORMAT_BC4_UNORM
    { VK_FORMAT_BC4_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC4_SNORM
    { VK_FORMAT_BC4_SNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC5_TYPELESS
    { VK_FORMAT_BC5_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED },
    // DXGI_FORMAT_BC5_UNORM
    { VK_FORMAT_BC5_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC5_SNORM
    { VK_FORMAT_BC5_SNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B5G6R5_UNORM
    { VK_FORMAT_R5G6B5_UNORM_PACK16,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B5G5R5A1_UNORM
    { VK_FORMAT_A1R5G5B5_UNORM_PACK16,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B8G8R8A8_UNORM
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B8G8R8X8_UNORM
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT, 0,
      { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G,
        VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_ONE }},
    // DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM
    { }, // Unsupported
    // DXGI_FORMAT_B8G8R8A8_TYPELESS
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED },
    // DXGI_FORMAT_B8G8R8A8_UNORM_SRGB
    { VK_FORMAT_B8G8R8A8_SRGB,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B8G8R8X8_TYPELESS
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B8G8R8X8_UNORM_SRGB
    { VK_FORMAT_B8G8R8A8_SRGB,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT, 0,
      { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G,
        VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_ONE }},
    // DXGI_FORMAT_BC6H_TYPELESS
    { VK_FORMAT_BC6H_UFLOAT_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED },
    // DXGI_FORMAT_BC6H_UF16
    { VK_FORMAT_BC6H_UFLOAT_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC6H_SF16
    { VK_FORMAT_BC6H_SFLOAT_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC7_TYPELESS
    { VK_FORMAT_BC7_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED },
    // DXGI_FORMAT_BC7_UNORM
    { VK_FORMAT_BC7_UNORM_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC7_UNORM_SRGB
    { VK_FORMAT_BC7_SRGB_BLOCK,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_AYUV
    { VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_R8G8B8A8_UINT,
      VK_IMAGE_ASPECT_COLOR_BIT, 0,
      { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_B,
        VK_COMPONENT_SWIZZLE_G, VK_COMPONENT_SWIZZLE_A } },
    // DXGI_FORMAT_Y410
    { }, // Unsupported
    // DXGI_FORMAT_Y416
    { }, // Unsupported
    // DXGI_FORMAT_NV12
    { VK_FORMAT_G8_B8R8_2PLANE_420_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT },
    // DXGI_FORMAT_P010
    { }, // Unsupported
    // DXGI_FORMAT_P016
    { }, // Unsupported
    // DXGI_FORMAT_420_OPAQUE
    { VK_FORMAT_G8_B8R8_2PLANE_420_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT },
    // DXGI_FORMAT_YUY2
    { VK_FORMAT_G8B8G8R8_422_UNORM,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_Y210
    { }, // Unsupported
    // DXGI_FORMAT_Y216
    { }, // Unsupported
    // DXGI_FORMAT_NV11
    { }, // Unsupported
    // DXGI_FORMAT_AI44
    { }, // Unsupported
    // DXGI_FORMAT_IA44
    { }, // Unsupported
    // DXGI_FORMAT_P8
    { }, // Unsupported
    // DXGI_FORMAT_A8P8
    { }, // Unsupported
    // DXGI_FORMAT_B4G4R4A4_UNORM
    { VK_FORMAT_A4R4G4B4_UNORM_PACK16,
      VK_FORMAT_UNDEFINED,
      VK_FORMAT_UNDEFINED,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_P208
    { }, // Unsupported
    // DXGI_FORMAT_V208
    { }, // Unsupported
    // DXGI_FORMAT_V408
    { }, // Unsupported
  }};


  const std::array<DXGI_VK_FORMAT_FAMILY, 133> g_dxgiFamilies = {{
    // DXGI_FORMAT_UNKNOWN
    { },
    // DXGI_FORMAT_R32G32B32A32_TYPELESS
    { VK_FORMAT_R32G32B32A32_UINT,
      VK_FORMAT_R32G32B32A32_SINT,
      VK_FORMAT_R32G32B32A32_SFLOAT },
    // DXGI_FORMAT_R32G32B32A32_FLOAT
    { },
    // DXGI_FORMAT_R32G32B32A32_UINT
    { },
    // DXGI_FORMAT_R32G32B32A32_SINT
    { },
    // DXGI_FORMAT_R32G32B32_TYPELESS
    { VK_FORMAT_R32G32B32_UINT,
      VK_FORMAT_R32G32B32_SINT,
      VK_FORMAT_R32G32B32_SFLOAT },
    // DXGI_FORMAT_R32G32B32_FLOAT
    { },
    // DXGI_FORMAT_R32G32B32_UINT
    { },
    // DXGI_FORMAT_R32G32B32_SINT
    { },
    // DXGI_FORMAT_R16G16B16A16_TYPELESS
    { VK_FORMAT_R16G16B16A16_UNORM,
      VK_FORMAT_R16G16B16A16_SNORM,
      VK_FORMAT_R16G16B16A16_UINT,
      VK_FORMAT_R16G16B16A16_SINT,
      VK_FORMAT_R16G16B16A16_SFLOAT },
    // DXGI_FORMAT_R16G16B16A16_FLOAT
    { },
    // DXGI_FORMAT_R16G16B16A16_UNORM
    { },
    // DXGI_FORMAT_R16G16B16A16_UINT
    { },
    // DXGI_FORMAT_R16G16B16A16_SNORM
    { },
    // DXGI_FORMAT_R16G16B16A16_SINT
    { },
    // DXGI_FORMAT_R32G32_TYPELESS
    { VK_FORMAT_R32G32_UINT,
      VK_FORMAT_R32G32_SINT,
      VK_FORMAT_R32G32_SFLOAT },
    // DXGI_FORMAT_R32G32_FLOAT
    { },
    // DXGI_FORMAT_R32G32_UINT
    { },
    // DXGI_FORMAT_R32G32_SINT
    { },
    // DXGI_FORMAT_R32G8X24_TYPELESS
    { },
    // DXGI_FORMAT_D32_FLOAT_S8X24_UINT
    { },
    // DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS
    { },
    // DXGI_FORMAT_X32_TYPELESS_G8X24_UINT
    { },
    // DXGI_FORMAT_R10G10B10A2_TYPELESS
    { VK_FORMAT_A2B10G10R10_UNORM_PACK32,
      VK_FORMAT_A2B10G10R10_UINT_PACK32 },
    // DXGI_FORMAT_R10G10B10A2_UNORM
    { },
    // DXGI_FORMAT_R10G10B10A2_UINT
    { },
    // DXGI_FORMAT_R11G11B10_FLOAT
    { },
    // DXGI_FORMAT_R8G8B8A8_TYPELESS
    { VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_R8G8B8A8_SNORM,
      VK_FORMAT_R8G8B8A8_SRGB,
      VK_FORMAT_R8G8B8A8_UINT,
      VK_FORMAT_R8G8B8A8_SINT },
    // DXGI_FORMAT_R8G8B8A8_UNORM
    { VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_R8G8B8A8_SRGB },
    // DXGI_FORMAT_R8G8B8A8_UNORM_SRGB
    { VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_R8G8B8A8_SRGB },
    // DXGI_FORMAT_R8G8B8A8_UINT
    { },
    // DXGI_FORMAT_R8G8B8A8_SNORM
    { },
    // DXGI_FORMAT_R8G8B8A8_SINT
    { },
    // DXGI_FORMAT_R16G16_TYPELESS
    { VK_FORMAT_R16G16_UNORM,
      VK_FORMAT_R16G16_SNORM,
      VK_FORMAT_R16G16_UINT,
      VK_FORMAT_R16G16_SINT,
      VK_FORMAT_R16G16_SFLOAT },
    // DXGI_FORMAT_R16G16_FLOAT
    { },
    // DXGI_FORMAT_R16G16_UNORM
    { },
    // DXGI_FORMAT_R16G16_UINT
    { },
    // DXGI_FORMAT_R16G16_SNORM
    { },
    // DXGI_FORMAT_R16G16_SINT
    { },
    // DXGI_FORMAT_R32_TYPELESS
    { VK_FORMAT_R32_UINT,
      VK_FORMAT_R32_SINT,
      VK_FORMAT_R32_SFLOAT },
    // DXGI_FORMAT_D32_FLOAT
    { },
    // DXGI_FORMAT_R32_FLOAT
    { },
    // DXGI_FORMAT_R32_UINT
    { },
    // DXGI_FORMAT_R32_SINT
    { },
    // DXGI_FORMAT_R24G8_TYPELESS
    { },
    // DXGI_FORMAT_D24_UNORM_S8_UINT
    { },
    // DXGI_FORMAT_R24_UNORM_X8_TYPELESS
    { },
    // DXGI_FORMAT_X24_TYPELESS_G8_UINT
    { },
    // DXGI_FORMAT_R8G8_TYPELESS
    { VK_FORMAT_R8G8_UNORM,
      VK_FORMAT_R8G8_SNORM,
      VK_FORMAT_R8G8_UINT,
      VK_FORMAT_R8G8_SINT },
    // DXGI_FORMAT_R8G8_UNORM
    { },
    // DXGI_FORMAT_R8G8_UINT
    { },
    // DXGI_FORMAT_R8G8_SNORM
    { },
    // DXGI_FORMAT_R8G8_SINT
    { },
    // DXGI_FORMAT_R16_TYPELESS
    { VK_FORMAT_R16_UNORM,
      VK_FORMAT_R16_SNORM,
      VK_FORMAT_R16_UINT,
      VK_FORMAT_R16_SINT,
      VK_FORMAT_R16_SFLOAT },
    // DXGI_FORMAT_R16_FLOAT
    { },
    // DXGI_FORMAT_D16_UNORM
    { },
    // DXGI_FORMAT_R16_UNORM
    { },
    // DXGI_FORMAT_R16_UINT
    { },
    // DXGI_FORMAT_R16_SNORM
    { },
    // DXGI_FORMAT_R16_SINT
    { },
    // DXGI_FORMAT_R8_TYPELESS
    { VK_FORMAT_R8_UNORM,
      VK_FORMAT_R8_SNORM,
      VK_FORMAT_R8_UINT,
      VK_FORMAT_R8_SINT },
    // DXGI_FORMAT_R8_UNORM
    { },
    // DXGI_FORMAT_R8_UINT
    { },
    // DXGI_FORMAT_R8_SNORM
    { },
    // DXGI_FORMAT_R8_SINT
    { },
    // DXGI_FORMAT_A8_UNORM
    { },
    // DXGI_FORMAT_R1_UNORM
    { }, // Unsupported
    // DXGI_FORMAT_R9G9B9E5_SHAREDEXP
    { },
    // DXGI_FORMAT_R8G8_B8G8_UNORM
    { },
    // DXGI_FORMAT_G8R8_G8B8_UNORM
    { },
    // DXGI_FORMAT_BC1_TYPELESS
    { VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
      VK_FORMAT_BC1_RGBA_SRGB_BLOCK },
    // DXGI_FORMAT_BC1_UNORM
    { VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
      VK_FORMAT_BC1_RGBA_SRGB_BLOCK },
    // DXGI_FORMAT_BC1_UNORM_SRGB
    { VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
      VK_FORMAT_BC1_RGBA_SRGB_BLOCK },
    // DXGI_FORMAT_BC2_TYPELESS
    { VK_FORMAT_BC2_UNORM_BLOCK,
      VK_FORMAT_BC2_SRGB_BLOCK },
    // DXGI_FORMAT_BC2_UNORM
    { VK_FORMAT_BC2_UNORM_BLOCK,
      VK_FORMAT_BC2_SRGB_BLOCK },
    // DXGI_FORMAT_BC2_UNORM_SRGB
    { VK_FORMAT_BC2_UNORM_BLOCK,
      VK_FORMAT_BC2_SRGB_BLOCK },
    // DXGI_FORMAT_BC3_TYPELESS
    { VK_FORMAT_BC3_UNORM_BLOCK,
      VK_FORMAT_BC3_SRGB_BLOCK },
    // DXGI_FORMAT_BC3_UNORM
    { VK_FORMAT_BC3_UNORM_BLOCK,
      VK_FORMAT_BC3_SRGB_BLOCK },
    // DXGI_FORMAT_BC3_UNORM_SRGB
    { VK_FORMAT_BC3_UNORM_BLOCK,
      VK_FORMAT_BC3_SRGB_BLOCK },
    // DXGI_FORMAT_BC4_TYPELESS
    { VK_FORMAT_BC4_UNORM_BLOCK,
      VK_FORMAT_BC4_SNORM_BLOCK },
    // DXGI_FORMAT_BC4_UNORM
    { },
    // DXGI_FORMAT_BC4_SNORM
    { },
    // DXGI_FORMAT_BC5_TYPELESS
    { VK_FORMAT_BC5_UNORM_BLOCK,
      VK_FORMAT_BC5_SNORM_BLOCK },
    // DXGI_FORMAT_BC5_UNORM
    { },
    // DXGI_FORMAT_BC5_SNORM
    { },
    // DXGI_FORMAT_B5G6R5_UNORM
    { },
    // DXGI_FORMAT_B5G5R5A1_UNORM
    { },
    // DXGI_FORMAT_B8G8R8A8_UNORM
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_B8G8R8X8_UNORM
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM
    { }, // Unsupported
    // DXGI_FORMAT_B8G8R8A8_TYPELESS
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_B8G8R8A8_UNORM_SRGB
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_B8G8R8X8_TYPELESS
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_B8G8R8X8_UNORM_SRGB
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_BC6H_TYPELESS
    { VK_FORMAT_BC6H_UFLOAT_BLOCK,
      VK_FORMAT_BC6H_SFLOAT_BLOCK },
    // DXGI_FORMAT_BC6H_UF16
    { },
    // DXGI_FORMAT_BC6H_SF16
    { },
    // DXGI_FORMAT_BC7_TYPELESS
    { VK_FORMAT_BC7_UNORM_BLOCK,
      VK_FORMAT_BC7_SRGB_BLOCK },
    // DXGI_FORMAT_BC7_UNORM
    { VK_FORMAT_BC7_UNORM_BLOCK,
      VK_FORMAT_BC7_SRGB_BLOCK },
    // DXGI_FORMAT_BC7_UNORM_SRGB
    { VK_FORMAT_BC7_UNORM_BLOCK,
      VK_FORMAT_BC7_SRGB_BLOCK },
    // DXGI_FORMAT_AYUV
    { VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_R8G8B8A8_UINT },
    // DXGI_FORMAT_Y410
    { }, // Unsupported
    // DXGI_FORMAT_Y416
    { }, // Unsupported
    // DXGI_FORMAT_NV12
    { VK_FORMAT_R8_UNORM,
      VK_FORMAT_R8G8_UNORM,
      VK_FORMAT_R8_UINT,
      VK_FORMAT_R8G8_UINT },
    // DXGI_FORMAT_P010
    { }, // Unsupported
    // DXGI_FORMAT_P016
    { }, // Unsupported
    // DXGI_FORMAT_420_OPAQUE
    { VK_FORMAT_R8_UNORM,
      VK_FORMAT_R8G8_UNORM,
      VK_FORMAT_R8_UINT,
      VK_FORMAT_R8G8_UINT },
    // DXGI_FORMAT_YUY2
    { VK_FORMAT_G8B8G8R8_422_UNORM,
      VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_R8G8B8A8_UINT },
    // DXGI_FORMAT_Y210
    { }, // Unsupported
    // DXGI_FORMAT_Y216
    { }, // Unsupported
    // DXGI_FORMAT_NV11
    { }, // Unsupported
    // DXGI_FORMAT_AI44
    { }, // Unsupported
    // DXGI_FORMAT_IA44
    { }, // Unsupported
    // DXGI_FORMAT_P8
    { }, // Unsupported
    // DXGI_FORMAT_A8P8
    { }, // Unsupported
    // DXGI_FORMAT_B4G4R4A4_UNORM
    { }, // Unsupported
    // DXGI_FORMAT_P208
    { }, // Unsupported
    // DXGI_FORMAT_V208
    { }, // Unsupported
    // DXGI_FORMAT_V408
    { }, // Unsupported
  }};
  
  
  DXGIVkFormatTable::DXGIVkFormatTable(const Rc<DxvkDevice>& device)
  : m_dxgiFormats (g_dxgiFormats), m_dxgiFamilies(g_dxgiFamilies) {
    // AMD do not support 24-bit depth buffers on Vulkan,
    // so we have to fall back to a 32-bit depth format.
    if (!CheckImageFormatSupport(device, VK_FORMAT_D24_UNORM_S8_UINT,
          VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT |
          VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT)) {
      Logger::info("DXGI: VK_FORMAT_D24_UNORM_S8_UINT -> VK_FORMAT_D32_SFLOAT_S8_UINT");
      RemapDepthFormat(DXGI_FORMAT_R24G8_TYPELESS,        VK_FORMAT_D32_SFLOAT_S8_UINT);
      RemapDepthFormat(DXGI_FORMAT_R24_UNORM_X8_TYPELESS, VK_FORMAT_D32_SFLOAT_S8_UINT);
      RemapDepthFormat(DXGI_FORMAT_X24_TYPELESS_G8_UINT,  VK_FORMAT_D32_SFLOAT_S8_UINT);
      RemapDepthFormat(DXGI_FORMAT_D24_UNORM_S8_UINT,     VK_FORMAT_D32_SFLOAT_S8_UINT);
    }

    if (!CheckImageFormatSupport(device, VK_FORMAT_A8_UNORM_KHR,
          VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT |
          VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT |
          VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT)) {
      Logger::info("DXGI: VK_FORMAT_A8_UNORM_KHR -> VK_FORMAT_R8_UNORM");
      RemapColorFormat(DXGI_FORMAT_A8_UNORM, VK_FORMAT_R8_UNORM, {
          VK_COMPONENT_SWIZZLE_ZERO, VK_COMPONENT_SWIZZLE_ZERO,
          VK_COMPONENT_SWIZZLE_ZERO, VK_COMPONENT_SWIZZLE_R });
    }
  }
  
  
  DXGIVkFormatTable::~DXGIVkFormatTable() {
    
  }
  
  
  DXGI_VK_FORMAT_INFO DXGIVkFormatTable::GetFormatInfo(
          DXGI_FORMAT         Format,
          DXGI_VK_FORMAT_MODE Mode) const {
    return GetFormatInfoFromMapping(
      GetFormatMapping(Format), Mode);
  }


  DXGI_VK_FORMAT_INFO DXGIVkFormatTable::GetPackedFormatInfo(
          DXGI_FORMAT         Format,
          DXGI_VK_FORMAT_MODE Mode) const {
    return GetFormatInfoFromMapping(
      GetPackedFormatMapping(Format), Mode);
  }
  
  
  DXGI_VK_FORMAT_FAMILY DXGIVkFormatTable::GetFormatFamily(
          DXGI_FORMAT         Format,
          DXGI_VK_FORMAT_MODE Mode) const {
    if (Mode == DXGI_VK_FORMAT_MODE_DEPTH)
      return DXGI_VK_FORMAT_FAMILY();
    
    const size_t formatId = size_t(Format);

    return formatId < m_dxgiFamilies.size()
      ? m_dxgiFamilies[formatId]
      : m_dxgiFamilies[0];
  }


  DXGI_VK_FORMAT_INFO DXGIVkFormatTable::GetFormatInfoFromMapping(
    const DXGI_VK_FORMAT_MAPPING* pMapping,
          DXGI_VK_FORMAT_MODE   Mode) const {
    switch (Mode) {
      case DXGI_VK_FORMAT_MODE_ANY:
        return pMapping->FormatColor != VK_FORMAT_UNDEFINED
          ? DXGI_VK_FORMAT_INFO { pMapping->FormatColor, pMapping->AspectColor, pMapping->Swizzle }
          : DXGI_VK_FORMAT_INFO { pMapping->FormatDepth, pMapping->AspectDepth };
      
      case DXGI_VK_FORMAT_MODE_COLOR:
        return { pMapping->FormatColor, pMapping->AspectColor, pMapping->Swizzle };
      
      case DXGI_VK_FORMAT_MODE_DEPTH:
        return { pMapping->FormatDepth, pMapping->AspectDepth };
      
      case DXGI_VK_FORMAT_MODE_RAW:
        return { pMapping->FormatRaw, pMapping->AspectColor };
    }
    
    Logger::err("DXGI: GetFormatInfoFromMapping: Internal error");
    return DXGI_VK_FORMAT_INFO();
  }


  const DXGI_VK_FORMAT_MAPPING* DXGIVkFormatTable::GetFormatMapping(
          DXGI_FORMAT         Format) const {
    const size_t formatId = size_t(Format);
    
    return formatId < m_dxgiFormats.size()
      ? &m_dxgiFormats[formatId]
      : &m_dxgiFormats[0];
  }
  

  const DXGI_VK_FORMAT_MAPPING* DXGIVkFormatTable::GetPackedFormatMapping(
          DXGI_FORMAT         Format) const {
    const size_t formatId = size_t(Format);
    
    return formatId < g_dxgiFormats.size()
      ? &g_dxgiFormats[formatId]
      : &g_dxgiFormats[0];
  }
  

  bool DXGIVkFormatTable::CheckImageFormatSupport(
    const Rc<DxvkDevice>&       Device,
          VkFormat              Format,
          VkFormatFeatureFlags2 Features) const {
    DxvkFormatFeatures supported = Device->getFormatFeatures(Format);
    
    return (supported.linear  & Features) == Features
        || (supported.optimal & Features) == Features;
  }
  
  
  void DXGIVkFormatTable::RemapDepthFormat(
          DXGI_FORMAT         Format,
          VkFormat            Target) {
    m_dxgiFormats[uint32_t(Format)].FormatDepth = Target;
  }
  

  void DXGIVkFormatTable::RemapColorFormat(
          DXGI_FORMAT         Format,
          VkFormat            Target,
          VkComponentMapping  Swizzle) {
    m_dxgiFormats[uint32_t(Format)].FormatColor = Target;
    m_dxgiFormats[uint32_t(Format)].Swizzle = Swizzle;
  }

}
