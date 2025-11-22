#ifndef STRING_CONJUNCTION_H
#define STRING_CONJUNCTION_H

#include <string>
#include <iostream>

class IBitString {
public:
    virtual ~IBitString() = default;
    
    virtual void fromString(const std::string& inputString) = 0;
    virtual void setFromString(const std::string& inputString) = 0;
    virtual char& getChar(int index) = 0;
    virtual const char& getChar(int index) const = 0;
    virtual int getSize() const = 0;
    
    virtual void input(int n) = 0;
    virtual void output(int n) const = 0;
};

class BitStringBase : public IBitString {
protected:
    char* bs;
    int size;

public:
    BitStringBase();
    BitStringBase(const std::string& inputString);
    BitStringBase(const BitStringBase& other);
    virtual ~BitStringBase();

    void fromString(const std::string& inputString) override;
    void setFromString(const std::string& inputString) override;
    char& getChar(int index) override;
    const char& getChar(int index) const override;
    int getSize() const override;
};

class BitStringIO : public BitStringBase {
public:
    BitStringIO();
    BitStringIO(const std::string& inputString);
    BitStringIO(const BitStringIO& other);
    ~BitStringIO() override;

    void input(int n) override;
    void output(int n) const override;
    
    friend std::ostream& operator<<(std::ostream& os, const BitStringIO& bitStr);
    friend std::istream& operator>>(std::istream& is, BitStringIO& bitStr);
};

class BitString : public BitStringIO {
public:
    BitString();
    BitString(const std::string& inputString);
    BitString(const BitString& other);
    ~BitString() override;

    BitString conjunction(const BitString& other) const;
    
    BitString& operator=(const BitString& other);
    BitString operator&(const BitString& other) const;
    char& operator[](int index);
    const char& operator[](int index) const;
};

#endif