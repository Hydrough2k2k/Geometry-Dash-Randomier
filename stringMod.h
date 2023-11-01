#include <iostream>
#include <cstring>
#include <string>

using std::cout; std::string;

void removeSpecialChars(string &str) {
	if (str.size() == 0) return;

	str.erase(std::remove_if(str.begin(), str.end(),
		[](char c) { return !std::isspace(c) && !std::isalpha(c) && !std::isdigit(c); }),
		str.end());
}

void removeWhitespace(string& str) {
	if (str.size() == 0) return;

	while (str[0] == ' ' || str[0] == '\t')
		str.erase(0, 1);
}

void splitStringAt(string& str1, string& str2, char ch) {
	str2 = str1;
	int erasedChars = 0;
	while (str2[0] != ch) {
		erasedChars++;
		str2.erase(0, 1);
		if (str2.size() == 0)
			return;
	}
	str2.erase(0, 1);
	str1.erase(erasedChars, str1.size());
}

void numberToStringSeparated(string &str, size_t num) {
	if (num == 0) str += "0";
	bool firstPrint = true;
	for (int i = (int)(log10(num)) / 3; i >= 0; i--) {
		unsigned long long temp = (unsigned long long)((num / (pow(1000, i))));
		firstPrint ? str += to_string(temp) : str += ((to_string(temp / 100) + to_string((temp / 10) % 10)) + to_string(temp % 10));
		num -= ((unsigned long long)(temp * (pow(1000, i))));
		if (i != 0) str += " ";
		firstPrint = false;
	}
}