#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

void invert_binary_tree(ptr R){
   if(R==NULL)
       return;

   //for each node we swap its left and right children
   ptr temp = R->left;
   R->left = R->right;
   R->right = temp;

   //then we recursively call on its children
   invert_binary_tree(R->left);
   invert_binary_tree(R->right);

}
int main()
{
    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    displayTree(root,10,'-');

    invert_binary_tree(root);

    printf("after inverting the tree :   \n");
    displayTree(root,10,'-');

    return 0;
}
