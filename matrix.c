/*  
    Jonas Felipe da Fonseca Oliveira - 20210026948
    Samila Ellen Garrido Rodrigues   - 20210026788
*/
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//======== Functions for create matrices ========

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
    for (int i = matrix.offset; i < matrix.n_rows; i++){
        for (int j = matrix.offset; j < reps; j++){ 
            for (int k = matrix.offset; k < matrix.n_cols; k++){
                data[a++] = matrix.data[k+l];
            }
        }
        l = a/reps;
    }
    Matrix out = create_matrix(data, matrix.n_rows, matrix.n_cols*reps);
    return out;
}

//======== Functions for acess matrices ========

/*
    function to access element of an matrix
    > int matrix :  is ​​the matrix that will be accessed
    > int ri : is the element's row index
    > int ci : is the column index of the element
    get_element returns an element of the array according to its position.
*/
int get_element(Matrix matrix, int ri, int ci){
    return matrix.data[ri*matrix.stride_rows +ci*matrix.stride_cols];
}

/*
    function places an element in the array according to position.
    > int matrix :  is ​​the matrix that will be accessed
    > int ri : is the element's row index
    > int ci : is the column index of the element
    > int elem : elem is the element that will be placed
    put_element returns an element of the array according to its position.
*/
void put_element(Matrix matrix, int ri, int ci, int elem){
    matrix.data[ri*matrix.stride_rows +ci*matrix.stride_cols] = elem;
}

/*
    function displays the data in matrix format.
    > int matrix :  displays the data in matrix format.
    print_matrix returns an matrix of elements
*/
void print_matrix(Matrix matrix){
    int a = 0;
    printf("{");
    for (int i = matrix.offset; i < matrix.n_rows; i++){
        if(i == matrix.offset)
         printf(" ");

        if(i > 0)
            printf("  ");
        printf(" {");
        
        for (int j = 0; j < matrix.n_cols; j++){
            if (j < matrix.n_cols-1)
                printf("%d, ", matrix.data[a++]);
            else
                printf("%d", matrix.data[a++]);
        }
        if (i < matrix.n_rows-1)
            printf("},");
        else
            printf("} ");
        if (i < matrix.n_rows)
            puts("");
    }
    printf("}\n\n");
}

//======== Functions for manipulating dimensions ========

/*
    function transpose returns the transposed matrix.
    > int matrix : is ​​the matrix used to generate the transposed matrix
*/
Matrix transpose(Matrix matrix){
    int *df = (int *) malloc(matrix.n_rows*matrix.n_cols*sizeof(int));
    int i = 0, j = 0, init = 0;
    do{
        if(j < matrix.n_cols*matrix.n_rows){   
            df[i] = matrix.data[j];
            i++;
            j += matrix.n_cols;
        }else{
            j = init+1;
            init++;
        }
    }while(i != matrix.n_cols*matrix.n_rows);

    Matrix out = create_matrix(df, matrix.n_cols, matrix.n_rows);
    return out;
}

/*
    function reshape changes the dimensions of the array. But not all dimensions are
    valid, as the number of elements must be consistent with the dimensions of the
    array (number_of_elements = n_rows * n_cols).
    > int matrix : is ​​the matrix that will have its dimensions changed
    > int new_n_rows : is the new number of rows
    > int new_n_columns : is the new number of columns
*/
Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols){

    if(matrix.n_rows*matrix.n_cols == new_n_rows*new_n_cols)
        return create_matrix(matrix.data, new_n_rows, new_n_cols);
    else{
        printf("! Invalid dimensions ! \noriginal matrix rows = %d, cols = %d \nreshape matrix rows = %d, cols = %d\n", matrix.n_rows, matrix.n_cols, new_n_rows, new_n_cols);
        return matrix;
    }
}

/*
    function slice returns a “snip” of the original array.
    > int rs : is the index of the initial line of the clipping
    > int re : is the index of the end line of the clipping
    > int cs : is the index of the initial column of the clipping
    > int ce : is the index of the final column of the clipping
*/
Matrix slice(Matrix a_matrix, int rs, int re, int cs, int ce){
    int rows = re-rs;
    int cols = ce-cs;
    int *data = (int *) malloc(rows*cols*sizeof(int));
    int a = 0;
    int s = 0;
    for (int i = 0; i < a_matrix.n_rows; i++){
        for (int j = 0; j < a_matrix.n_cols; j++){
            if (i >= rs && i < re && j >= cs && j < ce){
                data[a] = a_matrix.data[s];
                a++;
                s++;
            }
            else
                s++;
        }
    }

    Matrix out = create_matrix(data, 2, 2);
    
    return out;
}

//======== Functions for aggregation ========

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

//======== Functions for arithmetic operations ========

/* 
    add, sub, div and mul are the four arithmetic operations. 
    These functions do element-by-element operations and return the array.
*/
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
