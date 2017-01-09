#include "fraction.h"

int fraction::gcf(int a, int b) const {
	if (a == 0) {
		return b;
	} else if (b == 0) {
		return a;
	} else {
		return gcf(b, a%b);
	}
}

int fraction::lcm(int a, int b) const {
	return (a * b) / gcf(a,b);
}

fraction fraction::normalize() const {
	int g = gcf(cntr, denom);
	return fraction(cntr / g, denom / g);
}

fraction fraction::operator* (const fraction &b) const {
	fraction product = fraction(cntr * b.get_counter(), denom * b.get_denominator());
	return product.normalize();
}

fraction fraction::operator* (int factor) const {
	fraction product = fraction(cntr * factor, denom);
	return product.normalize();
}

fraction fraction::operator/ (const fraction &b) const {
	return (*this) * fraction(b.get_denominator(), b.get_counter());
}

fraction fraction::operator/ (int factor) const {
	return (*this) * fraction(1, factor);
}

fraction fraction::operator+ (const fraction &b) const {
	//we need the least common multiple to be able to add a fraction to another one
	int common_denom = lcm(denom, b.get_denominator());

	int factor1 = common_denom / denom;
	int factor2 = common_denom / b.get_denominator();

	fraction sum = fraction(factor1 * cntr + factor2 * b.get_counter(), common_denom);
	return sum.normalize();
}

fraction fraction::operator- (const fraction &b) const {
	int common_denom = lcm(denom ,b.get_denominator());

	int factor1 = common_denom / denom;
	int factor2 = common_denom / b.get_denominator();

	fraction difference = fraction(factor1 * cntr - factor2 * b.get_counter(), common_denom);
	return difference.normalize();
}