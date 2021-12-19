﻿#include<iostream>
#include<string>
using namespace std;
int inputInt(int minValue, int maxValue) {
	int x;
	while (true)
	{
		cin >> x;
		if (x < maxValue && x > minValue)
			return x;
		cout << "Enter correct word" << endl;
	}
}
int findWordAmount(const int& L, const int& m, const string s1, const string s2) {
	int  indexFirstPref = 0, indexSecondPref = 0, amount = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == s2[indexFirstPref]) {
			for (int j = i; j < s1.length(); j++)
			{
				if (s1[j] == s2[indexFirstPref])
				{
					indexFirstPref++;
				}
				else {
					indexFirstPref = 0;
					break;
				}
			}

		}
	}

	int length = L - (s1.length() + s2.length() - indexFirstPref);
	if (length > 0)
		amount = pow(26, length) * 2;
	else if (length == 0)
		amount = 1;
	else
		amount = 0;
	return amount % m;
}

int main() {
	int counter = inputInt(0, 101);
	while (counter > 0) {
		int L = inputInt(0, 10e9 + 1), m = inputInt(0, 10e4 + 1);
		string s1, s2;
		cin.ignore(32767, '\n');
		getline(cin, s1);
		getline(cin, s2);
		cout << findWordAmount(L, m, s1, s2);
		counter--;
	}
}
