#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <stdbool.h>
#include <limits.h>
bool is_BST(ptr R,int* min,int* max){
   if(R==NULL)
      return true;

   if(LC(R) == NULL && RC(R) == NULL){  //a leaf
      *max = *min = data(R);
      return true;
   }
   else {
       int right_max=0;
       int right_min=0;
       int left_max=0;
       int left_min=0;
       if(LC(R) == NULL){ //RC not null

             bool right_is_bst = is_BST(RC(R),&right_min,&right_max);

             *min = data(R);   /// no right sub tree
             *max = right_max;

             return right_is_bst && data(R)<=data(RC(R)) && data(R) <= right_min;
       }
       else if(RC(R) == NULL){ //LC not null

             bool left_is_bst = is_BST(LC(R),&left_min,&left_max);

             *min = left_min;
             *max = data(R);   /// no right sub tree

             return left_is_bst && data(R)>=data(LC(R)) && data(R) >= left_max;
       }
       else{///both non null
             bool right_is_bst = is_BST(RC(R),&right_min,&right_max);
             bool left_is_bst = is_BST(LC(R),&left_min,&left_max);

             *max=right_max;
             *min=left_min;

             return right_is_bst && data(R)<=data(RC(R)) && data(R) <= right_min && left_is_bst && data(R)>=data(LC(R)) && data(R) >= left_max;

       }


   }



}

bool is_BST_2(ptr R,int min,int max){
   if(R==NULL)
       return true;

   if(LC(R) != NULL && data(LC(R))>data(R))
       return false;

   if(RC(R) != NULL && data(RC(R))<data(R))
       return false;

   if(data(R) > max || data(R) < min)  ///of its parent
      return false;

   ///this node identifies the property, so we check its children
   return is_BST_2(LC(R),min,data(R)) && is_BST_2(RC(R),data(R),max);


}

int main()
{
    ptr root =new_node(20);
    root->left = new_node(20);
    root->right = new_node(30);
    root->right->left = new_node(05);
    root->right->right = new_node(35);

    displayTree(root,10,'-');


    int miiiin=0,maaaax=0;

    printf(is_BST(root,&miiiin,&maaaax) ? "yes":"no");

    return 0;
}
