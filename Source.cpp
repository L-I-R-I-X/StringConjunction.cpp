#include "string_conjunction.h"
#include <iostream>
#include <string>
#include <stdexcept>

BitString::BitString() : size(8) {
    bs = new char[size];
    for (int i = 0; i < size; i++) {
        bs[i] = '0';
    }
}

BitString::BitString(const std::string& inputString) : size(8) {
    bs = new char[size];
    fromString(inputString);
}

BitString::BitString(const BitString& other) : size(other.size) {
    bs = new char[size];
    for (int i = 0; i < size; i++) {
        bs[i] = other.bs[i];
    }
}

BitString::~BitString() {
    delete[] bs;
}

void BitString::fromString(const std::string& inputString) {
    if (inputString.length() > size) {
        throw std::invalid_argument("Длина строки не должна превышать " + std::to_string(size) + " символов!");
    }
    
    for (char c : inputString) {
        if (c != '0' && c != '1') {
            throw std::invalid_argument("Строка должна содержать только '0' и '1'.");
        }
    }

    // Заполняем битовую строку
    int i = 0;
    for (; i < inputString.length(); i++) {
        bs[i] = inputString[i];
    }
    // Дополняем нулями если нужно
    for (; i < size; i++) {
        bs[i] = '0';
    }
}

void BitString::input(int n) {
    std::string prompt = "Введите " + std::to_string(n) + "-ую строку\n";
    std::cout << prompt;
    std::string userInput;
    std::cin >> userInput;
    fromString(userInput);
}

void BitString::output(int n) const {
    std::string promptText = std::to_string(n) + "-ая строка (с нулями)\n";
    std::cout << promptText;
    for (int i = 0; i < size; i++) {
        std::cout << bs[i];
    }
    std::cout << "\n";
}

BitString BitString::conjunction(const BitString& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Размеры битовых строк должны совпадать для операции конъюнкции.");
    }
    
    BitString result;
    for (int i = 0; i < size; ++i) {
        result.bs[i] = (bs[i] == '1' && other.bs[i] == '1') ? '1' : '0';
    }
    return result;
}

BitString& BitString::operator=(const BitString& other) {
    if (this == &other) return *this;
    
    if (size != other.size) {
        throw std::invalid_argument("Размеры битовых строк должны совпадать для присваивания.");
    }
    
    for (int i = 0; i < size; i++) {
        bs[i] = other.bs[i];
    }
    return *this;
}