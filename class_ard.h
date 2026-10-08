#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
private:
    int* m_data;       // Указатель на динамический массив данных
    int m_size;        // Текущий размер массива

public:
    // Конструкторы и деструктор
    DynamicArray();                        // Конструктор по умолчанию
    explicit DynamicArray(int size);       // Конструктор со спецификацией размера
    ~DynamicArray();                       // Деструктор для очистки памяти

    // Правило трех (Rule of Three): копирование необходимо реализовать, 
    // чтобы избежать утечек памяти и двойного удаления
    DynamicArray(const DynamicArray& other);            // Конструктор копирования
    DynamicArray& operator=(const DynamicArray& other); // Оператор присваивания

    // Методы для работы с массивом
    void resize(int newSize);              // Метод изменения размера
    int getSize() const;                   // Получить текущий размер

    // Доступ к элементам
    int& operator[](int index);             // Оператор для чтения и записи: arr[i] = 5;
    const int& operator[](int index) const; // Оператор только для чтения
    void set (int peremen, int index); //
    int get(int index); //
    void print() const;
    void end_arr(int peremen);
    void sum(const DynamicArray& other);
    void raz(const DynamicArray& other);


};

#endif // DYNAMIC_ARRAY_H