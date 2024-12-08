#include "libs/graph.h"
#include <climits>
#include <iostream>

using namespace Graph;
using std::cin;
using std::cout;
using std::endl;

int main() {
  int size = 0, start;
  unsigned ui_flag = 1;
  cout << "Введите размер матрицы смежности: ";
  for (; cin.fail() || size <= 0 || size >= INT_MAX;) {
    cin >> size;
    cout << "Некорректный ввод, повторите попытку: " << endl;
    cin.clear();
    cin.ignore();
    cout << "> ";
  }

  std::vector<int> dist(size);
  matrix G = generate_adjacency_matrix(size);
  cout << "Матрица смежности для графа G:" << endl;
  print_matrix(G);
  while (ui_flag) {
    cout << "Введите стартовую вершину: ";
    cin >> start;
    if (start > G.size() || start <= 0 || start >= INT_MAX || cin.fail()) {
      cout << "Вершина " << start << " не входит в граф G." << endl;
      cin.clear();
      cin.ignore();
      continue;
    }
    DKP(G, start - 1);
    cout << "\n1. Выполнить заново." << endl;
    cout << "0. Завершить программу." << endl;
    cout << "> ";
    cin >> ui_flag;
    while (ui_flag > 1 || cin.fail()) {
      cout << "Некорректный ввод, повторите попытку. " << endl;
      cin.clear();
      cin.ignore();
      cout << "\n1. Выполнить заново." << endl;
      cout << "0. Завершить программу." << endl;
      cout << "> ";
      cin >> ui_flag;
    }
  }

  return 0;
}
