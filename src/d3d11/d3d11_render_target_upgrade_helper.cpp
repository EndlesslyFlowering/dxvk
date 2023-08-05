#include "d3d11_render_target_upgrade_helper.h"

namespace dxvk
{

  DXGI_FORMAT D3D11RenderTargetUpgradeHelper::RenderTargetFormatUpgradeHelper(
    DXGI_FORMAT OriginalFormat,
    DXGI_FORMAT UpgradedFormat,
    FORMAT_TYPE UpgradeType)
  {
#ifdef _HDR_DEBUG
    RenderTargetFormatLogger(OriginalFormat,
                             UpgradedFormat,
                             UpgradeType);
#endif

    if (UpgradedFormat != DXGI_FORMAT_UNKNOWN)
    //  && UpgradedFormat < OriginalFormat)
    {
      return UpgradedFormat;
    }
    else
    {
      return OriginalFormat;
    }
  }

//  void D3D11RenderTargetUpgradeHelper::ViewUpgradeHelper(
//    DXGI_FORMAT  ResourceFormat,
//    DXGI_FORMAT* ViewFormat,
//    DXGI_FORMAT  UpgradedResourceFormat,
//    DXGI_FORMAT  UpgradedViewFormat,
//    FORMAT_TYPE  UpgradeType,
//    bool         LogViewsOfRenderTargets)
//  {
//    if (LogViewsOfRenderTargets)
//    {
//      ViewLogger(ResourceFormat,
//                 *ViewFormat,
//                 UpgradedResourceFormat,
//                 UpgradedViewFormat,
//                 UpgradeType);
//    }
//
//    if (UpgradedResourceFormat != DXGI_FORMAT_UNKNOWN
//     && UpgradedViewFormat     != DXGI_FORMAT_UNKNOWN)
//    {
//      *ViewFormat     = UpgradedViewFormat;
//    }
//    return;
//  }

#ifdef _HDR_DEBUG
  std::string D3D11RenderTargetUpgradeHelper::GetUpgradeString(
    FORMAT_TYPE UpgradeType)
  {
    return UpgradeType == FORMAT_TYPE::RENDER_TARGET                     ? "Render Target):                     "
         : UpgradeType == FORMAT_TYPE::RENDER_TARGET_VIEW                ? "Render Target View):                "
         : UpgradeType == FORMAT_TYPE::SHADER_RESOURCE_VIEW              ? "Shader Resource View):              "
         : UpgradeType == FORMAT_TYPE::UNORDERED_ACCESS_VIEW             ? "Unordered Access View):             "
         : UpgradeType == FORMAT_TYPE::BACK_BUFFER                       ? "Back Buffer):                       "
         : UpgradeType == FORMAT_TYPE::BACK_BUFFER_RENDER_TARGET_VIEW    ? "Back Buffer Render Target View):    "
         : UpgradeType == FORMAT_TYPE::BACK_BUFFER_SHADER_RESOURCE_VIEW  ? "Back Buffer Shader Resource View):  "
         : UpgradeType == FORMAT_TYPE::BACK_BUFFER_UNORDERED_ACCESS_VIEW ? "Back Buffer Unordered Access View): "
         : "wth";
  }

  void D3D11RenderTargetUpgradeHelper::RenderTargetFormatLogger(
    DXGI_FORMAT OriginalFormat,
    DXGI_FORMAT UpgradedFormat,
    FORMAT_TYPE UpgradeType)
  {
    std::string upgradeString = GetUpgradeString(UpgradeType);

    if (UpgradedFormat != DXGI_FORMAT_UNKNOWN)
    {
      Logger::info(str::format("D3D11: format upgrade (", upgradeString,
                               GetDXGIFormatNameAsString(OriginalFormat),
                               " -> ",
                               GetDXGIFormatNameAsString(UpgradedFormat)));
      return;
    }
    else
    {
      Logger::info(str::format("D3D11: used format (", upgradeString, "   ",
                               GetDXGIFormatNameAsString(OriginalFormat)));
      return;
    }
  }
#endif

//  void D3D11RenderTargetUpgradeHelper::ViewLogger(
//    DXGI_FORMAT ResourceFormat,
//    DXGI_FORMAT ViewFormat,
//    DXGI_FORMAT UpgradedResourceFormat,
//    DXGI_FORMAT UpgradedViewFormat,
//    FORMAT_TYPE UpgradeType)
//  {
//    std::string upgradeString = GetUpgradeString(UpgradeType);//

//    if (UpgradedResourceFormat != DXGI_FORMAT_UNKNOWN
//     && UpgradedViewFormat     != DXGI_FORMAT_UNKNOWN)
//    {
//      Logger::info(str::format("D3D11: format upgrade (", upgradeString,
//                         "\n", "                                            render target: ",
//                               GetDXGIFormatNameAsString(ResourceFormat),
//                               " -> ", GetDXGIFormatNameAsString(UpgradedResourceFormat),
//                         "\n", "                                                     view: ",
//                               GetDXGIFormatNameAsString(ViewFormat),
//                               " -> ", GetDXGIFormatNameAsString(UpgradedViewFormat)));
//      return;
//    }
//    else
//    {
//      Logger::info(str::format("D3D11: used format (", upgradeString,
//                         "\n", "                                            render target: ",
//                               GetDXGIFormatNameAsString(ResourceFormat),
//                         "\n", "                                                     view: ",
//                               GetDXGIFormatNameAsString(ViewFormat)));
//      return;
//    }
//  }

}
