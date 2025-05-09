#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <stdbool.h>





void boundary_traversal(ptr R){
    ///boundary traversal is determined by the leaves and path between the root and leftmost and rightmost leaves
    int T[100],size=0;
    identify_leaves_LR(R,T,&size);

    stack S_left;
    stack S_right,S_left_reversed;
    create_stack(&S_left);     create_stack(&S_right);

    ptr left_most = left_most_leaf(R);
    ptr right_most = right_most_leaf(R);

    bool sily_boolean = get_path(R,left_most,&S_left);    //the path to the leftmost leaf

    ///we need to traverse from the root to the left most leaf
    create_stack(&S_left_reversed);
    ptr temp;
    while(!empty_stack(S_left)){
        pop(&S_left,&temp);
       // printf(" %d ",data(temp));
        push(&S_left_reversed,temp);
    }

    //now we display from root to left most leaf
    while(!empty_stack(S_left_reversed)){
        pop(&S_left_reversed,&temp);
        printf(" %d ",data(temp));
    }

    //from leftmost to rightmost excluding em
    int i;
    for(i=1;i<size-1;i++){
        printf(" %d ",T[i]);
    }



    //from rightmost to root
    sily_boolean = get_path(R,right_most,&S_right);   //the path to the rightmost leaf

    while(!empty_stack(S_right)){
        pop(&S_right,&temp);
        if(temp != R) ///we make sure not to display the root again
            printf(" %d ",data(temp));
    }

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
    root->left->left->left = new_node(8);
    root->left->left->right = new_node(9);
    root->left->right->right = new_node(10);
    root->right->right->left = new_node(11);
    root->left->left->right->left = new_node(12);
    root->left->left->right->right = new_node(13);
    root->right->right->left->left = new_node(14);


    displayTree(root,10,'-');
    printf("\nboundary traversal :  ");

    boundary_traversal(root);


    return 0;
}
