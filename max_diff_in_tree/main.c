#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"
#include <stdbool.h>




int max_diff_root(ptr root,ptr R){
   if(R==NULL)
      return 0;
   else{
      int diff = ((data(root)-data(R)) > 0 ? data(root)-data(R) : data(R) - data(root));
      int left = max_diff_root(root,LC(R));
      int right = max_diff_root(root,RC(R));

      if(diff>= left && diff >= right)
          return diff;
      if(left>=diff && left >= right)
          return left;
      if(right>= left && right >= diff)
           return right;
   }
}

void max_diff_in_tree(ptr R,int* max){
   if(R!=NULL){

      int difference = max_diff_root(R,R);
      if(*max<difference)
          *max = difference;

      max_diff_in_tree(LC(R),max);
      max_diff_in_tree(RC(R),max);
   }

}
int main()
{
    ptr root = new_node(6);
    root->left = new_node(3);
    root->right = new_node(8);
    root->right->left = new_node(2);
    root->right->right = new_node(4);
    root->right->left->left = new_node(1);
    root->right->left->right = new_node(7);

    displayTree(root,10,'-');
    int max_diff ;
    max_diff_in_tree(root,&max_diff);


    printf(" %d   ",max_diff);
    return 0;
}
