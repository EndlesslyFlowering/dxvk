#include "d3d11_enums.h"

std::ostream& operator << (std::ostream& os, D3D_FEATURE_LEVEL e) {
  switch (e) {
    ENUM_NAME(D3D_FEATURE_LEVEL_9_1);
    ENUM_NAME(D3D_FEATURE_LEVEL_9_2);
    ENUM_NAME(D3D_FEATURE_LEVEL_9_3);
    ENUM_NAME(D3D_FEATURE_LEVEL_10_0);
    ENUM_NAME(D3D_FEATURE_LEVEL_10_1);
    ENUM_NAME(D3D_FEATURE_LEVEL_11_0);
    ENUM_NAME(D3D_FEATURE_LEVEL_11_1);
    ENUM_NAME(D3D_FEATURE_LEVEL_12_0);
    ENUM_NAME(D3D_FEATURE_LEVEL_12_1);
    ENUM_DEFAULT(e);
  }
}

std::ostream& operator << (std::ostream& os, D3D11_RESOURCE_DIMENSION e) {
  switch (e) {
    ENUM_NAME(D3D11_RESOURCE_DIMENSION_UNKNOWN);

    ENUM_NAME(D3D11_RESOURCE_DIMENSION_BUFFER);
    ENUM_NAME(D3D11_RESOURCE_DIMENSION_TEXTURE1D);
    ENUM_NAME(D3D11_RESOURCE_DIMENSION_TEXTURE2D);
    ENUM_NAME(D3D11_RESOURCE_DIMENSION_TEXTURE3D);

    ENUM_DEFAULT(e);
  }
}

std::ostream& operator << (std::ostream& os, D3D11_USAGE e) {
  switch (e) {
    ENUM_NAME(D3D11_USAGE_DEFAULT);
    ENUM_NAME(D3D11_USAGE_IMMUTABLE);
    ENUM_NAME(D3D11_USAGE_DYNAMIC);
    ENUM_NAME(D3D11_USAGE_STAGING);

    ENUM_DEFAULT(e);
  }
}

std::ostream& operator << (std::ostream& os, D3D11_RTV_DIMENSION e) {
  switch (e) {
    ENUM_NAME(D3D11_RTV_DIMENSION_UNKNOWN);

    ENUM_NAME(D3D11_RTV_DIMENSION_BUFFER);
    ENUM_NAME(D3D11_RTV_DIMENSION_TEXTURE1D);
    ENUM_NAME(D3D11_RTV_DIMENSION_TEXTURE1DARRAY);
    ENUM_NAME(D3D11_RTV_DIMENSION_TEXTURE2D);
    ENUM_NAME(D3D11_RTV_DIMENSION_TEXTURE2DARRAY);
    ENUM_NAME(D3D11_RTV_DIMENSION_TEXTURE2DMS);
    ENUM_NAME(D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY);
    ENUM_NAME(D3D11_RTV_DIMENSION_TEXTURE3D);

    ENUM_DEFAULT(e);
  }
}


#define ENUM_NAME_FLAG(Flags, Flag) \
          if (Flags & Flag)  \
            strStr << #Flag << " | "

std::string enumerateD3d11BindFlags(UINT BindFlags) {
  std::stringstream strStr;

  strStr << static_cast<int32_t>(BindFlags) << ": ";

  ENUM_NAME_FLAG(BindFlags, D3D11_BIND_VERTEX_BUFFER);
  ENUM_NAME_FLAG(BindFlags, D3D11_BIND_INDEX_BUFFER);
  ENUM_NAME_FLAG(BindFlags, D3D11_BIND_CONSTANT_BUFFER);
  ENUM_NAME_FLAG(BindFlags, D3D11_BIND_SHADER_RESOURCE);
  ENUM_NAME_FLAG(BindFlags, D3D11_BIND_STREAM_OUTPUT);
  ENUM_NAME_FLAG(BindFlags, D3D11_BIND_RENDER_TARGET);
  ENUM_NAME_FLAG(BindFlags, D3D11_BIND_DEPTH_STENCIL);
  ENUM_NAME_FLAG(BindFlags, D3D11_BIND_UNORDERED_ACCESS);
  ENUM_NAME_FLAG(BindFlags, D3D11_BIND_DECODER);
  ENUM_NAME_FLAG(BindFlags, D3D11_BIND_VIDEO_ENCODER);

  std::string str = strStr.str();

  if (str.length() > 4) {
    str.resize(str.length() - 3);
  }
  else {
    str.append("none");
  }

  return str;
}

