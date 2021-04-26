# particles

Implements particle systems using openGL

![Fireworks Particle System](results/fireworks.gif)

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake -G "Visual Studio 16 2019" ..
particles/build $ start CS312-Particles.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
particles/build $ ../bin/Debug/billboard
particles/build $ ../bin/Debug/confetti
particles/build $ ../bin/Debug/demo
```

*macOS*

Open terminal to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake ..
particles/build $ make
```

To run each program from build, you would type

```
particles/build $ ../bin/billboard
particles/build $ ../bin/confetti
particles/build $ ../bin/demo
```

## Results

Confetti Particle System

![Confetti Particle System](results/confetti.gif)

Fireworks Particle System (using gravitational acceleration and particle life cycle)

![Fireworks Particle System](results/fireworks.gif)

Fireworks Particle System (with homogenous colors)

![Fireworks Particle System](results/fireworks2.gif)
