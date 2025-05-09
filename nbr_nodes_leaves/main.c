#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"



int count_nodes_tree(ptr R){
   //base case
   if(R==NULL)
     return 0;
   else
     return 1 + count_nodes_tree(LC(R)) + count_nodes_tree(RC(R));


}

int count_leaves_tree(ptr R){
   if(R==NULL)
     return 0 ;
   else{
      if (LC(R) == NULL && RC(R) == NULL)  //is a leaf
        return 1;
      else
        return count_leaves_tree(LC(R)) + count_leaves_tree(RC(R));
   }

}

int main()
{
   ptr Q;
   ptr R =new_node(15);
   ass_LC(&R , new_node(13));
   ass_RC(&R, new_node(17));
   Q = LC(R);

   ass_RC(&(R->right) ,new_node(20));
   ass_RC(&(R->right->right) , new_node(22));
   ass_LC(&Q, new_node(10));
   ass_RC(&Q, new_node(14));




    displayTree(R,0,' ');


    printf("the number of nodes is %d\n",count_nodes_tree(R));
    printf("the number of leaves is %d",count_leaves_tree(R));
    return 0;
}
