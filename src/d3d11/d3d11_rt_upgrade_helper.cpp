#include "d3d11_rt_upgrade_helper.h"

#include <array>
#include <dxgiformat.h>
#include <stdint.h>

namespace dxvk {

  const std::array<D3D11RTUpgradeHelper::FormatInfo, 116> formatInfoArray =
  {{
    // DXGI_FORMAT_UNKNOWN
    {"unknown"},
    // DXGI_FORMAT_R32G32B32A32_TYPELESS
    {"typeless",
     4,
     "rgba",
     32, 32, 32, 32},
    // DXGI_FORMAT_R32G32B32A32_FLOAT
    {"float",
     4,
     "rgba",
     32, 32, 32, 32},
    // DXGI_FORMAT_R32G32B32A32_UINT
    {"uint",
     4,
     "rgba",
     32, 32, 32, 32},
    // DXGI_FORMAT_R32G32B32A32_SINT
    {"sint",
     4,
     "rgba",
     32, 32, 32, 32},
    // DXGI_FORMAT_R32G32B32_TYPELESS
    {"typeless",
     3,
     "rgb",
     32, 32, 32},
    // DXGI_FORMAT_R32G32B32_FLOAT
    {"float",
     3,
     "rgb",
     32, 32, 32},
    // DXGI_FORMAT_R32G32B32_UINT
    {"uint",
     3,
     "rgb",
     32, 32, 32},
    // DXGI_FORMAT_R32G32B32_SINT
    {"sint",
     3,
     "rgb",
     32, 32, 32},
    // DXGI_FORMAT_R16G16B16A16_TYPELESS
    {"typeless",
     4,
     "rgba",
     16, 16, 16, 16},
    // DXGI_FORMAT_R16G16B16A16_FLOAT
    {"float",
     4,
     "rgba",
     16, 16, 16, 16},
    // DXGI_FORMAT_R16G16B16A16_UNORM
    {"unorm",
     4,
     "rgba",
     16, 16, 16, 16},
    // DXGI_FORMAT_R16G16B16A16_UINT
    {"uint",
     4,
     "rgba",
     16, 16, 16, 16},
    // DXGI_FORMAT_R16G16B16A16_SNORM
    {"snorm",
     4,
     "rgba",
     16, 16, 16, 16},
    // DXGI_FORMAT_R16G16B16A16_SINT
    {"sint",
     4,
     "rgba",
     16, 16, 16, 16},
    // DXGI_FORMAT_R32G32_TYPELESS
    {"typeless",
     2,
     "rg",
     32},
    // DXGI_FORMAT_R32G32_FLOAT
    {"float",
     2,
     "rg",
     32},
    // DXGI_FORMAT_R32G32_UINT
    {"uint",
     2,
     "rg",
     32},
    // DXGI_FORMAT_R32G32_SINT
    {"sint",
     2,
     "rg",
     32},
    // DXGI_FORMAT_R32G8X24_TYPELESS
    {"typeless",
     2,
     "rgu",
     32, 8, 24},
    // DXGI_FORMAT_D32_FLOAT_S8X24_UINT
    {"float+uint",
     2,
     "dsu",
     32, 8, 24},
    // DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS
    {"float+typeless", 1,
     "ruu",
     32, 8, 24},
    // DXGI_FORMAT_X32_TYPELESS_G8X24_UINT
    {"typeless+uint",
     1,
     "ugu",
     32, 8, 24},
    // DXGI_FORMAT_R10G10B10A2_TYPELESS
    {"typeless",
     4,
     "rgba",
     10, 10, 10, 2},
    // DXGI_FORMAT_R10G10B10A2_UNORM
    {"unorm",
     4,
     "rgba",
     10, 10, 10, 2},
    // DXGI_FORMAT_R10G10B10A2_UINT
    {"uint",
     4,
     "rgba",
     10, 10, 10, 2},
    // DXGI_FORMAT_R11G11B10_FLOAT
    {"float",
     3,
     "rgb",
     11, 11, 10},
    // DXGI_FORMAT_R8G8B8A8_TYPELESS
    {"typeless",
     4,
     "rgba",
     8, 8, 8, 8},
    // DXGI_FORMAT_R8G8B8A8_UNORM
    {"unorm",
     4,
     "rgba",
     8, 8, 8, 8},
    // DXGI_FORMAT_R8G8B8A8_UNORM_SRGB
    {"unorm_srgb",
     4,
     "rgba",
     8, 8, 8, 8},
    // DXGI_FORMAT_R8G8B8A8_UINT
    {"uint",
     4,
     "rgba",
     8, 8, 8, 8},
    // DXGI_FORMAT_R8G8B8A8_SNORM
    {"snorm",
     4,
     "rgba",
     8, 8, 8, 8},
    // DXGI_FORMAT_R8G8B8A8_SINT
    {"sint",
     4,
     "rgba",
     8, 8, 8, 8},
    // DXGI_FORMAT_R16G16_TYPELESS
    {"typeless",
     2,
     "rg",
     16},
    // DXGI_FORMAT_R16G16_FLOAT
    {"float",
     2,
     "rg",
     16},
    // DXGI_FORMAT_R16G16_UNORM
    {"unorm",
     2,
     "rg",
     16},
    // DXGI_FORMAT_R16G16_UINT
    {"uint",
     2,
     "rg",
     16},
    // DXGI_FORMAT_R16G16_SNORM
    {"snorm",
     2,
     "rg",
     16},
    // DXGI_FORMAT_R16G16_SINT
    {"sint",
     2,
     "rg",
     16},
    // DXGI_FORMAT_R32_TYPELESS
    {"typeless",
     1,
     "r",
     16},
    // DXGI_FORMAT_D32_FLOAT
    {"float",
     1,
     "d",
     16},
    // DXGI_FORMAT_R32_FLOAT
    {"float",
     1,
     "r",
     16},
    // DXGI_FORMAT_R32_UINT
    {"uint",
     1,
     "r",
     16},
    // DXGI_FORMAT_R32_SINT
    {"sint",
     1,
     "r",
     16},
    // DXGI_FORMAT_R24G8_TYPELESS
    {"typeless",
     2,
     "rg",
     24, 8},
    // DXGI_FORMAT_D24_UNORM_S8_UINT
    {"unorm+uint",
     2,
     "ds",
     24, 8},
    // DXGI_FORMAT_R24_UNORM_X8_TYPELESS
    {"typeless",
     2,
     "du",
     24, 8},
    // DXGI_FORMAT_X24_TYPELESS_G8_UINT
    {"typeless+uint",
     2,
     "ug",
     24, 8},
    // DXGI_FORMAT_R8G8_TYPELESS
    {"typeless",
     2,
     "rg",
     8, 8},
    // DXGI_FORMAT_R8G8_UNORM
    {"unorm",
     2,
     "rg",
     8, 8},
    // DXGI_FORMAT_R8G8_UINT
    {"uint",
     2,
     "rg",
     8, 8},
    // DXGI_FORMAT_R8G8_SNORM
    {"snorm",
     2,
     "rg",
     8, 8},
    // DXGI_FORMAT_R8G8_SINT
    {"sint",
     2,
     "rg",
     8, 8},
    // DXGI_FORMAT_R16_TYPELESS
    {"typeless",
     1,
     "r",
     16},
    // DXGI_FORMAT_R16_FLOAT
    {"float",
     1,
     "r",
     16},
    // DXGI_FORMAT_D16_UNORM
    {"unorm",
     1,
     "d",
     16},
    // DXGI_FORMAT_R16_UNORM
    {"unorm",
     1,
     "r",
     16},
    // DXGI_FORMAT_R16_UINT
    {"uint",
     1,
     "r",
     16},
    // DXGI_FORMAT_R16_SNORM
    {"snorm",
     1,
     "r",
     16},
    // DXGI_FORMAT_R16_SINT
    {"sint",
     1,
     "r",
     16},
    // DXGI_FORMAT_R8_TYPELESS
    {"typeless",
     1,
     "r",
     8},
    // DXGI_FORMAT_R8_UNORM
    {"unorm",
     1,
     "r",
     8},
    // DXGI_FORMAT_R8_UINT
    {"uint",
     1,
     "r",
     8},
    // DXGI_FORMAT_R8_SNORM
    {"snorm",
     1,
     "r",
     8},
    // DXGI_FORMAT_R8_SINT
    {"sint",
     1,
     "r",
     8},
    // DXGI_FORMAT_A8_UNORM
    {"unorm",
     1, "a",
     8},
    // DXGI_FORMAT_R1_UNORM
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_R9G9B9E5_SHAREDEXP
    {"sharedexp",
     4,
     "rgbe",
     9, 9, 9, 5},
    // DXGI_FORMAT_R8G8_B8G8_UNORM
    {"unorm",
     4,
     "rgbg",
     8, 8, 8, 8},
    // DXGI_FORMAT_G8R8_G8B8_UNORM
    {"unorm",
     4,
     "grgb",
     8, 8, 8, 8},
    // DXGI_FORMAT_BC1_TYPELESS
    {"ignore"},
    // DXGI_FORMAT_BC1_UNORM
    {"ignore"},
    // DXGI_FORMAT_BC1_UNORM_SRGB
    {"ignore"},
    // DXGI_FORMAT_BC2_TYPELESS
    {"ignore"},
    // DXGI_FORMAT_BC2_UNORM
    {"ignore"},
    // DXGI_FORMAT_BC2_UNORM_SRGB
    {"ignore"},
    // DXGI_FORMAT_BC3_TYPELESS
    {"ignore"},
    // DXGI_FORMAT_BC3_UNORM
    {"ignore"},
    // DXGI_FORMAT_BC3_UNORM_SRGB
    {"ignore"},
    // DXGI_FORMAT_BC4_TYPELESS
    {"ignore"},
    // DXGI_FORMAT_BC4_UNORM
    {"ignore"},
    // DXGI_FORMAT_BC4_SNORM
    {"ignore"},
    // DXGI_FORMAT_BC5_TYPELESS
    {"ignore"},
    // DXGI_FORMAT_BC5_UNORM
    {"ignore"},
    // DXGI_FORMAT_BC5_SNORM
    {"ignore"},
    // DXGI_FORMAT_B5G6R5_UNORM
    {"unorm",
     3,
     "rgb",
     5, 6, 5},
    // DXGI_FORMAT_B5G5R5A1_UNORM
    {"unorm",
     4,
     "rgba",
     5, 5, 5, 1},
    // DXGI_FORMAT_B8G8R8A8_UNORM
    {"unorm",
     4,
     "bgra",
     8, 8, 8, 8},
    // DXGI_FORMAT_B8G8R8X8_UNORM
    {"unorm",
     3,
     "bgru",
     8, 8, 8, 8},
    // DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_B8G8R8A8_TYPELESS
    {"typeless",
     4,
     "bgra",
     8, 8, 8, 8},
    // DXGI_FORMAT_B8G8R8A8_UNORM_SRGB
    {"unorm_srgb",
     4,
     "bgra",
     8, 8, 8, 8},
    // DXGI_FORMAT_B8G8R8X8_TYPELESS
    {"typeless",
     3,
     "bgru",
     8, 8, 8, 8},
    // DXGI_FORMAT_B8G8R8X8_UNORM_SRGB
    {"unorm_srgb",
     3,
     "bgru",
     8, 8, 8, 8},
    // DXGI_FORMAT_BC6H_TYPELESS
    {"ignore"},
    // DXGI_FORMAT_BC6H_UF16
    {"ignore"},
    // DXGI_FORMAT_BC6H_SF16
    {"ignore"},
    // DXGI_FORMAT_BC7_TYPELESS
    {"ignore"},
    // DXGI_FORMAT_BC7_UNORM
    {"ignore"},
    // DXGI_FORMAT_BC7_UNORM_SRGB
    {"ignore"},
    // DXGI_FORMAT_AYUV
    {"ignore"},
    // DXGI_FORMAT_Y410
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_Y416
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_NV12
    {"ignore"},
    // DXGI_FORMAT_P010
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_P016
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_420_OPAQUE
    {"ignore"},
    // DXGI_FORMAT_YUY2
    {"ignore"},
    // DXGI_FORMAT_Y210
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_Y216
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_NV11
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_AI44
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_IA44
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_P8
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_A8P8
    {"unsupported"}, // Unsupported
    // DXGI_FORMAT_B4G4R4A4_UNORM
    {"unorm",
     4,
     "rgba",
     4, 4, 4, 4},
  }};


