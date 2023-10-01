#include "Calculator.h"
#include<cmath>
#include<sstream>


Calculator::Calculator() {
	
	priorities.insert(std::pair<std::string, int>("+", 0));
	priorities.insert(std::pair<std::string, int>("-", 0));
	priorities.insert(std::pair<std::string, int>("*", 1));
	priorities.insert(std::pair<std::string, int>("/", 1));
	priorities.insert(std::pair<std::string, int>("^", 2));


	functionalities.insert(std::pair<std::string, double(*)(double, double)>("+",
		[](double x, double y) -> double {return x + y; }));
	functionalities.insert(std::pair<std::string, double(*)(double, double)>("-",
		[](double x, double y) -> double {return y - x; }));
	functionalities.insert(std::pair<std::string, double(*)(double, double)>("*",
		[](double x, double y) -> double {return x * y; }));
	functionalities.insert(std::pair<std::string, double(*)(double, double)>("/",
		[](double x, double y) -> double {return y / x; }));
	functionalities.insert(std::pair<std::string, double(*)(double, double)>("^",
		[](double x, double y) -> double {return pow(y, x); }));
}

void Calculator::clean_stack(std::stack<std::string> st) {
	std::stack<std::string> empty;
	std::swap(st, empty);
}

void Calculator::clean_stack(std::stack<double> st) {
	std::stack<double> empty;
	std::swap(st, empty);
}

Calculator::~Calculator() {
	clean_stack(nums);
	clean_stack(operations);
	priorities.clear();
	functionalities.clear();
}

std::string Calculator::standart_view(std::string str) {
	char prev = '(';
	std::string res;
	for (auto cur : str) {
		if (prev == '(' && cur == '-') {
			res += " 0 ";
			res.push_back(cur);
			prev = cur;
			continue;
		}
		if (cur == '.' || prev == '.') {
			res.push_back(cur);
			prev = cur;
			continue;
		}

		if ((cur >= '0' && cur <= '9') && (prev >= '0' && prev <= '9')) {
			res.push_back(cur);
			prev = cur;
			continue;
		}

		if ((cur >= 'a' && cur <= 'z') && (prev >= 'a' && prev <= 'z')) {
			res.push_back(cur);
			prev = cur;
			continue;
		}

		res += " ";
		res.push_back(cur);
		prev = cur;
	}
	return res;
}

void Calculator::do_step() {
	double first, second;
	std::string operation;

	operation = operations.top();
	operations.pop();
	if (standard_function(operation)) {
		first = nums.top();
		nums.pop();

		second = nums.top();
		nums.pop();

		double res = functionalities[operation](first, second);
		nums.push(res);
		return;
	}
	if (reader.is_in_plugins(operation)) {
		first = nums.top();
		nums.pop();
		double res = reader.calculate(operation, first);
		nums.push(res);
	}
	else throw std::exception(); 
	
}

bool Calculator::is_num(std::string str) {
	for (auto ch : str) {
		if ((ch < '0' || ch > '9') && ch != '.') return false;
	}
	return true;
};

double Calculator::to_double(std::string str) {
	std::stringstream buffer;
	buffer << str;
	double res;
	buffer >> res;
	return res;
};

bool Calculator::standard_function(std::string str) {
	if (functionalities.find(str) != functionalities.end()) return true;
	return false;
}

double Calculator::calculate(std::string str) {
	clean_stack(nums);
	clean_stack(operations);
	str = standart_view(str);
	std::stringstream buffer;
	buffer << str;
	std::string cur;

	while (buffer >> cur) {
		if (is_num(cur)) nums.push(to_double(cur));
		else {
			if (operations.empty()) {
				operations.push(cur);
				continue;
			} 
			if (cur == ")") {
				while (operations.top() != "(") {
					do_step();
				}
				operations.pop();
				continue;
			}
			if (cur == "(") {
				operations.push(cur);
				continue;
			}

			if (!standard_function(cur)) {
				operations.push(cur);
				continue;
			}
			while (!operations.empty() && operations.top() != "(" 
				&& !standard_function(operations.top())) {
				do_step();
			}
			while (!operations.empty() && operations.top() != "(" 
				&& priorities[cur] <= priorities[operations.top()]) {
				do_step();
			}
			operations.push(cur);
		}
	}

	while (!operations.empty()) do_step();
	return nums.top();
}