#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

void delete_tree(ptr R){
   if(R==NULL)
      return;

   ptr left = R->left;
   ptr right = R->right;

   free(R);
   delete_tree(left);
   delete_tree(right);

}

int main()
{

    return 0;
}
