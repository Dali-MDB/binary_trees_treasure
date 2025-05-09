#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <stdbool.h>

ptr construct_from_pre_leaf_info(int* Preorder , bool* leaf_info,int size){
   if(size==0) //empty array
      return NULL;

   ptr root=NULL,temp;
   stack STK;
   int i;
   create_stack(&STK);

   for(i=0;i<size;i++){
      ptr N = new_node(Preorder[i]);
      if(empty_stack(STK))///no previous nodes then we set the root
          root = N;
      else{
          pop(&STK,&temp);
          if(LC(temp) == NULL){
              temp->left = N; //we set it as LC
              push(&STK,temp);   //we push it back
          }
          else{  //we set it as rc
              temp->right = N;  ///and we don't push it back
          }

      }

      if( !leaf_info[i] )//not a leaf
         push(&STK,N);      //we push it for the next elements
      ///if it's a leaf we don't push it cuz it can't have children



   }

   return root;






}

int main()
{
    int  Preorder_traversal[] = { 1, 2, 4, 5, 3, 6, 8, 9, 7 };
    bool leaf_info[] = { false, false, true, true, false, false, true, true, true };
    int size = (int) (sizeof(Preorder_traversal) / sizeof(Preorder_traversal[0]));

    ptr Tree = construct_from_pre_leaf_info(Preorder_traversal,leaf_info,size);
    displayTree(Tree,10,'-');
    return 0;
}
