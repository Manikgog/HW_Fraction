#include "Fraction.h"

int Fraction::gcd(int a, int b)
{
	if (a < b) {
		std::swap(a, b);
	}

	while (b) {
		a %= b;
		std::swap(a, b);
	}

	return a;
}

Fraction::Fraction() : _numerator(0), _denominator(1)
{}

Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator)
{
	if (_denominator == 0)
		throw 1;
	int g = gcd(std::abs(_numerator), std::abs(_denominator));
	_numerator /= g;
	_denominator /= g;
}

Fraction::Fraction(int num) : Fraction(num, 1) {}

void Fraction::SetDenominator(int denominator) {
	if (denominator == 0)
		throw 1;
	_denominator = denominator;
}


void Fraction::SetNumerator(int numerator) {
	_numerator = numerator;
}


void Fraction::SetBoth(int numerator, int denominator) {
	if (denominator == 0)
		throw 1;
	_denominator = denominator;
	_numerator = numerator;
}

int Fraction::GetDenominator() const {
	return _denominator;
}

int Fraction::GetNumerator() const {
	return _numerator;
}

int Fraction::WholePart() const
{
	return _numerator / _denominator;
}

Fraction Fraction::FractionalPart() const
{
<<<<<<< HEAD
	return Fraction { std::abs((_numerator % _denominator)), _denominator };
=======
	return { (std::abs(_numerator % _denominator)), _denominator };
>>>>>>> 36d51befed3253a9ea55d67be45772402a111230
}

Fraction Fraction::InverseFraction() const
{
	return { _denominator, _numerator };
}

Fraction Fraction::operator*(const Fraction& f) const
{
<<<<<<< HEAD
	return { _numerator * f.GetNumerator(), _denominator * f.GetDenominator() };
=======
	return Fraction(_numerator * f.GetNumerator(), _denominator * f.GetDenominator());
>>>>>>> 36d51befed3253a9ea55d67be45772402a111230
}

Fraction Fraction::operator/(const Fraction& f) const
{
	return { _numerator * f.GetDenominator(), _denominator * f.GetNumerator() };
}

Fraction Fraction::operator+(const Fraction& f) const
{
	int numerator, denominator;
	denominator = _denominator * f.GetDenominator();
	numerator = _numerator * f.GetDenominator() + _denominator * f.GetNumerator();
	return { numerator, denominator };
}

Fraction Fraction::operator-(const Fraction& f) const
{
	int numerator, denominator;
	denominator = _denominator * f.GetDenominator();
	numerator = _numerator * f.GetDenominator() - _denominator * f.GetNumerator();
<<<<<<< HEAD
	return { numerator, denominator };
=======
	Fraction tmp{ numerator, denominator };
	return tmp;
>>>>>>> 36d51befed3253a9ea55d67be45772402a111230
}

Fraction& Fraction::operator+()		// унарный плюс
{
	return *this;
}

Fraction& Fraction::operator-()		// унарный минус
{
	_numerator = -_numerator;
	return *this;
}

Fraction Fraction::operator++()		// прединкремент
{
	_numerator += _denominator;
	return *this;
}

Fraction Fraction::operator++(int)	// постинкремент
{
	Fraction tmp{ _numerator, _denominator };
	++(*this);
	return tmp;
}

Fraction Fraction::operator--()		// преддекремент
{
	_numerator -= _denominator;
	return *this;
}

Fraction Fraction::operator--(int)	// постдекремент
{
	Fraction tmp{ _numerator, _denominator };
	--(*this);
	return tmp;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
	int numerator = f.GetNumerator();
	int denominator = f.GetDenominator();
	if (std::abs(numerator) < denominator)
		out << numerator << "/" << denominator;
	else if (std::abs(numerator) == denominator)
	{
		if (numerator < 0)
			out << -1;
		else
			out << 1;
	}
	else
	{
		if (numerator < 0)
			out << f.WholePart() << "." << (f.FractionalPart());
		else
			out << f.WholePart() << "." << (f.FractionalPart());
	}
	return out;
}