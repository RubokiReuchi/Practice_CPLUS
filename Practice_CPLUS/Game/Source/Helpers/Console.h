#pragma once

#include <iostream>

using namespace std;

class Console {
public:
    static void print(const string& message) {
        cout << message << endl;
    }
};