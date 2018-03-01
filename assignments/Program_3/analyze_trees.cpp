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
	//
	loadtrees(infile, treeavl, bstree);

	cout << "Please enter the name of the file you would like to open "
		<< "\n Or enter 1 to load default: ";
	cin >> ifile;
	if (ifile == "1")
		infile.open("tenthousandwords.txt");
	else
		infile.open(ifile);

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


void loadtrees(ifstream& infile, avlTree& treeavl, BSTree& bstree)
{
	string temp, type;
	
	//load the avl tree also use ""while(infile)""
	type = "adj";
	//while (infile >> temp)
	for (int i = 0; i < 500; i ++ )
	{
		bstree.insert(temp,type);
		treeavl.insert(temp, type);
	}
	infile.close();
	
	infile.open("adverbs.txt");
	type = "adv";
	//while (infile >> temp)
	for (int i = 0; i < 500; i++)
	{
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();

	infile.open("animals.txt");
	type = "animals";
	//while (infile >> temp)
	for (int i = 0; i < 500; i++)
	{
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();

	infile.open("nouns.txt");
	type = "noun";
	//while (infile >> temp)
	for (int i = 0; i < 500; i++)
	{
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();

	infile.open("verbs");
	type = "verb";
	//while (infile >> temp)
	for (int i = 0; i < 500; i++)
	{
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();
}