// A C++ program to print topological sorting of a DAG
#include <iostream>
#include <list>
#include <stack>
using namespace std;
 
// Class to represent a graph
class Graph
{
    int V;    // No. of vertices'
    // Pointer to an array containing adjacency listsList
    list<int> *adj;
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v-1].push_back(w-1); // Add w to v’s list.
}
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    Stack.push(v);
}
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
    while (Stack.empty() == false)
    {
        cout<<std::fixed;
        cout << Stack.top()+1 << " ";
        Stack.pop();
    }
}
 
// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    long long int n,m,i,a,b;
    cin>>n>>m;
    Graph g(n);
    for(i=0;i<m;i++){
        cin>>a>>b;
        g.addEdge(a, b);
    }
    g.topologicalSort();
 
    return 0;
}