#include "config.h"

// The name of the game window
const std::string WINDOW_TITLE { "Minesweeper" };
// The number of images displayed per second
const int WINDOW_FPS { 60 };

// The dimensions of the grid (in pixels)
const Vector2 GRID_SIZE { 40, 22 };
// The length of the side of a cell (in pixels)
const float CELL_SIZE { 32 };

// The dimensions of the window (in pixels)
const Vector2 WINDOW_SIZE { GRID_SIZE * CELL_SIZE };