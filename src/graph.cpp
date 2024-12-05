#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#define INF INT_MAX
using std::cout;
using std::endl;
using std::vector;
using matrix = vector<vector<int>>;

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
/* Функция поиска вершины с минимальным расстоянием до стартовой. */
int min_dist(vector<int> U) {
  int min_index = 0;
  int min_weight = INT_MAX;
  /* Поиск минимального значения в векторе. */
  for (int i = 0; i < U.size(); i++)
    if (min_weight > U[i] and U[i] > 0)
      min_weight = U[i];

  /* Поиск индекса минимального элемента в векторе. */
  for (int i = 0; i < U.size(); i++)
    if (U[i] == min_weight) {
      min_index = i;
      break;
    }

  return min_index;
}
void DKP(matrix G, int start) {

  vector<int> dist(G.size()); /* Вектор кратчайших путей. */
  vector<int> U(0); /* Вектор непосещенных вершин. */

  /* Инициализация векторов. */
  for (int i = 0; i < G.size(); i++) {
    dist[i] = INF;
    U.push_back(G[start][i]);
  }
  dist[start] = 0;
  int u = start;
  int end_flag = INT_MAX;
  while (end_flag > 0) {
    end_flag = 0;
    for (int w = 0; w < G.size(); w++) {
      if (dist[w] > dist[u] + G[u][w] and G[u][w] > 0)
        dist[w] = dist[u] + G[u][w];
      end_flag += U[w];
    }

    U[u] = 0; /* Вершина u посещена. */
    u = min_dist(U);
  }
  cout << "Вектор кратчайших путей от вершины " << start + 1
       << " до всех остальных:" << endl;

  for (int i = 0; i < G.size(); i++)
    cout << i + 1 << '\t';
  cout << endl;

  for (auto i : dist)
    cout << i << '\t';
}
} // namespace Graph
