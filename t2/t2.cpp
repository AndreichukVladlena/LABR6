#include <iostream>
#include <string>
using namespace std;
int main() {
	int str_l = 3;
	char* str = (char*)malloc(str_l * sizeof(char));
	str[0] = ' ';
	cout << "Enter the string : \n";
	for (int l = 1; '\n' - (str[l] = getchar()); l++) {
		str = (char*)realloc(str, str_l++ * sizeof(char));
	}
	int word_l = 2;
	char* nword = (char*)malloc(word_l * sizeof(char));
	cout << "Enter new word : \n";
	for (int l = 0; '\n' - (nword[l] = getchar()); l++) {
		nword = (char*)realloc(nword, word_l++ * sizeof(char));
	}
	int length;
	cout << "Enter length : \n";
	cin >> length;
	int res_l = 2;
	char* res = (char*)malloc(res_l * sizeof(char));
	int space;
	int sh_res = 0;
	for (int i = 0; i < str_l - 1; i++) {
		if (str[i] == ' '||str[i]=='\n') {
			space = i;
			res = (char*)realloc(res, res_l++ * sizeof(char));
			res[sh_res] = ' ';
			sh_res++;
			if (str[i - 1 - length] == ' ') {
				sh_res = sh_res - length - 1;
				res = (char*)realloc(res, res_l += word_l - 2 * sizeof(char));
				for (int k = 0; k < word_l - 1; k++, sh_res++) {
					if (nword[k] == '\n') {
						res[sh_res] = ' ';
					}
					else {
						res[sh_res] = nword[k];
					}
				}
				res[sh_res] = ' ';
			}

		}
		else {
			res = (char*)realloc(res, res_l++ * sizeof(char));
			res[sh_res++] = str[i];
		}
	}
	res = (char*)realloc(res, res_l++ * sizeof(char));
	res[sh_res] = '\0';
	cout << res;
	free(nword);
	free(str);
	return 0;
}
