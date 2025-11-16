#ifndef STRING_CONJUNCTION_H
#define STRING_CONJUNCTION_H

#include <string>

class BitString {
private:
    char* bs;
    int size;

    void fromString(const std::string& inputString);

public:
    BitString(); // Конструктор по умолчанию
    BitString(const std::string& inputString); // Конструктор инициализации
    BitString(const BitString& other); // Конструктор копирования
    ~BitString(); // Деструктор

    void input(int n);
    void output(int n) const;
    BitString conjunction(const BitString& other) const;
    
    // Оператор присваивания для правильной работы с динамической памятью
    BitString& operator=(const BitString& other);
};

#endif