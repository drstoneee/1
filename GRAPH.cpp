
//bfs dfs degree create(list/matrix) display

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class Graph
{

    int V;
    vector<vector<int>>  adj;

    public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void depthFirstSearchUtil(int vertex, vector<bool>& visited, vector<int>& ans)
    {
        visited[vertex] = true;
        
        ans.push_back(vertex);
        cout << vertex << " ";
        for (int neighbor : adj[vertex])
            if (!visited[neighbor])
                depthFirstSearchUtil(neighbor, visited, ans);

        
    }

    vector<int> depthFirstSearch(int startingVertex)
    {
        vector<int> ans;
        vector<bool> visited(V, false);
        depthFirstSearchUtil(startingVertex, visited,ans);

        return ans;

    }


    void breadthFirstSearch(int startingVertex) {
        vector<bool> isVertexVisited(V, false);
        queue<int> vertexQueue;

        isVertexVisited[startingVertex] = true;
        vertexQueue.push(startingVertex);

        while (!vertexQueue.empty()) {
            int currentVertex = vertexQueue.front();
            cout << currentVertex << " ";
            vertexQueue.pop();

            for (int neighbor : adj[currentVertex]) {
                if (!isVertexVisited[neighbor]) {
                    isVertexVisited[neighbor] = true;
                    vertexQueue.push(neighbor);
                }
            }
        }
    }


    void display ()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout<<"  "<<"DEGREE: "<<adj[i].size();
            cout << endl;
        }
    }


};


int main ()
{   

    Graph g(4);
    g.addEdge(2, 3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    
    // g.depthFirstSearch(0);
    cout << endl;
    vector<int> ans = g.depthFirstSearch(2);

    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
    g.display();
    return 0;
}

