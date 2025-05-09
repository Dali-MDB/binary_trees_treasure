#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>


bool isHeightBalanced(ptr R, int* root_max){
   if(R==NULL)
      return true;

   int left_max = 0 ,right_max = 0;

   if(isHeightBalanced(LC(R),&left_max) && isHeightBalanced(RC(R),right_max)){
       *root_max= (right_max>left_max ? right_max : left_max);
       int root_min = (right_max<left_max ? right_max : left_max);

       return (*root_max)*2 <= root_min;

   }
   else
       return false;  ///on of or both the subtrees are not balanced


}
int main()
{
    printf("Hello world!\n");
    return 0;
}
