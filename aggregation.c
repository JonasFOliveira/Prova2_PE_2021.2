#include "header.h"

int min(Matrix matrix){
    int m = matrix.data[0];
    for(int i = 0; i < matrix.n_cols*matrix.n_rows; i++){
        if(m > matrix.data[i])
            m = matrix.data[i];
    }
    return m;
}
int max(Matrix matrix){
    int m = matrix.data[0];
    for(int i = 0; i < matrix.n_cols*matrix.n_rows; i++){
        if(m < matrix.data[i])
            m = matrix.data[i];
    }
    return m;
}
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