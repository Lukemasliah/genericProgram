#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <vector>

template <typename T>
class Codeword
{
private:
	std::vector<T> cWords;

public:
	Codeword(int length);	// Generate special symbol codeword
	Codeword(int seed, int length);
	std::vector<T> getCodeWord() const;
	int weight() const;
	int distance(Codeword<T> &) const;
	void display() const;
};

template<typename T>
class Codebook
{
	private:
	std::vector<Codeword<T>> cBook;
	std::vector<int> distances;
	
	public:
	Codebook(int, int, int, int);
	int minimumWeight() const;
	void calcDistance();	
	int minimumDistance() const;
	void display() const;
};

#include "templates.cpp"	// Template implementation

#endif  //TEMPLATES_H

