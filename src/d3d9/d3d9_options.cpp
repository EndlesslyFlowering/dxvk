#include "../util/util_math.h"

#include "d3d9_options.h"

#include "d3d9_caps.h"

namespace dxvk {

  //HDR-mod helpers start
  std::string GetD3DFormatAsString(
    const D3DFORMAT Format)
  {
    return
      Format == D3DFMT_UNKNOWN             ? "D3DFMT_UNKNOWN            "
    : Format == D3DFMT_R8G8B8              ? "D3DFMT_R8G8B8             "
    : Format == D3DFMT_A8R8G8B8            ? "D3DFMT_A8R8G8B8           "
    : Format == D3DFMT_X8R8G8B8            ? "D3DFMT_X8R8G8B8           "
    : Format == D3DFMT_R5G6B5              ? "D3DFMT_R5G6B5             "
    : Format == D3DFMT_X1R5G5B5            ? "D3DFMT_X1R5G5B5           "
    : Format == D3DFMT_A1R5G5B5            ? "D3DFMT_A1R5G5B5           "
    : Format == D3DFMT_A4R4G4B4            ? "D3DFMT_A4R4G4B4           "
    : Format == D3DFMT_R3G3B2              ? "D3DFMT_R3G3B2             "
    : Format == D3DFMT_A8                  ? "D3DFMT_A8                 "
    : Format == D3DFMT_A8R3G3B2            ? "D3DFMT_A8R3G3B2           "
    : Format == D3DFMT_X4R4G4B4            ? "D3DFMT_X4R4G4B4           "
    : Format == D3DFMT_A2B10G10R10         ? "D3DFMT_A2B10G10R10        "
    : Format == D3DFMT_A8B8G8R8            ? "D3DFMT_A8B8G8R8           "
    : Format == D3DFMT_X8B8G8R8            ? "D3DFMT_X8B8G8R8           "
    : Format == D3DFMT_G16R16              ? "D3DFMT_G16R16             "
    : Format == D3DFMT_A2R10G10B10         ? "D3DFMT_A2R10G10B10        "
    : Format == D3DFMT_A16B16G16R16        ? "D3DFMT_A16B16G16R16       "
    : Format == D3DFMT_A8P8                ? "D3DFMT_A8P8               "
    : Format == D3DFMT_P8                  ? "D3DFMT_P8                 "
    : Format == D3DFMT_L8                  ? "D3DFMT_L8                 "
    : Format == D3DFMT_A8L8                ? "D3DFMT_A8L8               "
    : Format == D3DFMT_A4L4                ? "D3DFMT_A4L4               "
    : Format == D3DFMT_V8U8                ? "D3DFMT_V8U8               "
    : Format == D3DFMT_L6V5U5              ? "D3DFMT_L6V5U5             "
    : Format == D3DFMT_X8L8V8U8            ? "D3DFMT_X8L8V8U8           "
    : Format == D3DFMT_Q8W8V8U8            ? "D3DFMT_Q8W8V8U8           "
    : Format == D3DFMT_V16U16              ? "D3DFMT_V16U16             "
    : Format == D3DFMT_A2W10V10U10         ? "D3DFMT_A2W10V10U10        "
    : Format == D3DFMT_UYVY                ? "D3DFMT_UYVY               "
    : Format == D3DFMT_R8G8_B8G8           ? "D3DFMT_R8G8_B8G8          "
    : Format == D3DFMT_YUY2                ? "D3DFMT_YUY2               "
    : Format == D3DFMT_G8R8_G8B8           ? "D3DFMT_G8R8_G8B8          "
    : Format == D3DFMT_DXT1                ? "D3DFMT_DXT1               "
    : Format == D3DFMT_DXT2                ? "D3DFMT_DXT2               "
    : Format == D3DFMT_DXT3                ? "D3DFMT_DXT3               "
    : Format == D3DFMT_DXT4                ? "D3DFMT_DXT4               "
    : Format == D3DFMT_DXT5                ? "D3DFMT_DXT5               "
    : Format == D3DFMT_D16_LOCKABLE        ? "D3DFMT_D16_LOCKABLE       "
    : Format == D3DFMT_D32                 ? "D3DFMT_D32                "
    : Format == D3DFMT_D15S1               ? "D3DFMT_D15S1              "
    : Format == D3DFMT_D24S8               ? "D3DFMT_D24S8              "
    : Format == D3DFMT_D24X8               ? "D3DFMT_D24X8              "
    : Format == D3DFMT_D24X4S4             ? "D3DFMT_D24X4S4            "
    : Format == D3DFMT_D16                 ? "D3DFMT_D16                "
    : Format == D3DFMT_D32F_LOCKABLE       ? "D3DFMT_D32F_LOCKABLE      "
    : Format == D3DFMT_D24FS8              ? "D3DFMT_D24FS8             "
    : Format == D3DFMT_D32_LOCKABLE        ? "D3DFMT_D32_LOCKABLE       "
    : Format == D3DFMT_S8_LOCKABLE         ? "D3DFMT_S8_LOCKABLE        "
    : Format == D3DFMT_L16                 ? "D3DFMT_L16                "
    : Format == D3DFMT_VERTEXDATA          ? "D3DFMT_VERTEXDATA         "
    : Format == D3DFMT_INDEX16             ? "D3DFMT_INDEX16            "
    : Format == D3DFMT_INDEX32             ? "D3DFMT_INDEX32            "
    : Format == D3DFMT_Q16W16V16U16        ? "D3DFMT_Q16W16V16U16       "
    : Format == D3DFMT_MULTI2_ARGB8        ? "D3DFMT_MULTI2_ARGB8       "
    : Format == D3DFMT_R16F                ? "D3DFMT_R16F               "
    : Format == D3DFMT_G16R16F             ? "D3DFMT_G16R16F            "
    : Format == D3DFMT_A16B16G16R16F       ? "D3DFMT_A16B16G16R16F      "
    : Format == D3DFMT_R32F                ? "D3DFMT_R32F               "
    : Format == D3DFMT_G32R32F             ? "D3DFMT_G32R32F            "
    : Format == D3DFMT_A32B32G32R32F       ? "D3DFMT_A32B32G32R32F      "
    : Format == D3DFMT_CxV8U8              ? "D3DFMT_CxV8U8             "
    : Format == D3DFMT_A1                  ? "D3DFMT_A1                 "
    : Format == D3DFMT_A2B10G10R10_XR_BIAS ? "D3DFMT_A2B10G10R10_XR_BIAS"
    : Format == D3DFMT_BINARYBUFFER        ? "D3DFMT_BINARYBUFFER       "
    : "wth";
  }

