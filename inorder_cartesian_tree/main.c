#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

int min_index_array(int* T ,int min , int max){
  int i,min_val,index;

  min_val = T[min];     index = min;   //initialized

  for(i=min;i<=max;i++){
     if(T[i] < min_val){
         min_val = T[i];
         index = i;
     }
  }

  return index;

}

ptr inorder_cartesian_tree(int* INORDER, int min , int max){       ///create a tree from inorder according to heap property(the value of the parent is less than its children)
    if(min>max) //stop condition
        return NULL;
    else{
        //we search for the minimum value in the range between min and max
        int index = min_index_array(INORDER,min,max);

        ptr N = new_node(INORDER[index]);    //a node containing this value
        //we search for the roots of the left and right sub trees (even if NULL)
        ptr Left = inorder_cartesian_tree(INORDER,min,index-1);
        ptr Right = inorder_cartesian_tree(INORDER,index+1,max);

        N->left = Left;
        N->right = Right;

        return N;       ///we return the root of the current sub tree
    }



}

int main()
{
    int INORDER[] = { 9, 3, 7, 1, 8, 12, 10, 20, 15, 18, 5 };
    int LB=0 , RB = (int)sizeof(INORDER)/sizeof(INORDER[0]) - 1;
//    printf("%d",INORDER[min_index_array(INORDER,LB,RB)]);

    ptr root = inorder_cartesian_tree(INORDER,LB,RB);

    displayTree(root,10,'-');

    return 0;
}
