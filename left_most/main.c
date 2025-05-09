#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"

ptr left_Most_Node(ptr R){
   if(R==NULL)
      return NULL;

   if(LC(R) == NULL){
      if(RC(R) == NULL)  //the it's a leaf
        return R;
      else
        return left_Most_Node(RC(R));   //we search in the right sub tree since the left one is null
   }
   else{
      return left_Most_Node(LC(R));
   }

}

int main()
{
    ptr R = new_node(49);

    R->left = new_node(30);
    //R->left->left = new_node(22);
    R->left->right = new_node(41);
   // R->left->left->left = new_node(15);
   // R->left->left->right = new_node(27);
    R->left->right->left = new_node(36);
    R->left->right->right = new_node(44);

    R->right = new_node(70);
    R->right->left = new_node(60);
    R->right->right = new_node(87);
    R->right->left->left = new_node(55);
    R->right->left->right = new_node(62);
    R->right->right->left = new_node(75);
    R->right->right->right = new_node(99);

    displayTree(R,0,' ');
    printf("%d",data(leftMostNode(R)));
    return 0;
}
