#!/bin/bash

# Colors
# Ansi color code variables
red="\e[0;91m"
blue="\e[0;94m"
expand_bg="\e[K"
blue_bg="\e[0;104m${expand_bg}"
red_bg="\e[0;101m${expand_bg}"
green_bg="\e[0;102m${expand_bg}"
green="\e[0;92m"
white="\e[0;97m"
bold="\e[1m"
uline="\e[4m"
reset="\e[0m"

if ping -c 1 gentoo.org; then
  echo -e "${red}It appears you have a working internet connection"
fi

sleep 3;

emerge -av sudo zsh scrot neofetch dev-vcs/git mirrorselect \
htop gentoolkit genlop xorg-server alsa-mixer       \
mlocate io-scheduler-udev-rules grub vim libXrandr

sleep 3;

clear

echo -e "${red}Dependencies have been compiled"

