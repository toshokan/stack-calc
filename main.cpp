#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <sstream>

#include "registers.h"

int main(int argc, char** argv){
	Registers<double> registers;
	registers.print();
		while(false){
			std::string b;
			std::cout << "enter a number ";
			std::getline(std::cin, b);
			std::cout << "that was a number: " << std::isdigit(b[0]) << std::endl;
		}
	if (argc > 1 && strcmp(argv[1], "-e") == 0){
		std::string s;
		std::string b;
		std::vector<std::string> v;
		std::cout << "Enter a full RPN expression to evaluate: ";
		std::getline(std::cin, s);
		std::stringstream ss(s);
		while (ss >> b){
			v.push_back(b);
		}
		for(auto &val : v){
			try{
				auto n = stod(val);
				registers.push(n);
			} catch (...) {
				registers.apply(registers.stoo(val));
			}
		}
		registers.print();
	}
	std::string buff;
	while (true) {
		std::cout << "Enter a number or operator" << std::endl;
		std::cin >> buff;
		if (buff.size() != 1 || std::isdigit(buff[0])){
			registers.push(stod(buff));
		} else {
			registers.apply(registers.stoo(buff));
		}
		registers.print();
	}
}

