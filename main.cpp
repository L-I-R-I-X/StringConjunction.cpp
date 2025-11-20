#include "string_conjunction.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        BitString a, b;
        a.input(1);
        b.input(2);
        
        BitString c = a.conjunction(b);
        
        a.output(1);
        b.output(2);
        std::cout << "Result: ";
        c.output(3);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}