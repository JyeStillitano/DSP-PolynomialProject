#pragma once
#include <iostream>
#define MAX_DEGREE 20+1	// Maximum degree = 10 + 10 + 1 (0 - 20)

class Polynomial
{
	private:
		int fDegree;	// the maximum degree of the polynomial
		double fCoeffs[MAX_DEGREE];		// the coefficients (0..10, 0..20)

	public:
		// the default constructor (initializes all member variables)
		Polynomial();
		
		// binary operator* to multiply two polynomials
		// arguments are read-only, signified by const
		// the operator* returns a fresh polynomial with degree i+j
		Polynomial operator* ( const Polynomial& aRHS) const;
		
		// binary operator==to compare two polynomials
		// arguments are read-only, signified by const
		// the operator== returns trueif this polynomial is
		// structurally equivalent to the aRHS polynomial
		bool operator== ( const Polynomial& aRHS ) const;
		
		// input operator for polynomials
		friend std::istream& operator>> ( std::istream& aIStream, Polynomial& aObject );
		
		// output operator for polynomials
		friend std::ostream& operator<< ( std::ostream& aOStream, const Polynomial& aObject );
};

