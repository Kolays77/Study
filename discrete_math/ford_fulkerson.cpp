#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
#include <fstream>
#include <ctime>
#include <stdio.h>

using namespace std; 
  
bool bfs(int** rGraph, int s, int t, int parent[], int n) {  
  bool* visited= new bool[n]; 
  memset(visited, 0, n); 

  queue <int> q; 
  q.push(s); 
  visited[s] = true; 
  parent[s] = -1; 

  while (!q.empty()) { 
    int u = q.front(); 
    q.pop(); 

    for (int v=0; v<n; v++) { 
      if (visited[v]==false && rGraph[u][v] > 0) { 
        q.push(v); 
        parent[v] = u; 
        visited[v] = true; 
      } 
    } 
  } 
  return (visited[t] == true); 
} 


int fordFulkerson(int** graph, int s, int t, int n) { 
  int u, v; 

  int** rGraph = new int*[n];   
  for(int i = 0; i<n; i++)
    rGraph[i] = new int[n];
    
 
  for (u = 0; u < n; u++) 
    for (v = 0; v < n; v++) 
      rGraph[u][v] = graph[u][v]; 

  int* parent= new int[n];

  int max_flow = 0;

  
  while (bfs(rGraph, s, t, parent, n)) { 
    int path_flow = INT_MAX; 
    for (v=t; v!=s; v=parent[v])  { 
      u = parent[v]; 
      path_flow = min(path_flow, rGraph[u][v]); 
    } 
    for (v=t; v != s; v=parent[v]) { 
      u = parent[v]; 
      rGraph[u][v] -= path_flow; 
      rGraph[v][u] += path_flow; 
    } 
    max_flow += path_flow; 
  } 
  return max_flow; 
} 
  

int main() { 
  clock_t start = clock ();

  int n;
  ifstream file ("test8.in");
  file>>n;
  int** graph = new int*[n];

  for(int i = 0; i<n;++i) {
    graph[i] = new int[n];
  }
  
  for(int i = 0; i<n;++i){
    for(int j=0; j<n;++j){
      file>>graph[i][j];
    }
  }
  
    cout << "MAX FLOW IS " << fordFulkerson(graph, 0, 1, n)<<endl; 
    clock_t stop = clock (); 
    cout<<"The execution time = "<<(double)(stop - start) / CLOCKS_PER_SEC<<endl;
    return 0; 
} 