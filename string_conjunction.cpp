#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int SIZE = 8;
    char str1[SIZE + 1] = {'\0'}; // +1 для нуль-терминатора
    char str2[SIZE + 1] = {'\0'};
    char result[SIZE + 1] = {'\0'};
    char temp1[100], temp2[100];

    // Ввод первой строки
    cin >> temp1;
    
    // Проверка первой строки
    if (strlen(temp1) > SIZE) {
        cout << "Строка не должна превышать 8 символов!" << endl;
        return 1;
    }
    for (int i = 0; i < strlen(temp1); ++i) {
        if (temp1[i] != '0' && temp1[i] != '1') {
            cout << "Строка должна содержать только '0' и '1'." << endl;
            return 1;
        }
    }
    
    // Дополнение первой строки нулями
    int zeros_to_add = SIZE - strlen(temp1);
    for (int i = 0; i < zeros_to_add; ++i) {
        str1[i] = '0';
    }
    for (int i = zeros_to_add; i < SIZE; ++i) {
        str1[i] = temp1[i - zeros_to_add];
    }
    str1[SIZE] = '\0';

    // Ввод и проверка второй строки (аналогично)
    cin >> temp2;
    if (strlen(temp2) > SIZE) {
        cout << "Строка не должна превышать 8 символов!" << endl;
        return 1;
    }
    for (int i = 0; i < strlen(temp2); ++i) {
        if (temp2[i] != '0' && temp2[i] != '1') {
            cout << "Строка должна содержать только '0' и '1'." << endl;
            return 1;
        }
    }
    
    // Дополнение второй строки нулями
    zeros_to_add = SIZE - strlen(temp2);
    for (int i = 0; i < zeros_to_add; ++i) {
        str2[i] = '0';
    }
    for (int i = zeros_to_add; i < SIZE; ++i) {
        str2[i] = temp2[i - zeros_to_add];
    }
    str2[SIZE] = '\0';

    // Конъюнкция
    for (int i = 0; i < SIZE; ++i) {
        result[i] = (str1[i] == '1' && str2[i] == '1') ? '1' : '0';
    }
    result[SIZE] = '\0';

    // Вывод (требование 6)
    cout << "Первая строка (с нулями): " << str1 << endl;
    cout << "Вторая строка (с нулями): " << str2 << endl;
    cout << "Результат: " << result << endl;

    return 0;
}