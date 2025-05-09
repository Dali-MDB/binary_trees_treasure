#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>

void identify_leaves(ptr R , int L[100] , int *leaves){
    if(R!=NULL){
        if(LC(R) == NULL && RC(R) == NULL){///a leaf
            L[*leaves] = data(R);
            (*leaves)++;
        }
        else{
            identify_leaves(LC(R),L,leaves);
            identify_leaves(RC(R),L,leaves);
        }
    }
}

int sum_path(ptr R,int V){
   int sum=0;
   bool found=false;

   while(R!=NULL){
      sum += data(R);    //we add the value of the current node to the sum
      if(data(R)==V){
         found = true;
      }

      if(data(R) > V)
         R = LC(R);
      else
         R = RC(R);
   }

   //now the result
   if(!found)
      return 0;
   else
      return sum;


}
int max_sum_path_bst(ptr R){
   if(R==NULL)
      return 0;

   //first we identify the leaves
   int L[100];
   int i,max_sum=0,leaves = 0;
   identify_leaves(R,L,&leaves);

   for(i=0;i<leaves;i++){
        if(max_sum<sum_path(R,L[i]))
               max_sum = sum_path(R,L[i]);
   }

   return max_sum;

}

int max_sum_path_2(ptr R,int current){
   if(R==NULL){    //empty tree or node
       return current;
   }
   else{
       current += data(R);
       return Max(max_sum_path_2(LC(R),current),max_sum_path_2(RC(R),current));
   }

}


int main()
{
    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(8);
    root->left->right = new_node(4);
    root->right->left = new_node(5);
    root->right->right = new_node(6);
    root->left->right->left = new_node(10);
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(9);
    root->right->right->right = new_node(5);

    displayTree(root,10,'-');
    printf("\n\nthe maximum sum from root to leaf is :  %d",max_sum_path_2(root,0));

    return 0;
}
