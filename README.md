# teiler - a little screenshot tool written in bash

teiler uses dmenu (or simpleswitcher-dd) to draw a menu which lets you
choose between screenshots or screencasts.

screenshots can be delayed and you can also draw areas to capture.
teiler can also upload your files via scp, ix, imgur or filebin. (http://git.server-speed.net/users/flo/filebin/)

Last, but not least teiler can store your Screenshots in clipboard for use in other applications.

## Dependencies:

* xininfo (https://github.com/DaveDavenport/xininfo)
* dmenu2 (https://bitbucket.org/melek/dmenu2) OR
* simpleswitcher-dd (https://github.com/DaveDavenport/simpleswitcher)
* dzen2 with xft, xinerama patches (https://sites.google.com/site/gotmor/dzen)
* ffmpeg
* xclip
* scrot
* pygtk

## Optional Dependencies

* fb-client
* dmenu2
* simpleswitcher-dd-git
* xorg-xwininfo
* gtk2
* gtk3
* xdotool
* imgur
* ix
