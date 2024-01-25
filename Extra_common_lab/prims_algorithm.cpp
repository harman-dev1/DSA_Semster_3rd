#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adjList;

public:
    void addVertex(int v) {
        if (adjList.find(v) == adjList.end()) {
            adjList[v] = vector<int>();
        }
    }

    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1); // Uncomment if undirected graph
    }

    void displayGraph() {
        for (auto it = adjList.begin(); it != adjList.end(); ++it) {
            cout << it->first << " -> ";
            for (int neighbor : it->second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    g.displayGraph();

    return 0;
}
