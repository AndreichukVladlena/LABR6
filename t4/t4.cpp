#include <iostream>
#include <string>
using namespace std;
string replace(string text, string str_nach, string str_kon) {
	int el = text.find(str_nach);
	while (el != -1) {
		text = text.replace(el, size(str_nach), str_kon);
		el = text.find(str_nach);
	}
	return text;
}
int main()
{
	string text;
	cout << "Enter the text : \n";
	getline(cin, text);
	string ce = "ce"; string se = "se";
	string cy = "cy"; string sy = "sy";
	string ci = "ci"; string si = "si";
	string qu = "qu"; string kv = "kv";
	string q = "q"; string k = "k";
	string w = "w"; string v = "v";
	string ph = "ph"; string  f = "f";
	string you = "you"; string oo = "oo"; string  u = "u";
	string ee = "ee"; string  i = "i";
	string th = "th"; string  z = "z";
	string x = "x"; string  ks = "ks";
	text = replace(text, ce, se);
	text = replace(text, cy, sy);
	text = replace(text, ci, si);
	text = replace(text, qu, kv);
	text = replace(text, q, k);
	text = replace(text, w, v);
	text = replace(text, ph, f);
	text = replace(text, you, u);
	text = replace(text, oo, u);
	text = replace(text, ee, i);
	text = replace(text, th, z);
	text = replace(text, x, ks);
	text.insert(text.size(), "\0");
	data(text);
	cout << "\nRESULT : \n";
	for (int i = 0; i < size(text); i++) {
		if (text[i] != text[i + 1]) cout << text[i];
	}
	return 0;
}
