#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"

ptr delete_tree(ptr R , int V){

    ptr temp;
    if (R == NULL)
     return NULL;

    if (data(R) == V){ //either leaf or one child or two children

     if(LC(R) == NULL && RC(R) == NULL){ ///leaf
        free(R);
        R = NULL;
     }
     else if(LC(R) == NULL){     ///one kid
        temp = R;
        R = RC(R);    //the right sub tree will replace this node
        free(temp);
     }
     else if(RC(R) == NULL){    ///one kid
        temp = R;
        R = LC(R);
        free(temp);
     }
     else{ ///both children non null
        temp = minTree(RC(R));    //we search for the smallest element in the right sub tree
        R->val = data(temp);   ///we replace the value with the data of the min leaf
        R->right = delete_tree(RC(R),data(temp));   ///we delete the leaf from the right sub tree
     }
   }
   else{//we keep searching in the two sub trees
     if(data(R) > V)
        R->left = delete_tree(LC(R),V);
     else
        R->right = delete_tree(RC(R),V);
   }


   return R;    ///we return the node either modified or not to be passed as a sub tree for the calling parent node


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

    R = delete_tree(R,13);

    //printf("%d",data(minTree(RC(RC(R)))));
    displayTree(R,0,' ');
    return 0;
}
