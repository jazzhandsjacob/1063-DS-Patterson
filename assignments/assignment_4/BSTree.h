#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
	node()
	{
		data = -1;
		left = NULL;
		right = NULL;
	}
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

class BSTree
{
private:
	//sets up the root of the tree
	node *root;

	// a recursive fucntion that traverses down the 
	// the left and right of the tree adding every
	// node in the tree
	int count(node *root);

	//insertes the new node to the tree with the number
	// that was passed in.
	void insert(node *&, node *&);

	// trevereses down the list and prints every level
	// of the tree out to the screen.
	void print_node(node *, string );

	// finds the succser to the node that is being deleted.
	node *minValueNode(node *);

	// findes the specified node and removes it from the tree
	// and rearanges the pointers to reconect the tree.
	node *deleteNode(node *&, int );

	// traverses down the tree finding the lowest node and
	// and returns adress 
	int height(node *);

	// prints the level of the tree to the screen
	// as it traverses down the tree
	void printGivenLevel(node *, int );
	void GraphVizGetIds(node *, ofstream &);
	void GraphVizMakeConnections(node *, ofstream &);
public:
	//constructor
	BSTree();

	//destructor
	~BSTree();

	// public accessor to count all the nodes in the tree
	int count();

	//passes the int value to the private method
	// to be inserted into the list
	void insert(int x);

	//passes the 'key' int value to the private function
	// to be deleted
	void deleteNode(int key);

	// a function call to find the succseor
	void minValue();

	// finds the hight of the tree and returns the number 
	int height(int );

	//finds and returns the data.
	int top();

	// prints the tree top to bottom 
	void printLevelOrder();

	void GraphVizOut(string filename);
};