  uint32_t D3D11RTUpgradeHelper::GetFormatID(
    const DXGI_FORMAT Format)
  {
    return size_t(Format) <= formatInfoArray.size()
         ? size_t(Format)
         : 0;
  }


  DXGI_FORMAT D3D11RTUpgradeHelper::TranslateFormatString(
    const DXGI_FORMAT inputFormat,
    const std::string targetFormatString)
  {
    const size_t inputFormatID = GetFormatID(inputFormat);

    const uint32_t inputDepth = formatInfoArray[inputFormatID].depth0 +
                                formatInfoArray[inputFormatID].depth1 +
                                formatInfoArray[inputFormatID].depth2;

    const DXGI_FORMAT targetFormat = targetFormatString ==    "fp32" ? DXGI_FORMAT_R32G32B32A32_FLOAT
                                   : targetFormatString ==    "fp16" ? DXGI_FORMAT_R16G16B16A16_FLOAT
                                   : targetFormatString ==  "uint32" ? DXGI_FORMAT_R32G32B32A32_UINT
                                   : targetFormatString ==  "uint16" ? DXGI_FORMAT_R16G16B16A16_UINT
                                   : targetFormatString ==  "sint32" ? DXGI_FORMAT_R32G32B32A32_SINT
                                   : targetFormatString ==  "sint16" ? DXGI_FORMAT_R16G16B16A16_SINT
                                   : targetFormatString == "unorm16" ? DXGI_FORMAT_R16G16B16A16_UNORM
                                   : targetFormatString == "snorm16" ? DXGI_FORMAT_R16G16B16A16_SNORM
                                   : inputFormat;

    const size_t targetFormatID = GetFormatID(targetFormat);

    const uint32_t targetDepth = formatInfoArray[targetFormatID].depth0 +
                                 formatInfoArray[targetFormatID].depth1 +
                                 formatInfoArray[targetFormatID].depth2;

    if ((inputDepth > 0 && targetDepth > 0)
     && (targetDepth >= inputDepth))
      return targetFormat;
    else
      return inputFormat;
  }


