#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
#include <vector>
#include <stack>
#define _USE_MATH_DEFINES
#include <cmath>

enum Operation {
	Plus,
	Minus,
	Multiply,
	Divide,
	Pow,
	Negate,
	Square,
	SquareRoot,
	Sin,
	Cos,
	Tan,
	NamedConstPi,
	NamedConstE,
	MetaClear,
};

template <typename T>
class Registers {
	public:
		Registers() = default;
		~Registers() = default;
		void print() const;
		void push(T i);
		void apply(Operation o);
		Operation stoo(std::string s) const;
	private:
		void apply_unary(Operation o);
		void apply_binary(Operation o);
		void push_named(Operation o);
		void apply_meta(Operation o);
		std::stack<T> r;
};


template <typename T>
void Registers<T>::print() const{
	std::stack<T> temp = this->r;
	std::cout << "Registers:" << std::endl;
	std::vector<T> v;
	while (!temp.empty()){
		v.push_back(temp.top());
		temp.pop();
	}
	for(auto i = v.rbegin(); i != v.rend(); i++){
		std::cout << *i << std::endl;
	}
}

template <typename T>
void Registers<T>::apply(Operation o){
	switch (o) {
		case Plus:
		case Minus:
		case Multiply:
		case Divide:
		case Pow:
			this->apply_binary(o);
			break;
		case Negate:
		case Square:
		case SquareRoot:
		case Sin:
		case Cos:
		case Tan:
			this->apply_unary(o);
			break;
		case NamedConstPi:
		case NamedConstE:
			this->push_named(o);
			break;
		case MetaClear:
			this->apply_meta(o);
			break;
	}
}

template <typename T>
void Registers<T>::apply_unary(Operation o){
	T x;
	if(this->r.size() >= 1){
		x = this->r.top();
		this->r.pop();
		switch(o){
			case Negate:
				this->push(-x);
				break;
			case Square:
				this->push(pow(x, 2));
				break;
			case SquareRoot:
				this->push(sqrt(x));
				break;
			case Sin:
				this->push(sin(x));
				break;
			case Cos:
				this->push(cos(x));
				break;
			case Tan:
				this->push(tan(x));
				break;
		}
	}
}

template <typename T>
void Registers<T>::apply_binary(Operation o){
	T x,y;
	if(this->r.size() >= 2){
		x = this->r.top();
		this->r.pop();
		y = this->r.top();
		this->r.pop();
		switch(o){
			case Plus:
				this->push(y + x);
				break;
			case Minus:
				this->push(y - x);
				break;
			case Multiply:
				this->push(y * x);
				break;
			case Divide:
				this->push(y / x);
				break;
			case Pow:
				this->push(pow(y, x));
				break;
		}
	}
}

template <typename T>
void Registers<T>::push_named(Operation o){
	switch(o){
		case NamedConstPi:
			this->push(M_PI);
			break;
		case NamedConstE:
			this->push(M_E);
			break;
	}
}

template <typename T>
void Registers<T>::apply_meta(Operation o){
	switch(o){
		case MetaClear:
			while(!this->r.empty()){
				this->r.pop();
			}
	}
}
			

template <typename T>
Operation Registers<T>::stoo(std::string s) const{
		if(s == "+") return Plus;
		if(s == "-") return Minus;
		if(s == "*") return Multiply;
		if(s == "/") return Divide;
		if(s == "^") return Pow;
		if(s == "neg") return Negate;
		if(s == "sq") return Square;
		if(s == "sqrt") return SquareRoot;
		if(s == "sin") return Sin;
		if(s == "cos") return Cos;
		if(s == "tan") return Tan;
		if(s == "pi") return NamedConstPi;
		if(s == "e") return NamedConstE;
		if(s == "clear") return MetaClear;
}

template <typename T>
void Registers<T>::push(T i){
	this->r.push(i);
}

#endif
