#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"
#include <stdbool.h>

bool is_leaf(ptr R){
   if(R==NULL)
      return false;
   else{
      if(LC(R)==NULL && RC(R)==NULL)
          return true;
      else
          return false;
   }

}

bool exists_in_array(int T[100],int size,int V){
   int i;
   for(i=0;i<size;i++){
       if(T[i]==V)
          return true;
   }

   return false;
}

void nodes_dist_leaf(ptr R,int dist,int T[100],int size,int result[100],int* result_size){
    if(R!=NULL){
        T[size] = data(R);    size++;

        if(is_leaf(R)){
            int d=0 , i = size-1;
            while((d<dist) && (i>=0) ){ ///we haven't reached th dist and elements of T (path) are still accessible
                d++;
                i--;
            }
            if(i>=0){//we didn't quit bcs of underflow

                if(!(exists_in_array(result,*result_size,T[i]))){///we make sure to add uniq elements

                    result[*result_size] = T[i];
                    (*result_size)++;
                   // printf("%d  ",T[i]);
                }
            }

        }else{///we keep descending to its sub trees
            nodes_dist_leaf(LC(R),dist,T,size,result,result_size);
            nodes_dist_leaf(RC(R),dist,T,size,result,result_size);
        }

        size--;
    }

}

int main()
{
    ptr root = new_node(15);
    root->left = new_node(10);
    root->right = new_node(20);
    root->left->left = new_node(8);
    root->left->right = new_node(12);
    root->right->left = new_node(16);
    root->right->right = new_node(25);
    root->right->left->left = new_node(18);

    displayTree(root,10,'-');

    int T[100],size=0,result[100],result_size=0,i;
    printf("\nthe nodes at distance 3 are: ");
    nodes_dist_leaf(root,2,T,size,&result,&result_size);
   for(i=0;i<result_size;i++){
        printf(" %d ",result[i]);
    }

    return 0;
}
