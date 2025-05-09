#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"
#include <stdbool.h>



int is_parent_tree(ptr R , int V){
   if(R==NULL)
      return false;
   else{
      if((LC(R) != NULL && data(LC(R)) == V) || (RC(R) != NULL && data(RC(R)) == V ))
         return true;
      else
         return false;

   }


}
bool are_cousins_tree(ptr R,int V1, int V2){
    if(R==NULL)
        return false;

    if(is_parent_tree(R,V1) && is_parent_tree(R,V2)) ///siblings
        return false;
    else{
        ptr Left = LC(R);
        ptr Right = RC(R);

        if ( ( is_parent_tree(Left,V1) && is_parent_tree(Left,V2)) || ( is_parent_tree(Right,V1) && is_parent_tree(Right,V2)))
            return false;    //siblings
        else if ( (is_parent_tree(Left,V1) && is_parent_tree(Right,V2)) || (is_parent_tree(Left,V2) && is_parent_tree(Right,V1)) )
            return true ;  ///cousins
        else //we check the sub trees
            return are_cousins_tree(Left,V1,V2) || are_cousins_tree(Right,V1,V2);
    }


}

void cousins_in_tree(ptr R){
  if (R==NULL)
    return;

  if(LC(R) == NULL && RC(R) == NULL)
     return;
  else{ //both or one of them is not NULL
     if (LC(R) == NULL )  ///then RC isn't NULL
        cousins_in_tree(RC(R));
     else if (RC(R) == NULL )  ///then LC isn't NULL
        cousins_in_tree(LC(R));
     else{/// both non null then we can find cousins
        if ( (LC(LC(R)) != NULL || RC(LC(R)) != NULL) && (LC(RC(R)) != NULL || RC(RC(R)) != NULL) )  ///to assure there are cousins
        {
            if(LC(LC(R)) != NULL )
                printf("%d",data(LC(LC(R))));

            if(RC(LC(R)) != NULL )
                printf("   %d",data(RC(LC(R))));

            printf("    cousins of :  ");

            if(LC(RC(R)) != NULL )
                printf("%d",data(LC(RC(R))));

            if(RC(RC(R)) != NULL )
                printf("   %d",data(RC(RC(R))));

            printf("\n");   //to prepare for the next xousins

            ///now we verify the sub tres
            cousins_in_tree(LC(R));
            cousins_in_tree(RC(R));

        }

     }

     return;

  }



}

int main()
{
    ptr R = new_node(49);

    R->left = new_node(30);
    R->left->left = new_node(22);
    R->left->right = new_node(41);
   // R->left->left->left = new_node(15);
   // R->left->left->right = new_node(27);
    R->left->right->left = new_node(36);
    R->left->right->right = new_node(44);

    R->right = new_node(70);
    R->right->left = new_node(60);
    R->right->right = new_node(87);
    R->right->left->left = new_node(55);
 //   R->right->left->right = new_node(62);
    //R->right->right->left = new_node(75);
    R->right->right->right = new_node(99);

    displayTree(R,0,'=');
    printf("\n\n\n");
    cousins_in_tree(R);
    return 0;
}
