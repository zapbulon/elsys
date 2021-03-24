#include <iostream>
#include <array>

using namespace std;

class Cell {

};

template<int WIDTH, int HEIGHT>
class Maze {
public:
    Maze() {}

    void setLayout(const char* layout) {
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                cout << layout[row * WIDTH + col] << (col == WIDTH-1 ? "\n" : "");
            }
        }
    }
private:
    std::array<std::array<Cell, HEIGHT>, WIDTH> board;
};

int main() {
    // 21
    // # swamp +6
    // * speed boost 2 for 1 next 4 moves

    const char* layout =
        "@@@@@@@@@"
        "@       @"
        "@ @@#@@ @"
        "@     @  "
        "@@@ @ @@@"
        "@   @   @"
        "@@@@@@@ @";

    Maze<9, 7> maze;

    maze.setLayout(layout);
}