  bool IsSensibleFormatUpgrade(
    const D3DFORMAT OriginalFormat,
    const D3DFORMAT UpgradedFormat)
  {
    bool returnBool = false;
    if ((OriginalFormat == D3DFMT_A2B10G10R10 || OriginalFormat == D3DFMT_A2R10G10B10)
     && UpgradedFormat < D3DFMT_A16B16G16R16) {
      returnBool = false;
    }
    else if (OriginalFormat == D3DFMT_A16B16G16R16 && UpgradedFormat < D3DFMT_A16B16G16R16F) {
      returnBool = false;
    }
    else if (OriginalFormat == D3DFMT_A16B16G16R16F && UpgradedFormat < D3DFMT_A32B32G32R32F) {
      returnBool = false;
    }
    else {
      returnBool = true;
    }

    if (!returnBool) {
      Logger::info(str::format("D3D9: it makes no sense to upgrade: ",
                               GetD3DFormatAsString(OriginalFormat),
                               " to ",
                               GetD3DFormatAsString(UpgradedFormat), " !!"));
    }

    return returnBool;
  }

  void D3DFORMAT_UpgradeHelper(
    const std::string                 Format,
    const D3DFORMAT                   OriginalFormat,
          std::array<D3DFORMAT, 120>* pFormatUpgradeArray)
  {

#define GET_FORMAT_UPGRADE(if_, TargetFormat, UpgradedD3DFormat)                                              \
          if_ (Format == TargetFormat                                                                         \
            && IsSensibleFormatUpgrade(OriginalFormat, UpgradedD3DFormat))                                    \
          {                                                                                                   \
            pFormatUpgradeArray->at(static_cast<size_t>(OriginalFormat)) = UpgradedD3DFormat;                 \
          }

    GET_FORMAT_UPGRADE(if,      "rgb10a2_unorm", D3DFMT_A2B10G10R10)
    GET_FORMAT_UPGRADE(else if, "bgr10a2_unorm", D3DFMT_A2R10G10B10)
    GET_FORMAT_UPGRADE(else if, "rgba16_unorm",  D3DFMT_A16B16G16R16)
    GET_FORMAT_UPGRADE(else if, "rgba16_float",  D3DFMT_A16B16G16R16F)
    GET_FORMAT_UPGRADE(else if, "rgba32_float",  D3DFMT_A32B32G32R32F)
    else {
      Logger::info(str::format("D3D9: render target upgrade disabled for: ",
                   GetD3DFormatAsString(OriginalFormat)));
      return;
    }

    Logger::info(str::format("D3D9: render target upgrade enabled for:  ",
                             GetD3DFormatAsString(OriginalFormat),
                             " -> ",
                             GetD3DFormatAsString(pFormatUpgradeArray->at(static_cast<size_t>(OriginalFormat)))));
    return;

#undef GET_FORMAT_UPGRADE

  }

