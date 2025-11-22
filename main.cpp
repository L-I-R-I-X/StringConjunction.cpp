#include "string_conjunction.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        BitString a, b;
        
        std::cout << "Enter 1 string: ";
        std::cin >> a;
        std::cout << "Enter 2 string: ";
        std::cin >> b;
        
        BitString c = a & b;
        
        std::cout << "1 string (with zeros): " << a << std::endl;
        std::cout << "2 string (with zeros): " << b << std::endl;
        std::cout << "Result: " << c << std::endl;
        
        std::cout << "First character of result: " << c[0] << std::endl;
        c[0] = '1';
        std::cout << "Modified result: " << c << std::endl;
        
        BitString d = a.conjunction(b);
        std::cout << "Using conjunction method: " << d << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}