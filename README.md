# cub3D

A first-person 3D maze in the style of *Wolfenstein 3D*, written in C with the MiniLibX. The 3D view is rendered in real time by **raycasting** from a 2D map described in a `.cub` file.

42 project, built as a team of two.

![C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)
![MiniLibX](https://img.shields.io/badge/MiniLibX-X11-555)
![Raycasting](https://img.shields.io/badge/raycasting-DDA-a371f7)

## Features

- **Raycasting with DDA**: one ray per screen column, using the perpendicular wall distance to avoid the fish-eye effect
- **Textured walls**: a different 64 × 64 XPM texture for the north, south, east and west faces
- **Floor and ceiling colours** read from the map file
- **Smooth controls**: keys can be held together (move, strafe and turn at the same time), with wall collisions
- **Strict map parser**: checks textures, RGB values, closed walls and a single player, with 30 invalid maps in `maps/bad/` to test it

## Controls

| Key | Action |
|---|---|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Strafe left / right |
| `←` / `→` | Turn left / right |
| `Esc` or the window's close button | Quit |

## Build and run

Requirements: Linux with X11. The MiniLibX for Linux is included in `mlx/`.

```bash
sudo apt install gcc make xorg libxext-dev libbsd-dev zlib1g-dev   # MiniLibX dependencies
git clone https://github.com/Tpicoulegiusta/cub3D.git
cd cub3D
make
./cub3D map.cub
```

## Map format

A `.cub` file gives the four wall textures, the floor (`F`) and ceiling (`C`) colours, then the map:

```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm

F 20,20,20
C 200,200,200

111111111111
100000000001
1000N0000001
111111111111
```

`1` is a wall, `0` is empty space, and `N`, `S`, `E` or `W` is the player's starting position and direction. The map must be closed by walls. See [`map.cub`](map.cub) for a complete map.

## How it works

1. **Parsing**: the `.cub` file is read and validated: textures, colours, map characters, closed walls, exactly one player.
2. **Ray direction**: for each screen column, a ray is cast from the player's position along the view direction, offset along the camera plane.
3. **DDA**: the ray walks through the grid one cell at a time until it hits a wall.
4. **Projection**: the perpendicular distance to the wall gives the height of the wall slice. The exact hit point selects the column of the texture to draw.
5. **Frame**: ceiling and floor are filled, the textured slices are drawn into an image, and the image is pushed to the window on every loop.

## Project structure

```
.
├── cub3d.c, cub3d.h       entry point and shared types
├── parsing*.c             .cub file and map validation
├── algo.c, raycasting.c   DDA and rendering
├── inputs*.c, multitouch.c movement, rotation and held-key state
├── win_manage.c           window, hooks and clean exit
├── mlx/                   MiniLibX (Linux)
├── maps/good, maps/bad    valid and invalid test maps
└── textures/              XPM wall textures
```

## Team

- **Tommi Picoulet-Giusta** (tpicoule)
- **rbulanad**: [lien GitHub à ajouter]
