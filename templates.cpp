#include <iostream>
#include <vector>
#include <limits.h>

#include "templates.h"

//---------------CODEWORD--------------------------------//

template <typename T>
Codeword<T>::Codeword(int seed, int length) 
{
	for (int i = 0; i < length; i++)
	{
		T obj(seed);
		cWords.push_back(obj);
	}
}

template <typename T>
Codeword<T>::Codeword(int length)
{
	for (int i = 0; i < length; i++)
	{
		T obj;
		cWords.push_back(obj);
	}
}

template <typename T>
std::vector<T> Codeword<T>::getCodeWord() const
{
	return cWords;
}

template <typename T>
int Codeword<T>::weight() const
{
	int weight = 0;
	for (auto itr = cWords.cbegin(); itr != cWords.cend(); ++itr)
	{
		if (itr->getVal() != T::special)
			weight++;
	}
	return weight;
}

template <typename T>
int Codeword<T>::distance(Codeword<T> &other) const
{
	unsigned int total = 0;
	for(int i = 0; i < cWords.size(); i++)
	{
		total += (cWords[i] - other.getCodeWord()[i]);
	}
	return total;
}

template <typename T>
void Codeword<T>::display() const
{
	for (auto itr = cWords.cbegin(); itr != cWords.cend(); ++itr)
	{
		cout << itr->getVal() << " ";
	}
	cout << "    " << "Weight: " << weight() << endl;
}



//---------------CODEBOOK--------------------------------//

template<typename T>
Codebook<T>::Codebook(int seed, int length, int size, int modulus)
{
	Codeword<T> special(length);
	cBook.push_back(special);

	for(int i = 1; i < size; i++)	// start at 1 to include symbol codeword
	{
		Codeword<T> codeword(seed, length);
		cBook.push_back(codeword);
	}
	calcDistance();
}

template<typename T>
int Codebook<T>::minimumWeight() const
{
	int min = INT_MAX;
	for(auto itr = cBook.cbegin()+1; itr != cBook.cend(); ++itr)	// +1 to ignore Symbol codeword
	{
		if(itr->weight() < min)
			min = itr->weight();
	}
	return min;
}

template <typename T>
void Codebook<T>::calcDistance() 
{
	for (int i = 0; i < cBook.size(); i++)
	{
		for (int p = 0; p < cBook.size(); p++)
		{
			if(p != i)
				distances.push_back(cBook[i].distance(cBook[p]));
			else
			{
				distances.push_back(-1);
			}
		}
	}
}

template <typename T>
int Codebook<T>::minimumDistance() const
{
	int smallest = INT_MAX;
	for (auto itr = distances.cbegin(); itr != distances.cend(); ++itr)
	{
		if (*itr < smallest && *itr != -1)
			smallest = *itr;
	}
	return smallest;
}

template <typename T>
void Codebook<T>::display() const
{
	cout << "\n- Codebook Display " << T::getType() << " -\n" << endl;

	for (auto itr = cBook.cbegin(); itr != cBook.cend(); ++itr)
	{
		itr->display();
	}

	cout << "\nThe minimum weight is: " << minimumWeight() << endl;
	cout << "The minimum distance is: " << minimumDistance() << endl;

	cout << "\nDistance Table\n" << endl;
	int total = 0;
	for (int i = 0; i < cBook.size(); i++)
	{
		for (int p = 0; p < cBook.size(); p++)
		{
			int dist = distances[total];
			if(dist != -1)
				printf("%-4d", dist);
			else
				printf("%-4d", 0);

			total++;
		}
		cout << "\n" << endl;
	}
}
