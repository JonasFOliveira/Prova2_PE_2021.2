#include "header.h"
#include <stdio.h>
#include <stdlib.h>

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
    free(df);
    return out;
}
Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols){

    if(matrix.n_rows*matrix.n_cols == new_n_rows*new_n_cols)
        return create_matrix(matrix.data, new_n_rows, new_n_cols);
    else{
        printf("! Invalid dimensions ! \noriginal matrix rows = %d, cols = %d \nreshape matrix rows = %d, cols = %d\n", matrix.n_rows, matrix.n_cols, new_n_rows, new_n_cols);
        return matrix;
    }
}

Matrix slice(Matrix a_matrix, int rs, int re, int cs, int ce){
    int rows = re-rs;
    int cols = ce-cs;
    int *data = (int *) malloc(rows*cols*sizeof(int));
    printf("entrei\n");
    int a = 0;
    int s = 0;
    for (int i = 0; i < a_matrix.n_rows; i++){
        printf("primeiro for\n");
        for (int j = 0; j < a_matrix.n_cols; j++){
            printf("segundo for\n");
            if (i >= rs && i < re && j >= cs && j < ce){
                printf("entrei no if\n");
                printf("1 a = %d, s = %d\n", a, s);
                printf("data[s] = %d\n", a_matrix.data[s]);
                data[a] = a_matrix.data[s];
                a++;
                s++;
                printf("2 a = %d, s = %d\n", a, s);
            }
            else{
                s++;
                printf("s = %d\n", s);
            }
        }
    }
    for (int i = 0; i < 4; i++)
        printf("saida %d\n", data[i]);
    int baba[4] = {0};

    Matrix out = create_matrix(baba, 2, 2);
    free(data);
    return out;
}
 
//  1 2 3 4 5 6 7 8 9

//  1 2 3 
//  4 5 6
//  7 8 9

//  1 4 7
//  2 5 8
//  3 6 9

//  1 4 7 2 5 8 3 6 9

// 1 2 3 4
// 5 6 7 8

// 1 2
// // 3 4
// // 5 6
// // 7 8
//   0 1 2
// 0 1 2 3
// 1 4 5 6
// 2 7 8 9

//   1 2
// 0 2 3
// 1 5 6

// 1 2 3 4 5 6 7 8 9

// 2 3 5 6


// rs = 0
// re = 2 - 1 = 1
// cs = 1
// ce = 3 - 1 = 2