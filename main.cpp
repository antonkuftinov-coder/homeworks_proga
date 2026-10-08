#include "class_ard.h"
#include <iostream>

int main() {
    // ==== Задание 1: конструктор, set, get, print ====
    std::cout << "--- Задание 1 ---\n";
    DynamicArray a(5);
    for (int i = 0; i < 5; i++) {
        a.set(i * 10, i);   // значение, индекс
    }
    std::cout << "a = ";
    a.print();
    std::cout << "\n";
    std::cout << "a.get(2) = " << a.get(2) << "\n\n";

    // ==== Задание 2: конструктор копирования ====
    std::cout << "--- Задание 2 ---\n";
    DynamicArray b = a;   // вызов конструктора копирования
    std::cout << "b (копия a) = ";
    b.print();
    std::cout << "\n\n";

    // ==== Задание 3: push_back ====
    std::cout << "--- Задание 3 ---\n";
    a.end_arr(99);
    std::cout << "a после push_back(99) = ";
    a.print();
    std::cout << "\n\n";

    // ==== Задание 4: add / subtract ====
    std::cout << "--- Задание 4 ---\n";
    DynamicArray x(3);
    x.set(1, 0);
    x.set(2, 1);
    x.set(3, 2);

    DynamicArray y(5);
    y.set(1, 0);
    y.set(2, 1);
    y.set(3, 2);
    y.set(4, 3);
    y.set(5, 4);

    std::cout << "x = "; x.print(); std::cout << "\n";
    std::cout << "y = "; y.print(); std::cout << "\n";

    x.sum(y);
    std::cout << "x.add(y)      = "; x.print(); std::cout << "\n";

    x.raz(y);
    std::cout << "x.subtract(y) = "; x.print(); std::cout << "\n";

    return 0;
}