#include <stdio.h>
#include <stdlib.h>
#include "acess.h"

/*
    function to access element of an matrix
    > int matrix :  is ​​the matrix that will be accessed
    > int ri : is the element's row index
    > int ci : is the column index of the element
    get_element returns an element of the array according to its position.
*/
int get_element(Matrix matrix, int ri, int ci){
    for(int i = 0; i < ri; i++) {
      for(int j = 0; j < ci; j++) {
          pf("%d", matrix[i][j]);
          pf("%d", *(*(matrix + i) + j));
        }
        pf("/n");
    }
}