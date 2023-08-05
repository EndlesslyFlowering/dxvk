# HDR-mod

All options are also explained in the default [dxvk.conf](dxvk.conf)!

---

## New options added:

### d3d9:
- [d3d9.enableRenderTargetUpgrades](#enableRenderTargetUpgrades-d3d9d3d11)
- [d3d9.upgrade_***_renderTargetTo](#upgrade__renderTargetTo-d3d9d3d11)
- [d3d9.enableBackBufferUpgrade](d3d9enableBackBufferUpgrade-d3d9d3d11)
- [d3d9.upgradeBackBufferTo](#upgradeBackBufferTo-d3d9d3d11)
- [d3d9.enableSwapChainUpgrade](#enableSwapChainUpgrade-d3d9d3d11)
- [d3d9.upgradeSwapChainFormatTo](#upgradeSwapChainFormatTo-d3d9d3d11)
- [d3d9.upgradeSwapChainColorSpaceTo](#upgradeSwapChainColorSpaceTo-d3d9d3d11)
- [d3d9.enforceWindowModeInternally](#enforceWindowModeInternally-d3d9)
- [d3d9.logRenderTargetFormatsUsed](#logRenderTargetFormatsUsed-d3d9d3d11)

---

### d3d10/d3d11:
- [d3d11.enableRenderTargetUpgrades](#enableRenderTargetUpgrades-d3d9d3d11)
- [d3d11.upgrade_***_renderTargetTo](#upgrade__renderTargetTo-d3d9d3d11)
- [d3d11.enableBackBufferUpgrade](d3d9enableBackBufferUpgrade-d3d9d3d11)
- [d3d11.upgradeBackBufferTo](#upgradeBackBufferTo-d3d9d3d11)
- [d3d11.enableSwapChainUpgrade](#enableSwapChainUpgrade-d3d9d3d11)
- [d3d11.upgradeSwapChainFormatTo](#upgradeSwapChainFormatTo-d3d9d3d11)
- [d3d11.upgradeSwapChainColorSpaceTo](#upgradeSwapChainColorSpaceTo-d3d9d3d11)
- [d3d11.logRenderTargetFormatsUsed](#logRenderTargetFormatsUsed-d3d9d3d11)
- [d3d11.logViewsOfRenderTargets](#logViewsOfRenderTargets-d3d9d3d11)\
Yes these work for both d3d10 and d3d11 games!
---

### [Example usage](#Example-usage-1)

---

## enableRenderTargetUpgrades (d3d9/d3d11)

This enables upgrading the render targets.\
Check [upgrade_***_renderTargetTo](#upgrade__renderTargetTo-d3d9d3d11) for the individual formats.

> Supported values: `True`, `False`\
> Default/Fallback: `False`

---

## upgrade_***_renderTargetTo (d3d9/d3d11)

Individual render target upgrades per format.\
These may cause visual issues. Check [logRenderTargetFormatsUsed](#logRenderTargetFormatsUsed-d3d9d3d11) to fix those.

Setting `upgrade_***_renderTargetTo = rgba16_float` will allow for outputting 'overbright' data that would otherwise be lost to clipping.\
This needs '[upgradeSwapChainFormatTo](#upgradeSwapChainFormatTo-d3d9d3d11) = rgba16_float' and '[upgradeSwapChainColorSpaceTo](#upgradeSwapChainColorSpaceTo-d3d9d3d11) = scRGB' otherwise they are lost again.\
Additionally further post processing is needed to display the game correctly.

what option corresponds to what format:

### d3d9:
| option        | format                 | allows 'overbright' extraction |
|---------------|------------------------|--------------------------------|
| RGBA8_UNORM   | `D3DFMT_A8B8G8R8`      | no                             |
| RGBX8_UNORM   | `D3DFMT_X8B8G8R8`      | no                             |
| BGRA8_UNORM   | `D3DFMT_A8R8G8B8`      | no                             |
| BGRX8_UNORM   | `D3DFMT_X8R8G8B8`      | no                             |
| RGB10A2_UNORM | `D3DFMT_A2B10G10R10`   | no                             |
| BGR10A2_UNORM | `D3DFMT_A2R10G10B10`   | no                             |
| RGBA16_UNORM  | `D3DFMT_A16B16G16R16`  | no                             |
| RGBA16_FLOAT  | `D3DFMT_A16B16G16R16F` | yes                            |
| RGBA32_FLOAT  | `D3DFMT_A32B32G32R32F` | yes                            |
| B5G6R5_UNORM  | `D3DFMT_R5G6B5`        | no                             |
| BGR5A1_UNORM  | `D3DFMT_A1R5G5B5`      | no                             |
| BGR5X1_UNORM  | `D3DFMT_X1R5G5B5`      | no                             |
| BGRA4_UNORM   | `D3DFMT_A4R4G4B4`      | no                             |
| BGRX4_UNORM   | `D3DFMT_X4R4G4B4`      | no                             |
---

### d3d11:
| option           | format                              | allows 'overbright' extraction |
|------------------|-------------------------------------|--------------------------------|
| RGBA8_UNORM      | `DXGI_FORMAT_R8G8B8A8_UNORM`        | no                             |
| BGRA8_UNORM      | `DXGI_FORMAT_B8G8R8A8_UNORM`        | no                             |
| BGRX8_UNORM      | `DXGI_FORMAT_B8G8R8X8_UNORM`        | no                             |
| RGBA8_UNORM_SRGB | `DXGI_FORMAT_R8G8B8A8_UNORM_SRGB`   | no                             |
| BGRA8_UNORM_SRGB | `DXGI_FORMAT_B8G8R8A8_UNORM_SRGB`   | no                             |
| BGRX8_UNORM_SRGB | `DXGI_FORMAT_B8G8R8X8_UNORM_SRGB`   | no                             |
| RGBA8_TYPELESS   | `DXGI_FORMAT_R8G8B8A8_TYPELESS`     | no                             |
| BGRA8_TYPELESS   | `DXGI_FORMAT_B8G8R8A8_TYPELESS`     | no                             |
| BGRX8_TYPELESS   | `DXGI_FORMAT_B8G8R8X8_TYPELESS`     | no                             |
| RGB10A2_UNORM    | `DXGI_FORMAT_R10G10B10A2_UNORM`     | no                             |
| RGB10A2_TYPELESS | `DXGI_FORMAT_R10G10B10A2_TYPELESS`  | no                             |
| RG11B10_FLOAT    | `DXGI_FORMAT_R11G11B10_FLOAT`       | yes*                           |
| RGBA16_UNORM     | `DXGI_FORMAT_R16G16B16A16_UNORM`    | no                             |
| RGBA16_FLOAT     | `DXGI_FORMAT_R16G16B16A16_FLOAT`    | yes                            |
| RGBA16_TYPELESS  | `DXGI_FORMAT_R16G16B16A16_TYPELESS` | yes**                          |
| RGBA32_FLOAT     | `DXGI_FORMAT_R32G32B32A32_FLOAT`    | yes                            |
| RGBA32_TYPELESS  | `DXGI_FORMAT_R32G32B32A32_TYPELESS` | yes**                          |

\* `RG11B10_FLOAT` is not available as an upgrade option.

\** `TYPELESS` formats need to match their bitness siblings.\
So if you upgrade `RGBA8_UNORM` (8 bit format) to `RGBA16_FLOAT` or `RGBA16_UNORM` (16 bit format) you need to upgrade `RGBA8_TYPELESS` to `RGBA16_TYPELESS` too.\
When games use `TYPELESS` formats these can cause the most visual issues.

---

### d3d9:
**d3d9.upgrade_RGBA8_UNORM_renderTargetTo**:\
**d3d9.upgrade_RGBX8_UNORM_renderTargetTo**:\
**d3d9.upgrade_BGRA8_UNORM_renderTargetTo**:\
**d3d9.upgrade_BGRX8_UNORM_renderTargetTo**:

> Supported values: `disabled`, `rgb10a2_unorm`, `bgr10a2_unorm`, `rgba16_unorm`, `rgba16_float`, `rgba32_float`\
> Default/Fallback: `disabled`

---

**d3d9.upgrade_RGB10A2_UNORM_renderTargetTo**:\
**d3d9.upgrade_BGR10A2_UNORM_renderTargetTo**:

> Supported values: `disabled`, `rgba16_unorm`, `rgba16_float`, `rgba32_float`\
> Default/Fallback: `disabled`

---

**d3d9.upgrade_RGBA16_UNORM_renderTargetTo**:

> Supported values: `disabled`, `rgba16_float`, `rgba32_float`\
> Default/Fallback: `disabled`

---

**d3d9.upgrade_RGBA16_FLOAT_renderTargetTo**:

> Supported values: `disabled`, `rgba32_float`\
> Default/Fallback: `disabled`

---

### d3d11:
**d3d11.upgrade_RGBA8_UNORM_renderTargetTo**:\
**d3d11.upgrade_BGRA8_UNORM_renderTargetTo**:\
**d3d11.upgrade_BGRX8_UNORM_renderTargetTo**:

> Supported values: `disabled`, `rgb10a2_unorm`, `bgr10a2_unorm`, `rgba16_unorm`, `rgba16_float`, `rgba32_float`\
> Default/Fallback: `disabled`

---

**d3d11.upgrade_RGBA8_UNORM_SRGB_renderTargetTo**:\
**d3d11.upgrade_BGRA8_UNORM_SRGB_renderTargetTo**:\
**d3d11.upgrade_BGRX8_UNORM_SRGB_renderTargetTo**:

> Supported values: `rgba16_unorm`, `rgba16_float`, `rgba32_float`\
> Default/Fallback: `disabled`

---

**d3d11.upgrade_RGBA8_TYPELESS_renderTargetTo**:\
**d3d11.upgrade_BGRA8_TYPELESS_renderTargetTo**:\
**d3d11.upgrade_BGRX8_TYPELESS_renderTargetTo**:

> Supported values: `disabled`, `rgb10a2_typeless`, `rgba16_typeless`, `rgba32_typeless`\
> Default/Fallback: `disabled`

---

**d3d11.upgrade_RGB10A2_UNORM_renderTargetTo**:

> Supported values: `rgba16_unorm`, `rgba16_float`, `rgba32_float`\
> Default/Fallback: `disabled`

---

**d3d11.upgrade_RGB10A2_TYPELESS_renderTargetTo**:

> Supported values: `disabled`, `rgba16_typeless`, `rgba32_typeless`\
> Default/Fallback: `disabled`

---

**d3d11.upgrade_RG11B10_FLOAT_renderTargetTo**:

> Supported values: `rgba16_float`, `rgba32_float`\
> Default/Fallback: `disabled`

---

**d3d11.upgrade_RGBA16_UNORM_renderTargetTo**:

> Supported values: `rgba16_float`, `rgba32_float`\
> Default/Fallback: `disabled`

---

**d3d11.upgrade_RGBA16_FLOAT_renderTargetTo**:

> Supported values: `rgba32_float`\
> Default/Fallback: `disabled`

---

**d3d11.upgrade_RGBA16_TYPELESS_renderTargetTo**:

> Supported values: `disabled`, `rgba32_typeless`\
> Default/Fallback: `disabled`

---

## enableBackBufferUpgrade (d3d9/d3d11)

Enable upgrading the back buffer format.\
Set the format with [upgradeBackBufferTo](#upgradeBackBufferTo-d3d9d3d11).

> Supported values: `True`, `False`\
> Default/Fallback: `False`

---

## upgradeBackBufferTo (d3d9/d3d11)
Upgrade the back buffer format to another format.
Needs '[enableBackBufferUpgrade](#enableBackBufferUpgrade-d3d9d3d11) = True'!

> Supported values: `disabled`, `rgb10a2_unorm`, `bgr10a2_unorm`, `rgba16_unorm`, `rgba16_float`, `rgba32_float`\
> Default/Fallback: `disabled`

---

## enableSwapChainUpgrade (d3d9/d3d11)

Enable upgrading the swap chain format and color space.\
See [upgradeSwapChainFormatTo](#upgradeSwapChainFormatTo-d3d9d3d11) and [upgradeSwapChainColorSpaceTo](#upgradeSwapChainColorSpaceTo-d3d9d3d11). Both have to not be disabled for the upgrade to be enabled.

> Supported values: `True`, `False`\
> Default/Fallback: `False`

---

## upgradeSwapChainFormatTo (d3d9/d3d11)

Upgrade the output format to a higher bit depth one.

Needs '[enableSwapChainUpgrade](#enableSwapChainUpgrade-d3d9d3d11) = True'!\
Use in combination with [upgradeSwapChainColorSpaceTo](#upgradeSwapChainColorSpaceTo-d3d9d3d11)!

What works depends on your hardware and display combination.\
AMD graphics cards on Windows allow for a stupid amount of combinations.

Check the allowed ones with:
> `vulkaninfo | grep -E 'format =|colorSpace ='`

On Windows open up powershell and input this:
> `vulkaninfo | Select-String -CaseSensitive "format =|colorSpace ="`

Check the logs to see what format is being used and to see if the used format actually works.

> Supported values: `disabled`, `unchanged`, `rgb10a2_unorm`, `bgr10a2_unorm`, `rgba16_unorm`, `rgba16_float`\
> Default/Fallback: `disabled`

---

## upgradeSwapChainColorSpaceTo (d3d9/d3d11)

Upgrade the output color space.
Needs '[enableSwapChainUpgrade](#enableSwapChainUpgrade-d3d9d3d11) = True'!\
Use in combination with [upgradeSwapChainFormatTo](#upgradeSwapChainFormatTo-d3d9d3d11)!

Check the logs to see what color space is being used and to see if the used color space actually works.

> Supported values: `disabled`, `unchanged`, `PQ`, `scRGB`\
> Default/Fallback: `disabled`

---

## enforceWindowModeInternally (d3d9)

Enforce the internal window mode. This also affects the window DXVK creates.\
This is mainly a workaround for games with buggy window code.\
Some games switch between windowed and fullscreen, which might cause issues with HDR engaging when using Vulkan's FSE.

> Supported values: `disabled`, `windowed`, `fullscreen`\
> Default/Fallback: `disabled`

---

## logRenderTargetFormatsUsed (d3d9/d3d11)

Log D3D (d3d9) / DXGI (d3d11) render target formats that are being used by the application and the ones that are being upgraded.\
The main idea is to find render target formats that cause issues and change them to a working one or disable the upgrade.\
See [upgrade_***_renderTargetTo](#upgrade__renderTargetTo-d3d9d3d11).

> Supported values: `True`, `False`\
> Default/Fallback: `False`

---

## logViewsOfRenderTargets (d3d11)

Log information about all view types of render targets.

> Supported values: `True`, `False`\
> Default/Fallback: `False`

---

## Example Usage

### d3d9:

- output 'overbright' data (needs further post processing):
    ```ini
    d3d9.enableRenderTargetUpgrades           = true
    d3d9.upgrade_RGBA8_UNORM_renderTargetTo   = rgba16_float
    d3d9.upgrade_RGBX8_UNORM_renderTargetTo   = rgba16_float
    d3d9.upgrade_BGRA8_UNORM_renderTargetTo   = rgba16_float
    d3d9.upgrade_BGRX8_UNORM_renderTargetTo   = rgba16_float
    d3d9.upgrade_RGB10A2_UNORM_renderTargetTo = rgba16_float
    d3d9.upgrade_BGR10A2_UNORM_renderTargetTo = rgba16_float
    d3d9.upgrade_RGBA16_UNORM_renderTargetTo  = rgba32_float
    d3d9.enableBackBufferUpgrade        = true
    d3d9.upgradeBackBufferTo            = rgba16_float
    d3d9.enableSwapChainUpgrade               = true
    d3d9.upgradeSwapChainFormatTo             = rgba16_float
    d3d9.upgradeSwapChainColorSpaceTo         = scRGB
    ```

- get rid off banding issues:
    ```ini
    d3d9.enableRenderTargetUpgrades           = true
    d3d9.upgrade_RGBA8_UNORM_renderTargetTo   = rgba16_unorm
    d3d9.upgrade_RGBX8_UNORM_renderTargetTo   = rgba16_unorm
    d3d9.upgrade_BGRA8_UNORM_renderTargetTo   = rgba16_unorm
    d3d9.upgrade_BGRX8_UNORM_renderTargetTo   = rgba16_unorm
    d3d9.upgrade_RGB10A2_UNORM_renderTargetTo = rgba16_unorm
    d3d9.upgrade_BGR10A2_UNORM_renderTargetTo = rgba16_unorm
    d3d9.enableBackBufferUpgrade        = true
    d3d9.upgradeBackBufferTo            = rgba16_unorm
    d3d9.enableSwapChainUpgrade               = true
    d3d9.upgradeSwapChainFormatTo             = rgb10a2_unorm
    d3d9.upgradeSwapChainColorSpaceTo         = unchanged
    ```
    on AMD you can use:
    ```ini
    d3d9.upgradeSwapChainFormatTo             = rgba16_unorm
    ```

---

### d3d11:

- output 'overbright' data (needs further post processing):
    ```ini
    d3d11.enableRenderTargetUpgrades              = true
    d3d11.upgrade_RGBA8_UNORM_renderTargetTo      = rgba16_float
    d3d11.upgrade_BGRA8_UNORM_renderTargetTo      = rgba16_float
    d3d11.upgrade_BGRX8_UNORM_renderTargetTo      = rgba16_float
    d3d11.upgrade_RGBA8_UNORM_SRGB_renderTargetTo = rgba16_float
    d3d11.upgrade_BGRA8_UNORM_SRGB_renderTargetTo = rgba16_float
    d3d11.upgrade_BGRX8_UNORM_SRGB_renderTargetTo = rgba16_float
    d3d11.upgrade_RGBA8_TYPELESS_renderTargetTo   = rgba16_typeless
    d3d11.upgrade_BGRA8_TYPELESS_renderTargetTo   = rgba16_typeless
    d3d11.upgrade_BGRX8_TYPELESS_renderTargetTo   = rgba16_typeless
    d3d11.upgrade_RGB10A2_UNORM_renderTargetTo    = rgba16_float
    d3d11.upgrade_RGB10A2_TYPELESS_renderTargetTo = rgba16_typeless
    d3d11.upgrade_RG11B10_FLOAT_renderTargetTo    = rgba16_float
    d3d11.upgrade_RGBA16_UNORM_renderTargetTo     = rgba32_float
    d3d11.enableBackBufferUpgrade           = true
    d3d11.upgradeBackBufferTo               = rgba16_float
    d3d11.enableSwapChainUpgrade                  = true
    d3d11.upgradeSwapChainFormatTo                = rgba16_float
    d3d11.upgradeSwapChainColorSpaceTo            = scRGB
    ```

- get rid off banding issues:
    ```ini
    d3d11.enableRenderTargetUpgrades              = true
    d3d11.upgrade_RGBA8_UNORM_renderTargetTo      = rgba16_unorm
    d3d11.upgrade_BGRA8_UNORM_renderTargetTo      = rgba16_unorm
    d3d11.upgrade_BGRX8_UNORM_renderTargetTo      = rgba16_unorm
    d3d11.upgrade_RGBA8_UNORM_SRGB_renderTargetTo = rgba16_unorm
    d3d11.upgrade_BGRA8_UNORM_SRGB_renderTargetTo = rgba16_unorm
    d3d11.upgrade_BGRX8_UNORM_SRGB_renderTargetTo = rgba16_unorm
    d3d11.upgrade_RGBA8_TYPELESS_renderTargetTo   = rgba16_typeless
    d3d11.upgrade_BGRA8_TYPELESS_renderTargetTo   = rgba16_typeless
    d3d11.upgrade_BGRX8_TYPELESS_renderTargetTo   = rgba16_typeless
    d3d11.upgrade_RGB10A2_UNORM_renderTargetTo    = rgba16_unorm
    d3d11.upgrade_RGB10A2_TYPELESS_renderTargetTo = rgba16_typeless
    d3d11.upgrade_RG11B10_FLOAT_renderTargetTo    = rgba16_float
    d3d11.enableBackBufferUpgrade           = true
    d3d11.upgradeBackBufferTo               = rgba16_unorm
    d3d11.enableSwapChainUpgrade                  = true
    d3d11.upgradeSwapChainFormatTo                = rgba10_unorm
    d3d11.upgradeSwapChainColorSpaceTo            = unchanged
    ```
    on AMD you can use:
    ```ini
    d3d11.upgradeSwapChainFormatTo                = rgba16_unorm
    ```
