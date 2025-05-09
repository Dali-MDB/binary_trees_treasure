#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

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
   struct node *left,*right;
   bool threaded;

}node;


typedef struct node* ptr;

ptr new_node(int V){
   ptr N = (ptr) malloc(sizeof(node));
   N->left = NULL;
   N->right = NULL;
   N->val = V;
   N->threaded = false;
   return N;

}

int data(ptr R){
   return R->val;
}

ptr LC(ptr R){
   return R->left;
}

ptr RC(ptr R){
   return R->right;
}

void ass_LC(ptr* R, ptr Q) {
    if (R != NULL && *R != NULL && (*R)->left == NULL) {
        (*R)->left = Q;
    }
}

void ass_RC(ptr* R, ptr Q) {
    if (R != NULL && *R != NULL && (*R)->right == NULL) {
        (*R)->right = Q;
    }
}

void ass_data(ptr* R , int V){
    (*R)->val = V;
}

bool is_threaded(ptr R){
    return R->threaded;
}

void thread(ptr* R,ptr C){
    if(!is_threaded(*R)){
        ass_RC(R,C);        (*R)->threaded = true;
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

    int Value  =  data(root);

    ///RC first
    if(!is_threaded(root))
        displayTree(RC(root), space, '/'); // For right child, direction is '/'

    // Print current node after space count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");

    Textecolor(14);
    printf("%c(", direction);



    if(is_threaded(root))
        Textecolor(4);
    else
        Textecolor(11);

    printf("%d",Value);
    Textecolor(14);



    if((LC(root) !=NULL) && (RC(root) != NULL)){
        printf(")<\n");
    }
    else if (LC(root) != NULL ){ //RC == NULL
        printf(")\\\n");
    }
    else if(RC(root) != NULL){ //LC == NULL
        printf(")/\n");
    }
    else{ //a leaf
        printf(")=E\n");
    }

    ///LC
    displayTree(LC(root), space, '\\'); // For left child, direction is '\'
}

ptr convert_right_threaded(ptr R){
   if(R==NULL)
     return NULL;

   //first we determine the previous node in inorder  (either from ancestors or its left subtree)
   ///since the ancestor precessor necessarily has a right child,we can't thread it to the right

   ptr prev = convert_right_threaded(LC(R));
   if(prev != NULL)
        thread(&prev,R);        ///we set R to be the fake rc of prev

   if(RC(R)==NULL)
       return R;   ///the prev for the calling ancestor
   else
       return convert_right_threaded(RC(R));


}


int main()
{
    ptr root = new_node(7);
    root->left = new_node(3);
    root->left->left = new_node(1);
    root->left->right = new_node(5);
    root->left->right->left = new_node(4);
    root->right = new_node(10);
    root->right->left = new_node(8);
    root->right->left->right = new_node(9);
    root->right->right = new_node(12);
    root->right->right->right = new_node(13);

    displayTree(root,10,'-');

    ptr idk = convert_right_threaded(root);

    printf("after\n\n");
    displayTree(root,10,'-');

    return 0;
}
