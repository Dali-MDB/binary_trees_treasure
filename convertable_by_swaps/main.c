#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"
#include <stdbool.h>

bool conv_by_swaps(ptr R1,ptr R2){
   if(R1==R2)  ///NULL
      return true;
   else if ((R1 == NULL && R2 != NULL) || (R2 == NULL && R1 != NULL))
      return false;
   else{ //both non null
      if(data(R1) != data(R2))
         return false;
      else
         return  (conv_by_swaps(LC(R1),LC(R2)) && conv_by_swaps(RC(R1),RC(R2))) ||
                 (conv_by_swaps(LC(R1),RC(R2)) && conv_by_swaps(RC(R1),LC(R2)));

   }


}


int main()
{
    ptr X = new_node(6);
    X->left = new_node(3);
    X->right = new_node(8);
    X->left->left = new_node(1);
    X->left->right = new_node(7);
    X->right->left = new_node(4);
    X->right->right = new_node(2);
    X->right->left->left = new_node(1);
    X->right->left->right = new_node(7);
    X->right->right->right = new_node(3);


    ptr Y = new_node(6);
    Y->left = new_node(8);
    Y->right = new_node(3);
    Y->left->left = new_node(2);
    Y->left->right = new_node(4);
    Y->right->left = new_node(7);
    Y->right->right = new_node(1);
    Y->left->left->left = new_node(3);
    Y->left->right->left = new_node(1);
    Y->left->right->right = new_node(7);

    displayTree(X,0,'-');
    printf("\n\n\n");
    displayTree(Y,0,'=');

    printf("%d",conv_by_swaps(X,Y));
    return 0;
}
