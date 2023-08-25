#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>

class Fraction {
private:
	int _numerator;
	int _denominator;
	int gcd(int a, int b);
public:
	Fraction();

	Fraction(int numerator, int denominator);/* нет необходимости защищать от неявного преобразования этот конструктор так как 
												он содержит два параметра и запустить его неявно невозможно */

	explicit Fraction(int num);/* Eсть смысл поставить защиту (explicit) на конструктор с одним параметром. Так как есть опасность 
								неявного преобразования при выполнении перегруженных арифметических операциий.*/

	void SetDenominator(int denominator);

	void SetNumerator(int numerator);

	void SetBoth(int numerator, int denominator);

	int GetDenominator() const;

	int GetNumerator() const;

	int WholePart() const;								// получение целой части

	Fraction FractionalPart() const;					// получение дробной части

	Fraction InverseFraction() const;					// получение обратной дроби

	Fraction operator*(const Fraction& f) const;		// умножение

	Fraction operator/(const Fraction& f) const;		// деление

	Fraction operator+(const Fraction& f) const;		// сложение

	Fraction operator-(const Fraction& f) const;		// вычитание

	Fraction& operator+();								// унарный плюс

	Fraction& operator-();								// унарный минус

	Fraction operator++();								// прединкремент

	Fraction operator++(int);							// постинкремент

	Fraction operator--();								// преддекремент

	Fraction operator--(int);							// постдекремент

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

#endif // !_FRACTION_H_
