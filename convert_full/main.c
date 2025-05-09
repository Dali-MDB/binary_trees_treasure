#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>

ptr convert_full(ptr R){
    if(R==NULL)
        return R;

    R->left = convert_full(LC(R));
    R->right = convert_full(RC(R));
    if(LC(R)!=NULL && RC(R) != NULL){ //null or has 2 children
        return R;
    }
    else{//either one child on non
        if(LC(R) != NULL){
            ptr temp = LC(R);
            free(R);
            return temp;
        }
        else if(RC(R) != NULL){
            ptr temp = RC(R);
            free(R);
            return temp;
        }
        else //both null
            return R;
    }

}

int main()
{
    ptr root = new_node(0);
    root->left = new_node(1);
    root->right = new_node(2);
    root->left->left = new_node(3);
    root->right->left = new_node(4);
    root->left->left->left = new_node(5);
    root->right->left->left = new_node(6);
    root->right->left->right = new_node(7);

    displayTree(root,0,'-');
    printf("after:\n\n");
    root = convert_full(root);
    displayTree(root,0,'-');


    return 0;
}
