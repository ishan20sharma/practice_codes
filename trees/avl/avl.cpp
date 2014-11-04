#include<iostream>

using namespace std;

/* AVL Node */
struct AVLNode {
	int data;
	int height;
	AVLNode *left;
	AVLNode *right;
};

/* AVL tree class */
class AVLtree {
	AVLNode *root; /* Points to the root node of the AVL Tree */

	int max(int a, int b);
	int height(AVLNode *node);
	int getBalance(AVLNode *node);
	AVLNode *getNode(int data);
	AVLNode *rightRotate(AVLNode *root);
	AVLNode *leftRotate(AVLNode *root);
	AVLNode *auxInsertRecursive(AVLNode *root, int data);
	void auxInOrder(AVLNode *node);

public:
	AVLtree(): root(NULL) {};
	void insert(int data);
	void inOrder();
	int getHeight() { return root->height; };
	int getRootData() { return root->data; };
}; 

int AVLtree::max(int a, int b) {
	return (a > b)? a : b;
}

int AVLtree::height(AVLNode *node) {
	if(node == NULL)
		return 0;
	return node->height;
}

int AVLtree::getBalance(AVLNode *node) {
	if(node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

AVLNode* AVLtree::getNode(int data) {
	AVLNode *temp = new AVLNode;
	
	temp->data = data;
	temp->height = 1;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

AVLNode* AVLtree::rightRotate(AVLNode *root) {
	/* The new root will be the left child of present root */
	AVLNode *newRoot = root->left;
	
	/* Perform the rotation */
	root->left = newRoot->right;
	newRoot->right = root;

	/* Update the height for old and new roots */
	newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
	root->height = max(height(root->left), height(root->right)) + 1;
	
	return newRoot;
}

AVLNode* AVLtree::leftRotate(AVLNode *root) {
	AVLNode *newRoot = root->right;

	/* Perform the rotation */
	root->right = newRoot->left;
	newRoot->left = root;

	/* Update the height for old and new roots */
	root->height = max(height(root->left), height(root->right)) + 1;
        newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

	return newRoot;
}

void AVLtree::insert(int data) {

	root = auxInsertRecursive(root,data);
}

AVLNode* AVLtree::auxInsertRecursive(AVLNode *root,int data) {
	/* if the tree doesn't exist then create one */
	if(root == NULL) {
		return getNode(data);
	}

	/* If the tree exists then insert the node at its proper location */
	if(data < root->data) {
		root->left = auxInsertRecursive(root->left, data);
	}
	else {
		root->right = auxInsertRecursive(root->right, data);
	}

	root->height = max(height(root->left), height(root->right)) + 1;

	int balance = getBalance(root);

	/* left left case */
	if(balance > 1 && data < root->left->data) {
		return rightRotate(root);
	}
	/* right right case */
	if(balance < -1 && data > root->right->data) {
		return leftRotate(root);
	}
	/* left right case */
	if(balance > 1 && data > root->left->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	/* right left case */
	if(balance < -1 && data < root->right->data) {
		root->right = rightRotate(root->right);	
		return leftRotate(root);
	}

	return root;
}

void AVLtree::delete(int data) {
	root = auxDeleteRecursive(root);
}

AVLNode* AVLtree::auxDeleteRecursive(AVLNode *root, int data) {
	if(root == NULL)
		return NULL;

	if(data > root->data) {
		root->right = auxDeleteRecursive(root->right, data);
	}
	else {
		root->left = auxDeleteRecursive(root->left,data);
	}

	if(root->left != NULL && root->right != NULL) {
		int newValue = getMax(root->left);
		root->data = newValue;
		return auxDeleteRecursive(root->left);
	}
	else {
		AVLNode *temp = root;

		if(root->left == NULL)
			root = root->right;
		else
			root =  root->left

		delete temp;
	}

	if (root == NULL)
      		return root;

	root->height = max(height(root->left), height(root->right)) + 1;

	int balance = getBalance(root);

	// Left Left Case
    	if (balance > 1 && getBalance(root->left) >= 0)
        	return rightRotate(root);
 
  	  // Left Right Case
 	   if (balance > 1 && getBalance(root->left) < 0)
   	 {
       		 root->left =  leftRotate(root->left);
       		 return rightRotate(root);
   	 }
 
   	 // Right Right Case
   	 if (balance < -1 && getBalance(root->right) <= 0)
        	return leftRotate(root);
 
        // Right Left Case
   	 if (balance < -1 && getBalance(root->right) > 0)
   	 {
       		 root->right = rightRotate(root->right);
       		 return leftRotate(root);
   	 }

	return root;
}

void AVLtree::inOrder() {
	auxInOrder(root);
}

void AVLtree::auxInOrder(AVLNode *node) {
	if(node == NULL)
		return ;

	auxInOrder(node->left);
	cout << node->data << endl;
	auxInOrder(node->right);
}

int main() {
	AVLtree tree;	

	for(int i = 1; i<8 ; ++i)
		tree.insert(i);

	tree.inOrder();
	
	cout << "Tree Height: "<< tree.getHeight() << endl; 
	cout << "Root Data: "<< tree.getRootData() << endl;

	return 0;
}
