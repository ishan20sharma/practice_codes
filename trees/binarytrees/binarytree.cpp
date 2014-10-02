#include<iostream>
#include<cstdlib>

using namespace std;

/* Denotes a tree node */
struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
};

class BinaryTree {
	TreeNode *root;
	void auxPrintInOrder(TreeNode *current);
	void auxPrintPostOrder(TreeNode *current);
	void auxPrintPreOrder(TreeNode *current);

public:
	BinaryTree();
	bool isEmpty();
	TreeNode *getNode(int data);
	int printTree();
	int printInOrder();
	int printPostOrder();
	int printPreOrder();
	void insert(int data);
	void insert(TreeNode *newNode);
	
};

/* Default Constructor */
BinaryTree::BinaryTree(){
	root = NULL;
} 

/* Check whether the tree is empty or not */
bool BinaryTree::isEmpty() {
	return (root == NULL);
}

/* Creates a new Binary Tree node */
TreeNode *BinaryTree::getNode(int data) {
	TreeNode *temp = new TreeNode;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

/* Inerts a node with the given data */
void BinaryTree::insert(int data) {
	TreeNode *newNode = getNode(data);

	insert(newNode);
}

/* Uses the approach of inserting into a BST to insert a new node */
void BinaryTree::insert(TreeNode *newNode) {
	TreeNode *current = root;
	TreeNode *prev = NULL;

	/* Locate the position at which to insert the node. The position is determined by TreeNode *prev  */
	while(current != NULL) {
		prev = current;

		if(newNode->data < current->data)
			current = current->left;
		else
			current = current->right;
	}
	/* If the tree is empty, insert as root node */
	if(prev == NULL)
		root = newNode;
	else {
		if(newNode->data < prev->data)
			prev->left = newNode;
		else
			prev->right = newNode;
	}
}

/* Prints the tree */
int BinaryTree::printTree() {
	
	if(root == NULL) {
		cout << "Tree is empty" << endl;
		return 0;
	}
	
	auxPrintInOrder(root);

	return 1;
}

/* Prints the tree in inorder fashion recusrively */
int BinaryTree::printInOrder() {
	if(isEmpty())
		return 0;

	cout << "Printing the tree in Inorder fashion" << endl;

	auxPrintInOrder(root);

	return 1;
}

/* Prints the tree in postorder fashion recursively */
int BinaryTree::printPostOrder() {
	if(isEmpty())
		return 0;

	cout << "Printing the tree in Postorder fashion" << endl;

	auxPrintPostOrder(root);

	return 1;
}

/* Prints the tree in preorder fashion recursively */
int BinaryTree::printPreOrder() {
	if(isEmpty())
		return 0;

	cout << "Printing the tree in Preorder fashion" << endl;

	auxPrintPreOrder(root);

	return 1;
}

/* Prints the tree in inorder fashion recursively */
void BinaryTree::auxPrintInOrder(TreeNode *current) {
	if(current != NULL) {
		auxPrintInOrder(current->left);
		cout << "Data is: " << current->data << endl;
		auxPrintInOrder(current->right);
	}
}

/* Prints the tree in postorder fashion recursively*/
void BinaryTree::auxPrintPostOrder(TreeNode *current) {
	if(current != NULL) {
		auxPrintPostOrder(current->right);
		auxPrintPostOrder(current->right);
		cout << "Data is: " << current->data << endl;
	}	
}

/* Prints the tree in preorder fashion recursively */
void BinaryTree::auxPrintPreOrder(TreeNode *current) {
	if(current != NULL) {
		cout << "Data is: " << endl;
		auxPrintPreOrder(current->left);
		auxPrintPreOrder(current->right);
	}
}

int main() {
	BinaryTree tree;
	int j = 0;
	srand(time(0));
	for(int i = 0; i < 100; i++) {
		j = rand() % 100;
		tree.insert(j);
	}
	
	tree.printInOrder();	
	//tree.printPostOrder();
	//tree.printPreOrder();
	
	return 0;
}
