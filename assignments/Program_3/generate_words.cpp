#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<ctime>

using namespace std;
////////////// functions//////////////
void fillarrays(ifstream &, vector<string>&, vector<string>&,
	vector<string>&, vector<string>&, vector<string>&);
string getword(vector<string>&, vector<string>&,
	vector<string>&, vector<string>&, vector<string>&);

int main()
{
	///////// Definitions /////////
	ifstream infile;
	ofstream outfile;
	infile.open("adjectives.txt");
	outfile.open("tenthousandwords.txt");
	// vectors storing words
	vector<string> adj; vector<string> noun;
	vector<string> verb; vector<string> adv;
	vector<string> animal;
	string crazyword;
	int length;
	//Fills the vectors with words.
	fillarrays(infile, adj, noun, verb, adv, animal);
	
	// generates the word by 
	for (int i = 0; i < 10000; i++)
	{
		//generate a random number vtween one and three
		// then concatinate the function calls into one string.
		length = rand() % 5 + 3;
		if (length == 3)
		{
			crazyword = getword(adj, noun, verb, adv, animal) + " " +
				getword(adj, noun, verb, adv, animal) + " " +
				getword(adj, noun, verb, adv, animal);
		}
		else if (length == 4)
		{
			crazyword = getword(adj, noun, verb, adv, animal) + " " + 
				getword(adj, noun, verb, adv, animal) + " " +
				getword(adj, noun, verb, adv, animal) + " " +
				getword(adj, noun, verb, adv, animal);
		}
		else
		{
			crazyword = getword(adj, noun, verb, adv, animal) + " " + 
				getword(adj, noun, verb, adv, animal) + " " + 
				getword(adj, noun, verb, adv, animal) + " " + 
				getword(adj, noun, verb, adv, animal) + " " + 
				getword(adj, noun, verb, adv, animal);
		}
		outfile << crazyword << "\n";
	}
	outfile.close();
	return 0;
}

//fills the vectors and closes and opens new imput files
void fillarrays(ifstream & infile, vector<string>& adj, vector<string>& noun,
	vector<string>& verb, vector<string>& adv, vector<string>& animal)
{
	string temp;
	while (infile >> temp)
	{
		adj.push_back(temp);
	}
	infile.close();
	infile.open("nouns.txt");
	while (infile >> temp)
	{
		noun.push_back(temp);
	}
	infile.close();
	infile.open("verbs.txt");
	while (infile >> temp)
	{
		verb.push_back(temp);
	}
	infile.close();
	infile.open("adverbs.txt");
	while (infile >> temp)
	{
		adv.push_back(temp);
	}
	infile.close();
	infile.open("animals.txt");
	while (infile >> temp)
	{
		animal.push_back(temp);
	}
	infile.close(); 
}
// passes the vectors by refrence then randomly selcts one of the vectors
// to randomlly select from the vectors data values.
string getword(vector<string>& adj, vector<string>& noun,
	vector<string>& verb, vector<string>& adv, vector<string>& animal)
{
	// veriables
	int temp, randomIndex;

	//generate a randum number between 1
	//though 5 then pic a random number based
	//off the size of the vecotor
	temp = rand() % 5 + 1;
	if (temp == 1)
	{
	randomIndex = rand() % adj.size();
	return adj.at(randomIndex);
	}
	else if (temp == 2)
	{
		randomIndex = rand() % noun.size();
		return noun.at(randomIndex);
	}
	else if (temp == 3)
	{
		randomIndex = rand() % verb.size();
		return verb.at(randomIndex);
	}
	else if (temp == 4)
	{
		randomIndex = rand() % adv.size();
		return adv.at(randomIndex);
	}
	else
	{
		randomIndex = rand() % animal.size();
		return animal.at(randomIndex);
	}
}