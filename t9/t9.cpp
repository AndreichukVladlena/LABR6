#include <iostream>
#include <string>
using namespace std;
int sum = 0;
int summa(string s, int am, int i) {
	for (int k = i-am; k < i; k++) {
		sum += (s[k] - '0') * pow(10, am - 1);
		am--;
	}
	return sum;
}
int main()
{
	setlocale(LC_ALL, "");
	string s;
	cout << "Enter the string : \n";
	getline(cin, s);
	for (int i = 0; i < size(s); i++) {
		int am = 0;
		if (isdigit(s[i]) != 0) {
			while (isdigit(s[i]) != 0) {
				am++;
				i++;
			}
 			sum=summa(s, am, i);
		}
	}
	cout << "\nRESULT : \n" << sum;
	return 0;
}