  DXGI_FORMAT D3D11RTUpgradeHelper::UpgradeRenderTarget(
    const DXGI_FORMAT inputFormat)
  {
    const std::string targetFormatString =
      inputFormat == DXGI_FORMAT_R16G16B16A16_TYPELESS ? m_device->GetOptions()->upgrade_R16G16B16A16_TYPELESS
    : inputFormat == DXGI_FORMAT_R16G16B16A16_UNORM    ? m_device->GetOptions()->upgrade_R16G16B16A16_UNORM
    : inputFormat == DXGI_FORMAT_R16G16B16A16_UINT     ? m_device->GetOptions()->upgrade_R16G16B16A16_UINT
    : inputFormat == DXGI_FORMAT_R16G16B16A16_SNORM    ? m_device->GetOptions()->upgrade_R16G16B16A16_SNORM
    : inputFormat == DXGI_FORMAT_R16G16B16A16_SINT     ? m_device->GetOptions()->upgrade_R16G16B16A16_SINT
    : inputFormat == DXGI_FORMAT_R10G10B10A2_TYPELESS  ? m_device->GetOptions()->upgrade_R10G10B10A2_TYPELESS
    : inputFormat == DXGI_FORMAT_R10G10B10A2_UNORM     ? m_device->GetOptions()->upgrade_R10G10B10A2_UNORM
    : inputFormat == DXGI_FORMAT_R10G10B10A2_UINT      ? m_device->GetOptions()->upgrade_R10G10B10A2_UINT
    : inputFormat == DXGI_FORMAT_R11G11B10_FLOAT       ? m_device->GetOptions()->upgrade_R11G11B10_FLOAT
    : inputFormat == DXGI_FORMAT_R8G8B8A8_TYPELESS     ? m_device->GetOptions()->upgrade_R8G8B8A8_TYPELESS
    : inputFormat == DXGI_FORMAT_R8G8B8A8_UNORM        ? m_device->GetOptions()->upgrade_R8G8B8A8_UNORM
    : inputFormat == DXGI_FORMAT_R8G8B8A8_UNORM_SRGB   ? m_device->GetOptions()->upgrade_R8G8B8A8_UNORM_SRGB
    : inputFormat == DXGI_FORMAT_R8G8B8A8_UINT         ? m_device->GetOptions()->upgrade_R8G8B8A8_UINT
    : inputFormat == DXGI_FORMAT_R8G8B8A8_SNORM        ? m_device->GetOptions()->upgrade_R8G8B8A8_SNORM
    : inputFormat == DXGI_FORMAT_R8G8B8A8_SINT         ? m_device->GetOptions()->upgrade_R8G8B8A8_SINT
    : inputFormat == DXGI_FORMAT_B8G8R8A8_UNORM        ? m_device->GetOptions()->upgrade_B8G8R8A8_UNORM
    : inputFormat == DXGI_FORMAT_B8G8R8X8_UNORM        ? m_device->GetOptions()->upgrade_B8G8R8X8_UNORM
    : inputFormat == DXGI_FORMAT_B8G8R8A8_TYPELESS     ? m_device->GetOptions()->upgrade_B8G8R8A8_TYPELESS
    : inputFormat == DXGI_FORMAT_B8G8R8A8_UNORM_SRGB   ? m_device->GetOptions()->upgrade_B8G8R8A8_UNORM_SRGB
    : inputFormat == DXGI_FORMAT_B8G8R8X8_TYPELESS     ? m_device->GetOptions()->upgrade_B8G8R8X8_TYPELESS
    : inputFormat == DXGI_FORMAT_B8G8R8X8_UNORM_SRGB   ? m_device->GetOptions()->upgrade_B8G8R8X8_UNORM_SRGB
    : "";

    if (targetFormatString != "")
      return TranslateFormatString(inputFormat, targetFormatString);
    else
      return inputFormat;
  }


