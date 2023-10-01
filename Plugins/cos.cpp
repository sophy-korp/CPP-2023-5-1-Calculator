#include<cmath>
extern "C" __declspec(dllexport)

double universal_func(double num) {
	return std::cos(num);
}