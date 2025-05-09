#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

ptr closest_sibling_node(ptr R,int V){
   if(R == NULL)
      return NULL;

   //we perform level order traversal and we stop when we find the sibling
   queue Q;     create_queue(&Q);
   int cpt,current_level;    ///two counters to indicate the number of nodes present at the current level
   enqueue(&Q,R);     current_level = 1;

   while(current_level>0){
       cpt = 0;    //to count the nodes present at the following level
       while(current_level>0){
           dequeue(&Q,&R);      ///we retrieve the element
           current_level-=1;

           if(data(R) == V){  //the desired node
               if(current_level == 0)  ///no remaining nodes at this level <=> right most at this level
                  return NULL;
               else{ //the next node in the queue is its closest sibling
                  dequeue(&Q,&R);
                  return R;
               }
           }
           else{  //we continue the level order traversal normally

                if(R->left != NULL){
                    enqueue(&Q,R->left);
                    cpt +=1;   //a new_node added in the following level
                }
                if(R->right != NULL){
                    enqueue(&Q,R->right);
                    cpt +=1;   //a new_node added in the following level
                }

           }


       }

       ///we continue with the following level
       current_level = cpt;

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
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(8);

    displayTree(root,10,'-');
    ptr sibling =  closest_sibling_node(root,3);

    if (sibling != NULL)
        printf("\n%d", data(sibling));
    else
        printf("NULL");
    return 0;
}
