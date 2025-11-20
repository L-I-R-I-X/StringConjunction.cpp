[string_conjunction.h]
#ifndef STRING_CONJUNCTION_H
#define STRING_CONJUNCTION_H

#include <string>
#include <iostream>

class BitStringBase {
protected:
    char* bs;
    int size;

    void fromString(const std::string& inputString);

public:
    BitStringBase();
    BitStringBase(const std::string& inputString);
    BitStringBase(const BitStringBase& other);
    virtual ~BitStringBase();

    char& getChar(int index);
    const char& getChar(int index) const;
    int getSize() const { return size; }
};

class BitStringIO : public BitStringBase {
public:
    using BitStringBase::BitStringBase;

    void input(int n);
    void output(int n) const;
    
    void setFromString(const std::string& inputString) {
        fromString(inputString);
    }
};

std::ostream& operator<<(std::ostream& os, const BitStringIO& bitStr);
std::istream& operator>>(std::istream& is, BitStringIO& bitStr);

class BitString : public BitStringIO {
public:
    using BitStringIO::BitStringIO;

    BitString conjunction(const BitString& other) const;
    
    BitString& operator=(const BitString& other);
    BitString operator&(const BitString& other) const;
    char& operator[](int index);
    const char& operator[](int index) const;
};

#endif