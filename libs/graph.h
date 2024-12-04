#include <list>
#include <vector>

using matrix = std::vector<std::vector<int>>;
using adjacency_list = std::vector<std::list<int>>;

namespace Graph {

/* Создание матрицы смежности для невзвешенного графа. */
extern matrix generate_adjacency_matrix(int size);

/* Создание списка смежности на основе матрицы G. */
extern adjacency_list generate_adjacency_list(matrix G);

/* Печать матрицы. */
extern void print_matrix(matrix G);

/* Печать списка смежности. */
extern void print_list(adjacency_list l);

extern void DKP(matrix G, int start);

} // namespace Graph
namespace algorithm {}