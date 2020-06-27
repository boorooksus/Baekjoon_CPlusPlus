#include <iostream>
#include <algorithm>
using namespace std;

int t[501][501];
int d[501][501];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> t[i][j];
		}
	}
	d[0][0] = t[0][0];
	for (int i = 1; i < n; i++) {
		d[i][0] = d[i - 1][0] + t[i][0];
		for (int j = 1; j < i; j++) {
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + t[i][j];
		}
		d[i][i] = d[i - 1][i - 1] + t[i][i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < d[n - 1][i]) ans = d[n - 1][i];
	}
	cout << ans << "\n";
}