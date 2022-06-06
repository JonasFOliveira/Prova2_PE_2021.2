#include "header.h"

/*
    function min returns the smallest element of the array.
    > int matrix :  is ​​the matrix where the smallest element will be searched

*/
int min(Matrix matrix){
    int m = matrix.data[0];
    for(int i = 0; i < matrix.n_cols*matrix.n_rows; i++){
        if(m > matrix.data[i])
            m = matrix.data[i];
    }
    return m;
}

/*
    function max returns the largest element of the array.
    > int matrix :  is ​​the matrix where the smallest element will be searched

*/
int max(Matrix matrix){
    int m = matrix.data[0];
    for(int i = 0; i < matrix.n_cols*matrix.n_rows; i++){
        if(m < matrix.data[i])
            m = matrix.data[i];
    }
    return m;
}

/*
    function argmin returns the index of the smallest element in the array.
    > int matrix :  matrix is ​​the array where the index of the smallest element will be looked for

*/
int argmin(Matrix matrix){
    int m = min(matrix);
    int index = 0;
    for(int i = 0; i < matrix.n_cols*matrix.n_rows; i++){
        if(m == matrix.data[i]){
            index = i;
            break;
        }
    }
    return index;
}

/*
    function argmax returns the index of the largest element in the array.
    > int matrix :  matrix is ​​the array where the index of the largest element will be looked for

*/
int argmax(Matrix matrix){
    int m = max(matrix);
    int index = 0;
    for(int i = 0; i < matrix.n_cols*matrix.n_rows; i++){
        if(m == matrix.data[i]){
            index = i;
            break;
        }
    }
    return index;
}