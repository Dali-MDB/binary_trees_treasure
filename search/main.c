#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"

ptr search_tree_rec(ptr R , int V){
   if(R == NULL)
      return NULL;
   else if ( data(R) ==  V)
      return R;
   else{
     if(data(R) > V) //we search in the left sub tree
        search_tree_rec(LC(R),V);
     else //right sub tree
        search_tree_rec(RC(R),V);
   }

}

ptr search_tree(ptr R , int V){
   while(R != NULL){
     if(data(R) == V)
        return R;
     else{
        if(data(R) > V)
            R = LC(R);
        else
            R = RC(R);
     }
   }

   return R;   //once we're done
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


   //system("color 80");
    displayTree(R,0,' ');
    Q = search_tree(R,15);
    if(Q != NULL)
      printf("\n\n\n%d could be found ",data(Q));
    else
      printf("could not be found ");


    return 0;
}
