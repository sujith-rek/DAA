// Refer to the graph given in the form of an edge list in the attached file. Store the graph in an appropriate
// data structure and perform the following operations:
// 1. Find the largest connected component in the given graph and its size
// 2. Find the Girth of the graph


// # Directed graph (each unordered pair of nodes is saved once): Email-Enron.txt 
// # Enron email network (edge indicated that email was exchanged, undirected edges)
// # Nodes: 36692 Edges: 367662
// # FromNodeId	ToNodeId

#include<bits/stdc++.h>
using namespace std;


void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited){
    visited[u] = true;
    for(int v: graph[u]){
        if(!visited[v]){
            dfs(v, graph, visited);
        }
    }
}

int girth(vector<vector<int>> &graph){
    int n = graph.size();
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: graph[u]){
                if(dist[v] == INT_MAX){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
                else if(dist[v] >= dist[u]){
                    ans = min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
    }
    return ans;
}


int largest_connected_component(vector<vector<int>> &graph){
    int n = graph.size();
    vector<bool> visited(n, false);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, graph, visited);
            ans++;
        }
    }
    return ans;
}

vector<int> longest_connected_path(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: graph[u]){
            if(dist[v] == INT_MAX){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    int max_dist = 0;
    int max_node = 0;
    for(int i = 0; i < n; i++){
        if(dist[i] > max_dist){
            max_dist = dist[i];
            max_node = i;
        }
    }
    vector<int> path;
    while(max_node != -1){
        path.push_back(max_node);
        max_node = parent[max_node];
    }
    reverse(path.begin(), path.end());
    return path;
}


int main(){
    
    vector<vector<int>> graph(36692);


    ifstream file("Email-Enron.txt");
    string line;
    while(getline(file, line)){
        if(line[0] == '#') continue;
        int u, v;
        sscanf(line.c_str(), "%d%d", &u, &v);
        graph[u].push_back(v);
    }
    file.close();

    vector<int> path = longest_connected_path(graph);

    cout << "Length of longest connected componenet: " << path.size() << endl;
    cout << "Longest connected path: "<< endl;
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    // cout << "Girth: " << girth(graph) << endl;

}