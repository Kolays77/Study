#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
#include <fstream>
#include <ctime>
#include <stdio.h>

using namespace std; 
  
bool bfs(int** rGraph, int s, int t, int parent[], int n) 
{  
  bool* visited= new bool[n]; 
  memset(visited, 0, n); 

  queue <int> q; 
  q.push(s); 
  visited[s] = true; 
  parent[s] = -1; 

  while (!q.empty()) 
  { 
    int u = q.front(); 
    q.pop(); 

    for (int v=0; v<n; v++) 
    { 
      if (visited[v]==false && rGraph[u][v] > 0) 
      { 
        q.push(v); 
        parent[v] = u; 
        visited[v] = true; 
      } 
    } 
  } 
  return (visited[t] == true); 
} 


int fordFulkerson(int** graph, int s, int t, int n) 
{ 
  int u, v; 

  int** rGraph = new int*[n];   
  for(int i = 0; i<n; i++)
    rGraph[i] = new int[n];
    
 
  for (u = 0; u < n; u++) 
    for (v = 0; v < n; v++) 
      rGraph[u][v] = graph[u][v]; 

  int* parent= new int[n];

  int max_flow = 0;

  
  while (bfs(rGraph, s, t, parent, n)) 
  { 
    int path_flow = INT_MAX; 
    for (v=t; v!=s; v=parent[v]) 
    { 
      u = parent[v]; 
      path_flow = min(path_flow, rGraph[u][v]); 
    } 
    for (v=t; v != s; v=parent[v]) 
    { 
      u = parent[v]; 
      rGraph[u][v] -= path_flow; 
      rGraph[v][u] += path_flow; 
    } 
    max_flow += path_flow; 
  } 
  return max_flow; 
} 
  

int main() 
{ 
  clock_t start = clock ();

  int n, m;
  ifstream file ("test_max_matrix.in");
  file>>n>>m;
  int size = n+m+2;

  int** graph = new int*[size];

  for(int i = 0; i<size;++i){
    graph[i] = new int[size];
  }
  
  for(int i = 0; i<size;++i){
    for(int j=0; j<size;++j){
      graph[i][j] =0;
    }
  }
  //ограничения по строке
  for(int i = 1; i<n+1;++i){
      file>>graph[0][i];   
  }
  //ограничения по столбцам
  for(int j = 0; j<m;++j){
      file>>graph[j+n+1][size-1];
  }
  
  for(int i = 1; i<n+1;++i){
    for(int j=0; j<m;++j){
      graph[i][j+n+1] = min(graph[0][i], graph[j+n+1][size-1]);
    }
  };


    cout << "ANSWER is " << fordFulkerson(graph, 0,size-1, size)<<endl; 
    clock_t stop = clock (); 
    cout<<"The execution time = "<<(double)(stop - start) / CLOCKS_PER_SEC<<endl;
    file.close();
    for (int i = 0; i < size; ++i)
		  delete[] graph[i];
	  delete[] graph;
    return 0; 
} 