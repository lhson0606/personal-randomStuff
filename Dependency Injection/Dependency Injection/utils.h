#pragma once

#include <iostream>
#include <map>
#include <string>
#include <Windows.h>
#include <AtlBase.h>
#include <atlconv.h>

using std::cout, std::cin;
using std::map;
using std::string;

class Animal
{
public:
	virtual void doThing() = 0;
};

class Dog :public Animal {
public:
	Dog() = default;
	void doThing() override {
		cout << "dog sound";
	}
};

class Cat :public Animal {
public:
	Cat() = default;
	void doThing() override {
		cout << "cat sound";
	}
};

class Factory
{
	inline static map<string, Animal*(*) ()> ability;
public:
	inline static void addNewProduct(string name, Animal*(*src)()) {
		ability[name] = src;
	}
	inline static Animal* create(string name) {
		Animal* (*f)() = ability[name];
		if (f == nullptr) return nullptr;
		return f();
	}
};

Animal* createDog() {
	return new Dog();
}

Animal* createCat() {
	return new Cat();
}