#include <stdio.h>
#include <stdlib.h>
#include "header.h"



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
    > int ri : is the element's row gitindex
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
    for (int i = 0; i < matrix.n_rows; i++){
        if(i == 0)
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
        if (i < matrix.n_cols-1)
            puts("");
    }
    printf("}\n");
}
