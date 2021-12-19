#include <iostream>
#include <string>
using namespace std;

int reserve(string s, int begin, int end, int length) {
	int yes = 0, answer;
	for (int i = begin, j = end; i <= end || j >= begin; i++, j--) {
		if (s[i] == s[j])yes++;
	}
	if (yes == length) {
		return answer = -1;
	}
	else return answer = 0;
}
int substr(string s) {
	s.insert(s.size(), " ");
	s.insert(0, " ");
	int space=0, max = 0;
	for (int i = 1; i < size(s); i++) {
		if (s[i] == ' ') {
			if (i - 1 - space > max) {
				if (reserve(s, space + 1, i - 1, i - 1 - space) == 0) {
					max = i - 1 - space;
				}
				else max = -1;
			}
			space = i;
		}
	}
	return max;
}
int main()
{
	string s, plnd;
	cout << "Enter the string : \n";
	getline(cin, s);
	substr(s);
	int result = substr(s);
	cout << "\nRESULT : \n";
	cout << result;
	return 0;
}
