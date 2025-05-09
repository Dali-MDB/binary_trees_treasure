#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"
#include <stdbool.h>

bool is_mirror(ptr R1,ptr R2){
   if(R1 == NULL && R2 == NULL)
      return true;

   if((R1==NULL && R2 != NULL) || (R2 == NULL && R1 != NULL))  //different sons
      return false;

   else{ //both are non null
      if(data(R1) != data(R2))
          return false;   //different nodes , no need to check for sub trees
      else
          return is_mirror(LC(R1),RC(R2)) && is_mirror(RC(R1),LC(R2));

   }

}

bool is_symetrical(ptr R){
    if(R==NULL)
        return true;
    else  //we can check the sub trees
        return is_mirror(LC(R),RC(R));    ///no need to worry about NULL state or data cuz it will be handled within mirror


}

ptr conv_mirror(ptr R1,ptr R2){   //convert R1 into R2 as a mirror
    if(R1 == NULL)
        return NULL;

    else{
        R2 = new_node(data(R1));    ///first we create the node with the same data
        R2->left = conv_mirror(RC(R1),LC(R2));
        R2->right = conv_mirror(LC(R1),RC(R2));

        return R2;   //after modification we return it as a parent of the calling parent
    }


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

    ptr root2 = new_node(1);
    root2->right = new_node(2);
    root2->left = new_node(3);
    root2->right->right = new_node(4);
    root2->right->left = new_node(5);
    root2->left->right = new_node(6);
    root2->left->left = new_node(7);

    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(2);
    root->left->left = new_node(3);
    root->left->right = new_node(4);
    root->right->left = new_node(4);
    root->right->right = new_node(3);

   /* displayTree(root1,0,'-');
    printf("\n\n\n\n");
    displayTree(root2,0,'=');
    printf("%d",is_mirror(root1,root2));
    */

    //printf("%d",is_symetrical(root));

    ptr base_tree = new_node(25); // Root value set to 25
    base_tree->left = new_node(15);
    base_tree->right = new_node(35);
   // base_tree->left->left = new_node(5);
    base_tree->left->right = new_node(20);
    base_tree->right->left = new_node(30);
    base_tree->right->right = new_node(45);

    displayTree(base_tree,0,'-');

    ptr mirror_tree = conv_mirror(base_tree,mirror_tree);
    printf("\n\n\n");
    displayTree(mirror_tree,0,'=');

    return 0;
}
