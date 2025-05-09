#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

///the leaf's left and right child are not null, the point to the next leaf
int height_doubly_circular_lls_leaves(ptr R){
   if(R==NULL)
      return 0;
   else{
     ///leaves form a CIRCULAR lls, so (L1   <-->  L2) each adjacent leaves point back to eachother
     ///the paricular case is when there's only one leaf, so it's a regular one (LC==RC==NULL)
      bool leaf =(( (LC(R) == NULL)  || (LC(R) != NULL && LC(R)->right == R))
                  && ((RC(R) == NULL) ||(RC(R) != NULL && RC(R) ->left == R)));

      if(leaf)
         return 1;
      else
         return 1+Max(height_doubly_circular_lls_leaves(LC(R)),height_doubly_circular_lls_leaves(RC(R)));


   }


}

int main()
{
    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);        // leaf node
    root->right->right = new_node(6);       // leaf node
    root->left->left->left = new_node(7);   // leaf node

    displayTree(root,10,'-');

    ///we form the linked lists
    root->left->left->left->left = root->right->right;
    root->left->left->left->right = root->left->right;
    root->left->right->left = root->left->left->left;
    root->left->right->right = root->right->right;
    root->right->right->left = root->left->right;
    root->right->right->right = root->left->left->left;

    printf("the height of the tree is :  %d",height_doubly_circular_lls_leaves(root));



    return 0;
}
