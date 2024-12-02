
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>
#define INF UINT_MAX
using std::cout;
using std::endl;
using std::list;
using std::vector;
using matrix = vector<vector<int>>;
using adjacency_list = vector<list<int>>;

bool GreaterThanZero(int a, int b) { return a > b; }
namespace Graph {

matrix generate_adjacency_matrix(int size) {
  srand(time(NULL));
  /* Создание двумерного вектора. */
  matrix G(size, vector<int>(size));
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      G[i][j] = rand() % 10;
      G[j][i] = G[i][j];
    }
    G[i][i] = 0;
  }
  return G;
}
adjacency_list generate_adjacency_list(matrix G) {
  /* Создание вектора из двусвязных списков. */
  adjacency_list l(G.size(), list<int>(0));
  for (int i = 0; i < G.size(); i++) {
    for (int j = 0; j < G[i].size(); j++) {
      /* Если вершина i смежна с вершиной j, то записываем j в список. */
      if (G[i][j] >= 1)
        l[i].push_back(j + 1);
    }
  }
  return l;
}
void print_matrix(matrix G) {
  cout << "   ";
  for (int i = 0; i < G.size(); i++) {
    cout << i + 1 << ' ';
  }
  cout << endl;
  for (int i = 0; i < G.size(); i++) {
    cout << i + 1 << "  ";
    for (auto j : G[i]) {
      cout << j << ' ';
    }
    cout << endl;
  }
}
void print_list(adjacency_list l) {
  for (int i = 0; i < l.size(); i++) {
    std::cout << i + 1 << ':' << '\t';
    for (auto j : l[i]) {
      cout << j << '\t';
    }
    cout << endl;
  }
}
int minDistance(vector<int> dist, vector<int> visited, int V) {
  int min = INF, min_index;
  for (int i = 0; i < V; i++) {
    if (visited[i] == 0 and dist[i] <= min) {
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}
void printPath(vector<int> parent, int j) {
  if (parent[j] == -1)
    return;

  printPath(parent, parent[j]);
  cout << " " << j;
}
void DKP(matrix G, int start, int V) {
  if (start > G.size() or start < 0) {
    cout << "Вершины " << start << "не существует.";
    return;
  }
  if (V > G.size() or V < 0) {
    cout << "Вершины " << V << " не существует.";
    return;
  }
  vector<int> dist(V + 1);
  vector<int> visited(V + 1);
  vector<int> parent(V + 1);
  for (int i = 0; i < V; i++) {
    dist[i] = INF;
    visited[i] = 0;
    parent[i] = -1;
  }
  dist[start] = 0;
  for (int i = 0; i < V; i++) {
    int u = minDistance(dist, visited, V);
    visited[u] = 1;

    for (int v = 0; v < V; v++) {
      if (!visited[v] and G[u][v] and dist[u] != INT_MAX and
          dist[u] + G[u][v] < dist[v]) {
        dist[v] = dist[u] + G[u][v];
        parent[v] = u;
      }
    }
  }

  printf("Вершина \t Расстояние от источника \t Путь");
  for (int i = 0; i < V; i++) {
    printf("\n%d -> %d \t\t %d \t\t\t\t ", start + 1, i + 1, dist[i]);
    printPath(parent, i);
  }
}
} // namespace Graph