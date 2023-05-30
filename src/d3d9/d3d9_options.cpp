#include "../util/util_math.h"

#include "d3d9_options.h"

#include "d3d9_caps.h"

namespace dxvk {

  //HDR-mod helpers start
  D3DFORMAT D3DFMT_UpgradeHelper(
    const std::string format,
    const D3DFORMAT   originalFormat,
    const bool        isSwapchainFormat)
  {
    if (format == "disabled") {
      return originalFormat;
    }
    else if (originalFormat != D3DFMT_A16B16G16R16
          || originalFormat != D3DFMT_A16B16G16R16F)
    {
      if (format == "rgb10a2") {
        return D3DFMT_A2B10G10R10;
      }
      else if (format == "bgr10a2") {
        return D3DFMT_A2R10G10B10;
      }
      else if (format == "rgba16") {
        return D3DFMT_A16B16G16R16;
      }
    }
    else if (format == "rgba32f" && !isSwapchainFormat) {
      return D3DFMT_A32B32G32R32F;
    }
    else {
      return D3DFMT_A16B16G16R16F;
    }
  }

  VkFormat VkFormat_UpgradeHelper(const std::string format)
  {
    if (format == "disabled") {
      return VK_FORMAT_UNDEFINED;
    }
    else if (format == "rgb10a2") {
      return VK_FORMAT_A2B10G10R10_UNORM_PACK32;
    }
    else if (format == "bgr10a2") {
      return VK_FORMAT_A2R10G10B10_UNORM_PACK32;
    }
    else if (format == "rgba16") {
      return VK_FORMAT_R16G16B16A16_UNORM;
    }
    else {
      return VK_FORMAT_R16G16B16A16_SFLOAT;
    }
  }

  VkColorSpaceKHR VkColorSpace_UpgradeHelper(const std::string colorSpace)
  {
    if (colorSpace == "disabled") {
      return VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
    }
    else if (colorSpace == "bt709_non_linear") {
      return VK_COLOR_SPACE_BT709_NONLINEAR_EXT;
    }
    else if (colorSpace == "pq") {
      return VK_COLOR_SPACE_HDR10_ST2084_EXT;
    }
    else if (colorSpace == "bt2020_linear") {
      return VK_COLOR_SPACE_BT2020_LINEAR_EXT;
    }
    else {
      return VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT;
    }
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
      this->enableSwapchainUpgrade = false;
    }


    this->upgradeSwapchainFormatInternalTo =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeSwapchainFormatInternalTo", "rgba16f")),
                           D3DFMT_UNKNOWN,
                           true);
    if (this->upgradeSwapchainFormatInternalTo == D3DFMT_UNKNOWN) {
      this->enableSwapchainFormatUpgradeInternal = false;
    }

    this->upgrade_RGBA8_renderTargetTo =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgrade_RGBA8_renderTargetTo", "rgba16f")),
                           D3DFMT_A8B8G8R8,
                           false);
    this->upgrade_RGBX8_renderTargetTo =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgrade_RGBX8_renderTargetTo", "rgba16f")),
                           D3DFMT_X8B8G8R8,
                           false);
    this->upgrade_BGRA8_renderTargetTo =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgrade_BGRA8_renderTargetTo", "rgba16f")),
                           D3DFMT_A8R8G8B8,
                           false);
    this->upgrade_BGRX8_renderTargetTo =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgrade_BGRX8_renderTargetTo", "rgba16f")),
                           D3DFMT_X8R8G8B8,
                           false);
    this->upgrade_RGB10A2_renderTargetTo =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgrade_RGB10A2_renderTargetTo", "rgba16f")),
                           D3DFMT_A2B10G10R10,
                           false);
    this->upgrade_BGR10A2_renderTargetTo =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgrade_BGR10A2_renderTargetTo", "rgba16f")),
                           D3DFMT_A2R10G10B10,
                           false);
    this->upgrade_RGBA16_renderTargetTo = /*default to rgba16f for memory budget reasons*/
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgrade_RGBA16_renderTargetTo", "rgba16f")),
                           D3DFMT_A16B16G16R16,
                           false);
    this->upgrade_RGBA16F_renderTargetTo = /*default to disabled for memory budget reasons*/
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgrade_RGBA16F_renderTargetTo", "disabled")),
                           D3DFMT_A16B16G16R16F,
                           false);

    std::string strEnforceWindowModeInternally =
      Config::toLower(config.getOption<std::string>("d3d9.enforceWindowModeInternally", "disabled"));
    if (strEnforceWindowModeInternally == "windowed"
     || strEnforceWindowModeInternally == "fullscreen") {
      this->enforceWindowModeInternally = true;
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
