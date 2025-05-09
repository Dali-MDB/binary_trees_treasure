#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"
#include <stdbool.h>


int is_stricktBin(ptr R){
  if(R == NULL)
     return true;

  if((LC(R) == NULL && RC(R) != NULL ) || (RC(R)==NULL && LC(R) != NULL))   //one child
      return false;
  else
      return is_stricktBin(LC(R)) && is_stricktBin(RC(R));


}

bool is_complete_tree(ptr R){
   if (R==NULL)
      return true;
   else{
     if(depthTree(LC(R)) != depthTree(RC(R)) || !is_stricktBin(R))
        return false;
     else
        return is_complete_tree(LC(R)) && is_complete_tree(RC(R));

   }

}
int main()
{
    ptr R = new_node(49);

    R->left = new_node(30);
    R->left->left = new_node(22);
    R->left->right = new_node(41);
    R->left->left->left = new_node(15);
    R->left->left->right = new_node(27);
    R->left->right->left = new_node(36);
    R->left->right->right = new_node(44);

    R->right = new_node(70);
    R->right->left = new_node(60);
    R->right->right = new_node(87);
    R->right->left->left = new_node(55);
    R->right->left->right = new_node(62);
    R->right->right->left = new_node(75);
    R->right->right->right = new_node(99);

    displayTree(R,0,' ');
    printf("strict binary tree :  ");
    if (is_stricktBin(R) == true)
        printf("true");
    else
        printf("false");

    printf("\ncomplete tree      :  ");
    if (is_complete_tree(R) == true)
        printf("true");
    else
        printf("false");

    return 0;
}
