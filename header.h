#ifndef HEADER_H
#define HEADER_H

typedef struct {
   int *data;
   int n_rows;
   int n_cols;
   int stride_rows;
   int stride_cols;
   int offset; 
} Matrix;

//======== Functions for create matrices ========

Matrix create_matrix(int *data, int n_rows, int n_cols);
Matrix zeros_matrix(int n_rows, int n_cols);
Matrix full_matrix(int n_rows, int n_cols, int values);
Matrix i_matrix(int n);
Matrix tile_matrix(Matrix matrix, int reps);

//======== Functions for acess matrices ========

int get_element(Matrix matrix, int ri, int ci);
void put_element(Matrix matrix, int ri, int ci, int elem);
void print_matrix(Matrix matrix);

//======== Functions for manipulating dimensions ========

Matrix transpose(Matrix matrix);
Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols);
Matrix slice(Matrix a_matrix, int rs, int re, int cs, int ce);

//======== Functions for aggregation ========

int min(Matrix matrix);
int max(Matrix matrix);
int argmin(Matrix matrix);
int argmax(Matrix matrix);

#endif