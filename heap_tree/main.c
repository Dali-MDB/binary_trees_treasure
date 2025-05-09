#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../trees_lib.h"

typedef struct info{
    ptr par;
    int level,max_level;
}info;

bool is_heap_tree(ptr R){
   if(R==NULL)
      return true;

   if(LC(R) != NULL && data(R->left) > data(R))
       return false;
   if(RC(R) != NULL && data(R->right) > data(R))
       return false;

   return  is_heap_tree(LC(R)) && is_heap_tree(RC(R));
}

info srch_par_insert(ptr R,int lvl){
    info X;
    if(R==NULL){  ///can't insert here

       X.par = NULL;
       X.level = -1;
       X.level = -1;
       return X;
    }

    info X_left,X_right;
    X_left = srch_par_insert(R->left,lvl+1);
    X_right = srch_par_insert(R->right,lvl+1);

    ///now we determine which one to return
    if(X_left.par == NULL){//if left doesn't exist then right too
        X.par = R;   ///a potential parent
        X.level = lvl;
        X.max_level = lvl;   //cuz there's no children
    }
    else{
        if(X_right.par == NULL){  ///only left
            X.par = R;
            X.level = lvl;
            X.max_level = X_left.max_level;    //to indicate that there are other leaves deeper
        }
        else{///both non null
            //we determine which one to be returned
            if(X_left.max_level > X_right.max_level){
                 X.par = X_right.par;
            }
            else{ /// ==
                 X.par = X_left.par;
            }
            X.max_level = X_left.max_level;
            X.level = X_right.level;


        }
    }

}

ptr insert_heap(ptr root,int V){
    ptr N = new_node(V);
    if(root == NULL)
        return N;
    else{
        ptr Par = srch_par_insert(root,0);   ///we search the parent of N
        //insertion
        if(Par->left == NULL)
            Par->left = N;
        else
            Par->right = N;   ///Rc can't be null if par was returned(otherwise we would have returned a child of it)

        //now we perform swaps to ensure heap property is still valid
        ptr temp = root;
        stack S;    create_stack(&S);
        searc


    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
