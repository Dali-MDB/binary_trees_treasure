#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"


void vert_trav(ptr R){
   if(R==NULL)
      return NULL;

   //we perform a lvl order trav
   ptr_cell T[100];
   int size = 0;
   queue Q_nodes,Q_index;           create_queue(&Q_nodes);    create_queue(&Q_index);
   ptr i;
   enqueue(&Q_nodes,R);
   i = new_node(0);     ///to hold the index
   enqueue(&Q_index,i);

   while(!empty_queue(Q_nodes){
       dequeue(&Q,&R);
       ptr_cell N = allocate();
       N





    }





}

int main()
{
    printf("Hello world!\n");
    return 0;
}
