#include <iostream>
#include <queue>
#include <vector>
#include <array>

long gQueueLength, gMovesPerStep;
std::vector<std::pair<bool, long>> gQueues[2];
using Position = std::pair<bool, long>;
#define QUEUE first
#define ROW second
#define marked(a) gQueues[a.QUEUE][a.ROW].first
#define steps(a) gQueues[a.QUEUE][a.ROW].second
#define mark(a) marked(a) = true
#define neighbors(curr) std::array<Position, 3>({   \
    Position(curr.QUEUE, curr.ROW - 1),             \
    Position(curr.QUEUE, curr.ROW + 1),             \
    Position(!curr.QUEUE, curr.ROW + gMovesPerStep)})

void read_inputs() {
    std::cin >> gQueueLength >> gMovesPerStep;
    for (int i = 0; i < 2; i++) {
        getchar();
        for (long j = 0; j < gQueueLength; j++)
            gQueues[i].push_back(std::pair<bool, long>(getchar() == '.' ? false : true, 0));
    }
}

long find_shortest_distance() {
    std::queue<Position> bfsQ;
    marked(Position(0, 0)) = true;
    bfsQ.push(Position(0, 0));
    while (!bfsQ.empty()) {
        auto curr = bfsQ.front();
        bfsQ.pop();
        for (auto neigh : neighbors(curr)) {
            if (neigh.ROW >= gQueueLength)
                return steps(curr) + 1;
            if (!marked(neigh) && neigh.ROW >= steps(curr)) {
                steps(neigh) = steps(curr) + 1;
                mark(neigh);
                bfsQ.push(neigh);
            }
        }
    }
    return -1;
}

int main() {
    read_inputs();
    std::cout << find_shortest_distance() << std::endl;
    return 0;
}
