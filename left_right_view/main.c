#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

void left_view_tree(ptr R,int level ,ptr T[100], int* size){
    ///we modify pre-order traversal using hashing
    if(R!=NULL){
        if(level == *size){ ///no node has preocupied this position in the array
            T[(*size)++] = R;
        }

        ///we start by visiting the left then the right subtrees
        left_view_tree(R->left,level+1,T,size);
        left_view_tree(R->right,level+1,T,size);
    }

}

void right_view_tree(ptr R,int level ,ptr T[100], int* size){
    ///we modify pre-order traversal using hashing
    if(R!=NULL){
        if(level == *size){ ///no node has preocupied this position in the array
            T[(*size)++] = R;
        }

        ///we start by visiting the right then the left subtrees
        right_view_tree(R->right,level+1,T,size);
        right_view_tree(R->left,level+1,T,size);
    }

}

void printView(ptr T[100], int size){
   int i;
   for(i=0;i<size;i++)
      printf("  %d  ",data(T[i]));

}

int main()
{
    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->right = new_node(4);
    root->right->left = new_node(5);
    root->right->right = new_node(6);
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(8);
    root->right->left->right->left = new_node(9);

    displayTree(root,10,'-');

    ptr L_view[100],R_view[100];
    int size_L=0,size_R = 0;

    left_view_tree(root,0,L_view,&size_L);
    printf("the left view :  ");     printView(L_view,size_L);

    printf("\n");

    right_view_tree(root,0,R_view,&size_R);
    printf("the right view :  ");     printView(R_view,size_R);
    return 0;
}