  D3DFORMAT BackBufferFormatUpgradeHelper(const std::string Format)
  {
    D3DFORMAT upgradedFormat;
    if (Format == "rgb10a2_unorm") {
      upgradedFormat = D3DFMT_A2B10G10R10;
    }
    else if (Format == "bgr10a2_unorm") {
      upgradedFormat = D3DFMT_A2R10G10B10;
    }
    else if (Format == "rgba16_unorm") {
      upgradedFormat = D3DFMT_A16B16G16R16;
    }
    else if (Format == "rgba16_float") {
      upgradedFormat = D3DFMT_A16B16G16R16F;
    }
    else {
      upgradedFormat = D3DFMT_UNKNOWN;
    }
    if (upgradedFormat != D3DFMT_UNKNOWN) {
      Logger::info(str::format("D3D9: back buffer format will be upgraded to: ",
                               GetD3DFormatAsString(upgradedFormat)));
    }
    else {
      Logger::info("D3D9: back buffer format upgrade disabled");
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
      Logger::info("DXVK (D3D9): swap chain format will stay unchanged");
    }
    else if (upgradedFormat != VK_FORMAT_UNDEFINED) {
      Logger::info(str::format("DXVK (D3D9): swap chain format will be upgraded to:      ",
                               upgradedFormat));
    }
    else {
      Logger::info("DXVK (D3D9): swap chain format upgrade disabled");
    }
    return upgradedFormat;
  }

