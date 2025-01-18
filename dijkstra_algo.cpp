#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include<queue>

using namespace std;

struct edge
{
    int source, destination, weight;
    edge(int s, int d, int w) : source(s), destination(d), weight(w) {};
};

unordered_map<int, vector<edge *>> create()
{
    unordered_map<int, vector<edge *>> graph;
    graph[0].push_back(new edge(0, 1, 2));
    graph[0].push_back(new edge(0, 2, 4));
    graph[1].push_back(new edge(1, 2, 1));
    graph[1].push_back(new edge(1, 3, 7));
    graph[2].push_back(new edge(2, 4, 3));
    graph[3].push_back(new edge(3, 5, 1));
    graph[4].push_back(new edge(4, 3, 2));
    graph[4].push_back(new edge(4, 5, 5));
    return graph;
}

void visited_arr(unordered_map<int, bool> &visited, unordered_map<int, vector<edge *>> &graph)
{
    for (auto node : graph)
    {
        visited[node.first] = false;
    }
}

vector<int> dijkstra(unordered_map<int, bool> &visited, unordered_map<int, vector<edge *>> &graph, int source, vector<int> &distance_node)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    distance_node[source]=0;
    pq.push({0,source});
    while (!pq.empty())
    {
        int current=pq.top().second;
        pq.pop();
        if(visited[current])
            continue;    
        visited[current] = true;
        for(edge *e:graph[current])
        {
        int newdist=distance_node[current]+e->weight;
        if (newdist< distance_node[e->destination])
        {
            distance_node[e->destination] = newdist;
        }
        pq.push({newdist,e->destination});
        }
    }
    return distance_node;
}

int main()
{
    unordered_map<int, vector<edge *>> graph = create();
    unordered_map<int, bool> visited;
    visited_arr(visited, graph);
    int n = visited.size();
    vector<int> distance_node(n + 1, INT_MAX);
    for (auto node : graph)
    {
        if (!visited[node.first])
        {
            distance_node = dijkstra(visited, graph, 0, distance_node);
        }
    }

    for (int i = 0; i < distance_node.size(); i++)
    {
        cout << " node: " << i << " distance: " << distance_node[i] << "\t";
    }

    for (auto node : graph)
    {
        for (edge *e : node.second)
        {
            delete (e);
        }
    }
    return 0;
}