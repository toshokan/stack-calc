#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
#include <vector>
#include <stack>

enum Operation {
	Plus,
	Minus,
	Multiply,
	Divide,
	Square,
	SquareRoot,
	Sin,
	Cos,
	Tan,
};

template <typename T>
class Registers {
	public:
		Registers() = default;
		~Registers() = default;
		void print() const;
		void push(T i);
		void apply(Operation o);
		Operation stoo(std::string s);
	private:
		void apply_unary(Operation o);
		void apply_binary(Operation o);
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
			this->apply_binary(o);
			break;
		case Square:
		case SquareRoot:
		case Sin:
		case Cos:
		case Tan:
			this->apply_unary(o);
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
			case Square:
				this->push(x*x);
				break;
			case SquareRoot:
				this->push(x);
				break;
				// TODO
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
			case Divide:
				this->push(y / x);
		}
	}
}

template <typename T>
Operation Registers<T>::stoo(std::string s){
		if(s == "+") return Plus;
		if(s == "-") return Minus;
		if(s == "*") return Multiply;
		if(s == "/") return Divide;
		if(s == "sq") return Square;
		if(s == "sqrt") return SquareRoot;
		if(s == "sin") return Sin;
		if(s == "cos") return Cos;
		if(s == "tan") return Tan;
}

template <typename T>
void Registers<T>::push(T i){
	this->r.push(i);
}

#endif
