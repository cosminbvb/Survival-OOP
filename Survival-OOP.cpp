// Survival-OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Map.h"

using namespace std;

int main()
{
    Map m = Map(15, 15);
    m.setItem(1, 2, '1');
    m.setItem(1, 4, '2');
    m.setItem(3, 2, '3');
    m.setItem(3, 4, '4');
    cout << m;

    return 0;
}
