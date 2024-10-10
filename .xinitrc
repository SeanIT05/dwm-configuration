#!/bin/sh

dunst &
feh --bg-scale --randomize ~/Wallpapers/* &
gentoo-pipewire-launcher &
playerctld daemon
ibus-daemon -rxRd
gammastep -c .config/gammastep/config.ini &
slstatus &
unclutter &
xrdb -merge ~/.Xresources

exec dbus-launch --sh-syntax --exit-with-session dwm
