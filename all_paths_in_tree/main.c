#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"

void all_paths(ptr R){
  if(R==NULL)
     printf("\n");
  else{
    printf(" %d ",data(R));
    all_paths(LC(R));

    if(RC(R)!= NULL){
        printf(" %d ",data(R));
    }
    all_paths(RC(R));
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

    displayTree(X,0,' ');
    all_paths(X);
    return 0;
}
