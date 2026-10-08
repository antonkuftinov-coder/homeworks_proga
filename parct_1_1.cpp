#include "class_ard.h"
#include <iostream>
#include <algorithm> // Для std::copy и std::min
#include <stdexcept> // Для обработки исключений (out_of_range)

// Конструктор по умолчанию
DynamicArray::DynamicArray() : m_data(nullptr), m_size(0) {}

// Конструктор с заданным размером
DynamicArray::DynamicArray(int size) : m_size(size) {
    if (size > 0) {
        m_data = new int[size](); // () обнуляет элементы массива
    } else {
        m_data = nullptr;
        m_size = 0;
    }
}

// Деструктор: освобождаем выделенную память
DynamicArray::~DynamicArray() {
    delete[] m_data;
}

// Конструктор копирования
DynamicArray::DynamicArray(const DynamicArray& other) : m_size(other.m_size) {
    if (m_size > 0) {
        m_data = new int[m_size];
        std::copy(other.m_data, other.m_data + m_size, m_data);
    } else {
        m_data = nullptr;
    }
}

// Оператор присваивания (через Copy-and-Swap или классический метод)
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] m_data; // Удаляем старые данные

        m_size = other.m_size;
        if (m_size > 0) {
            m_data = new int[m_size];
            std::copy(other.m_data, other.m_data + m_size, m_data);
        } else {
            m_data = nullptr;
        }
    }
    return *this;
}

// Изменение размера массива с сохранением данных
void DynamicArray::resize(int newSize) {
    if (newSize < 0) newSize = 0;
    if (newSize == m_size) return;

    if (newSize == 0) {
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        return;
    }

    // 1. Выделяем новый кусок памяти
    int* newData = new int[newSize](); 

    // 2. Копируем старые данные в новый массив (сколько поместится)
    if (m_data != nullptr) {
        int elementsToCopy = std::min(m_size, newSize);
        std::copy(m_data, m_data + elementsToCopy, newData);
        
        // 3. Освобождаем старую память
        delete[] m_data;
    }

    // 4. Перенаправляем указатель и обновляем размер
    m_data = newData;
    m_size = newSize;
}

int DynamicArray::getSize() const {
    return m_size;
}

// Доступ по индексу (с базовой проверкой границ)
int& DynamicArray::operator[](int index) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_data[index];
}

const int& DynamicArray::operator[](int index) const {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_data[index];
}

void DynamicArray::print() const {
    std::cout << "{ ";
    for (int i = 0; i < m_size; i++) {
        std::cout << m_data[i] << " ";
    }
    std::cout << "}";
}

// Задание 3: добавить значение в конец с расширением массива
void DynamicArray::end_arr(int value) {
    if (value < -100 || value > 100) {
        std::cout << "Ошибка: значение должно быть в диапазоне [-100; 100]\n";
        return;
    }

    // создаём новый массив на 1 элемент больше
    int* newData = new int[m_size + 1];

    // копируем старые значения
    for (int i = 0; i < m_size; i++) {
        newData[i] = m_data[i];
    }
    // добавляем новое значение в конец
    newData[m_size] = value;

    // удаляем старый массив и подменяем указатель
    delete[] m_data;
    m_data = newData;
    m_size++;
}

// Задание 4: поэлементное сложение
void DynamicArray::sum(const DynamicArray& other) {
    for (int i = 0; i < m_size; i++) {
        // если в other нет элемента с таким индексом — берём 0
        int otherValue = (i < other.m_size) ? other.m_data[i] : 0;
        m_data[i] += otherValue;
    }
}

// Задание 4: поэлементное вычитание
void DynamicArray::raz(const DynamicArray& other) {
    for (int i = 0; i < m_size; i++) {
        int otherValue = (i < other.m_size) ? other.m_data[i] : 0;
        m_data[i] -= otherValue;
    }
}

void DynamicArray::set(int peremen, int index) {
    if (index < 0 || index >= m_size) {
        std::cout << "Error\n";
        return;
    }
    if (peremen < -100 || peremen > 100) {
        std::cout << "Error\n";
        return;
    }
    m_data[index] = peremen;
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= m_size) {
        std::cout << "Error\n";
        return 0;
    }
    return m_data[index];
}
