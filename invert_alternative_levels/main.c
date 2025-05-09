#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

void invert_alt_lvls(ptr R){
    if(R==NULL)
        return;

    ///we perform a level order traversal, and store the nodes of the lvl to be inverted in an array then we swap 2 by 2
    queue Q;          create_queue(&Q);
    int nodes_nbr=1,cpt;
    bool invert = false;
    ptr T[100];
    int size;
    enqueue(&Q,R);

    while(nodes_nbr>0){
        cpt = 0;     //reset to start counting the number of nodes in the following level
        size = 0;     ///we reset the size of the array to use it in this level
        while(nodes_nbr>0){
            dequeue(&Q,&R);
            nodes_nbr-=1;


            if(invert)
                T[size++] = R;     //we add it to the array to swap it later


            if(R->left){
                enqueue(&Q,R->left);
                cpt +=1;
            }
            if(R->right){
                enqueue(&Q,R->right);
                cpt +=1;
            }



        }

        if(invert){   ///we swap the values
            int i=0,j=size-1;
            int temp;

            while(i<j){//we swap
                temp = T[i]->val;      T[i]->val = T[j]->val;      T[j]->val = temp;
                i++;
                j--;
            }


        }

        nodes_nbr = cpt;    //for the following level
        invert = invert ? false : true;    ///we change the invert state (level by level)

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
    root->left->right->left = new_node(10);
    root->left->right->right = new_node(11);
    root->right->left->left = new_node(12);
    root->right->left->right = new_node(13);
    root->right->right->left = new_node(14);
    root->right->right->right = new_node(15);

    displayTree(root,10,'-');

    invert_alt_lvls(root);
    printf("after converting the tree in alternative levels manner :  \n");
    displayTree(root,10,'-');

    return 0;
}
