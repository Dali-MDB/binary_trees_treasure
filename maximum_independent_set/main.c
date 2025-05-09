#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

int max_ind_set(ptr R){
    if(R==NULL)
        return 0;

    ///if a node has been chosen, then we have the option to either include or exclude it
    int excluded = max_ind_set(LC(R)) + max_ind_set(RC(R));   //its children are potential elements of the set
    int included=1;  //the node itself

    if(LC(R) != NULL)//we check its left grand children if they exist
        included += max_ind_set(LC(LC(R))) + max_ind_set(RC(LC(R)));

    if(RC(R) != NULL)//we check its right grand children
        included += max_ind_set(LC(RC(R))) + max_ind_set(RC(RC(R)));

    return included > excluded ? included : excluded;




}
int main()
{
    printf("Hello world!\n");
    return 0;
}
