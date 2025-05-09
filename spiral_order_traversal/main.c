#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <ctype.h>

void spiral_order_traversal(ptr R,char dest){
    if(R == NULL)
        return;

    dest=toupper(dest);
    if ( toupper(dest) != 'L' && toupper(dest) != 'R') //the order wasn't specified
        dest = 'L';       //a default value

    stack children;
    stack S;         create_stack(&S);
    push(&S,R);
    int cpy,cpt_next_level;
    int nbr_level = 1;   ///the number of nodes at the current level
    create_stack(&children);    //the stack that we push the nodes of the ext level into
    while(nbr_level > 0){
       cpy = nbr_level;
       cpt_next_level = 0 ;  //to count the number of nodes of the next level
       while(cpy>0){
              pop(&S,&R);
              printf("  %d  ",data(R));
              cpy-=1;   //cuz we popped one element at this level


              if(dest == 'L'){    ///we push the children from left to right
                    if(R->left != NULL){
                        push(&children,R->left);
                        cpt_next_level+=1;
                    }
                    if(R->right != NULL){
                        push(&children,R->right);
                        cpt_next_level+=1;
                    }
              }
              else{///R  :  we push them from right to left
                    if(R->right != NULL){
                        push(&children,R->right);
                        cpt_next_level+=1;
                    }
                    if(R->left != NULL){
                        push(&children,R->left);
                        cpt_next_level+=1;
                    }
              }
        }
        nbr_level = cpt_next_level;   //we move to the next level
        ///we change the dest
        dest = (dest == 'L') ? 'R' : 'L';
        ///we change the stack
        stack temp;      create_stack(&temp);
        while(!empty_stack(children)){
            pop(&children,&R);
            push(&temp,R);
        }

        while(!empty_stack(temp)){
            pop(&temp,&R);
            push(&S,R);
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

    displayTree(root,10,'-');
    spiral_order_traversal(root,'L');


    return 0;
}
