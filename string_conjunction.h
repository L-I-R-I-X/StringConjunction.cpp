#ifndef STRING_CONJUNCTION_H
#define STRING_CONJUNCTION_H

#include <string>
#include <iostream>

class BitString {
private:
    char* bs;
    int size;

    void fromString(const std::string& inputString);

public:
    BitString();
    BitString(const std::string& inputString);
    BitString(const BitString& other);
    ~BitString();

    // Методы ввода/вывода
    void input(int n);
    void output(int n) const;
    BitString conjunction(const BitString& other) const;
    
    // Операторы
    BitString& operator=(const BitString& other);
    BitString operator&(const BitString& other) const;
    char& operator[](int index);
    const char& operator[](int index) const;
    
    // Дружественные операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const BitString& bitStr);
    friend std::istream& operator>>(std::istream& is, BitString& bitStr);
};

#endif