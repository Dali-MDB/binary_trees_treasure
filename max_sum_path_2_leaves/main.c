#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>



int max_path_between_two_leaves(ptr R,int* max){
   if(R==NULL)
       return 0;
   else{
      //we identify the maximum sum from sub trees
      int max_left = max_path_between_two_leaves(LC(R),max);
      int max_right = max_path_between_two_leaves(RC(R),max);

      if(max_left + max_right + data(R) > *max)
          *max = max_left + max_right + data(R);

      return Max(max_left,max_right) + data(R);    ///we return the highest path sum + the value of the current node

   }


}

int max_path_between_two_nodes(ptr R,int* max){  ///in this case a node's value might be negative
    if(R==NULL)
        return 0;
    else{
        int max_left = max_path_between_two_nodes(LC(R),max);
        int max_right = max_path_between_two_nodes(RC(R),max);

        ///we modify max if necessary
        if(max_left+max_right+data(R) > *max)
             *max = max_left+max_right+data(R);

        if(max_left+data(R) > *max)
             *max = max_left+data(R);

        if(max_right+data(R) > *max)
             *max = max_right+data(R);

        if(data(R) > *max)
             *max = data(R);


        ///now for the returned value
        if(data(R) > data(R)+max_left  && data(R) > data(R) + max_right)
              return data(R);
        else   //we must include one of the paths
              return data(R) + Max(max_left,max_right);
    }


}



int main()
{
    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->right = new_node(-4);
    root->right->left = new_node(5);
    root->right->right = new_node(6);
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(8);

    displayTree(root,10,'-');
    int max=0;
    int idk = max_path_between_two_leaves(root,&max);

    printf("the maximum path between two leaves is :  %d",max);

    return 0;
}
