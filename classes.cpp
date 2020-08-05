#include <string>
#include "generateValue.h"
#include "classes.h"


//---------------Mint-------------------//

int Mint::modulus = 0;
int Mint::special = 0;

Mint::Mint(unsigned int seed) { mint = generateMint(seed, modulus); }

Mint::Mint() { mint = special; }

int Mint::operator-(const Mint a) const	
{
	int result = (mint - a.mint);
	if(result < 0)
		result += modulus;
	return (result % modulus);
}

unsigned int Mint::getVal() const { return mint; }

std::string Mint::getType() { return "Mint"; }

//---------------Melt-------------------//

char Melt::special = 'a';

Melt::Melt(int seed) { melt = generateMelt(seed); }

Melt::Melt() { melt = special; }

char Melt::getVal() const { return melt;  }

int Melt::operator-(const Melt rhs) const
{
	if (melt != rhs.melt)
		return 1;
	else
		return 0;
}

std::string Melt::getType() { return "Melt"; }