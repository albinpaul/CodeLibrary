#Python program to print topological sorting of a DAG
from collections import defaultdict
 
#Class to represent a graph
class Graph:
    def __init__(self,vertices):
        self.graph = defaultdict(list) #dictionary containing adjacency List
        self.V = vertices #No. of vertices
 
    # function to add an edge to graph
    def addEdge(self,u,v):
        self.graph[u-1].append(v-1)
 
    # A recursive function used by topologicalSort
    def topologicalSortUtil(self,v,visited,stack):
 
        # Mark the current node as visited.
        visited[v] = True
 
        # Recur for all the vertices adjacent to this vertex
        for i in self.graph[v]:
            if visited[i] == False:
                self.topologicalSortUtil(i,visited,stack)
 
        # Push current vertex to stack which stores result
        stack.insert(0,v)
 
    # The function to do Topological Sort. It uses recursive 
    # topologicalSortUtil()
    def topologicalSort(self):
        # Mark all the vertices as not visited
        visited = [False]*self.V
        stack =[]
 
        # Call the recursive helper function to store Topological
        # Sort starting from all vertices one by one
        for i in range(self.V):
            if visited[i] == False:
                self.topologicalSortUtil(i,visited,stack)
 
        # Print contents of stack
        for i in stack:
            print(i+1,end='')
            print(" ",end='')
n,m=map(int,input().split())
g= Graph(n)
for _ in range(m):
    a,b=map(int,input().split())
    g.addEdge(a, b);
g.topologicalSort()
#This code is contributed by Neelam Yadav