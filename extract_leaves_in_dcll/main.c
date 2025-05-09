#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

typedef struct doubly_linked_list{
   ptr head;
   ptr tail;
}DLLS;

ptr extract_leaves_to_DLLS(ptr R, DLLS* List){
   if(R!=NULL){
      if(is_leaf(R)){
         //we add it to the list
         if((*List).head == NULL)//first creation
            (*List).head = R;
         else{ //+2nd
            ((*List).tail)->right  = R;
             R->left = (*List).tail;   ///double link
         }

         (*List).tail = R;    //update the tail of the list
         return NULL;  ///to the calling parent node

      }
      else{//not a leaf, so we only update its subtrees
          R->left = extract_leaves_to_DLLS(LC(R),List);
          R->right = extract_leaves_to_DLLS(RC(R),List);
      }

   }
   else
      return NULL;


}


void display_DLLS(DLLS list){

    ptr temp = list.head;
    while(temp != NULL){
        Textecolor(2);
        if(temp->left == NULL)   ///head
            printf("=|--");
        Textecolor(1);
        printf("( %d )",temp->val);
        Textecolor(2);
        if(temp->right == NULL)  ///tail
            printf("--|=");
        else
            printf("<==>");
         temp = temp->right;  //we move to the following element
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

    root->right->left->left = new_node(10);
    root->right->left->right = new_node(11);

    displayTree(root,10,'-');

    printf("\n\nthe tree after extracting its leaves : \n");
    DLLS leaves;      leaves.head = NULL;       leaves.tail = NULL;     ///initialize the list
    ptr root2 = extract_leaves_to_DLLS(root,&leaves);

    displayTree(root2,10,'-');

    Textecolor(5);
    printf("\nthe extraced leaves are :  ");
    display_DLLS(leaves);

    return 0;
}
