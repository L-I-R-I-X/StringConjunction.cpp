#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;
const string inPromptTemplate = "Введите {N}-ую строку\n";
const string outPromptTemplate = "{N}-ая строка (с нулями)";
const string outPromptRes = "Результат";

string inputString(int n) {
    string prompt = inPromptTemplate;
    // Находим маркер {N}
    size_t pos = prompt.find("{N}");
    if (pos != string::npos) {
        // Заменяем {N} на номер строки
        prompt.replace(pos, 3, to_string(n));
    }
    cout << prompt;
    string input;
    cin >> input;
    return input;
}

bool checkString(const string& str) {
    if (str.length() > SIZE) {
        cout << "Длина строки не должна превышать " << SIZE << " символов!\n";
        return false;
    }
    for (char c : str) {
        if (c != '0' && c != '1') {
            cout << "Строка должна содержать только '0' и '1'.\n";
            return false;
        }
    }
    return true;
}

string aadZeros(const string& str) {
    if (str.length() < SIZE) {
        cout << "Длина строки менее " << SIZE << " символов\n";
        cout << "Будет выполнено дополнение незначащими нулями\n";
        int zeros_to_add = SIZE - str.length();
        string zeros(zeros_to_add, '0');
        return zeros + str;
    }
    return str;
}

string conjunction(const string& str1, const string& str2) {
    string result = "";
    for (int i = 0; i < SIZE; ++i) {
        result += (str1[i] == '1' && str2[i] == '1') ? '1' : '0';
    }
    return result;
}

void outputString(const string& str, int n) {
    string prompt_text = outPromptTemplate;
    size_t pos = prompt_text.find("{N}");
    if (pos != string::npos) {
        prompt_text.replace(pos, 3, to_string(n));
    }
    cout << prompt_text << "\n";
    cout << str << "\n";
}

void outputRes(const string& res) {
    cout << outPromptRes << ": " << res << "\n";
}

int main() {
    string temp1 = inputString(1);
    while (!checkString(temp1)) {
        temp1 = inputString(1);
    }
    string str1 = aadZeros(temp1);

    string temp2 = inputString(2);
    while (!checkString(temp2)) {
        temp2 = inputString(2);
    }
    string str2 = aadZeros(temp2);

    string res = conjunction(str1, str2);

    outputString(str1, 1);
    outputString(str2, 2);
    outputRes(res);

    return 0;
}