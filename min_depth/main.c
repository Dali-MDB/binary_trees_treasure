#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

int min_depth(ptr R , stack* S){
    if(R==NULL)
        return 0;
    else{
        stack LSTK,RSTK;
        create_stack(&LSTK);       push(&LSTK,R);
        create_stack(&RSTK);        push(&RSTK,R);

        int ld = min_depth(R->left,&LSTK);
        int rd = min_depth(R->right,&RSTK);


        stack stk_temp;      create_stack(&stk_temp);
        ptr temp;

        if(ld == 0 && rd == 0){///a leaf
             return 1;
        }
        else{
            if(ld == 0){ ///RC only
                while(!empty_stack(RSTK)){
                   pop(&RSTK,&temp);
                   push(&stk_temp,temp);
                }

                ///now we push them back into S
                while(!empty_stack(stk_temp)){
                      pop(&stk_temp,&temp);
                      push(&S,temp);
                }

                return rd+1;
            }
            else if(rd == 0){///LC only
                while(!empty_stack(LSTK)){
                       pop(&LSTK,&temp);
                       push(&stk_temp,temp);
                }

                ///now we push them back into S
                while(!empty_stack(stk_temp)){
                      pop(&stk_temp,&temp);
                      push(&S,temp);
                }

                return ld + 1;
            }
            else{///both non null, so we take the minimum

                if(ld>rd){
                   //we copy the elements of LSTK into S
                   while(!empty_stack(LSTK)){
                       pop(&LSTK,&temp);
                       push(&stk_temp,temp);
                   }

                }
                else{///rd>=ld
                   //we copy the elements of RSTK into S
                   while(!empty_stack(RSTK)){
                       pop(&RSTK,&temp);
                       push(&stk_temp,temp);
                    }
                }

                ///now we push them back into S
                while(!empty_stack(stk_temp)){
                      pop(&stk_temp,&temp);
                      push(&S,temp);
                }

                return 1+ (ld>rd? rd:ld);

            }
        }

    }




}

int main()
{
    printf("Hello world!\n");
    return 0;
}
