# Setup

In most cases, Open1560 should run optimally straight away.
You do not need to install the XP patch, or use dgVoodoo.
However, there are certain things you may wish to change:
* If you have a laptop, ensure you are using the correct GPU.
* To enable anti-aliasing, use the `-msaa <LEVEL>` argument (possible levels are 1, 2, 4 or 8). This may not be available on certain older/integrated GPUs.
* If you have low performance:
    * Try using the `-legacygl` argument.
    * Consider disabling cloud shadows, the rear view mirror, or lowering the far clip distance.
* If using Wine:
    * If the hardware renderer is slow, try enabling threaded OpenGL with the environment variable `mesa_glthread=true` for Mesa, or `__GL_THREADED_OPTIMIZATIONS=1` for Nvidia.
    * If the software renderer is slow, try setting the environment variable `SDL_RENDER_DRIVER=opengl`.
* If your cursor does not move properly, try `-mousemode 1` or `-mousemode 2`.

# Common Issues

* The application was unable to start correctly (0xc0000022)
    * Activate DirectPlay

# Command Line Arguments

Open1560 uses command line arguments to configure certain aspects of the game.<br/>
These can be passed on the command line, or in a file named `commandline.txt`.<br/>
For a tutorial on how to use command line arguments, click [here](https://www.bleepingcomputer.com/tutorials/understanding-command-line-arguments-and-how-to-use-them/).

## Examples

| Value      | Description |
| ---------- | --- |
| -window    | Sets window to true (1) |
| -nowindow  | Sets window to false (0) |
| -msaa 4    | Sets msaa to 4 |

## Game

| Name       | Value | Description |
| ---------- | ----- | --- |
| aiphysics | false | Sets AI-like physics midair
| allcars    | false | Unlocks All Cars |
| allrace    | false | Unlocks All Races |
| detachopptrailermph | 50 | Speed at which the opponent semi will detach its trailer
| maxcops    | 3     | Max cops chasing you at once |
| nodamage   | false | Disables Damage |
| maxoppcolors   | auto | Cycles through the opponent car colors based on the number of paintjobs available |

## Basic

| Name       | Value | Description |
| ---------- | ----- | --- |
| affinity   | 0     | Sets the process affinity |
| afilter    | 16    | Anisotropic filtering level |
| border     | true  | Enables a border when in windowed mode |
| cdid       | false | Enables CD music in the menu when using a virtual CD |
| config     | false | Forces redetection of graphics modes |
| console    | false | Enables console logging |
| d3d        | false | Use the D3D renderer |
| fovfix     | true  | Enables FOV scaling based on resolution |
| heapsize   | 64    | The size in MB of the game heap |
| legacygl   | false | Uses a legacy/compatibility OpenGL context |
| maxaspect  |       | Maximum aspect ratio of available resolutions |
| maxfps     | 0     | Limits the max fps |
| minaspect  |       | Minimum aspect ratio of available resolutions |
| mousemode  | 0     | Mouse mode. 0 = Relative (Raw Input), 1 = Relative (Mouse Warping), 2 = Absolute |
| msaa       | 0     | Sets the anti-aliasing level (does not work with legacy OpenGL) |
| nativeres  | true  | Enables rendering internally at the native window resolution (enabled when using -msaa or -legacygl) |
| opengl     | true  | Use the OpenGL renderer |
| prio       | 2     | Sets the process priority |
| scaling    | 0     | Sets the scaling mode. 0 = Stretched (Keep Aspect), 1 = Stretched, 2 = Centered, 3 = Centered (Integer Scaling) |
| smoothstep | true  | Smoothes out the time between frames to avoid stutter |
| speedrun   | false | Enables speedrunning conditions (currently -nosmoothstep -maxfps=60 -speedycops) |
| speedycops | false | Enables the vanilla cop speed boost (fps dependant) |
| vsync      | true  | Enables vertical sync |
| window     | false | Puts the game in a window |
| windowmenu | false | Puts the game in a borderless window when in the menu |

## Advanced

| Name        | Value | Description |
| ----------- | ----- | --- |
| agiverbose  | false | Enables AGI (graphics) logging |
| ancientgl   |       | Use fixed-function OpenGL pipeline (glBegin/glEnd).
| cleandir    | true  | Deletes various debug files from the games directory |
| fontscale   |       | Sets the debug font scale |
| gldebug     | -1    | Sets the OpenGL debug output level |
| glstream    |       | Sets the mode for streaming data to the GPU |
| sync        | true  | Disables multi-threading |

## DirectDraw

| Name       | Value | Description |
| ---------- | ---   | --- |
| reshack    | true  | Enables resolutions above 2048x2048 when using MS ddraw |
| voodooaa   | false | Fixes text rendering when using dgVodooo's anti aliasing |

# Dev/Debug Functions

Beta 1560 contains many debug functions/hotkeys. To enter debug mode, press CTRL+ALT+SHIFT+F4.
For a list of hotkeys, see https://github.com/0x1F9F1/Open1560/blob/master/extra/keys.txt
