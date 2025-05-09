#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"
#include <stdbool.h>

bool subtrees_same_val(ptr R,ptr T[100],int* size){
    ///we start by the L and R children
    /// each node is the root if same_val nodes,only if each node shares the same value with its children

    if(R==NULL )
        return true;
    else{
        //we start by the subtrees
        bool left_is_verified = subtrees_same_val(LC(R),T,size);
        bool right_is_verified = subtrees_same_val(RC(R),T,size);

        if(LC(R)==NULL && RC(R) == NULL){
             T[*size] = R;
             (*size)++;
             return true;
        }
        else if(LC(R)==NULL){  //rc != NULL
             if(data(R) == data(RC(R)) && right_is_verified){
                  T[*size] = R;
                  (*size)++;
                  return true;
             }
             else
                  return false;
        }
        else if(RC(R)==NULL){  //rc != NULL
             if(data(R) == data(LC(R)) && left_is_verified){
                  T[*size] = R;
                  (*size)++;
                  return true;
             }
             else
                  return false;
        }
        else{//both non null
             if(data(R) == data(RC(R)) && right_is_verified && data(R) == data(LC(R)) && left_is_verified){
                  T[*size] = R;
                  (*size)++;
                  return true;
             }
             else
                  return false;

        }




    }


}


int main()
{
    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->right->left = new_node(5);
    root->right->right = new_node(6);
    root->left->left->left = new_node(4);
    root->right->left->left = new_node(5);
    root->right->left->right = new_node(5);
    root->right->right->right = new_node(7);


    displayTree(root,10,'-');
    int i,size=0;
    ptr T[100];
    bool idk = subtrees_same_val(root,T,&size);

    printf("the extracted sub trees that are consisting of the same value are :    \n");
    for(i=0;i<size;i++){
        displayTree(T[i],10,'-');
        printf("\n");
    }
    return 0;
}
