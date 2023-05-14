#include "d3d9_options.h"

#include "d3d9_caps.h"

namespace dxvk {

  D3DFORMAT D3DFMT_UpgradeHelper(const std::string str) {
    if (str == "false")
      return D3DFMT_UNKNOWN;
    else if (str == "rgba16")
      return D3DFMT_A16B16G16R16;
    else if (str == "rgb10a2")
      return D3DFMT_A2B10G10R10;
    else if (str == "bgr10a2")
      return D3DFMT_A2R10G10B10;
    else
      return D3DFMT_A16B16G16R16F;
  }

  VkFormat VkFormat_UpgradeHelper(const std::string str) {
    if (str == "false")
      return VK_FORMAT_UNDEFINED;
    else if (str == "rgba16")
      return VK_FORMAT_R16G16B16A16_UNORM;
    else if (str == "rgb10a2")
      return VK_FORMAT_A2B10G10R10_UNORM_PACK32;
    else if (str == "bgr10a2")
      return VK_FORMAT_A2R10G10B10_UNORM_PACK32;
    else
      return VK_FORMAT_R16G16B16A16_SFLOAT;
  }

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

    const int32_t vendorId = this->customDeviceId != -1
      ? this->customDeviceId
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
    this->supportD32                    = config.getOption<bool>        ("d3d9.supportD32",                    true);
    this->useD32forD24                  = config.getOption<bool>        ("d3d9.useD32forD24",                  false);
    this->disableA8RT                   = config.getOption<bool>        ("d3d9.disableA8RT",                   false);
    this->invariantPosition             = config.getOption<bool>        ("d3d9.invariantPosition",             true);
    this->memoryTrackTest               = config.getOption<bool>        ("d3d9.memoryTrackTest",               false);
    this->supportVCache                 = config.getOption<bool>        ("d3d9.supportVCache",                 vendorId == 0x10de);
    this->enableDialogMode              = config.getOption<bool>        ("d3d9.enableDialogMode",              false);
    this->forceSamplerTypeSpecConstants = config.getOption<bool>        ("d3d9.forceSamplerTypeSpecConstants", false);
    this->forceSwapchainMSAA            = config.getOption<int32_t>     ("d3d9.forceSwapchainMSAA",            -1);
    this->forceSampleRateShading        = config.getOption<bool>        ("d3d9.forceSampleRateShading",        false);
    this->forceAspectRatio              = config.getOption<std::string> ("d3d9.forceAspectRatio",              "");
    this->allowDiscard                  = config.getOption<bool>        ("d3d9.allowDiscard",                  true);
    this->enumerateByDisplays           = config.getOption<bool>        ("d3d9.enumerateByDisplays",           true);
    this->longMad                       = config.getOption<bool>        ("d3d9.longMad",                       false);
    this->tearFree                      = config.getOption<Tristate>    ("d3d9.tearFree",                      Tristate::Auto);
    this->apitraceMode                  = config.getOption<bool>        ("d3d9.apitraceMode",                  false);
    this->deviceLocalConstantBuffers    = config.getOption<bool>        ("d3d9.deviceLocalConstantBuffers",    false);
    this->allowDirectBufferMapping      = config.getOption<bool>        ("d3d9.allowDirectBufferMapping",      true);
    this->seamlessCubes                 = config.getOption<bool>        ("d3d9.seamlessCubes",                 false);
    this->textureMemory                 = config.getOption<int32_t>     ("d3d9.textureMemory",                 100) << 20;
    this->deviceLost                    = config.getOption<bool>        ("d3d9.deviceLost",                    false);

    this->upgradeRenderTargets                 = config.getOption<bool>        ("d3d9.upgradeRenderTargets",          false);
    this->upgradeOutputFormat                  = config.getOption<bool>        ("d3d9.upgradeOutputFormat",           false);
    this->upgradeOutputFormatInternal          = config.getOption<bool>        ("d3d9.upgradeOutputFormatInternal",   false);
    this->enforceWindowModeInternally          = config.getOption<std::string> ("d3d9.enforceWindowModeInternally",   "");
    this->logFormatsUsed                       = config.getOption<bool>        ("d3d9.logFormatsUsed",                false);


    this->upgradeOutputFormatTo =
      VkFormat_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeOutputFormatTo", "rgba16f")));
    this->upgradeOutputFormatInternalTo =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeOutputFormatInternalTo", "rgba16f")));

    std::string strUpgradeOutputColorSpaceTo = Config::toLower(config.getOption<std::string>("d3d9.upgradeOutputColorSpaceTo", "scRGB"));
    if (strUpgradeOutputColorSpaceTo == "pq")
      this->upgradeOutputColorSpaceTo = VK_COLOR_SPACE_HDR10_ST2084_EXT;
    else if (strUpgradeOutputColorSpaceTo == "bt2020_linear")
      this->upgradeOutputColorSpaceTo = VK_COLOR_SPACE_BT2020_LINEAR_EXT;
    else if (strUpgradeOutputColorSpaceTo == "bt709_non_linear")
      this->upgradeOutputColorSpaceTo = VK_COLOR_SPACE_BT709_NONLINEAR_EXT;
    else if (strUpgradeOutputColorSpaceTo == "srgb")
      this->upgradeOutputColorSpaceTo = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
    else
      this->upgradeOutputColorSpaceTo = VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT;

    this->upgrade_A8B8G8R8_to =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeRT_RGBA8_to",   "rgba16f")));
    this->upgrade_X8B8G8R8_to =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeRT_RGBX8_to",   "rgba16f")));
    this->upgrade_A8R8G8B8_to =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeRT_BGRA8_to",   "rgba16f")));
    this->upgrade_X8R8G8B8_to =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeRT_BGRX8_to",   "rgba16f")));
    this->upgrade_A2B10G10R10_to =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeRT_RGB10A2_to", "rgba16f")));
    this->upgrade_A2R10G10B10_to =
      D3DFMT_UpgradeHelper(Config::toLower(config.getOption<std::string>("d3d9.upgradeRT_BGR10A2_to", "rgba16f")));

    std::string floatEmulation = Config::toLower(config.getOption<std::string>("d3d9.floatEmulation", "auto"));
    if (floatEmulation == "strict") {
      d3d9FloatEmulation = D3D9FloatEmulation::Strict;
    } else if (floatEmulation == "false") {
      d3d9FloatEmulation = D3D9FloatEmulation::Disabled;
    } else if (floatEmulation == "true") {
      d3d9FloatEmulation = D3D9FloatEmulation::Enabled;
    } else {
      bool hasMulz = adapter != nullptr
                  && adapter->matchesDriver(VK_DRIVER_ID_MESA_RADV, 0, 0);
      d3d9FloatEmulation = hasMulz ? D3D9FloatEmulation::Strict : D3D9FloatEmulation::Enabled;
    }

    this->shaderDumpPath = env::getEnvVar("DXVK_SHADER_DUMP_PATH");
  }

}