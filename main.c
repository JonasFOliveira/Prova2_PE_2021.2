#include "header.h"
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

    int b[9] = {1,2,3,4,5,6,7,8,9};
    Matrix df = create_matrix(b, 3, 3);
    printf("%d\n", get_element(df, 2, 2));

    put_element(df, 2, 2, 10);
    printf("%d\n", get_element(df, 2, 2));

    print_matrix(df);

    Matrix t = transpose(df);
    print_matrix(t);

    print_matrix(a);
    print_matrix(reshape(a, 3, 2));
    print_matrix(reshape(a, 4, 2));
    print_matrix(df);
    Matrix sliced = slice(df, 0, 2, 1, 3);
    print_matrix(sliced);

    put_element(df, 1, 1, 10);
    print_matrix(df);

    
    printf("%d\n", min(df));
    printf("%d\n", max(df));
    printf("%d\n", argmin(df));
    printf("%d\n", argmax(df));

    print_matrix(add(df, df));
    print_matrix(sub(df, df));
    print_matrix(division(df, df));
    print_matrix(mul(df, df));

    return 0;
}

void printar_data(Matrix matrix){
    for (int i = 0; i < matrix.n_cols*matrix.n_rows; i++){
        printf("%d ", matrix.data[i]);
    }
    puts("");
}