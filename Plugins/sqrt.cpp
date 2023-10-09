#include <cmath>
#include <initializer_list>

extern "C" __declspec(dllexport)
double universal_func(std::initializer_list<double> x) {
	return std::sqrt(*x.begin());
}