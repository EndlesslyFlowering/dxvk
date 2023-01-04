# HDR-mod

All options are also explained in the default [dxvk.conf](dxvk.conf)!


## New options added:

- [d3d9.enableRenderTargetUpgrade](#d3d9enableRenderTargetUpgrade)
- [d3d9.upgrade_***_renderTargetTo](#d3d9upgrade__renderTargetTo)
- [d3d9.enableSwapchainUpgrade](#d3d9enableSwapchainUpgrade)
- [d3d9.upgradeSwapchainFormatTo](#d3d9upgradeSwapchainFormatTo)
- [d3d9.upgradeSwapchainColorSpaceTo](#d3d9upgradeSwapchainColorSpaceTo)
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
These may cause visual issues. Check [d3d9.logRenderTargetFormatsUsed](#d3d9logRenderTargetFormatsUsed) to fix those.\
Watch out for memory usage on 32 bit applications. Using `"rgba32f"` there can cause crashes or the game not loading.

Setting 'd3d9.upgrade_***_renderTargetTo = "rgba16f"' will allow for outputting 'overbright' data that would otherwise be lost to clipping.\
This needs '[d3d9.upgradeSwapchainFormatTo](#d3d9upgradeSwapchainFormatTo) = "rgba16f"' and '[d3d9.upgradeSwapchainColorSpaceTo](#d3d9upgradeSwapchainColorSpaceTo) = "scRGB"' otherwise they are lost again.

what option corresponds to what format:

| option  | format                 |
|---------|------------------------|
| RGBA8   | `D3DFMT_A8B8G8R8`      |
| RGBX8   | `D3DFMT_X8B8G8R8`      |
| BGRA8   | `D3DFMT_A8R8G8B8`      |
| BGRX8   | `D3DFMT_X8R8G8B8`      |
| RGB10A2 | `D3DFMT_A2B10G10R10`   |
| BGR10A2 | `D3DFMT_A2R10G10B10`   |
| RGBA16  | `D3DFMT_A16B16G16R16`  |
| RGBA16F | `D3DFMT_A16B16G16R16F` |
| RGBA32F | `D3DFMT_A32B32G32R32F` |

d3d9.upgrade_RGBA8_renderTargetTo:\
d3d9.upgrade_RGBX8_renderTargetTo:\
d3d9.upgrade_BGRA8_renderTargetTo:\
d3d9.upgrade_BGRX8_renderTargetTo:\
d3d9.upgrade_RGB10A2_renderTargetTo:\
d3d9.upgrade_BGR10A2_renderTargetTo:

Supported values: `"disabled"`, `"rgb10a2"`, `"bgr10a2"`, `"rgba16"`, `"rgba16f"`, `"rgba32f"`\
Default/Fallback: `"rgba16f"`


d3d9.upgrade_RGBA16_renderTargetTo:

Supported values: `"disabled"`, `"rgba16f"`, `"rgba32f"`\
Default/Fallback: `"rgba16f"`


## d3d9.enableSwapchainUpgrade

Enable Upgrading the swapchain format and color space.\
See [d3d9.upgradeSwapchainFormatTo](#d3d9upgradeSwapchainFormatTo) and [d3d9.upgradeSwapchainColorSpaceTo](#d3d9upgradeSwapchainColorSpaceTo).

Supported values: `True`, `False`\
Default/Fallback: `False`


## d3d9.upgradeSwapchainFormatTo

Upgrade the output format to a higher bit depth one.

Needs '[d3d9.enableSwapchainUpgrade](#d3d9enableSwapchainUpgrade) = True'!\
Use in combination with [d3d9.upgradeSwapchainColorSpaceTo](#d3d9upgradeSwapchainColorSpaceTo)!

What works depends on your hardware and display combination.\
AMD graphics cards on Windows allow for a stupid amount of combinations.

Check the allowed ones with:\
`vulkaninfo | grep -E 'format =|colorSpace ='`

On Windows open up powershell and input this:\
`vulkaninfo | Select-String -CaseSensitive "format =|colorSpace ="`

There is a fallback mechanism in place if the format + color space combo is not allowed. Check the logs to see what combo is being used.

Supported values: `"disabled"`, `"rgb10a2"`, `"bgr10a2"`, `"rgba16"`, `"rgba16f"`\
Default/Fallback: `"rgba16f"`


## d3d9.upgradeSwapchainColorSpaceTo

Upgrade the output color space.
Needs '[d3d9.enableSwapchainUpgrade](#d3d9enableSwapchainUpgrade) = True'!\
Use in combination with [d3d9.upgradeSwapchainFormatTo](#d3d9upgradeSwapchainFormatTo)!

There is a fallback mechanism in place if the format + color space combo is not allowed. Check the logs to see what combo is being used.

Supported values: `"disabled"`, `"PQ"`, `"scRGB"`\
Default/Fallback: `"scRGB"`


## d3d9.enforceWindowModeInternally

Enforce the internal window mode. This also affects the window DXVK creates.\
This is mainly a workaround for games with buggy window code.\
Some games switch between windowed and fullscreen, which might cause issues with HDR engaging when using Vulkan's FSE.

Supported values: `"disabled"`, `"windowed"`, `"fullscreen"`\
Default/Fallback: `"disabled"`


## d3d9.logRenderTargetFormatsUsed

Log D3D formats that are being used by the application and the ones that are being upgraded.\
The main idea is to find render target formats that cause issues and change them to a working one or disable the upgrade.\
See [d3d9.upgrade_***_renderTargetTo](#d3d9upgrade__renderTargetTo).

Supported values: `True`, `False`\
Default/Fallback: `False`


## Example Usage

Output "overbright" data (needs further post processing):
```ini
d3d9.enableRenderTargetUpgrade = true
d3d9.upgrade_RGBA8_renderTargetTo   = "rgba16f"
d3d9.upgrade_RGBX8_renderTargetTo   = "rgba16f"
d3d9.upgrade_BGRA8_renderTargetTo   = "rgba16f"
d3d9.upgrade_BGRX8_renderTargetTo   = "rgba16f"
d3d9.upgrade_RGB10A2_renderTargetTo = "rgba16f"
d3d9.upgrade_BGR10A2_renderTargetTo = "rgba16f"
d3d9.upgrade_RGBA16_renderTargetTo  = "rgba16f"
d3d9.enableSwapchainUpgrade = true
d3d9.upgradeSwapchainFormatTo = "rgba16f"
d3d9.upgradeSwapchainColorSpaceTo = "scRGB"
```

Get rid off banding issues:
```ini
d3d9.enableRenderTargetUpgrade = true
d3d9.upgrade_RGBA8_renderTargetTo   = "rgba16"
d3d9.upgrade_RGBX8_renderTargetTo   = "rgba16"
d3d9.upgrade_BGRA8_renderTargetTo   = "rgba16"
d3d9.upgrade_BGRX8_renderTargetTo   = "rgba16"
d3d9.upgrade_RGB10A2_renderTargetTo = "rgba16"
d3d9.upgrade_BGR10A2_renderTargetTo = "rgba16"
d3d9.upgrade_RGBA16_renderTargetTo  = "disabled"
d3d9.enableSwapchainUpgrade = true
d3d9.upgradeSwapchainFormatTo = "rgb10a2"
d3d9.upgradeSwapchainColorSpaceTo = "disabled"
```
on AMD you can use:
```ini
d3d9.upgradeSwapchainFormatTo = "rgba16"
```
