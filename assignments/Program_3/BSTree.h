#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;



class BSTree
{
	struct node
	{
		string data, val;
		node *left;
		node *right;
		node()
		{
			data = "";
			left = NULL;
			right = NULL;
		}
		node(string w, string x)
		{
			val = x;
			data = w;
			left = NULL;
			right = NULL;
		}
	};

private:
	node * root;
	//************************************************************************
	// Method Name: count
	//
	// Private
	//
	// Purpose: to use a recursife fuction to find the total number of nodes in a tree
	//
	// Arguments: pointer to the root
	//
	// Returns: the total number of modes in the tree
	//*************************************************************************
	int count(node *root)
	{
		if (!root)
		{
			return 0;
		}
		else
		{
			return 1 + count(root->left) + count(root->right);
		}
	}

	//************************************************************************
	// Method Name: insert
	//
	// Private
	//
	// Purpose: add a new value to the tree or make the tree
	//
	// Arguments: the root of the tree and the new value 
	//
	// Returns: the total number of comparisons made for the key word
	//*************************************************************************
	void insert(node *&root, node *&temp)
	{
		if (!root)
		{
			root = temp;
		}
		else
		{
			if (temp->data == root->data)
				return;

			else if (temp->data < root->data)
				insert(root->left, temp);
			
			else
				insert(root->right, temp);
			
		}
	}
	//************************************************************************
	// Method Name: print_node
	//
	// Private
	//
	// Purpose: to print values in the tree into the 
	//
	// Arguments: the word in the tree its looking for and an empty string
	//
	// Returns: none
	//*************************************************************************
	void print_node(node *n, string label = "")
	{
		if (label != "")
		{
			cout << "[" << label << "]";
		}
		cout << "[[" << n << "][" << n->data << "]]\n";
		if (n->left)
		{
			cout << "\t|-->[L][[" << n->left << "][" << n->left->data << "]]\n";
		}
		else
		{
			cout << "\t\\-->[L][null]\n";
		}
		if (n->right)
		{
			cout << "\t\\-->[R][[" << n->right << "][" << n->right->data << "]]\n";
		}
		else
		{
			cout << "\t\\-->[R][null]\n";
		}
	}

	/**
	* type = ['predecessor','successor']
	*/
	node *minValueNode(node *root)
	{
		node *current = root;

		if (root->right)
		{
			current = root->right;
			while (current->left != NULL)
			{
				current = current->left;
			}
		}
		else if (root->left)
		{
			current = root->left;
			while (current->right != NULL)
			{
				current = current->right;
			}
		}

		return current;
	}

	//************************************************************************
	// Method Name: delete node
	//
	// Private
	//
	// Purpose: deletes the node from the tree 
	//
	// Arguments: string value and a the root
	//
	// Returns: none
	//*************************************************************************
	node *deleteNode(node *&root, string key)
	{
		if (!root)
		{
			return NULL;
		}
		if (key < root->data)
		{
			cout << "going left" << endl;
			root->left = deleteNode(root->left, key);
		}
		else if (key > root->data)
		{
			cout << "going right" << endl;
			root->right = deleteNode(root->right, key);
		}
		else
		{
			if (root->left == NULL)
			{
				node *temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == NULL)
			{
				node *temp = root->left;
				delete root;
				return temp;
			}

			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			node *temp = minValueNode(root);

			print_node(temp, "minvaluenode");

			// Copy the inorder successor's content to this node
			root->data = temp->data;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->data);
		}
		return root;
	}

	//************************************************************************
	// Method Name: Height
	//
	// Private
	//
	// Purpose: to find the furthes node away from the root
	//
	// Arguments: root node
	//
	// Returns: intiger value of longes node count.
	//*************************************************************************
	int height(node *root)
	{
		if (!root)
		{
			return 0;
		}
		else
		{
			int left = height(root->left);
			int right = height(root->right);
			if (left > right)
			{
				return left + 1;
			}
			else
			{
				return right + 1;
			}
		}
	}

	/* Print nodes at a given level */
	void printGivenLevel(node *root, int level)
	{
		if (root == NULL)
			return;
		if (level == 1)
		{
			print_node(root);
		}
		else if (level > 1)
		{
			printGivenLevel(root->left, level - 1);
			printGivenLevel(root->right, level - 1);
		}
	}
	//************************************************************************
	// Method to help create GraphViz code so the expression tree can
	// be visualized. This method prints out all the unique node id's
	// by traversing the tree.
	// Recivies a node pointer to root and performs a simple recursive
	// tree traversal.
	//************************************************************************
	void GraphVizGetIds(node *nodePtr, ofstream &VizOut)
	{
		static int NullCount = 0;
		if (nodePtr)
		{
			GraphVizGetIds(nodePtr->left, VizOut);
			VizOut << "node" << nodePtr->data
				<< "[label=\"" << nodePtr->data << "\\n"
				//<<"Add:"<<nodePtr<<"\\n"
				//<<"Par:"<<nodePtr->parent<<"\\n"
				//<<"Rt:"<<nodePtr->right<<"\\n"
				//<<"Lt:"<<nodePtr->left<<"\\n"
				<< "\"]" << endl;
			if (!nodePtr->left)
			{
				NullCount++;
				VizOut << "nnode" << NullCount << "[label=\"X\",shape=point,width=.15]" << endl;
			}
			GraphVizGetIds(nodePtr->right, VizOut);
			if (!nodePtr->right)
			{
				NullCount++;
				VizOut << "nnode" << NullCount << "[label=\"X\",shape=point,width=.15]" << endl;
			}
		}
	}

	//************************************************************************
	// This method is partnered with the above method, but on this pass it
	// writes out the actual data from each node.
	// Don't worry about what this method and the above method do, just
	// use the output as your told:)
	//************************************************************************
	void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut)
	{
		static int NullCount = 0;
		if (nodePtr)
		{
			GraphVizMakeConnections(nodePtr->left, VizOut);
			if (nodePtr->left)
				VizOut << "node" << nodePtr->data << "->"
				<< "node" << nodePtr->left->data << endl;
			else
			{
				NullCount++;
				VizOut << "node" << nodePtr->data << "->"
					<< "nnode" << NullCount << endl;
			}

			if (nodePtr->right)
				VizOut << "node" << nodePtr->data << "->"
				<< "node" << nodePtr->right->data << endl;
			else
			{
				NullCount++;
				VizOut << "node" << nodePtr->data << "->"
					<< "nnode" << NullCount << endl;
			}

			GraphVizMakeConnections(nodePtr->right, VizOut);
		}
	}
	//************************************************************************
	// Method Name: search
	//
	// Private 
	//
	// Purpose: Private method to check if the value being searched for is in
	//		the tree.
	//
	// Arguments: address of a node
	//
	// Returns: void 
	//*************************************************************************

	int search(node *&root, string key)
	{

		int count = 0;

		if (!root)
			return 0;
		if (key == root->data)
			return 0;
		else if (key < root->data)
		{
			count++;
			count += search(root->left, key);
		}
		else if (key > root->data)
		{
			count++;
			count += search(root->right, key);
		}
		return count;
	}

