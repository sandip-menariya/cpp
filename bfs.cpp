#include <iostream>
#include <vector>
#include <unordered_map>
#include<queue>
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

void bfs(unordered_map<int,vector<edge*>>graph,unordered_map<int,bool>visited)
{
    queue<int>q;
    q.push(0);
    visited[0]=true;
    while (!q.empty())
    {
        int current=q.front();
        q.pop();
        cout<<current<<"\t";
        for(int i=0;i<graph[current].size();i++)
        {
            edge *e=graph[current][i];
            if(!visited[e->destination])
            {
            visited[e->destination]=true;
            q.push(e->destination);
            }
        }
    }
}

int main()
{
    unordered_map<int,vector<edge*>>graph=create();
    unordered_map<int,bool>visited;
    bfs(graph,visited);
    return 0;
}