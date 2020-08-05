# Raise the terrain

---

Using the SDL2 library, draw a matrix in 3D using a file with values depths.

### Compiling

```gcc
gcc -Wall -Werror -Wextra -pedantic Source/*.c -lm $(sdl2-config --cflags --libs) -o Raise_the_terrain
```

or

```bash
./compile.sh
```

### Using

```
./Raise_the_terrain [path/of/file]
```

in tests directory has a any files for test the program.

### Controls

[🡄]left arrow: rotate grid to left

[🡆]right arrow: rotate grid to right

---

## Author

* **Cristian A. Murcia T. ** - [Cris-Mur](https://github.com/Cris-Mur/)