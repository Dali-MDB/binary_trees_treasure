#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>

ptr min_tree_rec(ptr R){
  if(R==NULL)
    return NULL;
  else{
    if(LC(R) == NULL)  //no left sub-tree
       return R;
    else
       return min_tree_rec(LC(R));   //we search in the left sub-tree
  }
}

ptr max_tree_rec(ptr R){
  if(R==NULL)
    return NULL;
  else{
    if(RC(R) == NULL)  //no right sub-tree
       return R;
    else
       return max_tree_rec(RC(R));   //we search in the right sub-tree
  }
}


//non recursive versions

ptr min_tree(ptr R){
  if (R==NULL)
    return NULL;
  else{

    while(LC(R)!=NULL)
       R = LC(R);   //keep descending till we find that there's not left sub tree ( NULL )

    return R;

  }

}

ptr max_tree(ptr R){
  if (R==NULL)
    return NULL;
  else{

    while(RC(R)!=NULL)
       R = RC(R);   //keep descending till we find that there's not right sub tree ( NULL )

    return R;

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
    printf("max =  %d  |    min =  %d ",data(max_tree_rec(R)) , data(min_tree_rec(R)));
    return 0;
}
