#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial()
{
	fDegree = 0;
	for (int i = 0; i < MAX_DEGREE; i++) {
		fCoeffs[i] = 0.0;
	}
}

istream& operator>> (istream& aIStream, Polynomial& aObject)
{
	aIStream >> aObject.fDegree;
	for (int i = 0; i < aObject.fDegree + 1; i++) {
		aIStream >> aObject.fCoeffs[i];
	}

	return aIStream;
}

ostream& operator<< (ostream& aOStream, const Polynomial& aObject)
{
	for (int i = 0; i <= aObject.fDegree; i++) {
		// If not final term, print "+" at the end to show addition of multiple terms.
		if (i != aObject.fDegree) {
			// If coefficient is 0, skip term.
			if (aObject.fCoeffs[i] == 0) { continue; }
			// If this terms degree is 0, only print coefficient.
			if ((aObject.fDegree - i) == 0) {
				aOStream << aObject.fCoeffs[i] << " + ";
			}
			// If this terms degree is 1, only print coefficient and "x"
			else if ((aObject.fDegree - i) == 1) 
			{
				aOStream << aObject.fCoeffs[i] << "x" << " + ";
			}
			// Else print full statement
			else 
			{
				aOStream << aObject.fCoeffs[i] << "x^" << (aObject.fDegree - i) << " + ";
			}
		}
		else 
		{
			// If coefficient is 0, skip term.
			if (aObject.fCoeffs[i] == 0) { continue; }
			// If this terms degree is 0, only print coefficient.
			if ((aObject.fDegree - i) == 0) {
				aOStream << aObject.fCoeffs[i];
			}
			// If this terms degree is 1, only print coefficient and "x"
			else if ((aObject.fDegree - i) == 1)
			{
				aOStream << aObject.fCoeffs[i] << "x";
			}
			// Else print full statement
			else
			{
				aOStream << aObject.fCoeffs[i] << "x^" << (aObject.fDegree - i);
			}
		}
	}
	
	return aOStream;
}

bool Polynomial::operator== (const Polynomial& aRHS) const
{
	if (fDegree != aRHS.fDegree) { return false; }
	for (int i = 0; i <= fDegree; i++) 
	{
		if (fCoeffs[i] != aRHS.fCoeffs[i]) { return false; }
	}
	return true;
}

Polynomial Polynomial::operator* (const Polynomial& aRHS) const
{
	Polynomial result;

	result.fDegree = fDegree + aRHS.fDegree;

	for (int i = 0; i <= fDegree; i++) 
	{
		for (int j = 0; j <= aRHS.fDegree; j++) 
		{
			result.fCoeffs[i + j] += fCoeffs[i] * aRHS.fCoeffs[j];
		}
	}

	return result;
}