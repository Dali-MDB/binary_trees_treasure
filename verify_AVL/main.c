#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>
#include <math.h>


int TreeLength(ptr R){
   if(R==NULL)
      return 0;
   else
      return 1+Max(TreeLength(LC(R)),TreeLength(RC(R)));
}

int node_balance(ptr R){
    if(R==NULL)
        return 0;
    else{
        return (TreeLength(LC(R))-TreeLength(RC(R)));
    }

}

bool is_AVL_Tree(ptr R){
    if(R==NULL)
        return true;
    else{
        int balance = node_balance(R);

        if(abs(balance)>1)
            return false;
        else
            return (is_AVL_Tree(LC(R)) && is_AVL_Tree(RC(R)));
    }

}

int main()
{
    ptr root = new_node(4);
    root->left = new_node(2);
    root->right = new_node(6);
    root->left->left = new_node(1);
    root->left->right = new_node(3);
    root->right->left = new_node(5);
   // root->right->right = new_node(8);
    root->left->right->left = new_node(10);
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(9);
   // root->right->right->right = new_node(11);
    displayTree(root,10,'-');

    printf("%d",is_AVL_Tree(root));

    return 0;
}
