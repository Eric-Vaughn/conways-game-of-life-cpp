#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

class Grid
{
    // MUST put private first because some Grid methods rely on Cell subclass
    // Cell must be defined before the Grid class can use it
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

    // 2D vectors of grid cells
    std::vector<std::vector<Grid::Cell>> currentMatrix; // Frame 0
    std::vector<std::vector<Grid::Cell>> nextMatrix;    // Frame 1

    // TODO: Rule list

public:
    // Constructor
    Grid();

    // Deconstructor (std::vector handles its own memory, so a deconstructor isn't needed. May write one anyway.)

    // =================
    // ==== Getters ====
    // =================

    // Get the current matrix state
    std::vector<std::vector<Grid::Cell>> getCurrMatrix();
    // Get the next matrix state
    std::vector<std::vector<Grid::Cell>> getNextMatrix();

    // Get a specific Cell, immutable
    const Cell &getCellAt(const unsigned int x, const unsigned int y) const;
    // Get a specific Cell, mutable
    Cell &getCellAt(const unsigned int x, const unsigned int y);
    // Get a specific Cell's state
    bool getCellStateAt(const unsigned int x, const unsigned int y) const;

    // =================
    // ==== Setters ====
    // =================
    
    // Flips the given Cell's state (alive/dead | on/off | true/false)
    void flipCellState(Grid::Cell &cell);

    // =================
    // ==== Methods ====
    // =================

    // Advance the Grid by one frame
    void UpdateCurrentGrid();
    // Create what the Grid's next frame will be
    void UpdateNextGrid();
    // Draw the current Grid visually
    void Draw();
    // Make all Cells in the Grid dead/off
    void ResetGrid();
    // Check specific Cell against Grid's ruleset
    bool shouldCellSwitchState(const Grid::Cell &cell) const;
};

#endif