#include "header.h"
#include <stdio.h>
#include <stdlib.h>

Matrix add(Matrix matrix_1, Matrix matrix_2){
    if(matrix_1.n_cols == matrix_2.n_cols && matrix_1.n_rows == matrix_2.n_rows){
        int *data = (int *) malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));
        for(int i = 0; i < matrix_1.n_cols*matrix_1.n_rows; i++){
            data[i] = (matrix_1.data[i] + matrix_2.data[i]);
        }
        return create_matrix(data, matrix_1.n_cols, matrix_1.n_rows);
    }
    else{
        printf("! Invalid dimensions ! \n matrix_1 rows = %d, cols = %d \n matrix_2 rows = %d, cols = %d\n", matrix_1.n_rows, matrix_1.n_cols, matrix_2.n_rows, matrix_2.n_cols);
        return matrix_1;
    }
    
}
Matrix sub(Matrix matrix_1, Matrix matrix_2){
    if(matrix_1.n_cols == matrix_2.n_cols && matrix_1.n_rows == matrix_2.n_rows){
        int *data = (int *) malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));
        for(int i = 0; i < matrix_1.n_cols*matrix_1.n_rows; i++){
            data[i] = (matrix_1.data[i] - matrix_2.data[i]);
        }
        return create_matrix(data, matrix_1.n_cols, matrix_1.n_rows);
    }
    else{
        printf("! Invalid dimensions ! \n matrix_1 rows = %d, cols = %d \n matrix_2 rows = %d, cols = %d\n", matrix_1.n_rows, matrix_1.n_cols, matrix_2.n_rows, matrix_2.n_cols);
        return matrix_1;
    }

}
Matrix division(Matrix matrix_1, Matrix matrix_2){
    if(matrix_1.n_cols == matrix_2.n_cols && matrix_1.n_rows == matrix_2.n_rows){
        int *data = (int *) malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));
        for(int i = 0; i < matrix_1.n_cols*matrix_1.n_rows; i++){
            data[i] = (matrix_1.data[i] / matrix_2.data[i]);
        }
        return create_matrix(data, matrix_1.n_cols, matrix_1.n_rows);
    }
    else{
        printf("! Invalid dimensions ! \n matrix_1 rows = %d, cols = %d \n matrix_2 rows = %d, cols = %d\n", matrix_1.n_rows, matrix_1.n_cols, matrix_2.n_rows, matrix_2.n_cols);
        return matrix_1;
    }

}
Matrix mul(Matrix matrix_1, Matrix matrix_2){
    if(matrix_1.n_cols == matrix_2.n_cols && matrix_1.n_rows == matrix_2.n_rows){
        int *data = (int *) malloc(matrix_1.n_cols*matrix_1.n_rows*sizeof(int));
        for(int i = 0; i < matrix_1.n_cols*matrix_1.n_rows; i++){
            data[i] = (matrix_1.data[i] * matrix_2.data[i]);
        }
        return create_matrix(data, matrix_1.n_cols, matrix_1.n_rows);
    }
    else{
        printf("! Invalid dimensions ! \n matrix_1 rows = %d, cols = %d \n matrix_2 rows = %d, cols = %d\n", matrix_1.n_rows, matrix_1.n_cols, matrix_2.n_rows, matrix_2.n_cols);
        return matrix_1;
    }

}