#!/bin/bash

if [ "$1" == "zoom_in" ]; then
    echo "Haciendo zoom in..."
    xdotool key ctrl+plus  # Esto simula Ctrl + '=' (zoom in)
elif [ "$1" == "zoom_out" ]; then
    echo "Haciendo zoom out..."
    xdotool key ctrl+minus  # Esto simula Ctrl + '-' (zoom out)
else
    echo "Comando no válido."
fi


