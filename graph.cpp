#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct edge
{
    int source;
    int destination;
    int weight;
    edge(int s, int d, int w) : source(s), destination(d), weight(w) {};
};

unordered_map<int, vector<edge *>> create()
{
    unordered_map<int, vector<edge *>> graph;
    graph[0].push_back(new edge(0, 1, 4));
    graph[0].push_back(new edge(0, 2, 9));
    graph[1].push_back(new edge(1, 0, 4));
    graph[1].push_back(new edge(1, 3, 1));
    graph[2].push_back(new edge(2, 0, 9));
    graph[2].push_back(new edge(2, 4, 6));
    graph[3].push_back(new edge(3, 1, 1));
    graph[3].push_back(new edge(3, 4, 11));
    graph[3].push_back(new edge(3, 5, 8));
    graph[4].push_back(new edge(4, 2, 6));
    graph[4].push_back(new edge(4, 3, 11));
    graph[4].push_back(new edge(4, 5, 5));
    graph[5].push_back(new edge(5, 3, 8));
    graph[5].push_back(new edge(5, 4, 5));
    return graph;
}

void All_Paths(unordered_map<int, vector<edge *>> graph, vector<bool> vis, int current, string path, int destination)
{
    path += to_string(current);
    if (current == destination)
    {
        cout << path << endl;
        return;
    }
    for (int i = 0; i < graph[current].size(); i++)
    {
        edge *e = graph[current][i];
        if (!vis[e->destination])
        {
            vis[current] = true;
            All_Paths(graph, vis, e->destination, path, destination);
            vis[current] = false;
        }
    }
}

int main()
{
    unordered_map<int, vector<edge *>> graph = create();
    int n = graph.size();
    vector<bool> visited(n, false);
    All_Paths(graph, visited, 0, "", 5);
    return 0;
}