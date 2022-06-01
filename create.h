#ifndef CREATE_H
#define CREATE_C


typedef struct {
   int *data;
   int n_rows;
   int n_cols;
   int stride_rows;
   int stride_cols;
   int offset; 
} Matrix;

Matrix create_matrix(int *data, int n_rows, int n_cols);
Matrix zeros_matrix(int n_rows, int n_cols);
Matrix full_matrix(int n_rows, int n_cols, int values);
Matrix i_matrix(int n);
Matrix tile_matrix(Matrix matrix, int reps);
int get_element(Matrix matrix, int ri, int ci);


#endif