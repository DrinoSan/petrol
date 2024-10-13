#!/bin/sh

set -xe

gcc -std=c2x `pkg-config --cflags raylib` -o main main.c Player.c `pkg-config --libs raylib` -lm -lpthread -L/opt/homebrew/lib -lglfw -framework CoreFoundation -framework Cocoa -framework IOKit -framework OpenGL -Wall
