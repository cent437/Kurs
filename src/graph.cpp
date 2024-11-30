#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;
using matrix = vector<vector<int>>;
using adjacency_list = vector<list<int>>;

namespace Graph {

matrix generate_adjacency_matrix(int size) {
  srand(time(NULL));

  /* Создание двумерного вектора. */
  matrix G(size, vector<int>(size));
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      G[i][j] = rand() % 2;
      G[j][i] = G[i][j];
    }
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
} // namespace Graph