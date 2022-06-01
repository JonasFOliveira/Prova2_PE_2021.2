#include "create.h"
#include <stdio.h>

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

void printar_data(Matrix matrix){
    for (int i = 0; i < matrix.n_cols*matrix.n_rows; i++){
        printf("%d ", matrix.data[i]);
    }
    puts("");
}