#include <iostream>
#include <string>
using namespace std;
string input(int min, int max) {
	string text;
	while (true){
		cin >> text;
		if (text.length() < max && text.length() > min)
			return text;
		cin.clear();
		cin.ignore(32000, '\n');
		text = "";
		cout << "Enter correct word" << endl;
	}
}

int inputInt() {
	while (true) {
		int value;

		cin >> value;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Error. Enter again : \n";
		}
		else {
			cin.ignore(32767, '\n');

			return value;
		}
	}
}

int main() {
	int n, m = 1;
	string s, t;
	cout << "Enter n: ";
	n = inputInt();

	int* arr = new int[1];

	while (true) {
		int j = 1, p = -1;

		s = input(0, 501);
		t = input(0, 1000);

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == t[0]) {
				p = i;
				break;
			}
		}

		for (int i = 0; i < t.length() - 1; i++) {
			if (s[p + 1] == t[j]) {
				p++;
				j++;
			}
			else break;
		}

		if (j != t.length()) {
			for (int i = 0; i < t.length() - 1; i++) {
				if (j < t.length() && p > 0 && (s[p - 1] == t[j])) {
					j++;
					p--;
				}
				else break;
			}
		}

		if (j == t.length()) {
			arr[m - 1] = 1;
		}
		else {
			arr[m - 1] = 0;
		}
		if (m < n) ++m;
		else break;

		if (m != 1) arr = (int*)realloc(arr, m * sizeof(int));
	}

	for (int i = 0; i < m; ++i) {
		if (arr[i] == 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}