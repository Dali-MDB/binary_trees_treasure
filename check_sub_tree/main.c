#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"
#include <stdbool.h>

bool is_sub_tree(ptr R, ptr SR){
   if(SR == NULL)
     return true;    //the null tree is a sub tree of all trees

   if(R==NULL)
     return false;


   if(identicalTrees(R,SR))
      return true ;
   else //we check sub trees
      return is_sub_tree(LC(R),SR) || is_sub_tree(RC(R),SR);


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

    ptr R2 = new_node(10);
    R2->left = new_node(5);
    R2->right = new_node(15);

    displayTree(R,0,' ');
    printf("%d",is_sub_tree(R,R2));

    return 0;
}
