/*
BFS Traversal(Breadth First Search ) :-    
Breadth First Search (BFS) is a fundamental graph traversal algorithm. 
It begins with a node, then first traverses all its adjacent. Once all
 adjacent are visited, then their adjacent are traversed.

 Initialization: Enqueue the given source vertex into a queue and mark it as visited.

Exploration: While the queue is not empty:
Dequeue a node from the queue and visit it (e.g., print its value).
For each unvisited neighbor of the dequeued node:
Enqueue the neighbor into the queue.
Mark the neighbor as visited.
Termination: Repeat step 2 until the queue is empty.
This algorithm ensures that all nodes in the graph are visited in a breadth-first manner, starting from the starting node.
*/

// graph representation :-
// 1) Adjacency Matrix
// adjacency matrix is a 2D array of size V x V where V is the number of vertices in a graph.
// a value of 1 is stored at row i and column j if there is an edge from vertex i to vertex j.
// otherwise, a value of 0 is stored.
// If there is a weight associated with the edge, then the weight value is stored instead of 1.

// code part
// undirection unweighted graph 

// Space Complexity :- O(V2) // v is the number of vertex
// Time Complexity :- O(V2) 
#include <iostream>
using namespace std;
#include <vector>

int main() {
    int vertex, edges;
    cin >> vertex >> edges;
    // Initialize adjacency matrix with 0s
    // where first vertex is row and second vertex is column
    vector<vector<bool>> AdjMat(vertex, vector<bool>(vertex, 0));
    int u, v;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        // process the edge (u, v) as needed
        cout << "Edge from " << u << " to " << v << endl;
        AdjMat[u][v] = 1;
        AdjMat[v][u] = 1; // because undirected graph 
    }
        for(int i = 0; i < vertex; i++) {
            for(int j = 0; j < vertex; j++) {
                cout << AdjMat[i][j] <<" ";
            }
            cout << endl;
        }
    }

// Undirected weighted Graph
#include <iostream>
using namespace std;
#include <vector>

int main() {
    int vertex, edges;
    cin >> vertex >> edges;
    // Initialize adjacency matrix with 0s
    // where first vertex is row and second vertex is column
    vector<vector<int>> AdjMat(vertex, vector<int>(vertex, 0));
    int u, v, weight;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v >> weight;
        // process the edge (u, v) as needed
        cout << "Edge from " << u << " to " << v << endl;
        AdjMat[u][v] = weight;
        AdjMat[v][u] = weight; // because undirected graph 
    }
        for(int i = 0; i < vertex; i++) {
            for(int j = 0; j < vertex; j++) {
                cout << AdjMat[i][j] <<" ";
            }
            cout << endl;
        }
    }

// Directed Weighted Graph 
#include <iostream>
using namespace std;
#include <vector>

int main() {
    int vertex, edges;
    cin >> vertex >> edges;
    // Initialize adjacency matrix with 0s
    // where first vertex is row and second vertex is column
    vector<vector<int>> AdjMat(vertex, vector<int>(vertex, 0));
    int u, v, weight;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v >> weight;
        // process the edge (u, v) as needed
        cout << "Edge from " << u << " to " << v << endl;
        AdjMat[u][v] = weight;
 
    }
        for(int i = 0; i < vertex; i++) {
            for(int j = 0; j < vertex; j++) {
                cout << AdjMat[i][j] <<" ";
            }
            cout << endl;
        }
    }

// 2) Adjacency List
// An adjacency list is a collection of unordered lists used to represent a finite graph.
// Each list describes the set of neighbors of a vertex in the graph.
// Space Complexity :- O(V + E) // v is the number of vertex and e is the number of edges
// The worst case space complexity of an adjacency list is O(V2) [complete graph]
// Time Complexity :- O(V + E)
// The worst case time complexity for searching an edge is O(V2) in an adjacency list. [complete graph]

// Undirected Graph unweighted using adjacency list representation
#include <iostream>
using namespace std;
#include <vector>

int main() {
    int vertex, edges;
    cin >> vertex >> edges;

    vector<pair<int, int>> AdjList[vertex];
    int u, v, weight;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v >>  weight;
        AdjList[u].push_back(make_pair(v, weight));
        AdjList[v].push_back(make_pair(u, weight));
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

// Comparison between adjacency matrix and adjacency list
// Add edges in the adjancecy matrix is O(1) and in adjacency list is O(1)
// Remove edges in the adjancecy matrix is O(1) and in adjacency list is O(V) // V is the number of edges
// Edge existence in the adjancecy matrix is O(1) and in adjacency list is O(V) // V is the number of edges
// If there is dense graph then use adjacency matrix otherwise use adjacency list 
// Dense graph :- A graph in which the number of edges is close to the maximum number of edges. 
// Sparse graph :- A graph in which the number of edges is far less than the maximum number of edges.
// use adjacency list for sparse graph and adjacency matrix for dense graph

// Trees vs Graphs
// A tree is a special type of graph that is connected and acyclic.
// All trees are graphs, but not all graphs are trees.
// A tree with n vertices has exactly n-1 edges, while a graph can have any number of edges.
// Trees have a hierarchical structure with a single root node, while graphs can have multiple connections and cycles.
// Trees are often used to represent hierarchical data, while graphs are used to represent more complex relationships.