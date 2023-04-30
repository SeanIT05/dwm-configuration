#!/bin/sh
 
 picom -f &
 unclutter &
 slstatus &
 feh --bg-tile .local/share/bg



 # Loop
 #while true; do
 #	dwm >/dev/null 2>&1
 #done

 # Start DWM
 exec dwm

