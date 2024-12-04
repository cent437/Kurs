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

namespace Graph {

matrix generate_adjacency_matrix(int size) {

  srand(1733316677);

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

int min_dist(vector<int> U) {
  int min_index = 0;
  int min_weight = U[0];
  for (int i = 0; i < U.size(); i++) {
    if (min_weight > U[i] and U[i] > 0) {
      min_weight = U[i];
      min_index = i;
    } else if (min_weight < U[i]) {
      min_weight = U[i];
      min_index = i;
    }
  }
  return min_index;
}
void DKP(matrix G, int start) {

  vector<unsigned> dist(G.size()); /* Вектор кратчайших путей. */
  vector<int> visited(0); /* Вектор посещенных вершин. */
  vector<int> U(0); /* Вектор непосещенных вершин. */
  for (int i = 0; i < G.size(); i++) {
    dist[i] = INF;
  }
  for (int i = 0; i < G.size(); i++) {
    U.push_back(G[start][i]);
  }
  // visited.push_back(start);
  dist[start] = 0;
  int u = start;

  int end_flag = INT_MAX;
  while (end_flag > 0) {
    end_flag = 0;
    visited.push_back(u);
    for (int w = 0; w < G.size(); w++) {
      if (dist[w] > dist[u] + G[u][w] and G[u][w] > 0) { // dist[u] + G[u][w]
        dist[w] = dist[u] + G[u][w];                     // dist[u] + G[u][w]
      }
      end_flag += U[w];
    }
    U[u] = 0;
    u = min_dist(U);
  }
  cout << "Вектор кратчайших путей от вершины " << start + 1
       << " до всех остальных:" << endl;
  for (int i = 0; i < G.size(); i++)
    cout << i + 1 << '\t';
  cout << endl;
  for (auto i : dist) {
    cout << i << '\t';
  }
}
} // namespace Graph