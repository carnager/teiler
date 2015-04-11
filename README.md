# teiler - a little screenshot tool written in bash

teiler uses dmenu (or rofi) to draw a menu which lets you
choose between screenshots or screencasts.

screenshots can be delayed and you can also draw areas to capture.
teiler can also upload your files via scp or filebin. (http://git.server-speed.net/users/flo/filebin/)
Editing your screenshots before uploading is also supported.

Last, but not least teiler can store your Screenshots in clipboard for use in other applications.

## Dependencies:

* xininfo (https://github.com/DaveDavenport/xininfo)
* dmenu2 (https://bitbucket.org/melek/dmenu2) OR
* rofi (https://github.com/DaveDavenport/rofi)
* dzen2 with xft, xinerama patches (https://sites.google.com/site/gotmor/dzen)
* ffmpeg (http://www.ffmpeg.org)
* xclip
* maim (https://github.com/naelstrof/maim)
* slop (https://github.com/naelstrof/slop)

## Optional Dependencies

* imgur (http://imgur.com/tools/imgurbash.sh) (teiler expects this without a suffix)
* filebin (http://git.server-speed.net/users/flo/filebin)
* openssh (http://www.openssh.com)
* s3cmd (http://s3tools.org/s3cmd)
* ix (http://ix.io)
* copyq (https://github.com/hluk/CopyQ)

