# 🎮 Cub3D - 42 Project

> *A Wolfenstein 3D-inspired raycasting game engine built from scratch in C*

[![42 Project](https://img.shields.io/badge/42-Project-blue)](https://42.fr)
[![Made with C](https://img.shields.io/badge/Made%20with-C-orange)](https://en.wikipedia.org/wiki/C_(programming_language))

---

## 📋 Overview

**Cub3D** is a 42 school graphics programming project that challenges you to create a realistic 3D graphical representation of a maze from a first-person perspective. Using the **raycasting technique** pioneered by games like Wolfenstein 3D and early DOOM, this project demonstrates how to render 3D-like environments without actual 3D geometry.

The project bridges multiple computer science concepts: file parsing, mathematical algorithms, graphics rendering, and real-time game development.

---

## 🎯 What Does This Project Do?

Cub3D transforms a simple 2D map into an immersive first-person 3D experience:

1. **Reads & Parses** `.cub` map files containing maze layouts and configuration
2. **Validates** map integrity (closed walls, valid player position, proper elements)
3. **Renders** a 3D perspective view using raycasting mathematics
4. **Textures** walls based on orientation (North, South, East, West)
5. **Handles** real-time player movement and camera rotation
6. **Displays** floor and ceiling colors for complete environment immersion

---

## ✨ Features

### 🔷 Mandatory Part

#### Map Parsing System
- **File Validation** - Strict `.cub` format checking with error handling
- **Element Extraction** - Parses textures paths, colors (RGB), and map grid
- **Map Validation** - Ensures walls are closed, detects invalid characters
- **Player Detection** - Identifies starting position and orientation (N/S/E/W)

#### Raycasting Engine
- **Ray Projection** - Casts rays for each screen column to detect walls
- **Distance Calculation** - Uses DDA algorithm for precise wall intersections
- **Wall Height Rendering** - Projects wall slices based on calculated distances
- **Texture Mapping** - Applies correct texture strips to wall surfaces
- **Fish-eye Correction** - Prevents distortion in peripheral vision

#### Player Controls
- **Movement** - W/A/S/D keys for forward, left, backward, right
- **Rotation** - Arrow keys for camera rotation
- **Collision Detection** - Prevents walking through walls
- **Smooth Navigation** - Frame-independent movement

### 🔶 Bonus Features

- **Animated Sprites** - Dynamic sprite system with multiple animation states
  - Idle animations
  - Firing animations
  - Reloading sequences
- **Minimap** - Real-time 2D map overlay showing player position
- **Enhanced Visuals** - Additional graphical improvements
- **Wall Collision** - Advanced collision system

---

## 🔧 Technical Concepts

### The 2.5D Rendering Technique

Cub3D doesn't use true 3D graphics. Instead, it employs a clever **2.5D rendering technique**:

**How Raycasting Works:**
1. **Ray Generation** - For each vertical column of pixels on screen, cast a ray from the player's position
2. **Wall Detection** - Calculate where the ray intersects with walls using DDA (Digital Differential Analysis)
3. **Distance Calculation** - Measure the perpendicular distance to the wall (avoiding fish-eye effect)
4. **Wall Height Projection** - Closer walls appear taller, farther walls appear shorter
5. **Texture Sampling** - Extract the correct vertical slice from the wall texture
6. **Rendering** - Draw the textured wall slice to the screen

**Why 2.5D?**
- Simulates 3D perspective without true 3D geometry
- Computationally efficient (1990s hardware could run it)
- Perfect for maze-like environments on a single horizontal plane
- No pitch control (can't look up/down in classic implementation)

This technique is constrained to horizontal planes, making it ideal for maze navigation but limiting vertical movement.

---

## 🚀 Installation & Usage

### Prerequisites
- **MiniLibX** graphics library
- **GCC** compiler
- **Make**

### Building the Project

```bash
# Clone the repository
git clone <repository_url> neoCub
cd neoCub

# Build mandatory version
make

# Build with bonus features
make bonus

# Clean build files
make clean      # Remove object files
make fclean     # Remove object files and executable
make re         # Rebuild from scratch
```

### Running the Game

```bash
# Mandatory version
./cub3D maps/map.cub

# Bonus version
./cub3D_bonus maps/map.cub
```

### Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Move left |
| `D` | Move right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `ESC` | Exit game |

---

## 📁 Project Structure

```
mandatory/       # Core implementation
├── parsing/     # Map file parser and validator
├── raycasting/  # Rendering engine
└── include/     # Header files

bonus/           # Extended features
├── parsing/     # Enhanced parser
├── raycasting/  # Enhanced engine with sprites
├── sprites/     # Animation assets
└── include/     # Bonus headers

maps/            # Example map configurations
textures/        # Wall texture images
```

---

## 🎓 Learning Outcomes

- **Graphics Programming** - Low-level rendering and pixel manipulation
- **Mathematical Algorithms** - Trigonometry, vector math, DDA algorithm
- **File Parsing** - Robust input validation and error handling
- **Game Development** - Real-time rendering, player input, game loops
- **Optimization** - Performance considerations for real-time graphics
- **C Programming** - Memory management, pointers, data structures

---

**42 Project** • *Exploring the foundations of computer graphics and game development*