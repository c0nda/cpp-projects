#ifndef INC_15_11_2021_PROTTESTARRAYS_H
#define INC_15_11_2021_PROTTESTARRAYS_H

template <typename T> void delete_2Darray(T **ppi, int rows);
template <typename T> T** create_2D_indep_array(int rows, int columns);
template <typename T> T** create_2D_dep_array(int rows, int columns);
template <typename T> T** const_array(int rows, int columns, T cnst);
template <typename T> T** matrix_111(int rows, int columns);
template <typename T> T** t_matrix(T** arr, int rows, int columns);

#endif
