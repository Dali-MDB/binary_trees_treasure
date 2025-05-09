#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"


void nbr_nodes_lvl(ptr R,int lvl,int* T,int* size){
     if(R==NULL)
        return;

     if(lvl==*size)
        T[(*size)++]  +=1;

     nbr_nodes_lvl(R->left,lvl+1,T,size);
     nbr_nodes_lvl(R->right,lvl+1,T,size);

}

void max_nodes_lvl(ptr R){
    printf("the maximum number of nodes in a level is :   ");
    if(R==NULL)
        printf("%d   (a null tree)",0);

    int T[100],size=0,max=0;

    nbr_nodes_lvl(R,0,T,&size);

    int i;
    for(i=0;i<size;i++)
        if(T[i] > max)
           max = T[i];

    printf("%d",max);


}

int main()
{
    printf("Hello world!\n");
    return 0;
}
