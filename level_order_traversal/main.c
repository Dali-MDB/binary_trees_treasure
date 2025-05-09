#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"



void level_order_traversal(ptr R){
    if(R != NULL){
        queue Q;
        create_queue(&Q);
        enqueue(&Q,R);
        while(!empty_queue(Q)){
            dequeue(&Q,&R);
            printf("%d  ",data(R));
            if(LC(R) != NULL)
                enqueue(&Q,LC(R));
            if(RC(R) != NULL)
                enqueue(&Q,RC(R));

        }

    }



}

int main()
{
    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->right->left = new_node(5);
    root->right->right = new_node(6);
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(8);

    level_order_traversal(root);

    return 0;
}

