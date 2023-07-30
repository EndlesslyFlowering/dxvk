#pragma once

#include <ostream>

#include "d3d11_include.h"

#include "../dxgi/dxgi_enums.h"

std::ostream& operator << (std::ostream& os, D3D_FEATURE_LEVEL e);

std::ostream& operator << (std::ostream& os, D3D11_RESOURCE_DIMENSION e);

std::ostream& operator << (std::ostream& os, D3D11_USAGE e);

std::ostream& operator << (std::ostream& os, D3D11_RTV_DIMENSION e);

std::string enumerateD3d11BindFlags(UINT BindFlags);

std::string enumerateD3d11MiscFlags(UINT MiscFlags);
