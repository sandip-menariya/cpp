#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct edge
{
    int source, destination;
    edge(int s, int d) : source(s), destination(d) {};
};

unordered_map<int, vector<edge *>> create()
{
    unordered_map<int, vector<edge *>> graph;
    graph[0].push_back(new edge(0, 1));
    graph[0].push_back(new edge(0, 4));
    graph[1].push_back(new edge(1, 0));
    graph[1].push_back(new edge(1, 2));
    graph[1].push_back(new edge(1, 4));
    graph[2].push_back(new edge(2, 1));
    graph[2].push_back(new edge(2, 3));
    graph[3].push_back(new edge(3, 2));
    // graph[4].push_back(new edge(4, 0));
    graph[4].push_back(new edge(4, 1));
    graph[4].push_back(new edge(4, 5));
    graph[5].push_back(new edge(5, 4));
    return graph;
}

bool is_cycle(unordered_map<int, vector<edge *>> graph, vector<bool> visited, int current, int parent)
{
    visited[current] = true;
    for (int i = 0; i < graph[current].size(); i++)
    {
        edge *e = graph[current][i];
        if (visited[e->destination] == true && parent != e->destination)
        {
            return true;
        }
        else if (!visited[e->destination])
        {
            if (is_cycle(graph, visited, e->destination, current))
            {
                return true;
            }
        }
    }
    return false;
}

// unordered_map<int,bool> visited_init(unordered_map<int,bool>&visited,unordered_map<int,vector<edge*>>&graph)
// {
//     for(auto node:graph)
//     {
//         visited[node.first]=false;
//     }
// }

int main()
{
    unordered_map<int, vector<edge *>> graph = create();
    int n = graph.size();
    vector<bool> visited(n, false);
    bool is_c = false;
    // visited_init(visited,graph);
    for (auto node : graph)
    {
        if (!visited[node.first])
        {
            if (is_cycle(graph, visited, node.first, node.first))
            {
                is_c = true;
            }
        }
    }
    cout << (is_c?"cycle exist!":"cycle does not exist!") << endl;
    for(auto node:graph)
    {
        for(edge *e:node.second)
        {
            delete e;
        }
    }
    return 0;
}