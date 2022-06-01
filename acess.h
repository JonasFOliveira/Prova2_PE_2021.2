#ifndef ACESS_H
#define ACESS_H


// typedef struct {
//    int ri;
//    int ci;
//    int elem;
// } Catch;


int get_element(Matrix matrix, int ri, int ci);
void put_element(Matrix matrix, int ri, int ci, int elem);
void print_matrix(Matrix matrix);

#endif
