#include "../util/util_math.h"

#include "d3d9_options.h"

#include "d3d9_caps.h"

namespace dxvk {

  //HDR-mod helpers start
  std::string GetD3DFormatAsString(
    const D3DFORMAT format)
  {
    return
      format == D3DFMT_UNKNOWN             ? "D3DFMT_UNKNOWN            "
    : format == D3DFMT_R8G8B8              ? "D3DFMT_R8G8B8             "
    : format == D3DFMT_A8R8G8B8            ? "D3DFMT_A8R8G8B8           "
    : format == D3DFMT_X8R8G8B8            ? "D3DFMT_X8R8G8B8           "
    : format == D3DFMT_R5G6B5              ? "D3DFMT_R5G6B5             "
    : format == D3DFMT_X1R5G5B5            ? "D3DFMT_X1R5G5B5           "
    : format == D3DFMT_A1R5G5B5            ? "D3DFMT_A1R5G5B5           "
    : format == D3DFMT_A4R4G4B4            ? "D3DFMT_A4R4G4B4           "
    : format == D3DFMT_R3G3B2              ? "D3DFMT_R3G3B2             "
    : format == D3DFMT_A8                  ? "D3DFMT_A8                 "
    : format == D3DFMT_A8R3G3B2            ? "D3DFMT_A8R3G3B2           "
    : format == D3DFMT_X4R4G4B4            ? "D3DFMT_X4R4G4B4           "
    : format == D3DFMT_A2B10G10R10         ? "D3DFMT_A2B10G10R10        "
    : format == D3DFMT_A8B8G8R8            ? "D3DFMT_A8B8G8R8           "
    : format == D3DFMT_X8B8G8R8            ? "D3DFMT_X8B8G8R8           "
    : format == D3DFMT_G16R16              ? "D3DFMT_G16R16             "
    : format == D3DFMT_A2R10G10B10         ? "D3DFMT_A2R10G10B10        "
    : format == D3DFMT_A16B16G16R16        ? "D3DFMT_A16B16G16R16       "
    : format == D3DFMT_A8P8                ? "D3DFMT_A8P8               "
    : format == D3DFMT_P8                  ? "D3DFMT_P8                 "
    : format == D3DFMT_L8                  ? "D3DFMT_L8                 "
    : format == D3DFMT_A8L8                ? "D3DFMT_A8L8               "
    : format == D3DFMT_A4L4                ? "D3DFMT_A4L4               "
    : format == D3DFMT_V8U8                ? "D3DFMT_V8U8               "
    : format == D3DFMT_L6V5U5              ? "D3DFMT_L6V5U5             "
    : format == D3DFMT_X8L8V8U8            ? "D3DFMT_X8L8V8U8           "
    : format == D3DFMT_Q8W8V8U8            ? "D3DFMT_Q8W8V8U8           "
    : format == D3DFMT_V16U16              ? "D3DFMT_V16U16             "
    : format == D3DFMT_A2W10V10U10         ? "D3DFMT_A2W10V10U10        "
    : format == D3DFMT_UYVY                ? "D3DFMT_UYVY               "
    : format == D3DFMT_R8G8_B8G8           ? "D3DFMT_R8G8_B8G8          "
    : format == D3DFMT_YUY2                ? "D3DFMT_YUY2               "
    : format == D3DFMT_G8R8_G8B8           ? "D3DFMT_G8R8_G8B8          "
    : format == D3DFMT_DXT1                ? "D3DFMT_DXT1               "
    : format == D3DFMT_DXT2                ? "D3DFMT_DXT2               "
    : format == D3DFMT_DXT3                ? "D3DFMT_DXT3               "
    : format == D3DFMT_DXT4                ? "D3DFMT_DXT4               "
    : format == D3DFMT_DXT5                ? "D3DFMT_DXT5               "
    : format == D3DFMT_D16_LOCKABLE        ? "D3DFMT_D16_LOCKABLE       "
    : format == D3DFMT_D32                 ? "D3DFMT_D32                "
    : format == D3DFMT_D15S1               ? "D3DFMT_D15S1              "
    : format == D3DFMT_D24S8               ? "D3DFMT_D24S8              "
    : format == D3DFMT_D24X8               ? "D3DFMT_D24X8              "
    : format == D3DFMT_D24X4S4             ? "D3DFMT_D24X4S4            "
    : format == D3DFMT_D16                 ? "D3DFMT_D16                "
    : format == D3DFMT_D32F_LOCKABLE       ? "D3DFMT_D32F_LOCKABLE      "
    : format == D3DFMT_D24FS8              ? "D3DFMT_D24FS8             "
    : format == D3DFMT_D32_LOCKABLE        ? "D3DFMT_D32_LOCKABLE       "
    : format == D3DFMT_S8_LOCKABLE         ? "D3DFMT_S8_LOCKABLE        "
    : format == D3DFMT_L16                 ? "D3DFMT_L16                "
    : format == D3DFMT_VERTEXDATA          ? "D3DFMT_VERTEXDATA         "
    : format == D3DFMT_INDEX16             ? "D3DFMT_INDEX16            "
    : format == D3DFMT_INDEX32             ? "D3DFMT_INDEX32            "
    : format == D3DFMT_Q16W16V16U16        ? "D3DFMT_Q16W16V16U16       "
    : format == D3DFMT_MULTI2_ARGB8        ? "D3DFMT_MULTI2_ARGB8       "
    : format == D3DFMT_R16F                ? "D3DFMT_R16F               "
    : format == D3DFMT_G16R16F             ? "D3DFMT_G16R16F            "
    : format == D3DFMT_A16B16G16R16F       ? "D3DFMT_A16B16G16R16F      "
    : format == D3DFMT_R32F                ? "D3DFMT_R32F               "
    : format == D3DFMT_G32R32F             ? "D3DFMT_G32R32F            "
    : format == D3DFMT_A32B32G32R32F       ? "D3DFMT_A32B32G32R32F      "
    : format == D3DFMT_CxV8U8              ? "D3DFMT_CxV8U8             "
    : format == D3DFMT_A1                  ? "D3DFMT_A1                 "
    : format == D3DFMT_A2B10G10R10_XR_BIAS ? "D3DFMT_A2B10G10R10_XR_BIAS"
    : format == D3DFMT_BINARYBUFFER        ? "D3DFMT_BINARYBUFFER       "
    : "wth";
  }


