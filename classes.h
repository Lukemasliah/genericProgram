#ifndef CLASSES_H
#define CLASSES_H

#include <string>

class Mint {
private:
	unsigned int mint;

public: 
	static int modulus;
	static int special;
	Mint(unsigned int seed);
	Mint();		// Special Character Melt
	int operator-(const Mint) const;
	unsigned int getVal() const;
	std::string static getType();
};

class Melt {
private:
	char melt;

public:
	Melt(int seed);
	Melt();		// Special Character Melt
	static char special;
	char getVal() const;
	int operator-(const Melt) const;
	std::string static getType();
};


#endif //CLASSES_H

