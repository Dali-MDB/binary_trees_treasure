
#include <iostream>
#include <vector>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void printBinaryTree(Node* root, int space = 0, int height = 10)
{
    // Base case
    if (root == nullptr) {
        return;
    }

    // increase distance between levels
    space += height;

    // print right child first
    printBinaryTree(root->right, space);
    cout << endl;

    // print the current node after padding with spaces
    for (int i = height; i < space; i++) {
        cout << ' ';
    }
    cout << root->data;

    // print left child
    cout << endl;
    printBinaryTree(root->left, space);
}


// Utility function to perform preorder traversal on a given binary tree
void preorder(Node* root)
{
    if (root == nullptr) {
        return;
    }

    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

// Recursive function to return a list of tree pointers of all possible
// binary trees having the same inorder sequence as `in[start, end]`
vector<Node*> generateBinaryTrees(vector<int> &in, int start, int end)
{
    // create an empty list to store the root of the constructed binary trees
    vector<Node*> trees;

    // base case
    if (start > end)
    {
        trees.push_back(nullptr);
        return trees;
    }

    // consider each element in the inorder sequence as the root
    for (int i = start; i <= end; i++)
    {
        // recursively find all possible left subtrees for root `i`
        vector<Node*> left_subtrees = generateBinaryTrees(in, start, i - 1);

        // recursively find all possible right subtrees for root `i`
        vector<Node*> right_subtrees = generateBinaryTrees(in, i + 1, end);

        // do for each combination of left and right subtrees
        for (Node* l: left_subtrees)
        {
            for (Node* r: right_subtrees)
            {
                // construct a binary tree with i'th element as the root and whose
                // left and right children point to `l` and `r`, respectively
                Node* tree = new Node(in[i], l, r);

                // add this tree to the output list
                trees.push_back(tree);
            }
        }
    }

    return trees;
}

int main()
{
    vector<int> inorder = { 1, 2, 3 ,4};

    vector<Node*> trees = generateBinaryTrees(inorder, 0, inorder.size() - 1);

    cout << "Total binary trees are " << trees.size() << "\n\n";
    cout << "Preorder traversal for each tree:\n";
    for (Node* tree: trees)
    {
        printBinaryTree(tree,10,10);
        cout << endl;
    }

    return 0;
}
