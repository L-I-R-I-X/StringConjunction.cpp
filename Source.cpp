#include "string_conjunction.h"
#include <iostream>
#include <string>
#include <stdexcept>

BitStringBase::BitStringBase() : size(8) {
    bs = new char[size];
    for (int i = 0; i < size; i++) {
        bs[i] = '0';
    }
}

BitStringBase::BitStringBase(const std::string& inputString) : size(8) {
    bs = new char[size];
    fromString(inputString);
}

BitStringBase::BitStringBase(const BitStringBase& other) : size(other.size) {
    bs = new char[size];
    for (int i = 0; i < size; i++) {
        bs[i] = other.bs[i];
    }
}

BitStringBase::~BitStringBase() {
    delete[] bs;
}

void BitStringBase::fromString(const std::string& inputString) {
    if (inputString.length() > static_cast<size_t>(size)) {
        throw std::invalid_argument("String length must not exceed " + std::to_string(size) + " characters!");
    }
    
    for (char c : inputString) {
        if (c != '0' && c != '1') {
            throw std::invalid_argument("String must contain only '0' and '1'.");
        }
    }

    int inputLength = static_cast<int>(inputString.length());
    int padding = size - inputLength;
    
    for (int i = 0; i < padding; i++) {
        bs[i] = '0';
    }
    
    for (int i = 0; i < inputLength; i++) {
        bs[padding + i] = inputString[i];
    }
}

char& BitStringBase::getChar(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return bs[index];
}

const char& BitStringBase::getChar(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return bs[index];
}

void BitStringIO::input(int n) {
    std::string prompt = "Enter " + std::to_string(n) + " string\n";
    std::cout << prompt;
    std::string userInput;
    std::cin >> userInput;
    fromString(userInput);
}

void BitStringIO::output(int n) const {
    std::string promptText = std::to_string(n) + " string (with zeros)\n";
    std::cout << promptText;
    for (int i = 0; i < getSize(); i++) {
        std::cout << getChar(i);
    }
    std::cout << "\n";
}

std::ostream& operator<<(std::ostream& os, const BitStringIO& bitStr) {
    for (int i = 0; i < bitStr.getSize(); i++) {
        os << bitStr.getChar(i);
    }
    return os;
}

std::istream& operator>>(std::istream& is, BitStringIO& bitStr) {
    std::string input;
    is >> input;
    bitStr.setFromString(input);
    return is;
}

BitString BitString::conjunction(const BitString& other) const {
    if (getSize() != other.getSize()) {
        throw std::invalid_argument("BitString sizes must be equal for conjunction.");
    }
    
    BitString result;
    for (int i = 0; i < getSize(); ++i) {
        result.getChar(i) = (getChar(i) == '1' && other.getChar(i) == '1') ? '1' : '0';
    }
    return result;
}

BitString& BitString::operator=(const BitString& other) {
    if (this == &other) return *this;
    
    if (getSize() != other.getSize()) {
        throw std::invalid_argument("BitString sizes must be equal for assignment.");
    }
    
    for (int i = 0; i < getSize(); i++) {
        getChar(i) = other.getChar(i);
    }
    return *this;
}

BitString BitString::operator&(const BitString& other) const {
    return this->conjunction(other);
}

char& BitString::operator[](int index) {
    return getChar(index);
}

const char& BitString::operator[](int index) const {
    return getChar(index);
}