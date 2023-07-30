#pragma once

#include "../dxgi/dxgi_include.h"

#include <d3d11_4.h>

#if defined(__x86_64__) || defined(_M_X64)
  #define POINTER_SIZE uint64_t
#elif defined(__i386__) || defined(_M_IX86)
  #define POINTER_SIZE uint32_t
#endif
