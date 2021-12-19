#include <iostream>
#include <string>
using namespace std;
//Заполнение массива ' ', тем самым очищение его от предыдущих значений
char clear_array(char* arr, int N) {
	for (int i = 0; i < N; i++) arr[i] = ' ';
	return 0;
}
//Заполнение массива итоговым результатом
char min(char* arr, char* arr_0_1, int i, int min) {
	clear_array(arr_0_1, 81);
	int k = 0;
	for (int a = i - min; a < i; a++) {
		arr_0_1[k] = arr[a];
		k++;
	}
	return 0;
}
//Вывод массива
char array_output(char* arr_0_1, int MIN) {
	cout << "\n";
	for (int i = 0; i < MIN; i++) {
		cout << arr_0_1[i];
	}
	return 0;
}

int main()
{
	int min_0 = 0, MIN_0 = 81, min_1 = 0, MIN_1 = 81;
	char s[81], s0[81], s1[81];
	cout << "Enter the string : ";
	cin >> s;
	int a = strlen(s); //Размерность введенной строки
	for (int i = 0; i < a; ) {
		if (s[i] == '0') {
			while (s[i] == '0') {
				min_0++;
				i++;
			}
			if (min_0 < MIN_0) {
				MIN_0 = min_0;
				min(s, s0, i, min_0);
			}
			min_0 = 0;
		}
		if (s[i] == '1') {
			while (s[i] == '1') {
				min_1++;
				i++;
			}
			if (min_1 < MIN_1) {
				MIN_1 = min_1;
				min(s, s1, i, min_1);
			}
			min_1 = 0;
		}
		if (s[i] != '0' && s[i] != '1') { //Пропуск любых символов кроме 0 и 1
			i++;
		}
	}
	//Поиск минимального ответа и его вывод
	if (MIN_0 < MIN_1) cout << array_output(s0, MIN_0);
	if (MIN_0 > MIN_1) cout << array_output(s1, MIN_1);
	if (MIN_0 == MIN_1) {
		cout << array_output(s0, MIN_0);
		cout << array_output(s1, MIN_1);
	}
	return 0;
}
