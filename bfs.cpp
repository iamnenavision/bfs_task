#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <limits.h>

using namespace std;

void bfs(const vector<vector<int>>& graph, int start, vector<int>& distances) {
    int n = graph.size();
    distances.assign(n, INT_MAX);
    distances[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (distances[v] == INT_MAX) {
                distances[v] = distances[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ifstream file("graph.txt");

    int n, m;
    file >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        file >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    file >> start;

    file.close();

    vector<int> distances;

    bfs(graph, start, distances);

    for (int i = 0; i < n; ++i) {
        cout << distances[i] << endl;
    }

    return 0;
}
