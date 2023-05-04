#include "utils.h"

int main() {
	//initial products that our Factory can handle
	Factory::addNewProduct("Dog", createDog);
	Factory::addNewProduct("Cat", createCat);

	string input;//user input
	cout << "Input class: ";
	std::getline(cin, input);
	Animal* test = Factory::create(input);
	
	HMODULE hLib = nullptr;
	if (test == nullptr) {//check if our application is capable of creating current user's input
		string lib = "dependency/" + input + "DLL.dll";
		hLib = LoadLibrary(CA2W(lib.c_str()));
		cout << "class not found. Trying to load from \"" << lib << "\"\n";

		if (hLib) {
			Animal* (*func) ();// declare a function pointer to retrieve from dll
			string functionName = "create" + input;//e.g createBird is our function name
			func = (Animal * (*)()) GetProcAddress(hLib, functionName.c_str());

			Factory::addNewProduct(input, func);
			test = Factory::create(input);

			if (hLib && func) {
				cout << "loaded successfully\n";
			}
			else {
				cout << "loaded failed\n";
			}

		}
	}

	if (!test) {
		cout << "Result: unable to create your object.\n";
	}
	else {
		cout << "Result: ";
		test->doThing();
		cout << "\n";
	}

	if (hLib) {
		FreeLibrary(hLib);
	}

	delete test;

	cin.get();
	return 0;
}