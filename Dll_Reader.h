#ifndef DLL_READER
#define DLL_READER

#include<string>
#include<map>

class Dll_Reader {
public:
	Dll_Reader();
	double calculate(std::string str, double num);
	bool is_in_plugins(std::string str);
private:
	std::string path = "C:\\Users\\Admin\\source\\repos\\calculator_lab1\\Plugins\\";
	std::map<std::string, double(*)(std::initializer_list<double>)> plugins;

};

#endif 