std::string enumerateD3d11MiscFlags(UINT MiscFlags) {
  std::stringstream strStr;

  strStr << static_cast<int32_t>(MiscFlags) << ": ";

  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_GENERATE_MIPS);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_SHARED);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_TEXTURECUBE);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_DRAWINDIRECT_ARGS);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_BUFFER_STRUCTURED);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_RESOURCE_CLAMP);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_GDI_COMPATIBLE);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_SHARED_NTHANDLE);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_RESTRICTED_CONTENT);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE_DRIVER);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_GUARDED);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_TILE_POOL);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_TILED);
  ENUM_NAME_FLAG(MiscFlags, D3D11_RESOURCE_MISC_HW_PROTECTED);

  std::string str = strStr.str();

  if (str.length() > 4) {
    str.resize(str.length() - 3);
  }
  else {
    str.append("none");
  }

  return str;
}

std::string enumerateD3d11SrvBufferExFlags(UINT Flags) {
  std::stringstream strStr;

  strStr << static_cast<int32_t>(Flags) << ": ";

  ENUM_NAME_FLAG(Flags, D3D11_BUFFEREX_SRV_FLAG_RAW);

  std::string str = strStr.str();

  if (str.length() > 4) {
    str.resize(str.length() - 3);
  }
  else {
    str.append("none");
  }

  return str;
}

