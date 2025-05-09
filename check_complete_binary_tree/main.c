#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <stdbool.h>

bool is_complete_binary_tree(ptr R){///every level, except possibly the last, is filled, and all nodes are as far left as possibl
   if(R==NULL)
       return true;

   //we perform a level order traversal and check the estimated number of nodes at that level
   //we also check the gaps of NULL children

   int estimated_nbr=1;    //the estimated number of nodes at the following lvl
   int cpt ;
   bool prev_is_NULL = false;  //to tell if there were NULL children before

   queue Q;     create_queue(&Q);     enqueue(&Q,R);
   int current_lvl = 1;  //the number of nodes at the present level

   while(current_lvl>0){
       cpt = 0;   //reset the number of children
       estimated_nbr *=2;    //at each level the number of nodes doubles
       prev_is_NULL = false;    //the start of the level so there are no previous children
       while(current_lvl>0){
          dequeue(&Q,&R);  //we retrieve the node
        //  printf("%d  ",data(R));    getchar();
          current_lvl-=1;

          if(R->left != NULL){
              if(prev_is_NULL)    ///we can't find a gap in nodes at the same level
                  return false;

              //else we enqueue normally
              enqueue(&Q,R->left);
              cpt+=1;

          }
          else
             prev_is_NULL = true;      ///a null child, so we indicate to catch any gap found

          if(R->right != NULL){
               if(prev_is_NULL)    ///we can't find a gap in nodes at the same level
                    return false;

              //else we enqueue normally
              enqueue(&Q,R->right);
              cpt+=1;

          }
          else
             prev_is_NULL = true;      ///a null child, so we indicate to catch any gap found



       }

       if(cpt<estimated_nbr){///allowed only in the very last level ( no nodes at the following level)
            //we traverse the last level and launch an error if we find any children (another level)
            while(!empty_queue(Q)){
                dequeue(&Q,&R);
                if( !is_leaf(R)) //has children hence another level
                    return false;
            }
            return true;

       }

      current_lvl = cpt;    //continue with the following level

   }

   return true;   //if we finished traversing the whole tree without quiting it satisfies the conditions




}


int main()
{

    ptr root1 = new_node(1);
    root1->left = new_node(2);
    root1->right = new_node(3);
    root1->left->left = new_node(4);
    root1->left->right = new_node(5);
    root1->right->left = new_node(6);
    root1->right->right = new_node(7);

    displayTree(root1,10,'-');
    printf("\nis this tree a complete binary tree ?    :     ");
    printf(is_complete_binary_tree(root1) ? "true" : "false");

    printf("\n\nporess any key to continue :");   getchar();     system("cls");

    ptr root2 = new_node(1);
    root2->left = new_node(2);
    root2->right = new_node(3);
    root2->left->left = new_node(4);
    root2->left->right = new_node(5);
    root2->right->left = new_node(6);

    displayTree(root2,10,'-');
    printf("\nis this tree a complete binary tree ?    :     ");
    printf(is_complete_binary_tree(root2) ? "true" : "false");

    printf("\n\nporess any key to continue :");   getchar();     system("cls");

    ptr root3 = new_node(1);    ///we can adjust the nodes and try different forms of the tree
    root3->left = new_node(2);
    root3->right = new_node(3);
    //root3->left->left = new_node(4);
    root3->left->right = new_node(5);
   // root3->right->left = new_node(6);
    //root3->right->right = new_node(7);
    //root3->left->left->left = new_node(10);

    displayTree(root3,10,'-');
    printf("\nis this tree a complete binary tree ?    :     ");
    printf(is_complete_binary_tree(root3) ? "true" : "false");

    return 0;
}