public:
	// constructor 
	BSTree()
	{
		root = NULL;
	}
	// destructor
	~BSTree()
	{
	}
	//************************************************************************
	// Method Name: search
	//
	// public
	//
	// Purpose: to call the privaet method and pass it the needed parameters
	//
	// Arguments: the word in the tree its looking for
	//
	// Returns: the total number of comparisons made for the key word
	//*************************************************************************
	int search(string key)
	{
		return search(root, key);
	}

	//************************************************************************
	// Method Name: search
	//
	// public
	//
	// Purpose: to call the privaet method and pass it the needed parameters
	//
	// Arguments: none
	//
	// Returns: the total number of comparisons made for the key word
	//*************************************************************************
	int count()
	{
		return count(root);
	}
	//************************************************************************
	// Method Name: insert
	//
	// Public
	//
	// Purpose: to pass the string value to the  
	//
	// Arguments: the word and the tpye of word it is
	//
	// Returns: none
	//*************************************************************************

	void insert(string x, string type )
	{
		node *temp = new node(x,type);
		insert(root, temp);
	}

	void deleteNode(string key)
	{
		deleteNode(root, key);
	}

	void minValue()
	{
		print_node(minValueNode(root), "minVal");
	}
	//************************************************************************
	// Method Name: hight
	//
	// Private 
	//
	// Purpose: to call the privaet method and pass it the needed parameters
	//
	// Arguments: the word in the tree its looking for
	//
	// Returns: the total number of comparisons made for the key word
	//*************************************************************************
	int height(string key = "")
	{
		if (key != "")
		{
			//find node
		}
		else
		{
			return height(root);
		}
		return 0;
	}

	string top()
	{
		if (root)
			return root->data;
		else
			return 0;
	}

	/* Function to line by line print level order traversal a tree*/
	void printLevelOrder()
	{
		cout << "Begin Level Order===================\n";
		int h = height(root);
		int i;
		for (i = 1; i <= h; i++)
		{
			printGivenLevel(root, i);
			cout << "\n";
		}
		cout << "End Level Order===================\n";
	}

	//************************************************************************
	// Recieves a filename to place the GraphViz data into.
	// It then calls the above two graphviz methods to create a data file
	// that can be used to visualize your expression tree.
	//************************************************************************
	void GraphVizOut(string filename)
	{
		ofstream VizOut;
		VizOut.open(filename);
		VizOut << "Digraph G {\n";
		GraphVizGetIds(root, VizOut);
		GraphVizMakeConnections(root, VizOut);
		VizOut << "}\n";
		VizOut.close();
	}
};