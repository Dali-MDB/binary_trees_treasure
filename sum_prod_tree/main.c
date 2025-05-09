#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>

int sum_tree(ptr R ){
  if(R==NULL)
    return 0;
  else
    return data(R) + sum_tree(LC(R)) + sum_tree(RC(R));

}

int product_tree(ptr R){
   if(R == NULL)
      return 1;
   else{
      return data(R) * product_tree(LC(R)) * product_tree(RC(R));
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
   printf("sum =  %d\n",sum_tree(R));;
   printf("product = %d",product_tree(R));

    return 0;
}
