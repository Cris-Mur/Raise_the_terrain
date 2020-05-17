#!/bin/bash

gcc -Wall -Werror -Wextra -pedantic Source/*.c -lm $(sdl2-config --cflags --libs) -o Raise_the_terrain
