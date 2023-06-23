#pragma once

#include "d3d11_options.h"

namespace dxvk {

  class D3D11RenderTargetUpgradeHelper {

  public:

    enum class FORMAT_UPGRADE_TYPE {
      UPGRADE_RENDER_TARGET,
      UPGRADE_RENDER_TARGET_VIEW,
      UPGRADE_RESOURCE_VIEW,
      UPGRADE_UNORDERED_ACCESS_VIEW,
      UPGRADE_BACK_BUFFER,
      UPGRADE_BACK_BUFFER_RENDER_TARGET_VIEW,
      UPGRADE_BACK_BUFFER_RESOURCE_VIEW,
      UPGRADE_BACK_BUFFER_UNORDERED_ACCESS_VIEW,
    };

    static DXGI_FORMAT UpgradeFormat(
            DXGI_FORMAT         OriginalFormat,
            DXGI_FORMAT         UpgradedFormat,
            FORMAT_UPGRADE_TYPE UpgradeType,
            bool                LogRenderTargetFormatsUsed);


  private:

  };
}
