#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"
#include <ctype.h>

ptr insert_tree_rec(ptr R , int V){
  ptr N;
  char answer;
  char c;

  if(R==NULL){
    return new_node(V);
  }
  else{
    if(data(R) > V){
L:      R->left = insert_tree_rec(LC(R),V);   //we modify the left sub tree and return it
    }
    else if (data(R) < V){
R:      R->right=insert_tree_rec(RC(R),V);    //we modify the right sub tree and return it
    }
    else{ /// = already exists
        printf("the value you want to insert already exists \ndo you want to duplicate it anyways ?(y/n)  :  ");
        scanf("%c",&answer);
        if (tolower(answer) == 'y'){
            printf("do you want to insert it on the left (L) or on the right (R)  :  ");
            scanf(" %c",&answer);
            if (toupper(answer) ==  'L')
                goto L;
            else
                goto R;

        }
    }

    return R;    ///either modified or not (returned as a sub tree of the calling parent node)

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
    insert_tree_rec(R,15);

    displayTree(R,0,' ');
    return 0;
}
