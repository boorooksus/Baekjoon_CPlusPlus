#include <iostream>
#include <string>
#include <math.h>
using namespace std;

long long save;

long long multi(string x, string y, long long c) {
	long long res = 0;

	for (int i = 0; x[i] != '\0'; i++) {
		long long temp = 0;
		for (int j = 0; y[j] != '\0'; j++) {
			temp = ((temp * 10) % c + (long long)((x[i] - 48) * (y[j] - 48))) % c;
		}
		res = ((res * 10) % c + temp) % c;
	}

	return res;
}


int main() {
	string a;
	long long b, c;
	cin >> a >> b >> c;
	

	if (b == 1) {
		cout << a << "\n";
	}
	else{
		long long ans = multi(a, a, c);
		for(long long i = 3; i <= b; i++) {
			string ans_str = to_string(ans);
			ans = multi(ans_str, a, c);
		}
		cout << ans << "\n";
	}
}