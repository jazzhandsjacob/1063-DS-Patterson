#include<iostream>
#include<fstream>
#include"AVLtree.cpp"
#include"BSTree.h"

using namespace std;

////////////Functions////////////
void loadtrees(ifstream&, avlTree&, BSTree&);

int main()
{
	ifstream infile,infile2;
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
		infile2.open("tenthousandwords.txt");
	else
		infile2.open(ifile);
		
	cout<<"done loading"<<endl;
	while (infile2 >> temp)
	{
		cout<<temp<<endl;
		treeavl.search(temp);
		//bstTotal += bstree.search(temp);
	}
	cout<<"done looping"<<endl;
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
	infile.open("word_files/adjectives.txt");
	type = "adj";
	//while (infile >> temp)
	for (int i = 0; i < 500; i ++ )
	{
		infile>>temp;
		bstree.insert(temp,type);
		treeavl.insert(temp, type);
	}
	infile.close();
	
	infile.open("word_files/adverbs.txt");
	type = "adv";
	//while (infile >> temp)
	for (int i = 0; i < 500; i++)
	{
		infile>>temp;
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();

	infile.open("word_files/animals.txt");
	type = "animals";
	//while (infile >> temp)
	for (int i = 0; i < 500; i++)
	{
		infile>>temp;
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();

	infile.open("word_files/nouns.txt");
	type = "noun";
	//while (infile >> temp)
	for (int i = 0; i < 500; i++)
	{
		infile>>temp;
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();

	infile.open("word_files/verbs");
	type = "verb";
	//while (infile >> temp)
	for (int i = 0; i < 500; i++)
	{
		infile>>temp;
		bstree.insert(temp, type);
		treeavl.insert(temp, type);
	}
	infile.close();
}