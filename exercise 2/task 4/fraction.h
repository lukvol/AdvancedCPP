#include <stdexcept>
#include <iostream>
#include <cmath>

#ifndef fraction_H
#define fraction_H

class fraction {
private:
	int cntr; 
	int denom;
	/**
	 * Returns the greatest common factor of two integers.
	 * This is the standard euclidean algorithm
	 * @param  	a 		integer
	 * @param  	b 		integer
	 * @return   		the greatest common factor of two integers
	 */
	int gcf(int a, int b) const;

	/**
	 * Returns the least common multiple of two integers.
	 * @param  	a 		integer
	 * @param  	b 		integer
	 * @return   		the least common multiple of two integers
	 */
	int lcm(int a, int b) const;

	/**
	 * Returns a normalized version of the fraction by
	 * calculating the gcf of both the counter and the denominator
	 * and then divide the counter and denominator by the gcf
	 * @return 			normalized fraction
	 */
	fraction normalize() const;
public:
	//we use the setters since we check in the setter if the denominator is not null
	fraction(int c = 0, int d = 1) {
		set_counter(c);
		set_denominator(d);
	}

	//Getters and setters
    int get_counter() const{ return cntr; }
	void set_counter(int c) { cntr = c; }
	int get_denominator() const { return denom; }
	void set_denominator(int d) {
		if (d == 0) {
			throw std::invalid_argument("A fraction can't have 0 as its denominator!");
		} else {
			denom = d;
		}
	}

	/**
	 * Multiplies the fraction with another fraction
	 * @param 	b 		the fraction we want to multiply with.
	 * @return 			normalized fraction
	 */
	fraction operator* (const fraction &b) const;

	/**
	 * Multiplies the fraction with a factor
	 * @param 	factor	the factor we want fraction multiplied with
	 * @return 			normalized fraction
	 */
	fraction operator* (int factor) const;

	/**
	 * Divides the fraction by another fraction
	 * @param 	b 		the fraction we want to be divided by.
	 * @return 			normalized fraction
	 */
	fraction operator/ (const fraction &b) const;

	/**
	 * Divides the fraction by a factor
	 * @param 	factor 	the factor we want to be divided by.
	 * @return 			normalized fraction
	 */
	fraction operator/ (int factor) const;

	/**
	 * Builds the sum of two fractions
	 * @param	b 		the fraction we want to add
	 * @return 			normalized fraction
	 */
	fraction operator+ (const fraction &b) const;

	/**
	 * Adds a factor to a fraction
	 * @param	factor	the factor we want to add to the fraction
	 * @return 			the new value which our fraction represents
	 */
	double operator+ (double factor) const {
		//we need to convert the counter and denominator to double
		//since otherwise, information could be lost after the division
		return double(cntr) / double(denom) + factor;
	}

	/**
	 * Builds the difference of two fractions
	 * @param	b 		the fraction we want to subtract
	 * @return 			normalized fraction
	 */
	fraction operator- (const fraction &b) const;

	/**
	 * Subtracts a factor from our fraction
	 * @param	factor	the factor we want to subtract
	 * @return 			the new value which our fraction represents
	 */
	double operator- (int factor) const {
		return double(cntr) / double(denom) - factor;
	}

	/**
	 * Checks if our fraction is greater than another fraction
	 * @param	b		the fraction we want to be compare with
	 * @return 			true if the fraction is greater than b, false otherwise
	 */
	bool operator> (const fraction &b) const {
		//we compare the fractions by calculating the actual value of each fraction
		//and comparing these values with each other
		return (cntr / double(denom) > (b.get_counter() / double(b.get_denominator())));
	}

	/**
	 * Checks if our fraction is smaller than another fraction
	 * @param	b		the fraction we want to be compare with
	 * @return 			true if the fraction is smaller than b, false otherwise
	 */
	bool operator< (const fraction &b) const {
		return (cntr / double(denom) < (b.get_counter() / double(b.get_denominator())));
	}

	/**
	 * Checks if two fractions are equal
	 * @param	b		the fraction we want to be compare with
	 * @return 			true if the fractions are equal, false otherwise
	 */
	bool operator== (const fraction &b) const {
		return (cntr/double(denom)) == (b.get_counter() / double(b.get_denominator()));
	}

	/**
	 * Checks if two fractions are not equal
	 * @param	b		the fraction we want to be compare with
	 * @return 			true if the fractions are not equal, false otherwise
	 */
	bool operator!= (const fraction &b) const {
		return !((*this) == b);
	}

	/** 
	 * Prints the normalized representation of the fraction to the output stream
	 * @param 	output	the output stream we write the fraction into
	 * @param	a 		the normalized fraction we want to write into the output stream
	 * @return 	ostream	the output stream
	 */
	friend std::ostream &operator<< (std::ostream &output, const fraction &a) {
		fraction normalized = a.normalize();
		//we need to check if our fraction is positive or negative, if there is a negative value,
		//we display the negative value in front of the fraction
		output << (normalized.get_counter() * normalized.get_denominator() > 0 ? '\0' : '-')
			   << "(" << std::abs(normalized.get_counter()) << "/" << std::abs(normalized.get_denominator())
			   << ")";
		return output; 
	}
	/**
	 * Reads a fraction from the input stream. The user has to enter two integer values,
	 * separated by a space (' ') to be able to create a fraction
	 * @param 	input	the input stream from which we want to get the raw values
	 * @param	a 		the fraction we want to save the data into
	 * @return 	istream	the input stream
	 */
    friend std::istream &operator>> (std::istream &input, fraction &a) {
		int counter, denominator;
		//we use the setters since we need to check if the denominator is not 0
		input >> counter;
		a.set_counter(counter);
		input >> denominator;
		a.set_denominator(denominator);

		return input;            
	}
};

#endif
