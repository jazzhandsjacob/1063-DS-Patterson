//************************************************************************
//  Name: analye_trees
//
//  Purpose: fill both the avltree, and the BSTree the count the number of
//		of comarison between them and the total number of every word list
//		used.
//
//  Dr. Griffin
//
//  Date: 3/1/2018
//*************************************************************************

#include<iostream>
#include<fstream>
#include"AVLtree.h"
#include"BSTree.h"

using namespace std;

////////////Functions////////////
void loadtrees(ifstream&, avlTree&, BSTree&);

int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("adjectives.txt");
	outfile.open("analysis.out");
	avlTree treeavl;
	BSTree bstree;
	string temp, ifile;
	int bstTotal = 0;
	
	loadtrees(infile, treeavl, bstree);

	cout << "Please enter the name of the file you would like to open "
		<< "\n Or enter 1 to load default: ";
	cin >> ifile;
	if (ifile == "1")
		infile.open("tenthousandwords.txt");
	else
		infile.open(ifile);
	// passes the words from the file into the 
	while (infile >> temp)
	{
		treeavl.search(temp);
		bstTotal += bstree.search(temp);
	}
	outfile << "BST Comparisons = " << bstTotal << "\n"
		<< "AVL Comparisons = " << treeavl.gettotal() << "\n"
		<< "Number of Adjectives = " << treeavl.getadj() << "\n"
		<< "Number of Adverbs = " << treeavl.getadv() << "\n"
		<< "Number of Nouns = " << treeavl.getnoun() << "\n"
		<< "Number of verbs = " << treeavl.getverb() << "\n"
		<< "Number of Animals = " << treeavl.getanimal();
	
	infile.close();
	return 0;
}

//************************************************************************
// Function Name: loadtrees
//
// Purpose: fill both the avltree, and the BSTree
//
// Arguments: passes the imputfile, the avl tree and the BS Tree 
//		by refrence.
//
// Returns: void 
//*************************************************************************
void loadtrees(ifstream& infile, avlTree& treeavl, BSTree& bstree)
{
	string temp, type;
	
	//load the avlTree and the BSTree 
	type = "adj";
	while (infile >> temp)
	{
		bstree.insert(temp,type);
		treeavl.insert(temp, type);
	}
	infile.close();
	//closes and opens the next file to read in
	//then repeats for all 
	infile.open("adverbs.txt");
	type = "adv";
	while (infile >> temp)
	{
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();

	infile.open("animals.txt");
	type = "animals";
	while (infile >> temp)
	{
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();

	infile.open("nouns.txt");
	type = "noun";
	while (infile >> temp)
	{
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();

	infile.open("verbs.txt");
	type = "verb";
	while (infile >> temp)
	{
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();
}