#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

void corner_nodes_every_lvl(ptr R){
    if(R==NULL)
        return;

    //we perform a level order traversal and we keep track of every level
    queue Q;            create_queue(&Q);
    int current_level=1,next_level;
    enqueue(&Q,R);

    while(current_level>0){
        next_level=0;         //to start counting the number of nodes of the following level
        int copy_level = current_level;
        while(copy_level>0){
            dequeue(&Q,&R); //we retrieve the node
            if(copy_level==current_level)///the very first node at the present level
                printf("  %d  ",data(R));
            else{
                if(copy_level==1)///the last node at the present level
                    printf("  %d  ",data(R));
            }

            ///we enqueue the children
            if(R->left){
                enqueue(&Q,R->left);
                next_level+=1;
            }
            if(R->right){
                enqueue(&Q,R->right);
                next_level+=1;
            }


            copy_level-=1;         ///we decrement the counter cuz we took one node off

        }

        printf("\n");   //to seperate each level
        current_level = next_level;   //to continue with the following level


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
    root->left->left->left = new_node(7);
    root->right->left->left = new_node(8);
    root->right->left->right = new_node(9);
    root->right->right->right = new_node(10);

    displayTree(root,10,'-');
    corner_nodes_every_lvl(root);
    return 0;
}
