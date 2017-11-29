#include<iostream>
using namespace std;

//!Definition of Node for Binary search tree
struct Node
{
	int data;
	Node* left;
	Node* right;
};

//! Function to create a new Node in heap
Node* GetNewNode(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//!  To insert data in BST, returns address of root node
Node* Insert(Node* root,int data)
{
	if(root == NULL) // if tree is empty
		root = GetNewNode(data); //create a new node and pass data
	// if data to be inserted is lesser, insert in left subtree.
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	// else, insert in right subtree.
	else
		root->right = Insert(root->right,data);
	return root;
}
//! To search an element in BST, returns true if element is found
bool Search(Node* root,int data)
{
	if(root == NULL)
		return false;
	else if(root->data == data)
		return true;
	else if(data <= root->data)
		return Search(root->left,data);
	else
		return Search(root->right,data);
}

//! Function to delete a value from tree.
struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

//! Function to print tree elements in inorder form
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<" "<<root->data;
        inorder(root->right);
    }
}

//! Function to find min element in BST
int FindMin(Node *root)
{
    if(root == NULL)
    {
        cout<<"Error: Tree is empty!\n";
        return -1;
    }
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

//! Function to find max element in BST
int FindMax(Node *root)
{
    if(root == NULL)
    {
        cout<<"Error: Tree is empty!\n";
        return -1;
    }
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

//! Function to find height of binary tree
int FindHeight(Node *root)
{
    if(root == NULL)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

bool IsSubtreeLesser(Node *root, int value)
{
    if (root==NULL) return true;
    if (root->data <= value
        && IsSubtreeLesser(root->left, value)
        && IsSubtreeLesser(root->right, value))
            return true;
    else
        return false;
}

bool IsSubtreeGreater(Node *root, int value)
{
    if (root==NULL) return true;
    if (root->data > value
        && IsSubtreeGreater(root->left, value)
        && IsSubtreeGreater(root->right, value))
            return true;
    else
        return false;
}

//!Function to find whether given tree is a BST or not
bool IsBST(Node *root)
{
    if (root==NULL) return true;
    if (IsSubtreeLesser(root->left,root->data)
        && IsSubtreeGreater(root->right,root->data)
        && IsBST(root->left)
        && IsBST(root->right))
            return true;
    else
        return false;
}

int main()
{
	Node* root = NULL;  // Creating an empty tree
	int a[10], no;
	cout<<"Enter number of elements: "; cin>>no;
	cout<<"Enter the elements: ";
	for(int i=0; i<no; i++)
    {
        cin>>a[i];
        root = Insert(root,a[i]);
    }
	// Ask user to enter a number.
	int number;
	/*cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";*/
	cout<<"Elements are: \n";
	inorder(root);
	cout<<"\nMax element is: "<<FindMax(root);
	cout<<"\nHeight of the tree is: "<<FindHeight(root);
}

/* Function to check whether input is an integer or not
int isValid()
{
    int i;
    while( !(cin >> i) )
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter a valid integer."<<endl;
    }
    return i;
}
*/

