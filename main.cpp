#include "string_conjunction.h"

int main() {
    BitString a, b;
    a.input(1);
    b.input(2);
    
    BitString c = a.conjunction(b);
    
    a.output(1);
    b.output(2);
    std::cout << "Результат: ";
    c.output(3);
    
    return 0;
}