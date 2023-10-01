#include<cmath>
extern "C" __declspec(dllexport)

double universal_func(double num) {
	return std::sin(num) / std::cos(num);
}