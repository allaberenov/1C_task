#include <iostream>
#include <map>
#include <vector>


const std::vector<int> Sides = {'r', 'u', 'l', 'd'};       //right, left.

struct Cell {
    char status; //###000 - ### visited, isKnown
    bool visited;

    bool IsVisited() {
        return visited;
    }

    bool IsWall() {
        return status == 'w';
    }

    bool IsKnown() {
        return status == '?';
    }

    void Set(char arg, bool vis) {
        status = arg;
        visited = vis;
    }

    std::pair<int, int> GetNeighbour(int i) {
    }

    Cell(char st, bool vis) : status(st), visited(vis) {};
    Cell() = default;
};


class Minotawr {
    char rotation;
    Cell minotawr_location_cell;
    std::pair<int, int> location;

    char GetRotation(int x, int y, int x1, int y1) {
        switch (x - x1) {
            case -1: {
                return 'd';
            }
            case 1: {
                return 'u';
            }
        }
        switch (y- y1) {
            case -1: {
                return 'l';
            }
            case 1: {
                return 'r';
            }
        }
        return 0;
    }

    Minotawr(int x, int y, int x1, int x2) {
        rotation = GetRotation(x, y, x1, x2);
        minotawr_location_cell = {'p', true};
    }
};

struct Labirint {
    int timer;


    void AddCell(char ch) {

    }

    void Rotate(char arg) {

    }


public:
    std::map<std::pair<int, int>, Cell> labirint;
    Minotawr minotawr;
    int A, B, C, K;

    Labirint(int x, int y, int x1, int y1, int a, int b, int c, int k) {
        A = a;
        B = b;
        C = c;
        K = k;
        minotawr(x, y, x1, y1)
        labirint.insert({x, y}, start);
        time = 0;
    }

    void LightFire(int x, int y) {
        std::cout << 3;
        time += K;

        char ch;
        for (size_t i = 0; i < 2 * K + 1; ++i) {
            for (size_t j = 0; j < 2 * K + 1; ++j) {
                std::cin >> ch;
            }
        }

    }

    std::pair<int, int> Pass(std::pair<int, int> current_loc) {            //return pass result

    }


    int FindRotation(char rotation) {

    }

    void dfs(std::pair<int, int> current_location) {
        int n = GetInformationVolume(current_location);
        labirint[current_location].visited = true;     //set visited
        if (2 * (A + B) * n < C) {
            LightFire(current_location.first, current_location.second);
            for (auto iter: Sides) {
                std::pair<int, int> neighbour = labirint[current_location].GetNeighbour(iter);

                if (labirint.find(neighbour) == labirint.end()) {        // neighbour isn't in labirint
                    continue;
                }

                if (!labirint[neighbour].IsVisited() && labirint[neighbour].IsWall()) {
                    if (rotation != iter) {
                        Rotate(FindRotate(rotation));
                    }
                    dfs(Pass(current_location));
                }
            }
        } else {
            for (size_t i = 0; i < 4; ++i) {
                std::pair<int, int> new_location = Pass(current_location);
                int result = -1;
                std::cin >> result;
                if (result == 1) {
                    dfs(new_location);
                } else {
                    Rotate(1);
                }
            }
        }


    }

    void Start() {
        dfs(location);
//
    }
};

int main() {
    int x, y, x1, y1;
    int a, b, c, k;
    std::cin >> x >> y >> x1 >> y1 >> a >> b >> c >> k;
    Labirint labirint(x, y, x1, y1, a, b, c, k);
    labirint.Start();

}