#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <stdbool.h>

bool is_one_child_tree(ptr R){
    if(R==NULL)
        return true;

    if(LC(R) != NULL  &&  RC(R) != NULL)  //two children
        return false;
    else
        return is_one_child_tree(LC(R)) && is_one_child_tree(RC(R));     //NULL children return true


}

int main()
{
    ptr root = new_node(15);
    root->left = new_node(10);
    root->right = new_node(30);
    root->right->left = new_node(25);
    root->right->left->left = new_node(18);
    root->right->left->left->right = new_node(20);

    displayTree(root,10,'-');

    printf(is_one_child_tree(root) ? "the tree is a Skewed Tree" : "the tree is NOT a Skewed Tree");
    return 0;
}
