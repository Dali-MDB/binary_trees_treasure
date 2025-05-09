#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>


bool exists_no_bst(ptr R,int v){
   if(R==NULL)
      return false;

   if(data(R) == v)
      return true;
   else
      return exists_no_bst(LC(R),v) || exists_no_bst(RC(R),v);
}


void identify_leaves(ptr R , int L[100] , int *leaves){
    if(R!=NULL){
        if(LC(R) == NULL && RC(R) == NULL){///a leaf
            L[*leaves] = data(R);
            (*leaves)++;
        }
        identify_leaves(LC(R),L,leaves);
        identify_leaves(RC(R),L,leaves);
    }
}

int get_path_sum(ptr R , int V ){  //obtain the path of a given node (from node to root) stored in a LL

    int sum = 0;
    while(R!=NULL){
        sum += data(R);
        if(exists_no_bst(LC(R),V))
            R = LC(R);
        else
            if(exists_no_bst(RC(R),V))
               R=RC(R);
            else //doesn't exist in any of em
                R=NULL;  //to quit the loop
    }

    return sum;

}

void total_deletion(ptr R){//applies post order to delete the entire tree
   if(R!=NULL){
       total_deletion(LC(R));
       total_deletion(RC(R));
       free(R);  //delete the current node
   }
}

void remove_path_less_K(ptr R ,int current_sum ,int k){
   if(R!=NULL){
      //we check if left and right sub trees have no paths that their sum is greater than k
      current_sum += data(R);   //the current sum from the original root to this node

      int L[100];
      int i,S,max_Sum;


      if(LC(R) != NULL){
         //first we identify the leaves on this sub tree
         int leaves =0;
         identify_leaves(LC(R),L,&leaves);   ///now we have the leaves stored in L

         //we identify the maximum sum from this node to leaves
         max_Sum= 0;
         for(i=0;i<leaves;i++){
            S = get_path_sum(LC(R),L[i]);
            if(S>max_Sum)
                max_Sum = S;
         }


         ///now we check
         if( current_sum+max_Sum<k ){ //no path leading to a sum >= K
            total_deletion(LC(R));
            R->left = NULL;
         }
      }


      if(RC(R) != NULL){
         //first we identify the leaves on this sub tree
         int leaves =0;
         identify_leaves(RC(R),L,&leaves);   ///now we have the leaves stored in L
         //we identify the maximum sum from this node to leaves

         max_Sum= 0;
         for(i=0;i<leaves;i++){
            S = get_path_sum(RC(R),L[i]);
            if(S>max_Sum)
                max_Sum = S;
         }


         ///now we check
         if( current_sum+max_Sum<k ){ //no path leading to a sum >= K
            total_deletion(RC(R));
            R->right = NULL;
         }
      }

      ///we have a problem here


      remove_path_less_K(LC(R),current_sum,k);
      remove_path_less_K(RC(R),current_sum,k);

   }

}

int main()
{
    ptr root = new_node(6);
    root->left = new_node(3);
    root->right = new_node(8);

    root->right->left = new_node(4);
    root->right->right = new_node(2);
    root->right->right->right = new_node(3);

    root->right->left->left = new_node(1);
    root->right->left->right = new_node(7);

    displayTree(root,0,'-');

    printf("results:\n\n");
    remove_path_less_K(root,0,20);
   // printf("%d",get_path_sum(root,3));
    displayTree(root,0,'-');

    return 0;
}
