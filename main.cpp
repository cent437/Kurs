#include "libs/graph.h"
#include <iostream>

using namespace Graph;
using std::cin;
using std::cout;
using std::endl;

int main() {
  int size;
  cout << "Введите размер матрицы смежности: ";
  cin >> size;
  matrix G = generate_adjacency_matrix(size);
  adjacency_list l = generate_adjacency_list(G);

  cout << "Матрица смежности для графа G:" << endl;
  print_matrix(G);
  cout << "Список смежности для графа G:" << endl;
  print_list(l);
  return 0;
}