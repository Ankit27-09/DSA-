#include <iostream>
// using namespace std;
// #include <vector>

// int main() {
//     int vertex, edges;
//     cin >> vertex >> edges;
//     // Initialize adjacency matrix with 0s
//     // where first vertex is row and second vertex is column
//     vector<vector<bool>> AdjMat(vertex, vector<bool>(vertex, 0));
//     int u, v;
//     for(int i = 0; i < edges; i++) {
//         cin >> u >> v;
//         // process the edge (u, v) as needed
//         cout << "Edge from " << u << " to " << v << endl;
//         AdjMat[u][v] = 1;
//         AdjMat[v][u] = 1; // because undirected graph 
//     }
//         for(int i = 0; i < vertex; i++) {
//             for(int j = 0; j < vertex; j++) {
//                 cout << AdjMat[i][j] <<" ";
//             }
//             cout << endl;
//         }
//     }