/*  
    Jonas Felipe da Fonseca Oliveira - 20210026948
    Samila Ellen Garrido Rodrigues   - 20210026788
*/
#include "header.h"
#include <stdio.h>

int main(){

    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix df = create_matrix(a, 3, 3); //ok

    print_matrix(create_matrix(a, 3, 3)); //ok
    print_matrix(zeros_matrix(3, 3)); //ok
    print_matrix(full_matrix(3, 3, 5)); //ok
    print_matrix(i_matrix(3)); //ok
    print_matrix(tile_matrix(df, 3)); //ok

    print_matrix(df); //ok
    printf("%d\n", get_element(df, 2, 2)); //ok
    put_element(df, 2, 2, 80); //ok
    print_matrix(df); //ok

    printf("%d\n", min(df)); //ok
    printf("%d\n", max(df)); //ok
    printf("%d\n", argmin(df)); //ok
    printf("%d\n", argmax(df)); //ok

    print_matrix(transpose(df));
    Matrix dfb = create_matrix(b, 2, 5); //ok
    print_matrix(dfb);
    print_matrix(reshape(dfb, 5, 2)); //ok
    print_matrix(slice(df, 0, 2, 1, 3)); //ok

    print_matrix(add(df,df)); //ok
    print_matrix(sub(df,df)); //ok
    print_matrix(division(df, df)); //ok
    print_matrix(mul(df, df)); //ok


    return 0;
}