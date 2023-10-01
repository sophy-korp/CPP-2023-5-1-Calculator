
#ifndef CALCULATOR
#define CALCULATOR

#include<map>
#include<functional>
#include<string>
#include<stack>
#include"Dll_Reader.h"


class Calculator {
public:
	double calculate(std::string str);
	Calculator();
	~Calculator();
private:
	std::stack<double> nums;
	std::stack<std::string> operations;
	std::map<std::string, int> priorities;
	std::map<std::string, std::function<double(double, double)>> functionalities;
	std::string standart_view(std::string str);
	void do_step();
	bool is_num(std::string);
	double to_double(std::string str);
	bool standard_function(std::string str);
	void clean_stack(std::stack<double> st);
	void clean_stack(std::stack<std::string> st);
	Dll_Reader reader;
};

#endif