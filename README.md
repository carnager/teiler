# teiler - a little screenshot tool written in bash

teiler uses or rofi to draw a menu which lets you
choose between screenshots or screencasts.

## Screenshot

![teiker](screenshot.png "teiler in action")

## Features
* screenshots fullscreen/monitor/area
* delay of screenshots
* screencasts of monitor/area
* upload screenshots/screencasts - teiler can also upload your files via scp, imgur or filebin, ix (for pastes) and amazon s3.
* History of Images and Videos with support for Viewing, Editing and Uploading
* Commandline interface for direct access to all features. Useful for hotkeys

## Dependencies:

* xininfo (https://github.com/DaveDavenport/xininfo)
* rofi (https://github.com/DaveDavenport/rofi)
* ffmpeg (http://www.ffmpeg.org)
* xclip
* maim (https://github.com/naelstrof/maim)
* slop (https://github.com/naelstrof/slop)

## Optional Dependencies

* imgur (http://imgur.com/tools/imgurbash.sh) (teiler expects this without a suffix)
* filebin (http://git.server-speed.net/users/flo/filebin)
* openssh (http://www.openssh.com)
* ix (http://ix.io)
* s3 cli tools

