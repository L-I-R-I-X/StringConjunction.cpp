#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;

class BitString {
private:
    string bs;

    void fromString(const string& inputString) {
        if (inputString.length() > SIZE) {
            cout << "Длина строки не должна превышать " << SIZE << " символов!\n";
            return;
        }
        for (char c : inputString) {
            if (c != '0' && c != '1') {
                cout << "Строка должна содержать только '0' и '1'.\n";
                return;
            }
        }
        bs = inputString;
        bs.append(SIZE - inputString.length(), '0');
        bs = bs.substr(0, SIZE);
    }

public:
    BitString(const string& inputString = "") {
        bs = string(SIZE, '0');
        if (!inputString.empty()) {
            fromString(inputString);
        }
    }

    void input(int n) {
        string prompt = "Введите " + to_string(n) + "-ую строку\n";
        cout << prompt;
        string userInput;
        cin >> userInput;
        fromString(userInput);
    }

    void output(int n) {
        string promptText = to_string(n) + "-ая строка (с нулями)\n";
        cout << promptText;
        cout << bs << "\n";
    }

    BitString conjunction(const BitString& other) const {
        BitString result;
        for (int i = 0; i < SIZE; ++i) {
            result.bs[i] = (bs[i] == '1' && other.bs[i] == '1') ? '1' : '0';
        }
        return result;
    }
};

int main() {
    BitString a, b;
    a.input(1);
    b.input(2);
    BitString c = a.conjunction(b);
    a.output(1);
    b.output(2);
    cout << "Результат: ";
    c.output(3);
    return 0;
}
