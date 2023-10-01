#include "Calculator.h"
#include<iostream>

int main() {
	std::cout << "Hello! This is your calculator." << std::endl;
	std::cout << "You can use all standart operations like + , -, *, / , ^ " << std::endl;
	std::cout << "and also some additional ones : sin, cos, tg, ctg, lg, ln, sqrt." << std::endl;
	std::cout << "Press 'z' to exit." << std::endl;
	std::cout << "Have a good day!" << std::endl;

	std::string str;
	std::getline(std::cin, str);

	Calculator Calc;

	while (str != "z") {
		double res = Calc.calculate(str);
		std::cout << res << std::endl;
		std::getline(std::cin, str);
	}
	
	return 0;
}