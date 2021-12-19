#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int znam = 1;
int fact(int a) {
	int b = a-1;
	for (int i = b; i > 0; i--)a *= i;
	return a;
}
int rep(string word) {
	for (int i = 0; i < size(word); i++) {
		int am_of_sym = 1;
		for (int j = i + 1; j < size(word); j++) {
			if (word[j] == word[i]) {
				am_of_sym++;
				word.erase(j, 1);
				j--;
			}
		}
		if (am_of_sym > 1) {
			am_of_sym = fact(am_of_sym);
			znam *= am_of_sym;
			am_of_sym = 1;
		}
	}
	return znam;
}
	int main()
	{
		string word;
		cout << "Enter the word : \n";
		getline(cin, word);
		int length = size(word);
		length = fact(length);
		int znam = rep(word);
		cout << "\nRESULT : \n";
		cout << length / znam;
		return 0;
	}