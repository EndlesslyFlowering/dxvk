#include "d3d11_device.h"
#include <dxgiformat.h>

namespace dxvk {

  class D3D11Device;

  class D3D11RTUpgradeHelper {

  public:

    uint32_t GetFormatID(
      const DXGI_FORMAT Format);

    DXGI_FORMAT TranslateFormatString(
      DXGI_FORMAT inputFormat,
      std::string targetFormatString);

    DXGI_FORMAT UpgradeRenderTarget(
      DXGI_FORMAT Format);

    std::string GetDXGIFormatNameAsString(
      DXGI_FORMAT Format);

    struct FormatInfo
    {
      std::string type             = "unknown";
      uint32_t    activeComponents = 0;
      std::string channelStructure = "";
      uint32_t    depth0           = 0;
      uint32_t    depth1           = 0;
      uint32_t    depth2           = 0;
      uint32_t    depth3           = 0;
    };

  private:

    D3D11Device* m_device;

    std::string GetDXGIFormatInfo(
      DXGI_FORMAT Format);

  };
}