This is **SimpleROHook updated to work with 2018-03-28ragexe from iRO RE:Start**. It *may* also support current (Renewal?) clients from other servers.

I have only tested the Bowling Bash gutterline and M2E functionality; judging by the logging console, some other stuff is definitely still wrong.

This fork also updates the project to Visual Studio 2015 (+ runtime).

Special thanks to [@phaicm](https://github.com/phaicm) for the old default M2E configuration and [@Toxetic](https://github.com/Toxetic) for previously providing trusted binaries and the new default M2E config!

The best place to **get technical support** and be notified of updates is #addon-support on **[iROWiki's Discord](https://discord.gg/Pe7UrnF)**.

### Download/Usage/Installation

* Install the [Visual C++ 2015 Redistributable](https://www.microsoft.com/en-us/download/details.aspx?id=53587) (32-bit version, `vc_redist.x86.exe`, even with 64-bit Windows) if you don't have it. If SimpleROHook shows you a "LoadLibrary failed" error, it's likely because you didn't do this.
* **Download the latest build** at https://github.com/drdaxxy/SimpleROHook/releases and extract the archive somewhere.
  * You need "SimpleROHook.xxxx-xx-xx.zip", not the source code.
* Run SimpleROHookCS.exe
  * Only clients started *after* SimpleROHook will be affected. You'll get a logging console for previously started ones, but no actual functionality.
* Right click the SimpleROHook icon in the system tray.
* Uncheck *Window* > *NPC Logger* as it's useless.
* Check *3D Map Grid* > *Show BBE* to show gutterlines.
* The display is a little glitchy on uneven terrain. Adjusting *3D Map Grid* > *Ground Z Bias* can help.
* *3D Map Grid* > *Alpha Level* controls the opacity of the gutterline overlay.
* Feel free to close the console window that pops up when you run a client.

#### Updating

* To update, just replace the files in your existing SimpleROHook installation with the files from the new archive.
* **If you want to keep your settings,** do *not* replace `config.ini` or `config.xml`!

#### Ground skill effect display (M2E)

* Check *3D Map Grid* > *Show M2E* to mark cells currently affected by ground targeting skills (Storm Gust etc.).
* You can edit `config.ini` to set colors for specific skills.

#### New: Custom colors for deadcell/chatscope/castrange/gutterlines

* Since Apr 11, 2018 you can change colors for the other features.
* Edit `config.ini` as with M2E, you'll find a new `[MiscColor]` section at the top.
* If you're updating from a previous version and would like to keep your M2E settings, this is the section you need to add to the top or bottom of the file:
  * **Do not** just add it somewhere in the middle, that would break all following M2E skill colors!
  
```
[MiscColor]
; Alpha is ignored for these - use the alpha level option in the GUI
Deadcell=0x00FF00FF
Chatscope=0x0000FF00
Castrange=0x007F00FF
Gutterline=0x00FF0000
Demigutter=0x000000FF
```
  
### Disclaimers

I did the minimum work necessary to make Bowling Bash gutterline display work on the client mentioned above, with only a few minutes of testing. If this ends up crashing your client, I'd appreciate a heads up, but don't yell at me if that loses you an MvP or something.

As of September 24, 2017, iRO's GM team [appears to tolerate gutterline and ground skill target display client edits](https://forums.warpportal.com/index.php?/topic/202141-ro1-in-game-rules-and-guidelines/). Keep in mind they may change their stance at any time and this doesn't necessarily apply to other servers. Whatever you do, use this tool at your own responsibility.
  
### Build instructions (for developers)

* Install the [August 2007 DirectX SDK](https://www.microsoft.com/en-us/download/details.aspx?id=13287). Other versions **will not work**.
  * Note this will overwrite your `DXSDK_DIR` environment variable. If you've had the June 2010 SDK installed before, you'll probably want to set it back.
  * Set `DXSDK_AUG07_DIR` to the August 2007 DirectX SDK directory, e.g. `C:\Program Files (x86)\Microsoft DirectX SDK (August 2007)`.
* Clone the repository.
* Open in **Visual Studio 2015** (may also work in 2017, untested).
* Select `Release-iRO/Mixed Platforms` build configuration.
* Build Solution.

### Original README

    SimpleROHook

    Simply extend Ragnarok Online.
    For example, display font on client screen,it can placed easily in 3D map.

    Copyright (C) 2014 redcat Planetleaf.com Lab. All rights reserved.

                              http://lab.planetleaf.com/memory-of-rcx


    SimpleROHook is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.