#!/bin/sh

feh --bg-scale --randomize ~/Wallpapers/* &
picom -f --no-vsync &
pulseaudio --start &
playerctld daemon
slstatus &
unclutter &
# setxkbmap (yourkeyboardlanguage)
# Loop
 #while true; do
 #      dwm >/dev/null 2>&1
 #done

 # Start DWM
redshift &
exec dbus-launch dwm
