///////////////////////////////////////////////////////////////////////////////
// Title: Assignment #2
// Files: main.cpp, BSTree.cpp, BSTree.h
// Semester: CMPS 3013 Spring 2018
//
// Author: Jacob Patterson
// Email: jacobpatterson94@gmail.com
// Description:
// This program implements a BST and with the ability to find, delete and inset
// intiger numbers into the tree.
/////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BSTree.h"

//http://www.webgraphviz.com/

using namespace std;



int main()
{
	srand(2342);

	BSTree B;

	B.insert(38);
	B.insert(10);
	B.insert(29);
	B.insert(27);
	B.insert(5);
	B.insert(43);
	B.insert(36);
	B.insert(3);
	B.printLevelOrder();
	B.GraphVizOut("before.txt");

	while(B.top()){
	     cout<<"removing: "<<B.top()<<endl;
	     B.deleteNode(B.top());
	 }

	B.deleteNode(3);
	B.deleteNode(29);
	B.deleteNode(27);
	B.deleteNode(10);
	B.printLevelOrder();

	B.GraphVizOut("after.txt");
	system("pause");

	return 0;
}
