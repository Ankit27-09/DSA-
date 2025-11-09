/*
What is Graph?
Graph Data Structure is a non-linear data structure consisting of vertices and edges. It is useful in fields such as social network analysis,
recommendation systems, and computer networks. In the field of sports data science, graph data structure can be used to analyze and understand 
the dynamics of team performance and player interactions on the field.

Types Of Graphs in Data Structure and Algorithms
1. Null Graph
A graph is known as a null graph if there are no edges in the graph.

2. Trivial Graph
Graph having only a single vertex, it is also the smallest graph possible. 

3. Undirected Graph
A graph in which edges do not have any direction. That is the nodes are unordered pairs in the definition of every edge. 

4. Directed Graph
A graph in which edge has direction. That is the nodes are ordered pairs in the definition of every edge.

5. Connected Graph
The graph in which from one node we can visit any other node in the graph is known as a connected graph. 

6. Disconnected Graph
The graph in which at least one node is not reachable from a node is known as a disconnected graph.

7. Regular Graph
The graph in which the degree of every vertex is equal to K is called K regular graph.

8. Complete Graph
The graph in which from each node there is an edge to each other node.
// In a complete graph the number of edges is n(n-1)/2 where n is the number of vertices in the graph.
9. Cycle Graph
The graph in which the graph is a cycle in itself, the minimum value of degree of each vertex is 2. 

10. Cyclic Graph
A graph containing at least one cycle is known as a Cyclic graph.

11. Directed Acyclic Graph
A Directed Graph that does not contain any cycle. 

12. Bipartite Graph
A graph in which vertex can be divided into two sets such that vertex in each set does not contain any edge between them.

13. Weighted Graph
 A graph in which the edges are already specified with suitable weight is known as a weighted graph. 
 Weighted graphs can be further classified as directed weighted graphs and undirected weighted graphs. 

 14. Dense Graph
    A graph in which the number of edges is close to the maximum number of edges.

 15. Sparse Graph
    A graph in which the number of edges is far less than the maximum number of edges.   
 */

/*

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertex, edges;
    cin >> vertex >> edges;

    if (vertex <= 0 || edges < 0) {
        cout << "Invalid number of vertices or edges." << endl;
        return -1;
    }

    vector<vector<bool>> AdjMatrix(vertex, vector<bool>(vertex, 0));

    int u, v;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        if (u < 0 || u >= vertex || v < 0 || v >= vertex) {
            cout << "Invalid edge input: " << u << " " << v << endl;
            return -1;
        }
        AdjMatrix[u][v] = 1;
        AdjMatrix[v][u] = 1;
    }

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/

// Adjacency Matrix
// undirected weighted graph

/*
#include <iostream>
using namespace std;
#include <vector>

int main() {

    int vertex, edges;
    cin >> vertex >>  edges;

    if (vertex <= 0 || edges < 0) {
        cout << "Invalid number of vertices or edges." << endl;
        return -1;
    }

    vector<vector<int>> AdjMatrix(vertex, vector<int>(vertex,0));

    int u, v, weight;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v >> weight;
        AdjMatrix[u][v] = weight;
        AdjMatrix[v][u] = weight;
    }

    for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++){
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl; 
    }

}
*/

// Adjacency Matrix
// Directed Graph

/*
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<bool>>AdjMat(vertex, vector<bool>(vertex,0));

    int u, v;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        AdjMat[u][v] = 1;
    }

    for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++) {
            cout << AdjMat[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
} */

/*
#include <iostream>
using namespace std;
#include <vector>

int main() {
    int vertex, edges;
    cin >> vertex >> edges;

    if (vertex <= 0 || edges < 0) {
        cout << "Invalid number of vertices or edges." << endl;
        return -1;
    }

    vector<vector<int>> AdjMat(vertex, vector<int>(vertex, 0));

    int u, v, weight;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> weight;

        // Validate edge indices
        if (u < 0 || u >= vertex || v < 0 || v >= vertex) {
            cout << "Invalid edge input: " << u << " " << v << endl;
            return -1;
        }

        AdjMat[u][v] = weight;
    }

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << AdjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/

// undirected graph(no weight)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertex, edges;
    cin >> vertex >> edges;
    
    vector<int> AdjList[vertex];
    int u, v;
    
    // Input edges
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    
    // Print the adjacency list
    for (int i = 0; i < vertex; i++) {
        cout << i << " -> ";
        for (int j = 0; j < AdjList[i].size(); j++) { // Correct loop increment here
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

