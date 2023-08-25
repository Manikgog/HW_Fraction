/*
Задание
В реализованном ранее классе дробь реализовать перегрузку следующих унарных
oператоров:
инкремент "++"
декремент "--"
унарный минус "-"
унарный плюс "+"
Обратить внимание на конструкторы класса и те которые представляются нужными отметить
как explicit. выбор пояснить комментарием
Добавить в класс методы: 
- получения целой части от дроби;
- получения дробной части от дроби;
- сокращение дроби(уменьшение знаменателя до возможного минимума);
- получение обратной дроби.
``` задание сдаётся в виде ссылки на репозиторий либо подготовленным архивом проекта
*/

#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Fraction.h"

void displayFraction(const Fraction& f)
{
	std::cout << f.GetNumerator() << '/' << f.GetDenominator() << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста

	
	// вычитание
	try {
		Fraction f1(32, 5);
		Fraction f2(1, 2);
	
	Fraction f3;
	f3 = f1 - f2;
	std::cout << f1 << " - " << f2 << " = " << f3;
	std::cout << "\n\n";
	
	// сложение
	f3 = f1 + f2;
	std::cout << f1 << " + " << f2 << " = " << f3 << "\n\n";

	// умножение
	f3 = f1 * f2;
	std::cout << f1 << " * " << f2 << " = " << f3 << "\n\n";

	// деление
	f3 = f1 / f2;
	std::cout << f1 << " / " << f2 << " = " << f3 << "\n\n";
	

	Fraction f4{ 3, 2 };

	// постдекремент
	std::cout << f4 << "-- = ";
	f4--;
	std::cout << f4 << std::endl;
	// преддекремент
	std::cout << "--" << f4 << " = ";
	--f4;
	std::cout << f4 << std::endl;
	// постинкремент
	std::cout << f4 << "++ = ";
	f4++;
	std::cout << f4 << std::endl;
	// прединкремент
	std::cout << "++" << f4 << " = ";
	++f4;
	std::cout << f4 << std::endl;
	// унарный минус
	std::cout << "-" << f4 << " = ";
	-f4;
	std::cout << f4 << std::endl;
	// унарный плюс
	std::cout << "+" << f4 << " = ";
	+f4;
	std::cout << f4 << std::endl;
	// унарный минус
	std::cout << "-" << f4 << " = ";
	-f4;
	std::cout << f4 << std::endl;
	
	Fraction f5{ 4, 5 };
	Fraction f6{ 6, 7 };
	
	std::cout << "Исходная дробь -> " << f5 << std::endl;
	std::cout << "Обратная дробь -> " << f5.InverseFraction() << std::endl;
	}
	catch (int) {
		std::cerr << "Деление на ноль!\n";
	}

	return 0;
}
