#include "../util/util_math.h"

#include "d3d11_options.h"

namespace dxvk {

  //HDR-mod helpers start
  std::string GetDXGIFormatNameAsString(
    const DXGI_FORMAT Format) {
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

  bool CheckFormatCompatability(
    const DXGI_FORMAT OriginalFormat,
    const DXGI_FORMAT UpgradedFormat,
    const FORMAT_TYPE OriginalFormatType,
    const FORMAT_TYPE UpgradedFormatType)
  {

    if ((OriginalFormatType == FORMAT_TYPE::FORMAT_SINT
      || OriginalFormatType == FORMAT_TYPE::FORMAT_SNORM
      || OriginalFormatType == FORMAT_TYPE::FORMAT_UINT
      || OriginalFormatType == FORMAT_TYPE::FORMAT_TYPELESS)
     && OriginalFormatType != UpgradedFormatType) {
      return false;
    }
    else if (OriginalFormat == DXGI_FORMAT_R11G11B10_FLOAT
          && UpgradedFormat >  DXGI_FORMAT_R16G16B16A16_FLOAT) {
      return false;
    }
    else if (OriginalFormatType == FORMAT_TYPE::FORMAT_UNORM_SRGB
          && UpgradedFormat > DXGI_FORMAT_R16G16B16A16_UNORM) {
      return false;
    }
    else {
      return true;
    }

  }

  void DXGI_FORMAT_UpgradeHelper(
    const std::string                         UpgradedFormatString,
    const DXGI_FORMAT                         OriginalFormat,
          std::array<FormatUpgradeInfo, 116>* pFormatUpgradeInfoArray)
  {

    DXGI_FORMAT UpgradedFormat = DXGI_FORMAT_UNKNOWN;

#define GET_TARGET_FMT(if_, UpgradedFormatAsString, targetDXGIFMT) \
          if_ (UpgradedFormatString == UpgradedFormatAsString) {   \
            UpgradedFormat = targetDXGIFMT;                        \
          }

    GET_TARGET_FMT(if,      "rgba32_typeless",  DXGI_FORMAT_R32G32B32A32_TYPELESS)
    GET_TARGET_FMT(else if, "rgba32_float",     DXGI_FORMAT_R32G32B32A32_FLOAT)
    GET_TARGET_FMT(else if, "rgba32_uint",      DXGI_FORMAT_R32G32B32A32_UINT)
    GET_TARGET_FMT(else if, "rgba32_sint",      DXGI_FORMAT_R32G32B32A32_SINT)
    GET_TARGET_FMT(else if, "rgba16_typeless",  DXGI_FORMAT_R16G16B16A16_TYPELESS)
    GET_TARGET_FMT(else if, "rgba16_float",     DXGI_FORMAT_R16G16B16A16_FLOAT)
    GET_TARGET_FMT(else if, "rgba16_unorm",     DXGI_FORMAT_R16G16B16A16_UNORM)
    GET_TARGET_FMT(else if, "rgba16_uint",      DXGI_FORMAT_R16G16B16A16_UINT)
    GET_TARGET_FMT(else if, "rgba16_snorm",     DXGI_FORMAT_R16G16B16A16_SNORM)
    GET_TARGET_FMT(else if, "rgba16_sint",      DXGI_FORMAT_R16G16B16A16_SINT)
    GET_TARGET_FMT(else if, "rgb10a2_typeless", DXGI_FORMAT_R10G10B10A2_TYPELESS)
    GET_TARGET_FMT(else if, "rgb10a2_unorm",    DXGI_FORMAT_R10G10B10A2_UNORM)
    GET_TARGET_FMT(else if, "rgb10a2_uint",     DXGI_FORMAT_R10G10B10A2_UINT)
    else {
      Logger::info(str::format("D3D11: render target upgrade disabled for: ",
                               GetDXGIFormatNameAsString(OriginalFormat)));
      return;
    }

    if(CheckFormatCompatability(OriginalFormat,
                                UpgradedFormat,
                                pFormatUpgradeInfoArray->at(static_cast<size_t>(OriginalFormat)).type,
                                pFormatUpgradeInfoArray->at(static_cast<size_t>(UpgradedFormat)).type)) {
      Logger::info(str::format("D3D11: render target upgrade enabled for:  ",
                               GetDXGIFormatNameAsString(OriginalFormat),
                               " -> ",
                               GetDXGIFormatNameAsString(UpgradedFormat)));
      pFormatUpgradeInfoArray->at(static_cast<size_t>(OriginalFormat)).upgradedFormat = UpgradedFormat;
      return;
    }
    else {
      Logger::info(str::format("D3D11: render target upgrade disabled for: ",
                               GetDXGIFormatNameAsString(OriginalFormat),
                               " -> ",
                               GetDXGIFormatNameAsString(UpgradedFormat),
                               " is not possible"));
      return;
    }

#undef GET_TARGET_FMT

  }

  DXGI_FORMAT BackBufferFormatUpgradeHelper(const std::string Format)
  {
    DXGI_FORMAT upgradedFormat;
    if (Format == "rgb10a2_unorm") {
      upgradedFormat = DXGI_FORMAT_R10G10B10A2_UNORM;
    }
    else if (Format == "rgba16_unorm") {
      upgradedFormat = DXGI_FORMAT_R16G16B16A16_UNORM;
    }
    else if (Format == "rgba16_float") {
      upgradedFormat = DXGI_FORMAT_R16G16B16A16_FLOAT;
    }
    else {
      upgradedFormat = DXGI_FORMAT_UNKNOWN;
    }
    if (upgradedFormat != DXGI_FORMAT_UNKNOWN) {
      Logger::info(str::format("D3D11: back buffer format will be upgraded to: ",
                               GetDXGIFormatNameAsString(upgradedFormat)));
    }
    else {
      Logger::info("D3D11: back buffer format upgrade disabled");
    }
    return upgradedFormat;
  }

  VkFormat VkFormat_UpgradeHelper(const std::string Format)
  {
    VkFormat upgradedFormat;
    if (Format == "rgba8_unorm") {
      upgradedFormat = VK_FORMAT_R8G8B8A8_UNORM;
    }
    else if (Format == "bgra8_unorm") {
      upgradedFormat = VK_FORMAT_B8G8R8A8_UNORM;
    }
    else if (Format == "rgb10a2_unorm") {
      upgradedFormat = VK_FORMAT_A2B10G10R10_UNORM_PACK32;
    }
    else if (Format == "bgr10a2_unorm") {
      upgradedFormat = VK_FORMAT_A2R10G10B10_UNORM_PACK32;
    }
    else if (Format == "rgba16_unorm") {
      upgradedFormat = VK_FORMAT_R16G16B16A16_UNORM;
    }
    else if (Format == "rgba16_float") {
      upgradedFormat = VK_FORMAT_R16G16B16A16_SFLOAT;
    }
    else if (Format == "unchanged") {
      upgradedFormat = VK_FORMAT_MAX_ENUM;
    }
    else {
      upgradedFormat = VK_FORMAT_UNDEFINED;
    }
    if (upgradedFormat == VK_FORMAT_MAX_ENUM) {
      Logger::info("DXVK (D3D11): swap chain format will stay unchanged");
    }
    else if (upgradedFormat != VK_FORMAT_UNDEFINED) {
      Logger::info(str::format("DXVK (D3D11): swap chain format will be upgraded to:      ",
                               upgradedFormat));
    }
    else {
      Logger::info("DXVK (D3D11): swap chain format upgrade disabled");
    }
    return upgradedFormat;
  }

  VkColorSpaceKHR VkColorSpace_UpgradeHelper(const std::string ColorSpace)
  {
    VkColorSpaceKHR upgradedColorSpace;
    if (ColorSpace == "srgb") {
      upgradedColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
    }
    else if (ColorSpace == "bt709_non_linear") {
      upgradedColorSpace = VK_COLOR_SPACE_BT709_NONLINEAR_EXT;
    }
    else if (ColorSpace == "pq") {
      upgradedColorSpace = VK_COLOR_SPACE_HDR10_ST2084_EXT;
    }
    else if (ColorSpace == "bt2020_linear") {
      upgradedColorSpace = VK_COLOR_SPACE_BT2020_LINEAR_EXT;
    }
    else if (ColorSpace == "scrgb") {
      upgradedColorSpace = VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT;
    }
    else if (ColorSpace == "unchanged") {
      upgradedColorSpace = VK_COLOR_SPACE_PASS_THROUGH_EXT;
    }
    else {
      upgradedColorSpace = VK_COLOR_SPACE_MAX_ENUM_KHR;
    }
    if (upgradedColorSpace == VK_COLOR_SPACE_PASS_THROUGH_EXT) {
      Logger::info("DXVK (D3D11): swap chain color space will stay unchanged");
    }
    else if (upgradedColorSpace != VK_COLOR_SPACE_MAX_ENUM_KHR) {
      Logger::info(str::format("DXVK (D3D11): swap chain color space will be upgraded to: ",
                               upgradedColorSpace));
    }
    else {
      Logger::info("DXVK (D3D11): swap chain color space upgrade disabled");
    }
    return upgradedColorSpace;
  }
  //HDR-mod helpers end


  static bool IsAPITracingDXGI() {
#ifdef _WIN32
    return !!::GetModuleHandle("dxgitrace.dll");
#else
    return false;
#endif
  }

  D3D11Options::D3D11Options(const Config& config) {
    this->dcSingleUseMode               = config.getOption<bool>("d3d11.dcSingleUseMode", true);
    this->zeroInitWorkgroupMemory       = config.getOption<bool>("d3d11.zeroInitWorkgroupMemory", false);
    this->forceVolatileTgsmAccess       = config.getOption<bool>("d3d11.forceVolatileTgsmAccess", false);
    this->relaxedBarriers               = config.getOption<bool>("d3d11.relaxedBarriers", false);
    this->ignoreGraphicsBarriers        = config.getOption<bool>("d3d11.ignoreGraphicsBarriers", false);
    this->maxTessFactor                 = config.getOption<int32_t>("d3d11.maxTessFactor", 0);
    this->samplerAnisotropy             = config.getOption<int32_t>("d3d11.samplerAnisotropy", -1);
    this->samplerLodBias                = config.getOption<float>("d3d11.samplerLodBias", 0.0f);
    this->clampNegativeLodBias          = config.getOption<bool>("d3d11.clampNegativeLodBias", false);
    this->invariantPosition             = config.getOption<bool>("d3d11.invariantPosition", true);
    this->floatControls                 = config.getOption<bool>("d3d11.floatControls", true);
    this->forceSampleRateShading        = config.getOption<bool>("d3d11.forceSampleRateShading", false);
    this->disableMsaa                   = config.getOption<bool>("d3d11.disableMsaa", false);
    this->enableContextLock             = config.getOption<bool>("d3d11.enableContextLock", false);
    this->deferSurfaceCreation          = config.getOption<bool>("dxgi.deferSurfaceCreation", false);
    this->numBackBuffers                = config.getOption<int32_t>("dxgi.numBackBuffers", 0);
    this->maxFrameLatency               = config.getOption<int32_t>("dxgi.maxFrameLatency", 0);
    this->exposeDriverCommandLists      = config.getOption<bool>("d3d11.exposeDriverCommandLists", true);
    this->reproducibleCommandStream     = config.getOption<bool>("d3d11.reproducibleCommandStream", false);

    // HDR-mod options start
    this->enableRenderTargetUpgrades = config.getOption<bool>("d3d11.enableRenderTargetUpgrades", false);
    this->enableBackBufferUpgrade    = config.getOption<bool>("d3d11.enableBackBufferUpgrade",    false);
    this->enableSwapChainUpgrade     = config.getOption<bool>("d3d11.enableSwapChainUpgrade",     false);


    this->upgradeBackBufferTo =
      BackBufferFormatUpgradeHelper(Config::toLower(config.getOption<std::string>("d3d11.upgradeBackBufferTo", "disabled")));
    if (this->upgradeBackBufferTo == DXGI_FORMAT_UNKNOWN) {
      this->enableBackBufferUpgrade = false;
    }

    this->upgradeSwapChainFormatTo =
      VkFormat_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d11.upgradeSwapChainFormatTo", "disabled")));
    this->upgradeSwapChainColorSpaceTo =
      VkColorSpace_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d11.upgradeSwapChainColorSpaceTo", "disabled")));
    if (this->upgradeSwapChainFormatTo     == VK_FORMAT_UNDEFINED
     || this->upgradeSwapChainColorSpaceTo == VK_COLOR_SPACE_MAX_ENUM_KHR) {
      Logger::info("DXVK (D3D11): swap chain upgrade disabled");
      this->enableSwapChainUpgrade = false;
    }


#define DXGI_FORMAT_UPGRADE_HELPER(CfgString, OriginalFormat)                                \
          DXGI_FORMAT_UpgradeHelper(                                                         \
            Config::toLower(config.getOption<std::string>(("d3d11.upgrade_"                  \
                                                           CfgString                         \
                                                           "_renderTargetTo"), "disabled")), \
            OriginalFormat,                                                                  \
            &this->formatUpgradeInfoArray)

    DXGI_FORMAT_UPGRADE_HELPER("RGBA16_TYPELESS",  DXGI_FORMAT_R16G16B16A16_TYPELESS);
    DXGI_FORMAT_UPGRADE_HELPER("RGBA16_FLOAT",     DXGI_FORMAT_R16G16B16A16_FLOAT);
    DXGI_FORMAT_UPGRADE_HELPER("RGBA16_UNORM",     DXGI_FORMAT_R16G16B16A16_UNORM);
    DXGI_FORMAT_UPGRADE_HELPER("RGBA16_UINT",      DXGI_FORMAT_R16G16B16A16_UINT);
    DXGI_FORMAT_UPGRADE_HELPER("RGBA16_SNORM",     DXGI_FORMAT_R16G16B16A16_SNORM);
    DXGI_FORMAT_UPGRADE_HELPER("RGBA16_SINT",      DXGI_FORMAT_R16G16B16A16_SINT);
    DXGI_FORMAT_UPGRADE_HELPER("RGB10A2_TYPELESS", DXGI_FORMAT_R10G10B10A2_TYPELESS);
    DXGI_FORMAT_UPGRADE_HELPER("RGB10A2_UNORM",    DXGI_FORMAT_R10G10B10A2_UNORM);
    DXGI_FORMAT_UPGRADE_HELPER("RGB10A2_UINT",     DXGI_FORMAT_R10G10B10A2_UINT);
    DXGI_FORMAT_UPGRADE_HELPER("RG11B10_FLOAT",    DXGI_FORMAT_R11G11B10_FLOAT);
    DXGI_FORMAT_UPGRADE_HELPER("RGBA8_TYPELESS",   DXGI_FORMAT_R8G8B8A8_TYPELESS);
    DXGI_FORMAT_UPGRADE_HELPER("BGRA8_TYPELESS",   DXGI_FORMAT_B8G8R8A8_TYPELESS);
    DXGI_FORMAT_UPGRADE_HELPER("BGRX8_TYPELESS",   DXGI_FORMAT_B8G8R8X8_TYPELESS);
    DXGI_FORMAT_UPGRADE_HELPER("RGBA8_UNORM",      DXGI_FORMAT_R8G8B8A8_UNORM);
    DXGI_FORMAT_UPGRADE_HELPER("BGRA8_UNORM",      DXGI_FORMAT_B8G8R8A8_UNORM);
    DXGI_FORMAT_UPGRADE_HELPER("BGRX8_UNORM",      DXGI_FORMAT_B8G8R8X8_UNORM);
    DXGI_FORMAT_UPGRADE_HELPER("RGBA8_UNORM_SRGB", DXGI_FORMAT_R8G8B8A8_UNORM_SRGB);
    DXGI_FORMAT_UPGRADE_HELPER("BGRA8_UNORM_SRGB", DXGI_FORMAT_B8G8R8A8_UNORM_SRGB);
    DXGI_FORMAT_UPGRADE_HELPER("BGRX8_UNORM_SRGB", DXGI_FORMAT_B8G8R8X8_UNORM_SRGB);
    DXGI_FORMAT_UPGRADE_HELPER("RGBA8_UINT",       DXGI_FORMAT_R8G8B8A8_UINT);
    DXGI_FORMAT_UPGRADE_HELPER("RGBA8_SNORM",      DXGI_FORMAT_R8G8B8A8_SNORM);
    DXGI_FORMAT_UPGRADE_HELPER("RGBA8_SINT",       DXGI_FORMAT_R8G8B8A8_SINT);

#undef DXGI_FORMAT_UPGRADE_HELPER
    // HDR-mod options end


    // Clamp LOD bias so that people don't abuse this in unintended ways
    this->samplerLodBias = dxvk::fclamp(this->samplerLodBias, -2.0f, 1.0f);

    auto cachedDynamicResources = config.getOption<std::string>("d3d11.cachedDynamicResources", std::string());

    if (IsAPITracingDXGI()) {
      // apitrace reads back all mapped resources on the CPU, so
      // allocating everything in cached memory is necessary to
      // achieve acceptable performance
      this->cachedDynamicResources = ~0u;
    } else {
      this->cachedDynamicResources = 0u;

      for (char c : cachedDynamicResources) {
        switch (c) {
          case 'c': this->cachedDynamicResources |= D3D11_BIND_CONSTANT_BUFFER;   break;
          case 'v': this->cachedDynamicResources |= D3D11_BIND_VERTEX_BUFFER;     break;
          case 'i': this->cachedDynamicResources |= D3D11_BIND_INDEX_BUFFER;      break;
          case 'r': this->cachedDynamicResources |= D3D11_BIND_SHADER_RESOURCE;   break;
          case 'a': this->cachedDynamicResources  = ~0u;                          break;
          default:  Logger::warn(str::format("Unknown flag for d3d11.cachedDynamicResources option: ", c));
        }
      }
    }

    // Shader dump path is only available via an environment variable
    this->shaderDumpPath = env::getEnvVar("DXVK_SHADER_DUMP_PATH");
  }
  
}