std::string enumerateD3d11SrvDesc1(D3D11_SHADER_RESOURCE_VIEW_DESC1* pDesc) {
  std::stringstream unionStrstr;

  switch (pDesc->ViewDimension)
  {
    case D3D11_SRV_DIMENSION_BUFFER:
    {
      unionStrstr << "\n  View type:        Buffer";
      unionStrstr << "\n     FirstElement:  ";
      unionStrstr << pDesc->Buffer.FirstElement;
      unionStrstr << "\n  or ElementOffset: ";
      unionStrstr << pDesc->Buffer.ElementOffset;
      unionStrstr << "\n     NumElements:   ";
      unionStrstr << pDesc->Buffer.NumElements;
      unionStrstr << "\n  or ElementWidth:  ";
      unionStrstr << pDesc->Buffer.ElementWidth;
    } break;
    case D3D11_SRV_DIMENSION_TEXTURE1D:
    {
      unionStrstr << "\n  View type:        Texture1D";
      unionStrstr << "\n  MostDetailedMip:  ";
      unionStrstr << pDesc->Texture1D.MostDetailedMip;
    } break;
    case D3D11_SRV_DIMENSION_TEXTURE1DARRAY:
    {
      unionStrstr << "\n  View type:        Texture1DArray";
      unionStrstr << "\n  MostDetailedMip:  ";
      unionStrstr << pDesc->Texture1DArray.MostDetailedMip;
      unionStrstr << "\n  MipLevels:        ";
      unionStrstr << pDesc->Texture1DArray.MipLevels;
      unionStrstr << "\n  FirstArraySlice:  ";
      unionStrstr << pDesc->Texture1DArray.FirstArraySlice;
      unionStrstr << "\n  ArraySize:        ";
      unionStrstr << pDesc->Texture1DArray.ArraySize;
    } break;
    case D3D11_SRV_DIMENSION_TEXTURE2D:
    {
      unionStrstr << "\n  View type:        Texture2D";
      unionStrstr << "\n  MostDetailedMip:  ";
      unionStrstr << pDesc->Texture2D.MostDetailedMip;
      unionStrstr << "\n  MipLevels:        ";
      unionStrstr << pDesc->Texture2D.MipLevels;
      unionStrstr << "\n  PlanceSlice:      ";
      unionStrstr << pDesc->Texture2D.PlaneSlice;
    } break;
    case D3D11_SRV_DIMENSION_TEXTURE2DARRAY:
    {
      unionStrstr << "\n  View type:        Texture2DArray";
      unionStrstr << "\n  MostDetailedMip:  ";
      unionStrstr << pDesc->Texture2DArray.MostDetailedMip;
      unionStrstr << "\n  MipLevels:        ";
      unionStrstr << pDesc->Texture2DArray.MipLevels;
      unionStrstr << "\n  FirstArraySlice:  ";
      unionStrstr << pDesc->Texture2DArray.FirstArraySlice;
      unionStrstr << "\n  ArraySize:        ";
      unionStrstr << pDesc->Texture2DArray.ArraySize;
      unionStrstr << "\n  PlanceSlice:      ";
      unionStrstr << pDesc->Texture2DArray.PlaneSlice;
    } break;
    case D3D11_SRV_DIMENSION_TEXTURE2DMS:
    {
      unionStrstr << "\n  View type:        Texture2DMultiSampled";
    } break;
    case D3D11_SRV_DIMENSION_TEXTURE2DMSARRAY:
    {
      unionStrstr << "\n  View type:        Texture2DMultiSampledArray";
      unionStrstr << "\n  FirstArraySlice:  ";
      unionStrstr << pDesc->Texture2DMSArray.FirstArraySlice;
      unionStrstr << "\n  ArraySize:        ";
      unionStrstr << pDesc->Texture2DMSArray.ArraySize;
    } break;
    case D3D11_SRV_DIMENSION_TEXTURE3D:
    {
      unionStrstr << "\n View type:        Texture3D";
      unionStrstr << "\n MostDetailedMip:  ";
      unionStrstr << pDesc->Texture3D.MostDetailedMip;
      unionStrstr << "\n MipLevels:        ";
      unionStrstr << pDesc->Texture3D.MipLevels;
    } break;
    case D3D11_SRV_DIMENSION_TEXTURECUBE:
    {
      unionStrstr << "\n  View type:        TextureCube";
      unionStrstr << "\n  MostDetailedMip:  ";
      unionStrstr << pDesc->TextureCube.MostDetailedMip;
      unionStrstr << "\n  MipLevels:        ";
      unionStrstr << pDesc->TextureCube.MipLevels;
    } break;
    case D3D11_SRV_DIMENSION_TEXTURECUBEARRAY:
    {
      unionStrstr << "\n  View type:        TextureCubeArray";
      unionStrstr << "\n  MostDetailedMip:  ";
      unionStrstr << pDesc->TextureCubeArray.MostDetailedMip;
      unionStrstr << "\n  MipLevels:        ";
      unionStrstr << pDesc->TextureCubeArray.MipLevels;
      unionStrstr << "\n  First2DArrayFace: ";
      unionStrstr << pDesc->TextureCubeArray.First2DArrayFace;
      unionStrstr << "\n  NumCubes:         ";
      unionStrstr << pDesc->TextureCubeArray.NumCubes;
    } break;
    case D3D11_SRV_DIMENSION_BUFFEREX:
    {
      unionStrstr << "\n  View type:        BufferEx";
      unionStrstr << "\n  FirstElement:     ";
      unionStrstr << pDesc->BufferEx.FirstElement;
      unionStrstr << "\n  NumElements:      ";
      unionStrstr << pDesc->BufferEx.NumElements;
      unionStrstr << "\n  Flags:            ";
      unionStrstr << enumerateD3d11SrvBufferExFlags(pDesc->BufferEx.Flags);
    } break;
    default:
    {
      unionStrstr << "\n  View type:        unknown Dimension";
    }
  }

  return unionStrstr.str();
}

