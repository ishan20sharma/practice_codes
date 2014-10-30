#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

/* Denotes a linked list node */
struct ListNode {
	int data;
	ListNode *next;
};

/* Denotes a tree node */
struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
};

/* Represents the BinaryTree */
class BinaryTree {
	TreeNode *root;
	void auxPrintInOrder(TreeNode *current);
	void auxPrintPostOrder(TreeNode *current);
	void auxPrintPreOrder(TreeNode *current);
	bool auxIdenticalTrees(TreeNode *node1, TreeNode *node2);
	unsigned int auxGetMaxDepth(TreeNode *node);
	TreeNode *auxCreateMirror(TreeNode *);
	void auxPrintRootLeafPath(TreeNode *node, ListNode **head, ListNode **tail);
	void insertEnd(ListNode **head, ListNode **tail, int data);
	void printPath(ListNode *head);
	bool auxHasPathSum(TreeNode *node, int sum);
	void auxDeleteTree(TreeNode *node);
	int auxGetSize(TreeNode *node);
	int auxGetMin(TreeNode *node);
	int auxGetMax(TreeNode *node);
public:
	BinaryTree();
	int printTree();                           /* Prints the tree : done */
	int printInOrder();                        /* Prints the tree in InOrder fashion : done */
	int printPostOrder();                      /* Prints the tree in PostOrder fashion : done */
	int printPreOrder();                       /* Prints the tree in PreOrder fashion : done */
	void printLevelOrder();                    /* Prints the tree in LevelOrder fashion : done */
	void insert(int data);                     /* Inserts a node with the given data value : done */
	void insert(TreeNode *newNode);            /* Inserts a given node : done */
	void deleteElement(const int& value);      /* Deletes the node with the given value */
	void deleteTree();			   /* Deletes the binary tree : done */
	bool isEmpty();                            /* Checks whether the tree is empty : done */
	int getMin();				   /* Returns the minimum element of the tree */
	int getMax();				   /* Returns the maximum element of the tree */
	TreeNode *createNode(int data);            /* Creates a new tree node : done */
	int getSize();				   /* Returns the size (i.e number of nodes in the tree) */
	TreeNode *getRoot();                       /* Returns the value stored in TreeNode *root member variable : done */
	bool identicalTrees(BinaryTree &tree);     /* Given two trees, determine if they are identical or not : done */
	unsigned int getMaxDepth();                /* Returns the maximum depth or height of the tree : done */
	int getDeepestNode();                      /* Returns the value of the deepest node in the tree */
	int getNoOfLeaves();	                   /* Returns the number of leaves */
	int getNoOfFullNodes();                    /* Returns the number of full nodes (nodes with both left and right children) in a tree */
	int getNoOfHalfNodes();                    /* Returns the number of half nodes (nodes with either left or right child but not both) */
	int getDiameter();			   /* Returns the diameter/Width ( Number of nodes on the longest path between two leaves) */
	TreeNode *createMirror();                  /* Returns a Mirror Tree : done */
	void printRootLeafPath();                  /* Prints the path from root node to leaf node : done */
	bool hasPathSum(int sum);                  /* Determines whether a path exists which has the given sum : done */
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
TreeNode *BinaryTree::createNode(int data) {
	TreeNode *temp = new TreeNode;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

/* Returns the value stored in root pointer */
TreeNode *BinaryTree::getRoot() {
	return root;
}

/* Inerts a node with the given data */
void BinaryTree::insert(int data) {
	TreeNode *newNode = createNode(data);

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

/* Prints the tree in inorder fashion recursively */
void BinaryTree::auxPrintInOrder(TreeNode *current) {
	if(current != NULL) {
		auxPrintInOrder(current->left);
		cout << "Data is: " << current->data << endl;
		auxPrintInOrder(current->right);
	}
}

/* Prints the tree in postorder fashion recursively */
int BinaryTree::printPostOrder() {
	if(isEmpty())
		return 0;

	cout << "Printing the tree in Postorder fashion" << endl;

	auxPrintPostOrder(root);

	return 1;
}

/* Prints the tree in postorder fashion recursively*/
void BinaryTree::auxPrintPostOrder(TreeNode *current) {
	if(current != NULL) {
		auxPrintPostOrder(current->left);
		auxPrintPostOrder(current->right);
		cout << "Data is: " << current->data << endl;
	}	
}

/* Prints the tree in preorder fashion recursively */
int BinaryTree::printPreOrder() {
	if(isEmpty())
		return 0;

	cout << "Printing the tree in Preorder fashion" << endl;

	auxPrintPreOrder(root);

	return 1;
}

/* Prints the tree in preorder fashion recursively */
void BinaryTree::auxPrintPreOrder(TreeNode *current) {
	if(current != NULL) {
		cout << "Data is: " << current->data << endl;
		auxPrintPreOrder(current->left);
		auxPrintPreOrder(current->right);
	}
}

/* Prints the tree in level order fashion */
void BinaryTree::printLevelOrder() {
	queue<TreeNode *> q;
	
	/* If the tree is empty there is nothing to traverse */
	if (isEmpty()) {
		cout << "Tree is empty" << endl;
		return;
	}
	
	cout << "Printing the tree in level order fasion" << endl;

	/* Add the root node in the tree */
	q.push(root);

	/* Iterate through all the elements of the queue */
	while(!q.empty()) {
		TreeNode *current = q.front();

		/* Print the first queue element */
		cout << current->data << endl;

		/* Delete the element from the queue as it has been traversed */
		q.pop();

		/* Add the left and right children of the element in the queue */
		if(current->left != NULL) {
			q.push(current->left);
		}
		
		if(current->right != NULL) {
			q.push(current->right);
		}
	}
}

BinaryTree::deleteElement(const int &value) {
	auxDeleteElement(root, value);
}

BinaryTree::auxDeleteElement(TreeNode *node, const int &value) {	
	if(node == NULL)
		return NULL;
	/* Node to be deleted is in the left subtree */
	else if(value < node->data) {
		node->left = auxDeleteElement(node->left, value);
	}
	/* Node to be deleted is in the right subtree */
	else if(value > node->data) {
		node->right = auxDeleteElement(node->right, value);
	}
	/* Found element */
	else {
		/* Node has both children */
		if(node->left && node->right) {
			int temp = auxGetMax(node->left);
			node->data = temp;
			node->left = auxDeleteElement(node->left, temp);
		}
		/* Node has only one chile */
		else {
			TreeNode *temp = node;
			if(node->left == NULL)
				node = node->right;
			else
				node = node->left;
	
			delete temp;
		}
	}
	return node;
}

/* Returns the size of the binary tree */
int BinaryTree::getSize() {
	cout << "Calculating the size of the binary tree" << endl;
	return auxGetSize(root);
}
Rocio Oliva
int BinaryTree::auxGetSize(TreeNode *node) {
	if(node == NULL)
		return 0;

	else 
		return 1 + auxGetSize(node->left) + auxGetSize(node->right);
}

int BinaryTree::getMin() {
	auxGetMin(root);
}

int BinaryTree::auxGetMin(TreeNode *node) {
	if (node == NULL) {
		cout << "Tree is empty" << endl;
		return INT_MIN;
	}
	
	while(node->left != NULL) {
		node = node->left;
	}
	return node->data;
}

int BinaryTree::getMax() {
	auxGetMax(root);
}

int BinaryTree::auxGetMax() {
	if(node == NULL) {
		cout << "Tree is empty" << endl;
		return INT_MAX;
	}	

	while(node->right != NULL) {
		node = node->right;
	}
	return node->data;
}


/* Deletes the binary tree */
void BinaryTree::deleteTree() {
	cout << "Deleting the binary tree" << endl;

	auxDeleteTree(root);
	root = NULL;
}

void BinaryTree::auxDeleteTree(TreeNode *node) {
	/* If the node is NULL then there is nothing to delete */
	if(node == NULL)
		return;

	/* Delete the tree in postorder fashion */
	auxDeleteTree(node->left);
	auxDeleteTree(node->right);
	delete node;
}

/* Determines if two trees are identical or not */
bool BinaryTree::identicalTrees(BinaryTree &tree) {
	return auxIdenticalTrees(root, tree.getRoot());
}

bool BinaryTree::auxIdenticalTrees(TreeNode *node1, TreeNode *node2) {
	/* Empty nodes are equal */
	if(node1==NULL && node2 == NULL)
		return true;

	if(node1 != NULL && node2 != NULL) {
		return (node1->data == node2->data && auxIdenticalTrees(node1->left, node2->left) && auxIdenticalTrees(node1->right,node2->right));
	}

	return false;
}

/* Returns the maximum depth of the tree */
	unsigned int BinaryTree::getMaxDepth() {
	return auxGetMaxDepth(root);
}

/* Returns the maximum depth of the tree */
unsigned int BinaryTree::auxGetMaxDepth(TreeNode *node) {
	/* Node does not exist */
	if(node == NULL || (node->left == NULL && node->right == NULL))
		return 0;

	else {
		unsigned int lDepth = auxGetMaxDepth(node->left);
		unsigned int rDepth = auxGetMaxDepth(node->right);

		/* Return the larger depth +1 for the current node */
		if(lDepth > rDepth)
			return (lDepth+1);
		else
			return (rDepth+1);
	}
}

/* Creates a mirror tree */
TreeNode *BinaryTree::createMirror() {
	return auxCreateMirror(root);
}

TreeNode *BinaryTree::auxCreateMirror(TreeNode *node) {
	TreeNode *temp = NULL;
	if(node == NULL)
		return node;

	auxCreateMirror(node->left);
	auxCreateMirror(node->right);

	temp = node->right;
	node->right = node->left;
	node->left = temp;
	
	return node;
}

/* Prints the path from root to leaf node */
void BinaryTree::printRootLeafPath() {
	ListNode *head = NULL;
	ListNode *tail = NULL;

	auxPrintRootLeafPath(root, &head, &tail);
}

void BinaryTree::auxPrintRootLeafPath(TreeNode *node, ListNode **head, ListNode **tail) {
	if(node == NULL) {
		return;
	}
	else {
		ListNode *temp = NULL;
		insertEnd(head, tail, node->data);
		temp = *tail;
		/* If leaf node then print path */
		if(node->left == NULL && node->right == NULL) {
			printPath(*head);
		}
		/* Find leaf node in left and right subtree */
		else {
			auxPrintRootLeafPath(node->left, head, tail);
			*tail = temp; /* Required because we are traversing to the right subtree so paths belonging to left subtree must be deleted */
			auxPrintRootLeafPath(node->right, head, tail);
		}
	}
}


void BinaryTree::printPath(ListNode *head) {
	cout << "Printing the path from root to leaf" << endl;
	if(head == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	while(head) {
		cout << head->data << endl;
		head = head->next;
	}
}

void BinaryTree::insertEnd(ListNode **head, ListNode **tail, int data) {
	ListNode *temp = new ListNode;
	temp->data = data;
	temp->next = NULL;
	
	if(*head == NULL) {
		temp->next = *head;
		*head = temp;
		*tail = temp;
	}
	else {
		(*tail)->next = temp;
		*tail = temp;
	}
}

bool BinaryTree::hasPathSum(int sum) {
	auxHasPathSum(root, sum);
}

bool BinaryTree::auxHasPathSum(TreeNode *node, int sum) {
	if(node == NULL)
		return false;
	else {
		sum = sum - node->data;
		if(sum == 0)
			return true;
		else {
			return(auxHasPathSum(node->left, sum) || auxHasPathSum(node->right,sum));
		}
	}
}

int main() {
	BinaryTree tree1;
	//BinaryTree tree2;

	/* Creates a single right skewed tree */
	/*for(int i =0; i<100; i++) {
		tree1.insert(i);
	}*/
	
	/* Creates a full BST  */
	tree1.insert(20);
	tree1.insert(10);
	tree1.insert(30);
	tree1.insert(5);
	tree1.insert(15);
	tree1.insert(25);
	tree1.insert(35);

	
	/* Creates a second BST */
	/*tree2.insert(20);
        tree2.insert(10);
        tree2.insert(30);
        tree2.insert(5);
        tree2.insert(15);
        tree2.insert(25);
        tree2.insert(35);*/

	
	/* Creates two non-identical trees */
	/*int j = 0;
	srand(time(0));
	for(int i = 0; i < 100; i++) {
		j = rand() % 100;
		tree1.insert(j);
		j = rand() % 100;
		tree2.insert(j);
	}*/
	
	/* Creates two identical trees */
	/*for(int i=0; i<50;++i) {
		tree1.insert(i);
		tree2.insert(i);
	}*/
	
	cout << "Size of the tree is " << tree1.getSize() << endl;
	//tree1.printRootLeafPath();

	//tree1.createMirror();

	//tree1.deleteTree();

	/* Tree traversal */
	//tree1.printInOrder();	
	//tree1.printPostOrder();
	//tree1.printPreOrder();
	//tree1.printLevelOrder();	

	/*if(tree1.hasPathSum(36))
		cout << "Path exists" << endl;
	else
		cout << "Path doesn't exist" << endl;*/	

	//cout << "The maximum depth of the tree is: " << tree1.getMaxDepth() << endl;
	
	/* Checks if the trees are identical or not */
	/*if(tree1.identicalTrees(tree2))
		cout << "Both trees are identical" << endl;

	else
		cout << "Trees are not identical" << endl;*/

	return 0;
}
