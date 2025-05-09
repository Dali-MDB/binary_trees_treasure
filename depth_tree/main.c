#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <math.h>
#include <stdbool.h>

int max(int a,int b){
   if (a>b)
     return a;
   else
     return b;
}

int depth_tree(ptr R){
   if(R==NULL)
      return -1;
   else
     return 1+max(depth_tree(LC(R)) ,depth_tree(RC(R)));

}

int depth(ptr R , bool sub){
   int s;
   if (sub)
     s = 0;
   else{
     s = -1;
     sub = true;
   }
   if(R==NULL)
     return 0;
   else
     return 1 + max(depth(LC(R),sub) , depth(RC(R),sub)) + s;


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
    printf("the depth of the tree is  %d",depth(R,false));

    return 0;
}
