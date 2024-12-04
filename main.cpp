#include "libs/graph.h"
#include <iostream>

using namespace Graph;
using std::cin;
using std::cout;
using std::endl;

int main() {
  int size, start, V;
  bool ui_flag = true;
  cout << "Введите размер матрицы смежности: ";
  cin >> size;
  std::vector<int> dist(size);
  matrix G = generate_adjacency_matrix(size);
  cout << "Матрица смежности для графа G:" << endl;
  print_matrix(G);
  while (ui_flag) {
    cout << "Введите стартовую вершину: ";
    cin >> start;
    if (start > G.size() or start <= 0) {
      cout << "Вершина " << start << " не входит в граф G." << endl;
      continue;
    }
    DKP(G, start - 1);
    cout << "\n1. Выполнить заново." << endl;
    cout << "0. Завершить программу." << endl;
    cout << "> ";
    cin >> ui_flag;
  }

  return 0;
}