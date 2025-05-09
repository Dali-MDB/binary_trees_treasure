#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
void Textecolor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
// Texte couleur et fond:
void Color(int couleurdutexte, int couleurdufond)
{

    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurdufond * 16 + couleurdutexte);
}



typedef struct node{
   int val;
   struct node *left,*right,*next;   ///we add a field that points to the next node in the linked lst

}node;

typedef struct node* ptr;

typedef struct element{
   ptr head;
   ptr tail;
}element;

ptr new_node(int V){
   ptr N = (ptr) malloc(sizeof(node));
   N->left = NULL;
   N->right = NULL;
   N->next = NULL;
   N->val = V;
   return N;

}




///we use the array to store the previous pointer in each level
void construct_linked_lists_same_level(ptr R,int level,element* T,int* size){
   if(R!=NULL){

      if(level+1>*size) ///we update the size of the array to keep trace of the highest level
          *size = level+1;
      ptr prev = T[level].tail;

      if(prev == NULL)///the head of this level
          T[level].head = R;
      else ///we link em
          prev->next = R;  //we link the two adjacent nodes at the same level




      T[level].tail = R;  //the new tail

      ///now the recursive call for children
      construct_linked_lists_same_level(R->left,level+1,T,size);
      construct_linked_lists_same_level(R->right,level+1,T,size);

   }

}

void display_lists(element* T,int size){
    int i;
    for(i=0;i<size;i++){
        ptr temp = T[i].head;
        Textecolor(5);
        printf("level %d :  ",i);
        while(temp != NULL){
            Textecolor(1);
            printf("( %d )",temp->val);
            Textecolor(2);
            if(temp->next == NULL)
                printf("--E");
            else
                printf("-->");
             temp = temp->next;  //we move to the following element
        }
        printf("\n");
    }

}

void displayTree(ptr root, int space, char direction)
{
    const int COUNT = 10;

    Textecolor(14);
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    int Value  =  root->val;

    ///RC first
    displayTree(root->right, space, '/'); // For right child, direction is '/'

    // Print current node after space count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");

    Textecolor(14);
    printf("%c(", direction);


    Textecolor(11);
    printf("%d",Value);
    Textecolor(14);



    if((root->left !=NULL) && (root->right != NULL)){
        printf(")<\n");
    }
    else if (root->left != NULL ){ //RC == NULL
        printf(")\\\n");
    }
    else if(root->right != NULL){ //LC == NULL
        printf(")/\n");
    }
    else{ //a leaf
        printf(")=E\n");
    }

    ///LC
    displayTree(root->left, space, '\\'); // For left child, direction is '\'
}

int main()
{
    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->right = new_node(6);
    root->left->left->right = new_node(7);
    root->right->right->left = new_node(8);

    displayTree(root,10,'-');
    int i,size=0;
    element X;    X.head =NULL;   X.tail = NULL;
    element T[11] ;

    for(i=0;i<11;i++){
        T[i] = X;  //initialize to null
    }

    construct_linked_lists_same_level(root,0,T,&size);

    ///now we display the constructed lists
    display_lists(T,size);


    return 0;
}
