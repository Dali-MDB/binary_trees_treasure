#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

void alt_LR_level_order(ptr R){///we suppose that it's a perfect tree( each node has 2 or 0 children )
   if(R==NULL)
       return;


   printf("alternative left to right level order traversal :\n");
   //we will use two queue
   queue left_Q,right_Q;
   create_queue(&left_Q);      create_queue(&right_Q);

   printf("  %d  ",data(R));
   if(!is_leaf(R)){
      enqueue(&left_Q,R->left);
      enqueue(&right_Q,R->right);
   }

   while(!empty_queue(left_Q)){  //in parallel with right
       ptr left,right; //left and right children
       dequeue(&left_Q,&left);
       dequeue(&right_Q,&right);

       ///we display
       printf("  %d      %d  ",data(left),data(right));


       if(!is_leaf(left)){   ///we push left then right into the left queue
          enqueue(&left_Q,left->left);
          enqueue(&left_Q,left->right);
       }

       if(!is_leaf(right)){   ///we push right then left into the right queue
          enqueue(&right_Q,right->right);
          enqueue(&right_Q,right->left);
       }

   }




}

void rev_alt_LR_level_order(ptr R){///we suppose that it's a perfect tree( each node has 2 or 0 children )
   if(R==NULL)
       return;


    printf("reversed alternative left to right level order traversal :\n");
   //we will use two queue
   queue left_Q,right_Q;
   create_queue(&left_Q);      create_queue(&right_Q);

   //we also use two stacks to display in reversed order
   stack left_S,right_S;
   create_stack(&left_S);      create_stack(&right_S);

   if(!is_leaf(R)){
      enqueue(&left_Q,R->left);
      enqueue(&right_Q,R->right);

      push(&left_S,R->left);
      push(&right_S,R->right);
   }

   while(!empty_queue(left_Q)){  //in parallel with right
       ptr left,right; //left and right children
       dequeue(&left_Q,&left);
       dequeue(&right_Q,&right);




       if(!is_leaf(right)){   ///we push left then right into the left queue
          enqueue(&right_Q,right->left);
          enqueue(&right_Q,right->right);

          ///for the stack
          push(&right_S,right->left);
          push(&right_S,right->right);
       }

       if(!is_leaf(left)){   ///we push right then left into the right queue
          enqueue(&left_Q,left->right);
          enqueue(&left_Q,left->left);

          ///for the stack
          push(&left_S,left->right);
          push(&left_S,left->left);

       }

   }

   ///now the display
   ptr root = R;
   while(!empty_stack(left_S)){ //in parallel with right
       pop(&left_S,&R);
       printf("  %d  ",data(R));

       pop(&right_S,&R);
       printf("  %d  ",data(R));
   }

   ///it remains to display the root at the end
   printf("  %d  ",data(root));




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
    alt_LR_level_order(root);
    printf("\n");
    rev_alt_LR_level_order(root);

    return 0;
}
