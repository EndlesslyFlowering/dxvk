#pragma once

#include "d3d11_options.h"

namespace dxvk
{

  class D3D11RenderTargetUpgradeHelper {

  public:

    enum class FORMAT_TYPE
    {
      RENDER_TARGET,
      RENDER_TARGET_VIEW,
      SHADER_RESOURCE_VIEW,
      UNORDERED_ACCESS_VIEW,
      BACK_BUFFER,
      BACK_BUFFER_RENDER_TARGET_VIEW,
      BACK_BUFFER_SHADER_RESOURCE_VIEW,
      BACK_BUFFER_UNORDERED_ACCESS_VIEW,
    };

    static DXGI_FORMAT RenderTargetFormatUpgradeHelper(
      DXGI_FORMAT OriginalFormat,
      DXGI_FORMAT UpgradedFormat,
      FORMAT_TYPE UpgradeType);

    // static void ViewUpgradeHelper(
    //   DXGI_FORMAT  ResourceFormat,
    //   DXGI_FORMAT* ViewFormat,
    //   DXGI_FORMAT  UpgradedResourceFormat,
    //   DXGI_FORMAT  UpgradedViewFormat,
    //   FORMAT_TYPE  UpgradeType,
    //   bool         LogViewsOfRenderTargets);

  private:

#ifdef _HDR_DEBUG
    static std::string GetUpgradeString(
      FORMAT_TYPE UpgradeType);

    static void RenderTargetFormatLogger(
      DXGI_FORMAT OriginalFormat,
      DXGI_FORMAT UpgradedFormat,
      FORMAT_TYPE UpgradeType);
#endif

    // static void ViewLogger(
    //   DXGI_FORMAT ResourceFormat,
    //   DXGI_FORMAT ViewFormat,
    //   DXGI_FORMAT UpgradedResourceFormat,
    //   DXGI_FORMAT UpgradedViewFormat,
    //   FORMAT_TYPE UpgradeType);

  };
}
