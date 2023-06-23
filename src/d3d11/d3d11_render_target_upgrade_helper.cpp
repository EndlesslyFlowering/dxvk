#include "d3d11_render_target_upgrade_helper.h"

namespace dxvk {

  DXGI_FORMAT D3D11RenderTargetUpgradeHelper::UpgradeFormat(
          DXGI_FORMAT         OriginalFormat,
          DXGI_FORMAT         UpgradedFormat,
          FORMAT_UPGRADE_TYPE UpgradeType,
          bool                LogRenderTargetFormatsUsed)
  {
    std::string upgradeString;

    if (LogRenderTargetFormatsUsed) {
      upgradeString =
        UpgradeType == FORMAT_UPGRADE_TYPE::UPGRADE_RENDER_TARGET                     ? "render target):                     "
      : UpgradeType == FORMAT_UPGRADE_TYPE::UPGRADE_RENDER_TARGET_VIEW                ? "render target view):                "
      : UpgradeType == FORMAT_UPGRADE_TYPE::UPGRADE_RESOURCE_VIEW                     ? "resource view):                     "
      : UpgradeType == FORMAT_UPGRADE_TYPE::UPGRADE_UNORDERED_ACCESS_VIEW             ? "unordered access view):             "
      : UpgradeType == FORMAT_UPGRADE_TYPE::UPGRADE_BACK_BUFFER                       ? "back buffer):                       "
      : UpgradeType == FORMAT_UPGRADE_TYPE::UPGRADE_BACK_BUFFER_RENDER_TARGET_VIEW    ? "back buffer render target view):    "
      : UpgradeType == FORMAT_UPGRADE_TYPE::UPGRADE_BACK_BUFFER_RESOURCE_VIEW         ? "back buffer resource view):         "
      : UpgradeType == FORMAT_UPGRADE_TYPE::UPGRADE_BACK_BUFFER_UNORDERED_ACCESS_VIEW ? "back buffer unordered access view): "
      : "wth";
    }

    if (UpgradedFormat != DXGI_FORMAT_UNKNOWN) {
      if (LogRenderTargetFormatsUsed) {
        Logger::info(str::format("D3D11: format upgrade (", upgradeString,
                                 GetDXGIFormatNameAsString(OriginalFormat),
                                 " -> ",
                                 GetDXGIFormatNameAsString(UpgradedFormat)));
      }
      return UpgradedFormat;
    }
    else {
      if (LogRenderTargetFormatsUsed) {
        Logger::info(str::format("D3D11: used format (", upgradeString, "   ",
                                 GetDXGIFormatNameAsString(OriginalFormat)));
      }
      return OriginalFormat;
    }
  }

}
