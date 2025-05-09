#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>

bool identical_trees(ptr R1 , ptr R2 ){
   if(R1 == NULL  && R2 == NULL)
      return true ;
   else if ( (R1==NULL && R2 != NULL ) || (R2 == NULL && R1!= NULL))
      return false;
   else{ ///both are non null
      if(data(R1) != data(R2))
          return false;
      else //identical nodes , so we check the sub trees
        return identical_trees(LC(R1),LC(R2)) && identical_trees(RC(R1),RC(R2));

   }
}





int main()
{
    ptr root1 = new_node(49);
    ptr root2 = new_node(49);


    root1->left = new_node(30);
    root1->left->left = new_node(22);
    root1->left->right = new_node(41);
    root1->left->left->left = new_node(15);
    root1->left->left->right = new_node(27);
    root1->left->right->left = new_node(36);
    root1->left->right->right = new_node(44);
    root1->right = new_node(70);
    root1->right->left = new_node(60);
    root1->right->right = new_node(87);
    root1->right->left->left = new_node(55);
    root1->right->left->right = new_node(62);
    root1->right->right->left = new_node(75);
    root1->right->right->right = new_node(99);


    root2->left = new_node(30);
    root2->left->left = new_node(22);
    root2->left->right = new_node(41);
    root2->left->left->left = new_node(15);
    root2->left->left->right = new_node(27);
    root2->left->right->left = new_node(36);
    root2->left->right->right = new_node(44);
    root2->right = new_node(70);
    root2->right->left = new_node(60);
    root2->right->right = new_node(87);
    root2->right->left->left = new_node(55);
    root2->right->left->right = new_node(62);
    root2->right->right->left = new_node(75);
    root2->right->right->right = new_node(99);



    displayTree(root1,0,'-');
    printf("\n\n\n");
    displayTree(root2,0,'=');
    if(identical_trees(root1,root2) == true)
        printf("the trees are identical");
    else
        printf("the trees are not identical");


    return 0;
}
