#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
#include <vector>
#include <stack>

template <typename T>
class Registers {
	public:
		Registers() = default;
		~Registers() = default;
		void print() const;
		template <typename F>
		void apply(F func);
		void push(T i);
	private:
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

template <typename T> template <typename F>
void Registers<T>::apply(F func){
	T x, y;
	if(this->r.size() >= 2){
		x = this->r.top();
		this->r.pop();
		y = this->r.top();
		this->r.pop();
	}
	this->r.push(func(x,y));
}

template <typename T>
void Registers<T>::push(T i){
	this->r.push(i);
}

#endif
