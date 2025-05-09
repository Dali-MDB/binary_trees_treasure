#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"

void conv_sum_tree(ptr R){
   if(R==NULL)
     return;

   else{
     R->val = SumTree(LC(R)) + SumTree(RC(R));
     conv_sum_tree(LC(R));
     conv_sum_tree(RC(R));
}

}

///2nd solution
int convsumTree(ptr R){
   if(R==NULL)
     return 0;

   else{
     int Left = convsumTree(LC(R));
     int Right = convsumTree(RC(R));
     int old = data(R);    //we save the old value cuz it will be included in the sum for the parent node

     R->val = Left + Right;
     return old + data(R);
}

}

bool is_sum_tree(ptr R){
   if(R==NULL)
      return true;

   if (LC(R) == NULL && RC(R) == NULL)
      return true;
   else{
     if(data(R) != (SumTree(LC(R)) + SumTree(RC(R)) ))
        return false;
     else //the node itself is verifies so we check the subtrees
        return  is_sum_tree(LC(R)) && is_sum_tree(RC(R));

   }

}

int main()
{
    ptr R = new_node(1);

    R->left = new_node(2);
   // R->left->left = new_node(22);
    R->left->right = new_node(4);
  //  R->left->left->left = new_node(15);
   // R->left->left->right = new_node(27);
   // R->left->right->left = new_node(36);
  //  R->left->right->right = new_node(44);

    R->right = new_node(3);
    R->right->left = new_node(5);
    R->right->right = new_node(6);
    R->right->left->left = new_node(7);
    R->right->left->right = new_node(8);
  //  R->right->right->left = new_node(75);
    //R->right->right->right = new_node(99);

    conv_sum_tree(R);
    int total = convsumTree(R);
    displayTree(R,0,' ');

    ptr root = new_node(44);
    root->left = new_node(9);
    root->right = new_node(13);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);
    displayTree(root,0,' ');


    if(is_sum_tree(root) )
        printf("yes");
    else
        printf("zebiiiii");

    return 0;
}
