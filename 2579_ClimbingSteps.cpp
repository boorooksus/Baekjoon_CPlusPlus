#include <iostream>
#include <algorithm>
using namespace std;

int s[302];
int d[302][2];
//d[x][0] : 바로 직전 계단에서 오를 때 최대값
//d[x][1] : 두 계단 전에서 오를 때 최대값
//f(x - 3) + s[x - 1] + s[x], f(x - 2) + s[x],

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	d[1][0] = s[1];
	d[2][0] = d[1][0] + s[2];
	d[2][1] = s[2];
	for (int i = 3; i <= n; i++) {
		d[i][0] = max(d[i - 3][0], d[i - 3][1]) + s[i - 1] + s[i];
		d[i][1] = max(d[i - 2][0], d[i - 2][1]) + s[i];
	}

	cout << max(d[n][0], d[n][1]) << "\n";
}
 