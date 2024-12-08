
#include <vector>

using matrix = std::vector<std::vector<int>>;

namespace Graph {

/* Создание матрицы смежности. */
extern matrix generate_adjacency_matrix(int size);

/* Печать матрицы. */
extern void print_matrix(matrix G);

/* Поиск кратчайших путей в графе G. */
extern void DKP(matrix G, int start);

} // namespace Graph