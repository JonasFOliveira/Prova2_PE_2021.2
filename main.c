#include <stdio.h>
#include <stdlib.h>

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


void printar_data(Matrix matrix);

int main(){
    int data[6] = {1,2,3,4,5,6};
    Matrix a = create_matrix(data, 2, 3);
    Matrix zeros = zeros_matrix(3,2);
    Matrix full = full_matrix(3, 2, 5);
    Matrix i = i_matrix(3);
    Matrix tile = tile_matrix(a, 3);

    printar_data(a);
    printar_data(zeros);
    printar_data(full);
    printar_data(i);
    printar_data(tile);
    return 0;
}

Matrix create_matrix(int *data, int n_rows, int n_cols){
    Matrix df;

    df.data = data;
    df.n_rows = n_rows;
    df.n_cols = n_cols;
    df.stride_rows = n_cols;
    df.stride_cols = 1;
    df.offset = 0;
    return df;
}

Matrix zeros_matrix(int n_rows, int n_cols){

    int *data = (int *) malloc(n_rows*n_cols*sizeof(int));
    for(int i = 0; i < (n_rows*n_cols); i++){
        data[i] = 0;
    }
    
    return create_matrix(data, n_rows, n_cols); 
}

Matrix full_matrix(int n_rows, int n_cols, int values){

    int *data = (int *) malloc(n_rows*n_cols*sizeof(int));
    for(int i = 0; i < (n_rows*n_cols); i++){
        data[i] = values;
    }
    return create_matrix(data, n_rows, n_cols);
}

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
    return create_matrix(data, n, n);

}

Matrix tile_matrix(Matrix matrix, int reps){
    Matrix df;
    int *data = (int *) malloc(matrix.n_cols*matrix.n_rows*reps*sizeof(int));
    int a = 0;
    for (int i = 0; i < reps; i++){
        for (int j = 0; j < matrix.n_cols*matrix.n_rows; j++){
            data[a] = matrix.data[j];
            a++;
        }
    }

    return create_matrix(data, reps, matrix.n_cols*matrix.n_rows);
}


void printar_data(Matrix matrix){
    for (int i = 0; i < matrix.n_cols*matrix.n_rows; i++){
        printf("%d ", matrix.data[i]);
    }
    puts("");
}