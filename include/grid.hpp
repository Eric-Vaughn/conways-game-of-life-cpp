#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

class Grid
{
public:
    // Constructor
    // Deconstructor (std::vector handles its own memory, so a deconstructor isn't needed)
    // Getters
    // Setters
    // Methods
private:
    // Subclass: grid cell
    class Cell
    {
    public:
        // Constructor
        Cell(unsigned int xCoord, unsigned int yCoord) : x(xCoord), y(yCoord) {}

        // Deconstructor (We do not need a deconstructor)

        // Getters
        unsigned int getX() const { return x; }
        unsigned int getY() const { return y; }

        // Setters
        void setState(const bool value) { isAlive = value; }

        // Methods
        void flipState() { isAlive ? isAlive = false : isAlive = true; }

    private:
        const unsigned int CELL_SIZE = 30; // Constant size per cell (length & height)
        const unsigned int x, y;           // Coordinates, initialized in constructor
        bool isAlive = false;              // State
    };

    // Fixed Grid Dimensions
    const unsigned int NUM_ROWS = 10;
    const unsigned int NUM_COLS = 10;

    // 2D vector of grid cells
    std::vector<std::vector<Grid::Cell>> matrix;
};

#endif