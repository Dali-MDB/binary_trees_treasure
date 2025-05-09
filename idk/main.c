#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>


int main()
{

    ptr root = new_node(3);
    root->left = new_node(1);
    root->right = new_node(5);

    ptr p = LC(root), q = RC(root);
    free(p);
    root->left = NULL;
    if(LC(root)==NULL)
        printf("as I excpected");
    else
        printf("%d",data(LC(root)));
    return 0;
}