std::string enumerateD3d11UavBufferFlags(UINT Flags) {
  std::stringstream strStr;

  strStr << static_cast<int32_t>(Flags) << ": ";

  ENUM_NAME_FLAG(Flags, D3D11_BUFFER_UAV_FLAG_RAW);
  ENUM_NAME_FLAG(Flags, D3D11_BUFFER_UAV_FLAG_APPEND);
  ENUM_NAME_FLAG(Flags, D3D11_BUFFER_UAV_FLAG_COUNTER);

  std::string str = strStr.str();

  if (str.length() > 4) {
    str.resize(str.length() - 3);
  }
  else {
    str.append("none");
  }

  return str;
}

std::string enumerateD3d11UavDesc1(D3D11_UNORDERED_ACCESS_VIEW_DESC1* pDesc) {
  std::stringstream unionStrstr;

  switch (pDesc->ViewDimension)
  {
    case D3D11_UAV_DIMENSION_BUFFER:
    {
      unionStrstr << "\n  View type:       Buffer";
      unionStrstr << "\n  FirstElement:    ";
      unionStrstr << pDesc->Buffer.FirstElement;
      unionStrstr << "\n  NumElements:     ";
      unionStrstr << pDesc->Buffer.NumElements;
      unionStrstr << "\n  Flags:           ";
      unionStrstr << enumerateD3d11UavBufferFlags(pDesc->Buffer.Flags);
    } break;
    case D3D11_UAV_DIMENSION_TEXTURE1D:
    {
      unionStrstr << "\n  View type:       Texture1D";
      unionStrstr << "\n  MipSlice:        ";
      unionStrstr << pDesc->Texture1D.MipSlice;
    } break;
    case D3D11_UAV_DIMENSION_TEXTURE1DARRAY:
    {
      unionStrstr << "\n  View type:       Texture1DArray";
      unionStrstr << "\n  ArraySize:       ";
      unionStrstr << pDesc->Texture1DArray.ArraySize;
      unionStrstr << "\n  FirstArraySlice: ";
      unionStrstr << pDesc->Texture1DArray.FirstArraySlice;
      unionStrstr << "\n  MipSlice:        ";
      unionStrstr << pDesc->Texture1DArray.MipSlice;
    } break;
    case D3D11_UAV_DIMENSION_TEXTURE2D:
    {
      unionStrstr << "\n  View type:       Texture2D";
      unionStrstr << "\n  MipSlice:        ";
      unionStrstr << pDesc->Texture2D.MipSlice;
      unionStrstr << "\n  PlaneSlice:      ";
      unionStrstr << pDesc->Texture2D.PlaneSlice;
    } break;
    case D3D11_UAV_DIMENSION_TEXTURE2DARRAY:
    {
      unionStrstr << "\n  View type:       Texture2DArray";
      unionStrstr << "\n  ArraySize:       ";
      unionStrstr << pDesc->Texture2DArray.ArraySize;
      unionStrstr << "\n  FirstArraySlice: ";
      unionStrstr << pDesc->Texture2DArray.FirstArraySlice;
      unionStrstr << "\n  MipSlice:        ";
      unionStrstr << pDesc->Texture2DArray.MipSlice;
      unionStrstr << "\n  PlaneSlice:      ";
      unionStrstr << pDesc->Texture2DArray.PlaneSlice;
    } break;
    case D3D11_UAV_DIMENSION_TEXTURE3D:
    {
      unionStrstr << "\n  View type:       Texture3D";
      unionStrstr << "\n  FirstWSlice:     ";
      unionStrstr << pDesc->Texture3D.FirstWSlice;
      unionStrstr << "\n  MipSlice:        ";
      unionStrstr << pDesc->Texture3D.MipSlice;
      unionStrstr << "\n  WSize:           ";
      unionStrstr << pDesc->Texture3D.WSize;
    } break;
    default:
    {
      unionStrstr << "\n  View type:       unknown Dimension";
    }
  }

  return unionStrstr.str();
}

