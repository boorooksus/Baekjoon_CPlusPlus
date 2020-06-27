#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void isPalindrome(long long x) {
	string num_str = to_string(x);
	for (int i = 0; i < num_str.length() / 2; i++) {
		//cout << num_str[num_str.length() - i - 1] << "\n";
		if (num_str[i] != num_str[num_str.length() - i - 1])
	
	}
}

int main() {
	long long x;
	cin >> x;
	while (x < pow(10, 50)) {
		x++;
		if (isPalindrome(x)) {
			cout << x << "\n";
			return 0;
		}
	}
}