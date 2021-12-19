#include <iostream>

using namespace std;

int count(int index, char* str, char el)
{
    int kol = 0;
    for (int i = index; str[i] != ' '; ++i)
        if (str[i] == el)kol++;

    return kol;
}
int main()
{
    char* str = new char[100];

    cout << "Enter the line (end the line with a character *):\n";
    cin.getline(str, 100, '*');
    int code = 0, kol = 0;
    char el;

    cout << "New line:\n";

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ' ' || str[i] != '\0') {
            if (str[i] != str[i + 1])
                cout << str[i];
            else
            {
                code = str[i];
                el = str[i];
                kol = count(i, str, el);
                cout << "(255, " << code << ", " << kol << ")";
                i += kol - 1;
            }
        }
    }
    delete[] str;
}
