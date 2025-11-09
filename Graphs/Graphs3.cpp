// BFS Traversal --> breadh first search 
// BFS is a fundamental graph traversal algorithm. 
// It begins with a node, then first traverses all its adjacent. Once all
// adjacent are visited, then their adjacent are traversed.
// Here for the BFS queue is used to store the nodes
// Initialization: Enqueue the given source vertex into a queue and mark it as visited.
// Exploration: While the queue is not empty:
// Dequeue a node from the queue and visit it (e.g., print its value).
// For each unvisited neighbor of the dequeued node:   
// Enqueue the neighbor into the queue.
// Mark the neighbor as visited.    
// Termination: Repeat step 2 until the queue is empty.
// This algorithm ensures that all nodes in the graph are visited in a breadth-first manner, starting from the starting node.
// steps to follow 
// 1) Create the one vector that stores the visited nodes having length the number of vertices and initialize it with false
// 2) Create the queue to store the nodes
// 3) Push the source node in the queue and mark it as visited
// Node will look into its unvisited neighbour;
// 4) Push them in the queue and mark them as visited

// Space Complexity :- O(V) + O(V) // v is the number of vertex
// Time Complexity :- O(V + E) // v is the number of vertex and e is the number of edges

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal on a graph
vector<int> bfs(vector<vector<int>> &adj) {
    queue<int> q;                // Queue for BFS
    q.push(0);                   // Start BFS from node 0 (can be changed)
    
    vector<bool> visited(adj.size(), false);  // Track visited nodes
    visited[0] = true;            // Mark start node as visited
    
    vector<int> ans;              // Store BFS traversal order
    
    while(!q.empty()) {
        int node = q.front();     // Get the front node
        q.pop();                  // Remove it from queue
        
        ans.push_back(node);      // Add node to result
        
        // Explore all neighbors of the current node
        for(int j = 0; j < adj[node].size(); j++) {
            int neighbor = adj[node][j];  // Get neighbor
            
            if(!visited[neighbor]) {      // If not visited
                visited[neighbor] = true; // Mark as visited
                q.push(neighbor);         // Push into queue
            }
        }
    }
    return ans;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // adjacency list representation
    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // assuming 0-based input for vertices
        adj[u].push_back(v);
        adj[v].push_back(u); // if undirected graph
    }

    // Run BFS
    vector<int> result = bfs(adj);

    // Print BFS traversal order
    cout << "BFS Traversal: ";
    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


// DFS Traversal --> Depth First Search
// DFS is a fundamental graph traversal algorithm.
// It begins with a node, then first traverses as far as possible along each branch before backtracking.
// Here for the DFS stack is used to store the nodes
// It will visited all the neighbours one bye one 
// Agar usne saare neighbour explore karliye toh woh jahan se yahan ta wahi chala jayega 
// steps to follow
// 1) Create the one vector that stores the visited nodes having length the number of vertices and initialize it with false
// we are doing with the recursion 

// TIme Complexity will be O(V + E) // v is the number of vertex and e is the number of edges
// Space Complexity will be O(V) + O(V) // v is the number of vertex

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Helper function for DFS
    void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& visited) {
        visited[node] = true;        // mark node as visited
        ans.push_back(node);         // add node to result
        
        // explore all neighbors
        for(int j = 0; j < adj[node].size(); j++) {
            int neighbor = adj[node][j];
            if(!visited[neighbor]) {
                dfsHelper(neighbor, adj, ans, visited);
            }
        }
    }

    // Main DFS function
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(), false);
        vector<int> ans;
        
        // Call DFS starting from node 0 (can be modified)
        dfsHelper(0, adj, ans, visited);
        
        return ans;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        // assuming 0-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u); // if undirected
    }

    Solution sol;
    vector<int> result = sol.dfs(adj);

    cout << "DFS Traversal: ";
    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
