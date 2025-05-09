#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>


bool get_path(ptr R ,ptr N, stack* S){
    if(R==NULL)
        return false;
    else{
        push(S,R);
        if(data(R) == data(N))
             return true;
        else{
            if(get_path(LC(R),N,S) || get_path(RC(R),N,S)) ///exists in one of the subtrees
                return true;
            else{
                pop(S,R);    ///cuz it's not of this path, so we remove it from the path when returning to its par
                return false;
            }
        }
    }

}

ptr next_inorder(ptr R,stack PATH){

    if(R==NULL)
        return NULL;

    if(RC(R) != NULL){
        R=RC(R);
        while(LC(R) != NULL)  ///we reach the min node
            R = LC(R);

        return R;
    }
    else{  ///we ascend
        ptr Par = NULL;
        if(!(empty_stack(PATH)))
            pop(&PATH,&Par);

        while(!empty_stack(PATH) && RC(Par) == R){  ///we ascended from the right
            R = Par;
            pop(&PATH,&Par);
        }

        return Par;

    }


}

ptr next_preorder(ptr R,stack PATH){
     if(R==NULL)
        return NULL;

     if(LC(R) != NULL)
          return LC(R);
     else if(RC(R) != NULL)
          return RC(R);
     else{//both null
        ptr Par = NULL;
        if(!(empty_stack(PATH)))
            pop(&PATH,&Par);

        while(!empty_stack(PATH) && RC(Par) == R){  ///we ascended from the right
            R = Par;
            pop(&PATH,&Par);
        }

        if(Par == NULL)
             return Par;
        else
             return RC(Par);


     }

}

ptr next_postorder(ptr R,stack PATH){
    if(R==NULL)
        return NULL;

    ptr Par=NULL;
    pop(&PATH,&Par);
    if(Par == NULL || RC(Par) == R || RC(Par) == NULL) //R is the root || ascended from the right || from left but no lc
        return Par;
    else{//ascended from the left and rc esists
        R = RC(Par)    ;
        while(LC(R) != NULL)
             R=LC(R);
             return R;

    }


}

int main()
{
    printf("Hello world!\n");
    return 0;
}
