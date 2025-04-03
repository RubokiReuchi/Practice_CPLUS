#pragma once

#include <iostream>

using namespace std;

class Console {
public:
    static void print(const string& message) {
        cout << message << endl;
    }

    static void print(int number) {
        cout << number << endl;
    }

    static void print(float number) {
        cout << number << endl;
    }

    static void print(double number) {
        cout << number << endl;
    }
};