  VkColorSpaceKHR VkColorSpace_UpgradeHelper(const std::string ColorSpace)
  {
    VkColorSpaceKHR upgradedColorSpace;
    if (ColorSpace == "bt709_non_linear") {
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
      Logger::info("DXVK (D3D9): swap chain color space will stay unchanged");
    }
    else if (upgradedColorSpace != VK_COLOR_SPACE_MAX_ENUM_KHR) {
      Logger::info(str::format("DXVK (D3D9): swap chain color space will be upgraded to: ",
                               upgradedColorSpace));
    }
    else {
      Logger::info("DXVK (D3D9): swap chain color space upgrade disabled");
    }
    return upgradedColorSpace;
  }

#if defined(_MSC_VER)
  BOOL
#else
  WINBOOL
#endif
          D3D9_WindowModeHelper(const std::string WindowMode)
  {
    if (WindowMode == "windowed") {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }
  //HDR-mod helpers end

  static int32_t parsePciId(const std::string& str) {
    if (str.size() != 4)
      return -1;
    
    int32_t id = 0;

    for (size_t i = 0; i < str.size(); i++) {
      id *= 16;

      if (str[i] >= '0' && str[i] <= '9')
        id += str[i] - '0';
      else if (str[i] >= 'A' && str[i] <= 'F')
        id += str[i] - 'A' + 10;
      else if (str[i] >= 'a' && str[i] <= 'f')
        id += str[i] - 'a' + 10;
      else
        return -1;
    }

    return id;
  }


  D3D9Options::D3D9Options(const Rc<DxvkDevice>& device, const Config& config) {
    const Rc<DxvkAdapter> adapter = device != nullptr ? device->adapter() : nullptr;

    // Fetch these as a string representing a hexadecimal number and parse it.
    this->customVendorId        = parsePciId(config.getOption<std::string>("d3d9.customVendorId"));
    this->customDeviceId        = parsePciId(config.getOption<std::string>("d3d9.customDeviceId"));
    this->customDeviceDesc      =            config.getOption<std::string>("d3d9.customDeviceDesc");

    const uint32_t vendorId = this->customVendorId != -1
      ? this->customVendorId
      : (adapter != nullptr ? adapter->deviceProperties().vendorID : 0);

    this->maxFrameLatency               = config.getOption<int32_t>     ("d3d9.maxFrameLatency",               0);
    this->maxFrameRate                  = config.getOption<int32_t>     ("d3d9.maxFrameRate",                  0);
    this->presentInterval               = config.getOption<int32_t>     ("d3d9.presentInterval",               -1);
    this->shaderModel                   = config.getOption<int32_t>     ("d3d9.shaderModel",                   3);
    this->dpiAware                      = config.getOption<bool>        ("d3d9.dpiAware",                      true);
    this->strictConstantCopies          = config.getOption<bool>        ("d3d9.strictConstantCopies",          false);
    this->strictPow                     = config.getOption<bool>        ("d3d9.strictPow",                     true);
    this->lenientClear                  = config.getOption<bool>        ("d3d9.lenientClear",                  false);
    this->numBackBuffers                = config.getOption<int32_t>     ("d3d9.numBackBuffers",                0);
    this->deferSurfaceCreation          = config.getOption<bool>        ("d3d9.deferSurfaceCreation",          false);
    this->samplerAnisotropy             = config.getOption<int32_t>     ("d3d9.samplerAnisotropy",             -1);
    this->maxAvailableMemory            = config.getOption<int32_t>     ("d3d9.maxAvailableMemory",            4096);
    this->supportDFFormats              = config.getOption<bool>        ("d3d9.supportDFFormats",              true);
    this->supportX4R4G4B4               = config.getOption<bool>        ("d3d9.supportX4R4G4B4",               true);
    this->supportD16Lockable            = config.getOption<bool>        ("d3d9.supportD16Lockable",            false);
    this->useD32forD24                  = config.getOption<bool>        ("d3d9.useD32forD24",                  false);
    this->disableA8RT                   = config.getOption<bool>        ("d3d9.disableA8RT",                   false);
    this->invariantPosition             = config.getOption<bool>        ("d3d9.invariantPosition",             true);
    this->memoryTrackTest               = config.getOption<bool>        ("d3d9.memoryTrackTest",               false);
    this->supportVCache                 = config.getOption<bool>        ("d3d9.supportVCache",                 vendorId == uint32_t(DxvkGpuVendor::Nvidia));
    this->forceSamplerTypeSpecConstants = config.getOption<bool>        ("d3d9.forceSamplerTypeSpecConstants", false);
    this->forceSwapchainMSAA            = config.getOption<int32_t>     ("d3d9.forceSwapchainMSAA",            -1);
    this->forceSampleRateShading        = config.getOption<bool>        ("d3d9.forceSampleRateShading",        false);
    this->forceAspectRatio              = config.getOption<std::string> ("d3d9.forceAspectRatio",              "");
    this->enumerateByDisplays           = config.getOption<bool>        ("d3d9.enumerateByDisplays",           true);
    this->cachedDynamicBuffers          = config.getOption<bool>        ("d3d9.cachedDynamicBuffers",          false);
    this->deviceLocalConstantBuffers    = config.getOption<bool>        ("d3d9.deviceLocalConstantBuffers",    false);
    this->allowDirectBufferMapping      = config.getOption<bool>        ("d3d9.allowDirectBufferMapping",      true);
    this->seamlessCubes                 = config.getOption<bool>        ("d3d9.seamlessCubes",                 false);
    this->textureMemory                 = config.getOption<int32_t>     ("d3d9.textureMemory",                 100) << 20;
    this->deviceLossOnFocusLoss         = config.getOption<bool>        ("d3d9.deviceLossOnFocusLoss",         false);
    this->samplerLodBias                = config.getOption<float>       ("d3d9.samplerLodBias",                0.0f);
    this->clampNegativeLodBias          = config.getOption<bool>        ("d3d9.clampNegativeLodBias",          false);
    this->countLosableResources         = config.getOption<bool>        ("d3d9.countLosableResources",         true);
    this->reproducibleCommandStream     = config.getOption<bool>        ("d3d9.reproducibleCommandStream",     false);

    // D3D8 options
    this->drefScaling                   = config.getOption<int32_t>     ("d3d8.scaleDref",                     0);

    // Clamp LOD bias so that people don't abuse this in unintended ways
    this->samplerLodBias = dxvk::fclamp(this->samplerLodBias, -2.0f, 1.0f);

    //HDR-mod options start
    this->enableRenderTargetUpgrades    = config.getOption<bool> ("d3d9.enableRenderTargetUpgrades",    false);
    this->enableBackBufferFormatUpgrade = config.getOption<bool> ("d3d9.enableBackBufferFormatUpgrade", false);
    this->enableSwapChainUpgrade        = config.getOption<bool> ("d3d9.enableSwapChainUpgrade",        false);
    this->logRenderTargetFormatsUsed    = config.getOption<bool> ("d3d9.logRenderTargetFormatsUsed",    false);


    this->upgradeBackBufferFormatTo =
      BackBufferFormatUpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeBackBufferFormatTo", "disabled")));
    if (this->upgradeBackBufferFormatTo == D3DFMT_UNKNOWN) {
      this->enableBackBufferFormatUpgrade = false;
    }

    this->upgradeSwapChainFormatTo =
      VkFormat_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeSwapChainFormatTo", "rgba16f")));
    this->upgradeSwapChainColorSpaceTo =
      VkColorSpace_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeSwapChainColorSpaceTo", "scRGB")));
    if (this->upgradeSwapChainFormatTo     == VK_FORMAT_UNDEFINED
     || this->upgradeSwapChainColorSpaceTo == VK_COLOR_SPACE_MAX_ENUM_KHR) {
      Logger::info("DXVK (D3D9): swap chain upgrade disabled");
      this->enableSwapChainUpgrade = false;
    }


  this->formatUpgradeArray.fill( { D3DFMT_UNKNOWN } );

#define D3DFORMAT_UPGRADE_HELPER(CfgString, OriginalFormat)                                                          \
          D3DFORMAT_UpgradeHelper(                                                                                   \
            Config::toLower(config.getOption<std::string>("d3d9.upgrade_" CfgString "_renderTargetTo", "disabled")), \
            OriginalFormat,                                                                                          \
            &this->formatUpgradeArray)

    D3DFORMAT_UPGRADE_HELPER("B5G6R5_UNORM",  D3DFMT_R5G6B5);
    D3DFORMAT_UPGRADE_HELPER("BGR5A1_UNORM",  D3DFMT_A1R5G5B5);
    D3DFORMAT_UPGRADE_HELPER("BGR5X1_UNORM",  D3DFMT_X1R5G5B5);
    D3DFORMAT_UPGRADE_HELPER("BGRA4_UNORM",   D3DFMT_A4R4G4B4);
    D3DFORMAT_UPGRADE_HELPER("BGRX4_UNORM",   D3DFMT_X4R4G4B4);
    D3DFORMAT_UPGRADE_HELPER("RGBA8_UNORM",   D3DFMT_A8B8G8R8);
    D3DFORMAT_UPGRADE_HELPER("RGBX8_UNORM",   D3DFMT_X8B8G8R8);
    D3DFORMAT_UPGRADE_HELPER("BGRA8_UNORM",   D3DFMT_A8R8G8B8);
    D3DFORMAT_UPGRADE_HELPER("BGRX8_UNORM",   D3DFMT_X8R8G8B8);
    D3DFORMAT_UPGRADE_HELPER("RGB10A2_UNORM", D3DFMT_A2B10G10R10);
    D3DFORMAT_UPGRADE_HELPER("BGR10A2_UNORM", D3DFMT_A2R10G10B10);
    D3DFORMAT_UPGRADE_HELPER("RGBA16_UNORM",  D3DFMT_A16B16G16R16);
    D3DFORMAT_UPGRADE_HELPER("RGBA16_FLOAT",  D3DFMT_A16B16G16R16F);

#undef D3DFORMAT_UPGRADE_HELPER

    std::string strEnforceWindowModeInternally =
      Config::toLower(config.getOption<std::string>("d3d9.enforceWindowModeInternally", "disabled"));
    if (strEnforceWindowModeInternally == "windowed"
     || strEnforceWindowModeInternally == "fullscreen") {
      this->enforceWindowModeInternally = true;
      Logger::info(str::format("D3D9: ",
                               strEnforceWindowModeInternally,
                               "mode will be enforced"));
    }
    else {
      this->enforceWindowModeInternally = false;
    }
    this->enforcedWindowModeInternally = D3D9_WindowModeHelper(strEnforceWindowModeInternally);
    //HDR-mod options end


    std::string floatEmulation = Config::toLower(config.getOption<std::string>("d3d9.floatEmulation", "auto"));
    if (floatEmulation == "strict") {
      d3d9FloatEmulation = D3D9FloatEmulation::Strict;
    } else if (floatEmulation == "false") {
      d3d9FloatEmulation = D3D9FloatEmulation::Disabled;
    } else if (floatEmulation == "true") {
      d3d9FloatEmulation = D3D9FloatEmulation::Enabled;
    } else {
      bool hasMulz = adapter != nullptr
                  && (adapter->matchesDriver(VK_DRIVER_ID_MESA_RADV)
                   || adapter->matchesDriver(VK_DRIVER_ID_MESA_NVK)
                   || adapter->matchesDriver(VK_DRIVER_ID_AMD_OPEN_SOURCE, Version(2, 0, 316), Version())
                   || adapter->matchesDriver(VK_DRIVER_ID_NVIDIA_PROPRIETARY, Version(565, 57, 1), Version()));
      d3d9FloatEmulation = hasMulz ? D3D9FloatEmulation::Strict : D3D9FloatEmulation::Enabled;
    }

    this->shaderDumpPath = env::getEnvVar("DXVK_SHADER_DUMP_PATH");
  }

}