  D3DFORMAT D3DFMT_UpgradeHelper(
    const std::string format,
    const D3DFORMAT   originalFormat,
    const bool        isSwapchainFormat)
  {
    D3DFORMAT upgradedFormat;

#define GET_FMT_UPGRADE(if_, targetFormat, upgradedD3DFMT) \
          if_ (format == targetFormat                      \
            && upgradedD3DFMT > originalFormat)            \
          {                                                \
            upgradedFormat = upgradedD3DFMT;               \
          }

    GET_FMT_UPGRADE(if,      "rgb10a2", D3DFMT_A2B10G10R10)
    GET_FMT_UPGRADE(else if, "bgr10a2", D3DFMT_A2R10G10B10)
    GET_FMT_UPGRADE(else if, "rgba16",  D3DFMT_A16B16G16R16)
    GET_FMT_UPGRADE(else if, "rgba16f", D3DFMT_A16B16G16R16F)
    GET_FMT_UPGRADE(else if, "rgba32f", D3DFMT_A32B32G32R32F)
    else {
      Logger::info(str::format("D3D9: render target upgrade disabled for: ",
                   GetD3DFormatAsString(originalFormat)));
      return originalFormat;
    }

    if (!isSwapchainFormat) {
      Logger::info(str::format("D3D9: render target upgrade enabled for:  ",
                               GetD3DFormatAsString(originalFormat),
                               " -> ",
                               GetD3DFormatAsString(upgradedFormat)));
      return upgradedFormat;
    }
    else if (isSwapchainFormat) {
      if (upgradedFormat == D3DFMT_A32B32G32R32F) {
        upgradedFormat = D3DFMT_A16B16G16R16F;
      }
      Logger::info(str::format("D3D9: render target upgrade enabled for:  ",
                               GetD3DFormatAsString(originalFormat),
                               " -> ",
                               GetD3DFormatAsString(upgradedFormat)));
      return upgradedFormat;
    }
    else {
      Logger::info(str::format("D3D9: render target upgrade disabled for: ",
                               GetD3DFormatAsString(originalFormat)));
      return originalFormat;
    }


#undef CHECK_FMT_UPGRADE

  }

  VkFormat VkFormat_UpgradeHelper(const std::string format)
  {
    VkFormat upgradedFormat;
    if (format == "rgb10a2") {
      upgradedFormat = VK_FORMAT_A2B10G10R10_UNORM_PACK32;
    }
    else if (format == "bgr10a2") {
      upgradedFormat = VK_FORMAT_A2R10G10B10_UNORM_PACK32;
    }
    else if (format == "rgba16") {
      upgradedFormat = VK_FORMAT_R16G16B16A16_UNORM;
    }
    else if (format == "rgba16f") {
      upgradedFormat = VK_FORMAT_R16G16B16A16_SFLOAT;
    }
    else {
      upgradedFormat = VK_FORMAT_UNDEFINED;
    }
    if (upgradedFormat != VK_FORMAT_UNDEFINED) {
      Logger::info(str::format("D3D9: swapchain format will be upgraded to: ",
                               upgradedFormat));
    }
    else {
      Logger::info("D3D9: swapchain format upgrade disabled");
    }
    return upgradedFormat;
  }

