#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

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
		std::string fexp;
		std::cout << "Enter a full expression to evaluate in RPN: ";
		std::getline(std::cin, fexp);
		bool in_num = false;;
		std::string b;
		for(int i = 0; i < fexp.size(); i++){
			if (std::isdigit(fexp[i]) || fexp[i] == '.'){
				in_num = true;
				b.push_back(fexp[i]);
			} else {
				if (in_num){
					in_num = false;
					registers.push(stod(b));
					b.clear();
				}
				switch(fexp[i]) {
					case '+':
						registers.apply(std::plus<double>());
						break;
					case '-':
						registers.apply(std::minus<double>());
						break;
					case '*':
						registers.apply(std::multiplies<double>());
						break;
					case '/':
						registers.apply(std::divides<double>());
						break;
				}
			}
		}
		if (in_num){
			in_num = false;
			registers.push(stod(b));
			b.clear();
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
			switch(buff[0]) {
				case '+':
					registers.apply(std::plus<double>());
					break;
				case '-':
					registers.apply(std::minus<double>());
					break;
				case '*':
					registers.apply(std::multiplies<double>());
					break;
				case '/':
					registers.apply(std::divides<double>());
					break;
			}
		}
		registers.print();
	}
}

