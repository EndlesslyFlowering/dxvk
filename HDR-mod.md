# HDR-mod

All options are also explained in the default [dxvk.conf](dxvk.conf)!


## New options added:

- [d3d9.enableRenderTargetUpgrade](#d3d9enableRenderTargetUpgrade)
- [d3d9.upgrade_***_renderTargetTo](#d3d9upgrade__renderTargetTo)
- [d3d9.enableBackBufferFormatUpgrade](d3d9enableBackBufferFormatUpgrade)
- [d3d9.upgradeBackBufferFormatTo](#d3d9upgradeBackBufferFormatTo)
- [d3d9.enableSwapChainUpgrade](#d3d9enableSwapChainUpgrade)
- [d3d9.upgradeSwapChainFormatTo](#d3d9upgradeSwapChainFormatTo)
- [d3d9.upgradeSwapChainColorSpaceTo](#d3d9upgradeSwapChainColorSpaceTo)
- [d3d9.enforceWindowModeInternally](#d3d9enforceWindowModeInternally)
- [d3d9.logRenderTargetFormatsUsed](#d3d9logRenderTargetFormatsUsed)

[Example usage](#Example-usage)

## d3d9.enableRenderTargetUpgrade

This enables upgrading the render targets.\
Check [d3d9.upgrade_***_renderTargetTo](#d3d9upgrade__renderTargetTo) for the individual formats.

Supported values: `True`, `False`\
Default/Fallback: `False`


## d3d9.upgrade_***_renderTargetTo

Individual render target upgrades per format.\
These may cause visual issues. Check [d3d9.logRenderTargetFormatsUsed](#d3d9logRenderTargetFormatsUsed) to fix those.

Setting `d3d9.upgrade_***_renderTargetTo = rgba16_float` will allow for outputting 'overbright' data that would otherwise be lost to clipping.\
This needs '[d3d9.upgradeSwapChainFormatTo](#d3d9upgradeSwapChainFormatTo) = rgba16_float' and '[d3d9.upgradeSwapChainColorSpaceTo](#d3d9upgradeSwapChainColorSpaceTo) = scRGB' otherwise they are lost again.\
Additionally further post processing is needed to display the game correctly.

what option corresponds to what format:

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

d3d9.upgrade_RGBA8_UNORM_renderTargetTo:\
d3d9.upgrade_RGBX8_UNORM_renderTargetTo:\
d3d9.upgrade_BGRA8_UNORM_renderTargetTo:\
d3d9.upgrade_BGRX8_UNORM_renderTargetTo:\
d3d9.upgrade_RGB10A2_UNORM_renderTargetTo:\
d3d9.upgrade_BGR10A2_UNORM_renderTargetTo:

Supported values: `disabled`, `rgb10a2_unorm`, `bgr10a2_unorm`, `rgba16_unorm`, `rgba16_float`, `rgba32_float`\
Default/Fallback: `disabled`


d3d9.upgrade_RGBA16_UNORM_renderTargetTo:

Supported values: `disabled`, `rgba16_float`, `rgba32_float`\
Default/Fallback: `disabled`


d3d9.upgrade_RGBA16_FLOAT_renderTargetTo:

Supported values: `disabled`, `rgba32_float`\
Default/Fallback: `disabled`


## d3d9.enableBackBufferFormatUpgrade

Enable upgrading the back buffer format.\
Set the format with [d3d9.upgradeBackBufferFormatTo](#d3d9upgradeBackBufferFormatTo).

Supported values: `True`, `False`\
Default/Fallback: `False`


## d3d9.upgradeBackBufferFormatTo
Upgrade the back buffer format to another format.
Needs '[d3d9.enableBackBufferFormatUpgrade](d3d9enableBackBufferFormatUpgrade) = True'!

Supported values: disabled, rgb10a2_unorm, bgr10a2_unorm, rgba16_unorm, rgba16_float, rgba32_float
Default/Fallback: disabled


## d3d9.enableSwapChainUpgrade

Enable upgrading the swap chain format and color space.\
See [d3d9.upgradeSwapChainFormatTo](#d3d9upgradeSwapChainFormatTo) and [d3d9.upgradeSwapChainColorSpaceTo](#d3d9upgradeSwapChainColorSpaceTo). Both have to not be disabled for the upgrade to be enabled.

Supported values: `True`, `False`\
Default/Fallback: `False`


## d3d9.upgradeSwapChainFormatTo

Upgrade the output format to a higher bit depth one.

Needs '[d3d9.enableSwapChainUpgrade](#d3d9enableSwapChainUpgrade) = True'!\
Use in combination with [d3d9.upgradeSwapChainColorSpaceTo](#d3d9upgradeSwapChainColorSpaceTo)!

What works depends on your hardware and display combination.\
AMD graphics cards on Windows allow for a stupid amount of combinations.

Check the allowed ones with:\
`vulkaninfo | grep -E 'format =|colorSpace ='`

On Windows open up powershell and input this:\
`vulkaninfo | Select-String -CaseSensitive "format =|colorSpace ="`

Check the logs to see what format is being used and to see if it actually works.

Supported values: `disabled`, `rgb10a2_unorm`, `bgr10a2_unorm`, `rgba16_unorm`, `rgba16_float`\
Default/Fallback: `disabled`


## d3d9.upgradeSwapChainColorSpaceTo

Upgrade the output color space.
Needs '[d3d9.enableSwapChainUpgrade](#d3d9enableSwapChainUpgrade) = True'!\
Use in combination with [d3d9.upgradeSwapChainFormatTo](#d3d9upgradeSwapChainFormatTo)!

Check the logs to see what color space is being used and to see if it actually works.

Supported values: `disabled`, `PQ`, `scRGB`\
Default/Fallback: `disabled`


## d3d9.enforceWindowModeInternally

Enforce the internal window mode. This also affects the window DXVK creates.\
This is mainly a workaround for games with buggy window code.\
Some games switch between windowed and fullscreen, which might cause issues with HDR engaging when using Vulkan's FSE.

Supported values: `disabled`, `windowed`, `fullscreen`\
Default/Fallback: `disabled`


## d3d9.logRenderTargetFormatsUsed

Log D3D formats that are being used by the application and the ones that are being upgraded.\
The main idea is to find render target formats that cause issues and change them to a working one or disable the upgrade.\
See [d3d9.upgrade_***_renderTargetTo](#d3d9upgrade__renderTargetTo).

Supported values: `True`, `False`\
Default/Fallback: `False`


## Example Usage

- output 'overbright' data (needs further post processing):
    ```ini
    d3d9.enableRenderTargetUpgrade            = true
    d3d9.upgrade_RGBA8_UNORM_renderTargetTo   = rgba16_float
    d3d9.upgrade_RGBX8_UNORM_renderTargetTo   = rgba16_float
    d3d9.upgrade_BGRA8_UNORM_renderTargetTo   = rgba16_float
    d3d9.upgrade_BGRX8_UNORM_renderTargetTo   = rgba16_float
    d3d9.upgrade_RGB10A2_UNORM_renderTargetTo = rgba16_float
    d3d9.upgrade_BGR10A2_UNORM_renderTargetTo = rgba16_float
    d3d9.upgrade_RGBA16_UNORM_renderTargetTo  = rgba16_float
    d3d9.enableBackBufferFormatUpgrade        = true
    d3d9.upgradeBackBufferFormatTo            = rgba16_float
    d3d9.enableSwapChainUpgrade               = true
    d3d9.upgradeSwapChainFormatTo             = rgba16_float
    d3d9.upgradeSwapChainColorSpaceTo         = scRGB
    ```

- get rid off banding issues:
    ```ini
    d3d9.enableRenderTargetUpgrade            = true
    d3d9.upgrade_RGBA8_UNORM_renderTargetTo   = rgba16_unorm
    d3d9.upgrade_RGBX8_UNORM_renderTargetTo   = rgba16_unorm
    d3d9.upgrade_BGRA8_UNORM_renderTargetTo   = rgba16_unorm
    d3d9.upgrade_BGRX8_UNORM_renderTargetTo   = rgba16_unorm
    d3d9.upgrade_RGB10A2_UNORM_renderTargetTo = rgba16_unorm
    d3d9.upgrade_BGR10A2_UNORM_renderTargetTo = rgba16_unorm
    d3d9.upgrade_RGBA16_UNORM_renderTargetTo  = disabled
    d3d9.enableBackBufferFormatUpgrade        = true
    d3d9.upgradeBackBufferFormatTo            = rgba16_unorm
    d3d9.enableSwapChainUpgrade               = true
    d3d9.upgradeSwapChainFormatTo             = rgb10a2_unorm
    d3d9.upgradeSwapChainColorSpaceTo         = disabled
    ```
    on AMD you can use:
    ```ini
    d3d9.upgradeSwapChainFormatTo             = rgba16_unorm
    ```