std::string enumerateD3d11RtvDesc1(D3D11_RENDER_TARGET_VIEW_DESC1* pDesc) {
  std::stringstream unionStrstr;

  switch (pDesc->ViewDimension)
  {
    case D3D11_RTV_DIMENSION_BUFFER:
    {
      unionStrstr << "\n   View type:       Buffer";
      unionStrstr << "\n     FirstElement:  ";
      unionStrstr << pDesc->Buffer.FirstElement;
      unionStrstr << "\n  or ElementOffset: ";
      unionStrstr << pDesc->Buffer.ElementOffset;
      unionStrstr << "\n     NumElements:   ";
      unionStrstr << pDesc->Buffer.NumElements;
      unionStrstr << "\n  or ElementWidth:  ";
      unionStrstr << pDesc->Buffer.ElementWidth;
    } break;
    case D3D11_RTV_DIMENSION_TEXTURE1D:
    {
      unionStrstr << "\n  View type:        Texture1D";
      unionStrstr << "\n  MipSlice:         ";
      unionStrstr << pDesc->Texture1D.MipSlice;
    } break;
    case D3D11_RTV_DIMENSION_TEXTURE1DARRAY:
    {
      unionStrstr << "\n  View type:        Texture1DArray";
      unionStrstr << "\n  MipSlice:         ";
      unionStrstr << pDesc->Texture1DArray.MipSlice;
      unionStrstr << "\n  FirstArraySlice:  ";
      unionStrstr << pDesc->Texture1DArray.FirstArraySlice;
      unionStrstr << "\n  ArraySize:        ";
      unionStrstr << pDesc->Texture1DArray.ArraySize;
    } break;
    case D3D11_RTV_DIMENSION_TEXTURE2D:
    {
      unionStrstr << "\n  View type:        Texture2D";
      unionStrstr << "\n  MipSlice:         ";
      unionStrstr << pDesc->Texture2D.MipSlice;
      unionStrstr << "\n  PlanceSlice:      ";
      unionStrstr << pDesc->Texture2D.PlaneSlice;
    } break;
    case D3D11_RTV_DIMENSION_TEXTURE2DARRAY:
    {
      unionStrstr << "\n  View type:        Texture2DArray";
      unionStrstr << "\n  MipSlice:         ";
      unionStrstr << pDesc->Texture2DArray.MipSlice;
      unionStrstr << "\n  FirstArraySlice:  ";
      unionStrstr << pDesc->Texture2DArray.FirstArraySlice;
      unionStrstr << "\n  ArraySize:        ";
      unionStrstr << pDesc->Texture2DArray.ArraySize;
      unionStrstr << "\n  PlanceSlice:      ";
      unionStrstr << pDesc->Texture2DArray.PlaneSlice;
    } break;
    case D3D11_RTV_DIMENSION_TEXTURE2DMS:
    {
      unionStrstr << "\n  View type:        Texture2DMultiSampled";
    } break;
    case D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY:
    {
      unionStrstr << "\n  View type:        Texture2DMultiSampledArray";
      unionStrstr << "\n  FirstArraySlice:  ";
      unionStrstr << pDesc->Texture2DMSArray.FirstArraySlice;
      unionStrstr << "\n  ArraySize:        ";
      unionStrstr << pDesc->Texture2DMSArray.ArraySize;
    } break;
    case D3D11_RTV_DIMENSION_TEXTURE3D:
    {
      unionStrstr << "\n  View type:        Texture3D";
      unionStrstr << "\n  MipSlice:         ";
      unionStrstr << pDesc->Texture3D.MipSlice;
      unionStrstr << "\n  FirstWSlice:      ";
      unionStrstr << pDesc->Texture3D.FirstWSlice;
      unionStrstr << "\n  WSize:            ";
      unionStrstr << pDesc->Texture3D.WSize;
    } break;
    default:
    {
      unionStrstr << "\n  View type:        unknown Dimension";
    }
  }

  return unionStrstr.str();
}

#undef ENUM_NAME_FLAG
