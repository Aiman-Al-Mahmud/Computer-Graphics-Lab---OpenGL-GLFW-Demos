# Computer Graphics Lab - OpenGL GLFW Demos

Small OpenGL (immediate mode) demos built with GLFW. Each program renders a simple shape and applies a basic transformation ,scalling , rotation e.t.c .

## Subject

Computer Graphics Lab exercises focused on 2D primitives, viewing/viewport setup, transformations (translation, rotation, scaling), animation, and basic keyboard interaction using OpenGL + GLFW.

Keywords: computer graphics lab, OpenGL, GLFW, 2D transformations, viewport, animation

## Contents

- rectangle + triangle side‑by‑side scene.cpp: rectangle and triangle drawn side by side.
- rotated triangle and scaled triangle.cpp: split viewport; translated/rotated triangle (top-right) and scaled triangle (bottom-left).
- rotating triangle (toggle with space).cpp: rotating triangle (toggle with space).
- rotating‑triangle program.cpp: rotating triangle with faster spin (toggle with space).

## Controls

- rotated triangle and scaled triangle.cpp
  - R/L: move right/left
  - U/D: move up/down
  - Shift+S: start scaling animation
  - S: stop scaling animation
  - Esc: close window
- rotating triangle (toggle with space).cpp and rotating‑triangle program.cpp
  - Space: toggle rotation
  - Esc: close window
- rectangle + triangle side‑by‑side scene.cpp
  - no keyboard controls

## Build (Linux)

You need a C++ compiler, GLFW, and OpenGL.

Example build commands:

```bash
g++ "rectangle + triangle side‑by‑side scene.cpp" -o rectangle-triangle-scene -lglfw -lGL -ldl -lpthread

g++ "rotated triangle and scaled triangle.cpp" -o rotated-scaled-triangles -lglfw -lGL -ldl -lpthread

g++ "rotating triangle (toggle with space).cpp" -o rotating-triangle-toggle -lglfw -lGL -ldl -lpthread

g++ "rotating‑triangle program.cpp" -o rotating-triangle-fast -lglfw -lGL -ldl -lpthread
```

Run any program, for example:

```bash
./rotated-scaled-triangles
```

## Notes

- The include/ and src/ folders contain GLAD headers and source if you later decide to load OpenGL functions dynamically. These demos do not currently use GLAD.
