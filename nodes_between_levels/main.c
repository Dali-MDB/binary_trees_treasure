#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

void nodes_between_levels(ptr R ,int base_level ,int highest_level){
    if(R==NULL)
     return;
    queue Q;
    create_queue(&Q);
    enqueue(&Q,R);
    ptr new_level_indicator = NULL;
    int level = 1;
    while(!empty_queue(Q)  &&  level <= highest_level){
        dequeue(&Q,&R);
        ///we check if we're on a new level
        if(R == new_level_indicator){
            new_level_indicator = NULL;
            level++;
            printf("\n");  //to mark another level
        }

        ///we update the new_level_indicator
        if(new_level_indicator == NULL){
            if(LC(R) != NULL)
                new_level_indicator = LC(R);
            else{
                if(RC(R) != NULL)
                    new_level_indicator = RC(R);
            }
        }


        ///display the current node if it's within the specified interval
        if(level >= base_level && level <= highest_level)
            printf("%d  ",data(R));


        //we push its children to the queue
        if(LC(R) != NULL)
              enqueue(&Q,LC(R));
        if(RC(R) != NULL)
              enqueue(&Q,RC(R));


    }

}
int main()
{
    ptr root = new_node(15);
    root->left = new_node(10);
    root->right = new_node(20);
    root->left->left = new_node(8);
    root->left->right = new_node(12);
    root->right->left = new_node(16);
    root->right->right = new_node(25);
    root->right->right->right = new_node(30);

    displayTree(root,10,'-');
    nodes_between_levels(root,2,3);
    return 0;
}
