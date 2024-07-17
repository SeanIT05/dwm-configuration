#!/bin/sh

dunst &
feh --bg-scale --randomize ~/Wallpapers/* &
picom -f --no-vsync &
gentoo-pipewire-launcher &
playerctld daemon
ibus-daemon -rxRd
slstatus &
unclutter &
xrdb -merge ~/.Xresources

###
# while true; do
# 	dwm >/dev/null 2>&1
# done
###

exec dbus-launch --sh-syntax --exit-with-session dwm
