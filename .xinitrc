#!/bin/sh

dunst &
feh --bg-scale --randomize ~/Wallpapers/* &
picom -f --no-vsync &
playerctld daemon
ibus-daemon -rxRd
slstatus &
unclutter &
redshift &
gentoo-pipewire-launcher &
xrdb -merge ~/.Xresources
exec dbus-launch --sh-syntax --exit-with-session dwm
