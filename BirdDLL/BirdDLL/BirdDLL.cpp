// birdDLL.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "birdDLL.h"
#include <iostream>

using std::cout;

Animal* createBird()
{
    return new Bird();
}

void Bird::doThing()
{
    cout << "bird sound";
}
