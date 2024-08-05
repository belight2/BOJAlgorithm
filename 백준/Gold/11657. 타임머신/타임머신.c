#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000000
struct Edge{
  int src, dst, cost; 
};
struct Graph{
  int V, E;
  struct Edge *edges;
};
struct Graph* createGraph(int V, int E){
  struct Graph *graph = malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->edges = malloc(sizeof(struct Edge) * E);
  return graph;
}
int main(){
  int n, m, u, v, w;
  scanf("%d %d ", &n, &m);

  struct Graph *graph = createGraph(n, m);
  for(int i = 0; i < m; i++){
    scanf("%d %d %d ", &u, &v, &w);
    graph->edges[i].src = u;
    graph->edges[i].dst = v;
    graph->edges[i].cost = w;
  }

  long long *dist = malloc(sizeof(long long)*(n+1));
  dist[1] = 0;
  for(int i = 2; i <= n; i++)
    dist[i] = INF;
  
  int negCycle = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int u = graph->edges[j].src;
      int v = graph->edges[j].dst;
      int w = graph->edges[j].cost;
      if(dist[u] != INF && dist[u]+w < dist[v]){
        dist[v] = dist[u] + w;
        if(i == n - 1){
          negCycle = 1;
        }
      }
    }
  }

  if(negCycle){
    printf("-1");
  }
  else{
    for(int i = 2; i <= n; i++){
      if(dist[i] == INF) dist[i] = -1;
      printf("%lld\n", dist[i]);
    }
  }
}