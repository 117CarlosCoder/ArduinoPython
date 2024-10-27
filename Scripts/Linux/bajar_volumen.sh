#!/bin/bash
export PULSE_SERVER=unix:/run/user/$(id -u)/pulse/native
pactl set-sink-volume @DEFAULT_SINK@ -5%

