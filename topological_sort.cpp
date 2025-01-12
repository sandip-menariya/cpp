#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>

using namespace std;

struct edge
{
    int source,destination;
    edge(int s,int d):source(s),destination(d){};
};

unordered_map<int,vector<edge*>> create_graph()
{
    unordered_map<int,vector<edge*>> graph;
    graph[0].push_back(new edge(0,0));
    graph[1].push_back(new edge(1,1));
    graph[2].push_back(new edge(2,3));
    graph[3].push_back(new edge(3,1));
    graph[4].push_back(new edge(4,0));
    graph[4].push_back(new edge(4,1));
    graph[5].push_back(new edge(5,0));
    graph[5].push_back(new edge(5,2));
    return graph;
}

void topUtil(unordered_map<int,vector<edge*>>&graph,int current,unordered_map<int,bool>&visited,stack<int>&stk)
{
    visited[current]=true;
    for(int i=0;i<graph[current].size();i++)
    {
        edge *e=graph[current][i];
        if(!visited[e->destination])
        {
            topUtil(graph,e->destination,visited,stk);
        }
    }
    stk.push(current);
}

void topsort(unordered_map<int,vector<edge*>>&graph)
{
    unordered_map<int,bool>visited;
    stack<int>stk;
    for(auto &key:graph)
    {
        if(!visited[key.first])
        {
            topUtil(graph,key.first,visited,stk);
        }
    }
    cout<<"topological sorting of graph is: \n";
    while(!stk.empty())
    {
        cout<<stk.top()<<"\t";
        stk.pop();
    }
}

int main()
{
    unordered_map<int,vector<edge*>>graph=create_graph();
    topsort(graph);
    return 0;
}