  VkColorSpaceKHR VkColorSpace_UpgradeHelper(const std::string colorSpace)
  {
    VkColorSpaceKHR upgradeColorspace;
    if (colorSpace == "bt709_non_linear") {
      upgradeColorspace = VK_COLOR_SPACE_BT709_NONLINEAR_EXT;
    }
    else if (colorSpace == "pq") {
      upgradeColorspace = VK_COLOR_SPACE_HDR10_ST2084_EXT;
    }
    else if (colorSpace == "bt2020_linear") {
      upgradeColorspace = VK_COLOR_SPACE_BT2020_LINEAR_EXT;
    }
    else if (colorSpace == "scrgb") {
      upgradeColorspace = VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT;
    }
    else {
      upgradeColorspace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
    }
    if (upgradeColorspace != VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
      Logger::info(str::format("D3D9: swapchain colorspace will be upgraded to: ",
                               upgradeColorspace));
    }
    else {
      Logger::info("D3D9: swapchain colorspace upgrade disabled");
    }
    return upgradeColorspace;
  }

#if defined(_MSC_VER)
  BOOL
#else
  WINBOOL
#endif
          D3D9_WindowModeHelper(const std::string windowMode)
  {
    if (windowMode == "windowed")
      return TRUE;
    else
      return FALSE;
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
    this->enableDialogMode              = config.getOption<bool>        ("d3d9.enableDialogMode",              false);
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

    //HDR-mod start
    this->enableRenderTargetUpgrade            = config.getOption<bool> ("d3d9.enableRenderTargetUpgrade",            false);
    this->enableSwapchainUpgrade               = config.getOption<bool> ("d3d9.enableSwapchainUpgrade",               false);
    this->enableSwapchainFormatUpgradeInternal = config.getOption<bool> ("d3d9.enableSwapchainFormatUpgradeInternal", false);
    this->logRenderTargetFormatsUsed           = config.getOption<bool> ("d3d9.logRenderTargetFormatsUsed",           false);
    this->logFormatsUsed                       = config.getOption<bool> ("d3d9.logFormatsUsed",                       false);


    this->upgradeSwapchainFormatTo =
      VkFormat_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeSwapchainFormatTo", "rgba16f")));
    this->upgradeSwapchainColorSpaceTo =
      VkColorSpace_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeSwapchainColorSpaceTo", "scRGB")));
    if (this->upgradeSwapchainFormatTo     == VK_FORMAT_UNDEFINED
     || this->upgradeSwapchainColorSpaceTo == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
      Logger::info("D3D9: swapchain upgrade disabled");
      this->enableSwapchainUpgrade = false;
    }


    this->upgradeSwapchainFormatInternalTo =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeSwapchainFormatInternalTo", "disabled")),
                           D3DFMT_UNKNOWN,
                           true);
    if (this->upgradeSwapchainFormatInternalTo == D3DFMT_UNKNOWN) {
      this->enableSwapchainFormatUpgradeInternal = false;
    }


#define D3DFMT_UPGRADE_HELPER(cfgString, originalFormat)                                                                    \
          D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgrade_" cfgString "_To", "disabled")), \
                               originalFormat,                                                                              \
                               false)

    this->upgrade_RGBA8_To =
      D3DFMT_UPGRADE_HELPER("RGBA8",   D3DFMT_A8B8G8R8);
    this->upgrade_RGBX8_To =
      D3DFMT_UPGRADE_HELPER("RGBX8",   D3DFMT_X8B8G8R8);
    this->upgrade_BGRA8_To =
      D3DFMT_UPGRADE_HELPER("BGRA8",   D3DFMT_A8R8G8B8);
    this->upgrade_BGRX8_To =
      D3DFMT_UPGRADE_HELPER("BGRX8",   D3DFMT_X8R8G8B8);
    this->upgrade_RGB10A2_To =
      D3DFMT_UPGRADE_HELPER("RGB10A2", D3DFMT_A2B10G10R10);
    this->upgrade_BGR10A2_To =
      D3DFMT_UPGRADE_HELPER("BGR10A2", D3DFMT_A2R10G10B10);
    this->upgrade_RGBA16_To =
      D3DFMT_UPGRADE_HELPER("RGBA16",  D3DFMT_A16B16G16R16);
    this->upgrade_RGBA16F_To =
      D3DFMT_UPGRADE_HELPER("RGBA16F", D3DFMT_A16B16G16R16F);

#undef D3DFMT_UPGRADE_HELPER

    std::string strEnforceWindowModeInternally =
      Config::toLower(config.getOption<std::string>("d3d9.enforceWindowModeInternally", "disabled"));
    if (strEnforceWindowModeInternally == "windowed"
     || strEnforceWindowModeInternally == "fullscreen") {
      this->enforceWindowModeInternally = true;
      Logger::info(str::format("D3D9: ",
                               strEnforceWindowModeInternally,
                               "will be enforced"));
    }
    else {
      this->enforceWindowModeInternally = false;
    }
    this->enforcedWindowModeInternally = D3D9_WindowModeHelper(strEnforceWindowModeInternally);
    //HDR-mod end


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
