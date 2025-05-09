#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

void rev_lvl_order(ptr R){  //level order from bottom to top
    stack S;
    create_stack(&S);

    if(R != NULL){
        queue Q;
        create_queue(&Q);
        enqueue(&Q,R);

        while(!empty_queue(Q)){
            dequeue(&Q,&R);
            push(&S,R);
            //we push right then first chid if not null
            if(RC(R) != NULL)
                enqueue(&Q,RC(R));
            if(LC(R) != NULL)
                enqueue(&Q,LC(R));

        }

        ///now we pop and display
        printf("reversed level order : ");
        while(!empty_stack(S)){
            pop(&S,&R);
            printf("  %d  ",data(R));
        }

    }

}

int main()
{
    ptr root=new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    displayTree(root,20,'-');
    printf("\n\n");
    rev_lvl_order(root);
    return 0;
}
