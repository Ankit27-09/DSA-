// Undirected Graph unweighted using adjacency list representation
#include <iostream>
using namespace std;
#include <vector>

int main() {
    int vertex, edges;
    cin >> vertex >> edges;

    vector<int> AdjList[vertex];
    int u, v;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    // print the adjacency list

    for(int i = 0; i < vertex; i++) {
        cout << i << " -> ";
        for(int j = 0; j < AdjList[i].size(); j++) {
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }
}

// undirected weighted graph 
#include <iostream>
using namespace std;
#include <vector>

int main() {
    int vertex, edges;
    cin >> vertex >> edges;

    vector<pair<int, int>> AdjList[vertex];
    int u, v, weight;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        AdjList[u].push_back(make_pair(v, weight));
        AdjList[v].push_back(make_pair(u, weight));
    }

    // print the adjacency list

    for(int i = 0; i < vertex; i++) {
        cout << i << " -> ";
        for(int j = 0; j < AdjList[i].size(); j++) {
            cout << "(" << AdjList[i][j].first << ", " << AdjList[i][j].second << ") ";
        }
        cout << endl;
    }
}