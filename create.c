#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
    function that will create a matrix [n_rows * n_cols]
    > int *data : an interger array that will be a matrix
    > int n_rows : an interger number of quantity rows the matrix has
    > int n_cols : an interger number of quantity columns the matrix has
    Return an struct of the type "Matrix"
*/
Matrix create_matrix(int *data, int n_rows, int n_cols){
    Matrix df;

    df.data = data;
    df.n_rows = n_rows;
    df.n_cols = n_cols;
    df.stride_rows = n_cols; //stride_rows is a quantity of moves is necessary to 'jump' for other row
    df.stride_cols = 1; //stride_cols is a quantity of move is necessary to jump for other columns
    df.offset = 0; //offset is a location of the first element on array
    return df;
}

/*
    function that will create a matrix[n_rows * n_cols] filled by 0s
    > int n_rows : an interger number of quantity rows the matrix has
    > int n_cols : an interger number of quantity columns the matrix has
    Return an struct of the type "Matrix"
*/
Matrix zeros_matrix(int n_rows, int n_cols){

    int *data = (int *) malloc(n_rows*n_cols*sizeof(int));
    for(int i = 0; i < (n_rows*n_cols); i++){
        data[i] = 0;
    }
    
    Matrix out = create_matrix(data, n_rows, n_cols); 
    return out;
}

/*
    function that will create a matrix[n_rows * n_cols] filled by a value
    > int n_rows : an interger number of quantity rows the matrix has
    > int n_cols : an interger number of quantity columns the matrix has
    > int values : an interger number that will fill the matrix
    Return an struct of the type "Matrix"
*/
Matrix full_matrix(int n_rows, int n_cols, int values){

    int *data = (int *) malloc(n_rows*n_cols*sizeof(int));
    for(int i = 0; i < (n_rows*n_cols); i++){
        data[i] = values;
    }
    Matrix out = create_matrix(data, n_rows, n_cols);
    return out;
}

/*
    function that will create a n x n identity matrix 
    > int n : an interger number size of a indentity matrix
    Return an struct of the type "Matrix"
*/
Matrix i_matrix(int n){
    Matrix df;
    int a = 0;
    int *data = (int *) malloc(n*n*sizeof(int));
    for (int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            if(i == j)
                data[a++] = 1;
            else
                data[a++] = 0;
        }
    }

    Matrix out = create_matrix(data, n, n);
    return out;

}

/*
    function that will create a matrix with multiple elements of other matrix
    > Matrix matrix: the origin matrix that will be replicated n times 
    > int reps : an interger number of quantity of replicates
    Return an struct of the type "Matrix"
*/
Matrix tile_matrix(Matrix matrix, int reps){
    Matrix df;
    int *data = (int *) malloc(matrix.n_cols*matrix.n_rows*reps*sizeof(int));
    int a = 0;
    int l = 0;
    for (int i = 0; i < matrix.n_rows; i++){
        for (int j = 0; j < reps; j++){ 
            for (int k = 0; k < matrix.n_cols; k++){
                data[a++] = matrix.data[k+l];
            }
        }
        l = a/reps;
    }
    Matrix out = create_matrix(data, matrix.n_rows, matrix.n_cols*reps);
    return out;
}

// 0 1 2 | 3 4 5 | 6 7 8
// 1 2 3 | 4 5 6 | 7 8 9

//   0 1 2 
// 0 1 2 3
// 1 4 5 6
// 2 7 8 9

//   0 1 2 3 4 5  
// 0 1 2 3 1 2 3
// 1 4 5 6 4 5 6
// 2 7 8 9 7 8 9

// 0 1 2 4 5 6 | 7 8 9 10 11 12 | 13 14 15 16 17 18
// 1 2 3 1 2 3 | 4 5 6 4  5  6  | 7  8  9  7  8  9