#include<iostream>
#include<vector>
#include<climits>

using namespace std;


int MinDistance(vector<int>& dist, vector<bool>& spt) {
  int min = INT_MAX, min_index = 0;
  for(int i = 0; i < (int)dist.size(); i++) {
    if(spt[i] == false && dist[i] <= min) {
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}

void PrintSolution(vector<int>& dist) {
  cout<<endl;
  for(int i = 0; i < (int)dist.size(); i++) {
    cout<<dist[i]<<" ";
  }
}

// Dijkstra's Algorithm implementation
void dj(vector<vector<int>> graph, int src, int row, int col) {
  vector<int> dist(row, INT_MAX);
  vector<bool> spt(row, false);
  
  dist[src] = 0;
  
  for(int j = 0; j < row - 1; j++) {
      int u = MinDistance(dist, spt);
      spt[u] = true;
  
      for(int i = 0; i < row; i++) {
        if(spt[i] == false && graph[u][i] && dist[u] != INT_MAX
           && dist[u] + graph[u][i] < dist[i]) {
          dist[i] = dist[u] + graph[u][i];
        }
      }
  }
  PrintSolution(dist);
}

int main() {
    /* Let us create the example graph discussed above */
    vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dj(graph, 0, graph.size(), graph[0].size());
  return 0;
}
