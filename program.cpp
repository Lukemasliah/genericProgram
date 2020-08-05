#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include "classes.h"
#include "templates.h"

using namespace std;

//	Assignment 3
//
//	ID: 6273464 - Luke Masliah

int main(int argc, char* argv[])
{
	// Create argument values
	int choice = 0;
	int seed = 0;
	int length = 0;
	int size = 0;
	int mod = 0;
	
	// Error handling block --------------------//
	if (argc < 5 || argc > 6)
	{
		cerr << "Incorrect amount of inputs from user" << endl;
		exit(0);
	}

	try{
		choice = stoi(argv[1]);
		seed = stoi(argv[2]);
		length = stoi(argv[3]);
		size = stoi(argv[4]);
		
		if (argc == 6)
		{
			mod = stoi(argv[5]);
			Mint::modulus = mod;
		}
	}
	catch (const invalid_argument& ia)
	{
		cerr << "Invalid argument: " << ia.what() << " conversion" << endl;
		exit(0);
	}
	
	if (argc != 6 && choice == 0)
	{
		cerr << "Mint requires 5 inputs" << endl;
		exit(0);
	}

	if (argc != 5 && choice == 1)
	{
		cerr << "Melt requires 4 inputs" << endl;
		exit(0);
	}
	// End error handling block --------------------//
	
	// Operations
	if (choice == 0)
	{
		Codebook<Mint> codeBook(seed, length, size, mod);
		codeBook.display();
	}
	else
	{
		Codebook<Melt> codeBook(seed, length, size, mod);
		codeBook.display();
	}
}
