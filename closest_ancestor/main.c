#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"
#include <stdbool.h>

bool exist_tree(ptr R , int V){
  if (R==NULL)
    return false;

  if(data(R) == V)
     return true ;
  else{
    if (data(R) > V)
        return exist_tree(LC(R),V);   //we search in the left sub tree
    else
        return exist_tree(RC(R),V);   //we search in the right sub tree
  }
}
ptr closes_anc_tree(ptr R , int V1 , int V2){
   if(R==NULL)
     return NULL;

   if(exist_tree(R,V1) && exist_tree(R,V2)){
       if(!(exist_tree(LC(R),V1) && exist_tree(LC(R),V2)) && !(exist_tree(RC(R),V1) && exist_tree(RC(R),V2)))
           return R;     ///the left child isn't a common ancestor and so is the right child
       else{  ///we search either in LC or RC
           if(exist_tree(LC(R),V1) && exist_tree(LC(R),V2))  //LC is a common parent
              return closes_anc_tree(LC(R),V1,V2) ;
           else /// (exist_tree(RC(R),V1) && exist_tree(RC(R),V2))  //RC is a common parent
              return closes_anc_tree(RC(R),V1,V2);

       }

   }else { //V1 and V2 don't both exist
       printf("one or two of the values you provided don't exist");
       return NULL;
   }


}
int main()
{
    ptr R = new_node(49);

    R->left = new_node(30);
    R->left->left = new_node(22);
    R->left->right = new_node(41);
    R->left->left->left = new_node(15);
    R->left->left->right = new_node(27);
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
   // printf("%d",data(closes_anc_tree(R,14,13)));
    return 0;
}