  std::string D3D11RTUpgradeHelper::GetDXGIFormatNameAsString(
          DXGI_FORMAT         Format) {
    return
    Format == DXGI_FORMAT_UNKNOWN                    ? "UNKNOWN                      "
  : Format == DXGI_FORMAT_R32G32B32A32_TYPELESS      ? "R32G32B32A32_TYPELESS        "
  : Format == DXGI_FORMAT_R32G32B32A32_FLOAT         ? "R32G32B32A32_FLOAT           "
  : Format == DXGI_FORMAT_R32G32B32A32_UINT          ? "R32G32B32A32_UINT            "
  : Format == DXGI_FORMAT_R32G32B32A32_SINT          ? "R32G32B32A32_SINT            "
  : Format == DXGI_FORMAT_R32G32B32_TYPELESS         ? "   R32G32B32_TYPELESS        "
  : Format == DXGI_FORMAT_R32G32B32_FLOAT            ? "   R32G32B32_FLOAT           "
  : Format == DXGI_FORMAT_R32G32B32_UINT             ? "   R32G32B32_UINT            "
  : Format == DXGI_FORMAT_R32G32B32_SINT             ? "   R32G32B32_SINT            "
  : Format == DXGI_FORMAT_R16G16B16A16_TYPELESS      ? "R16G16B16A16_TYPELESS        "
  : Format == DXGI_FORMAT_R16G16B16A16_FLOAT         ? "R16G16B16A16_FLOAT           "
  : Format == DXGI_FORMAT_R16G16B16A16_UNORM         ? "R16G16B16A16_UNORM           "
  : Format == DXGI_FORMAT_R16G16B16A16_UINT          ? "R16G16B16A16_UINT            "
  : Format == DXGI_FORMAT_R16G16B16A16_SNORM         ? "R16G16B16A16_SNORM           "
  : Format == DXGI_FORMAT_R16G16B16A16_SINT          ? "R16G16B16A16_SINT            "
  : Format == DXGI_FORMAT_R32G32_TYPELESS            ? "      R32G32_TYPELESS        "
  : Format == DXGI_FORMAT_R32G32_FLOAT               ? "      R32G32_FLOAT           "
  : Format == DXGI_FORMAT_R32G32_UINT                ? "      R32G32_UINT            "
  : Format == DXGI_FORMAT_R32G32_SINT                ? "      R32G32_SINT            "
  : Format == DXGI_FORMAT_R32G8X24_TYPELESS          ? "    R32G8X24_TYPELESS        "
  : Format == DXGI_FORMAT_D32_FLOAT_S8X24_UINT       ? "D32_FLOAT_S8X24_UINT         "
  : Format == DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS   ? "R32_FLOAT_X8X24_TYPELESS     "
  : Format == DXGI_FORMAT_X32_TYPELESS_G8X24_UINT    ? "X32_TYPELESS_G8X24_UINT      "
  : Format == DXGI_FORMAT_R10G10B10A2_TYPELESS       ? " R10G10B10A2_TYPELESS        "
  : Format == DXGI_FORMAT_R10G10B10A2_UNORM          ? " R10G10B10A2_UNORM           "
  : Format == DXGI_FORMAT_R10G10B10A2_UINT           ? " R10G10B10A2_UINT            "
  : Format == DXGI_FORMAT_R11G11B10_FLOAT            ? "   R11G11B10_FLOAT           "
  : Format == DXGI_FORMAT_R8G8B8A8_TYPELESS          ? "    R8G8B8A8_TYPELESS        "
  : Format == DXGI_FORMAT_R8G8B8A8_UNORM             ? "    R8G8B8A8_UNORM           "
  : Format == DXGI_FORMAT_R8G8B8A8_UNORM_SRGB        ? "    R8G8B8A8_UNORM_SRGB      "
  : Format == DXGI_FORMAT_R8G8B8A8_UINT              ? "    R8G8B8A8_UINT            "
  : Format == DXGI_FORMAT_R8G8B8A8_SNORM             ? "    R8G8B8A8_SNORM           "
  : Format == DXGI_FORMAT_R8G8B8A8_SINT              ? "    R8G8B8A8_SINT            "
  : Format == DXGI_FORMAT_R16G16_TYPELESS            ? "      R16G16_TYPELESS        "
  : Format == DXGI_FORMAT_R16G16_FLOAT               ? "      R16G16_FLOAT           "
  : Format == DXGI_FORMAT_R16G16_UNORM               ? "      R16G16_UNORM           "
  : Format == DXGI_FORMAT_R16G16_UINT                ? "      R16G16_UINT            "
  : Format == DXGI_FORMAT_R16G16_SNORM               ? "      R16G16_SNORM           "
  : Format == DXGI_FORMAT_R16G16_SINT                ? "      R16G16_SINT            "
  : Format == DXGI_FORMAT_R32_TYPELESS               ? "         R32_TYPELESS        "
  : Format == DXGI_FORMAT_D32_FLOAT                  ? "         D32_FLOAT           "
  : Format == DXGI_FORMAT_R32_FLOAT                  ? "         R32_FLOAT           "
  : Format == DXGI_FORMAT_R32_UINT                   ? "         R32_UINT            "
  : Format == DXGI_FORMAT_R32_SINT                   ? "         R32_SINT            "
  : Format == DXGI_FORMAT_R24G8_TYPELESS             ? "R24G8_TYPELESS               "
  : Format == DXGI_FORMAT_D24_UNORM_S8_UINT          ? "D24_UNORM_S8_UINT            "
  : Format == DXGI_FORMAT_R24_UNORM_X8_TYPELESS      ? "R24_UNORM_X8_TYPELESS        "
  : Format == DXGI_FORMAT_X24_TYPELESS_G8_UINT       ? "X24_TYPELESS_G8_UINT         "
  : Format == DXGI_FORMAT_R8G8_TYPELESS              ? "        R8G8_TYPELESS        "
  : Format == DXGI_FORMAT_R8G8_UNORM                 ? "        R8G8_UNORM           "
  : Format == DXGI_FORMAT_R8G8_UINT                  ? "        R8G8_UINT            "
  : Format == DXGI_FORMAT_R8G8_SNORM                 ? "        R8G8_SNORM           "
  : Format == DXGI_FORMAT_R8G8_SINT                  ? "        R8G8_SINT            "
  : Format == DXGI_FORMAT_R16_TYPELESS               ? "         R16_TYPELESS        "
  : Format == DXGI_FORMAT_R16_FLOAT                  ? "         R16_FLOAT           "
  : Format == DXGI_FORMAT_D16_UNORM                  ? "         D16_UNORM           "
  : Format == DXGI_FORMAT_R16_UNORM                  ? "         R16_UNORM           "
  : Format == DXGI_FORMAT_R16_UINT                   ? "         R16_UINT            "
  : Format == DXGI_FORMAT_R16_SNORM                  ? "         R16_SNORM           "
  : Format == DXGI_FORMAT_R16_SINT                   ? "         R16_SINT            "
  : Format == DXGI_FORMAT_R8_TYPELESS                ? "          R8_TYPELESS        "
  : Format == DXGI_FORMAT_R8_UNORM                   ? "          R8_UNORM           "
  : Format == DXGI_FORMAT_R8_UINT                    ? "          R8_UINT            "
  : Format == DXGI_FORMAT_R8_SNORM                   ? "          R8_SNORM           "
  : Format == DXGI_FORMAT_R8_SINT                    ? "          R8_SINT            "
  : Format == DXGI_FORMAT_A8_UNORM                   ? "          A8_UNORM           "
  : Format == DXGI_FORMAT_R1_UNORM                   ? "          R1_UNORM           "
  : Format == DXGI_FORMAT_R9G9B9E5_SHAREDEXP         ? "    R9G9B9E5_SHAREDEXP       "
  : Format == DXGI_FORMAT_R8G8_B8G8_UNORM            ? "   R8G8_B8G8_UNORM           "
  : Format == DXGI_FORMAT_G8R8_G8B8_UNORM            ? "   G8R8_G8B8_UNORM           "
  : Format == DXGI_FORMAT_BC1_TYPELESS               ? "         BC1_TYPELESS        "
  : Format == DXGI_FORMAT_BC1_UNORM                  ? "         BC1_UNORM           "
  : Format == DXGI_FORMAT_BC1_UNORM_SRGB             ? "         BC1_UNORM_SRGB      "
  : Format == DXGI_FORMAT_BC2_TYPELESS               ? "         BC2_TYPELESS        "
  : Format == DXGI_FORMAT_BC2_UNORM                  ? "         BC2_UNORM           "
  : Format == DXGI_FORMAT_BC2_UNORM_SRGB             ? "         BC2_UNORM_SRGB      "
  : Format == DXGI_FORMAT_BC3_TYPELESS               ? "         BC3_TYPELESS        "
  : Format == DXGI_FORMAT_BC3_UNORM                  ? "         BC3_UNORM           "
  : Format == DXGI_FORMAT_BC3_UNORM_SRGB             ? "         BC3_UNORM_SRGB      "
  : Format == DXGI_FORMAT_BC4_TYPELESS               ? "         BC4_TYPELESS        "
  : Format == DXGI_FORMAT_BC4_UNORM                  ? "         BC4_UNORM           "
  : Format == DXGI_FORMAT_BC4_SNORM                  ? "         BC4_SNORM           "
  : Format == DXGI_FORMAT_BC5_TYPELESS               ? "         BC5_TYPELESS        "
  : Format == DXGI_FORMAT_BC5_UNORM                  ? "         BC5_UNORM           "
  : Format == DXGI_FORMAT_BC5_SNORM                  ? "         BC5_SNORM           "
  : Format == DXGI_FORMAT_B5G6R5_UNORM               ? "      B5G6R5_UNORM           "
  : Format == DXGI_FORMAT_B5G5R5A1_UNORM             ? "    B5G5R5A1_UNORM           "
  : Format == DXGI_FORMAT_B8G8R8A8_UNORM             ? "    B8G8R8A8_UNORM           "
  : Format == DXGI_FORMAT_B8G8R8X8_UNORM             ? "    B8G8R8X8_UNORM           "
  : Format == DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM ? "   R10G10B10_XR_BIAS_A2_UNORM"
  : Format == DXGI_FORMAT_B8G8R8A8_TYPELESS          ? "    B8G8R8A8_TYPELESS        "
  : Format == DXGI_FORMAT_B8G8R8A8_UNORM_SRGB        ? "    B8G8R8A8_UNORM_SRGB      "
  : Format == DXGI_FORMAT_B8G8R8X8_TYPELESS          ? "    B8G8R8X8_TYPELESS        "
  : Format == DXGI_FORMAT_B8G8R8X8_UNORM_SRGB        ? "    B8G8R8X8_UNORM_SRGB      "
  : Format == DXGI_FORMAT_BC6H_TYPELESS              ? "        BC6H_TYPELESS        "
  : Format == DXGI_FORMAT_BC6H_UF16                  ? "        BC6H_UF16            "
  : Format == DXGI_FORMAT_BC6H_SF16                  ? "        BC6H_SF16            "
  : Format == DXGI_FORMAT_BC7_TYPELESS               ? "         BC7_TYPELESS        "
  : Format == DXGI_FORMAT_BC7_UNORM                  ? "         BC7_UNORM           "
  : Format == DXGI_FORMAT_BC7_UNORM_SRGB             ? "         BC7_UNORM_SRGB      "
  : Format == DXGI_FORMAT_AYUV                       ? "AYUV                         "
  : Format == DXGI_FORMAT_Y410                       ? "Y410                         "
  : Format == DXGI_FORMAT_Y416                       ? "Y416                         "
  : Format == DXGI_FORMAT_NV12                       ? "NV12                         "
  : Format == DXGI_FORMAT_P010                       ? "P010                         "
  : Format == DXGI_FORMAT_P016                       ? "P016                         "
  : Format == DXGI_FORMAT_420_OPAQUE                 ? "420_OPAQUE                   "
  : Format == DXGI_FORMAT_YUY2                       ? "YUY2                         "
  : Format == DXGI_FORMAT_Y210                       ? "Y210                         "
  : Format == DXGI_FORMAT_Y216                       ? "Y216                         "
  : Format == DXGI_FORMAT_NV11                       ? "NV11                         "
  : Format == DXGI_FORMAT_AI44                       ? "AI44                         "
  : Format == DXGI_FORMAT_IA44                       ? "IA44                         "
  : Format == DXGI_FORMAT_P8                         ? "P8                           "
  : Format == DXGI_FORMAT_A8P8                       ? "A8P8                         "
  : Format == DXGI_FORMAT_B4G4R4A4_UNORM             ? "    B4G4R4A4_UNORM           "
  : Format == DXGI_FORMAT_P208                       ? "P208                         "
  : Format == DXGI_FORMAT_V208                       ? "V208                         "
  : Format == DXGI_FORMAT_V408                       ? "V408                         "
  : Format == DXGI_FORMAT_FORCE_UINT                 ? "FORCE_UINT                   "
  : "wth";
  }
}