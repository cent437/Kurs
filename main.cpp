#include "libs/graph.h"
#include <iostream>

using namespace Graph;
using std::cin;
using std::cout;
using std::endl;

int main() {
  int size, start, V;
  cout << "Введите размер матрицы смежности: ";
  cin >> size;
  std::vector<unsigned> dist(size);
  matrix G = generate_adjacency_matrix(size);
  adjacency_list l = generate_adjacency_list(G);

  cout << "Матрица смежности для графа G:" << endl;
  print_matrix(G);
  cout << "Список смежности для графа G:" << endl;
  print_list(l);
  cout << "Введите стартовую вершину: ";
  cin >> start;
  cout << "\nВведите конечную вершину: ";
  cin >> V;
  DKP(G, start - 1, V - 1);
  return 0;
}