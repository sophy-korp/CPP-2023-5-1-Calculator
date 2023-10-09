#include<string>
#include<map>
#include<Windows.h>
#include "Dll_Reader.h"

Dll_Reader::Dll_Reader() {
	WIN32_FIND_DATAA detection;
	HANDLE detect = FindFirstFileA((path + std::string("*.dll")).c_str(), &detection);
	if (detect == INVALID_HANDLE_VALUE) {
		throw std::exception();
	}
	else {
		do{
			std::string function_name(detection.cFileName);
			HMODULE hm = LoadLibraryA((path + function_name).c_str());
			if (!hm) throw std::exception();

			std::string function = function_name.substr(0, function_name.find(".dll"));

			auto func = (double(*)(std::initializer_list<double>))GetProcAddress(hm, "universal_func");

			if (func) {
				plugins.insert(std::pair<std::string, double(*)(std::initializer_list<double>)>(function, func));
			}
			else throw std::exception();
		} while (FindNextFileA(detect, &detection) != NULL);
	}
}

double Dll_Reader::calculate(std::string str, double num) {
	return(plugins[str]({ num }));
}

bool Dll_Reader::is_in_plugins(std::string str) {
	return(plugins.find(str) != plugins.end());
}
