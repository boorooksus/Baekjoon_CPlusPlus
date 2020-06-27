#include <iostream>
#include <algorithm>
#include <string>
#include <vector>;
#include <queue>;
using namespace std;

int d[1001][1001];

int main() {
	string a, b;
	cin >> a >> b;
	int ans = 0;

	for (int i = 0; a[i] != '\0'; i++) {
		for (int j = 0; b[j] != '\0'; j++) {
			if (a[i] == b[j]) {
				d[i + 1][j + 1] = d[i][j] + 1;
			}
			else {
				d[i + 1][j + 1] = max(d[i][j + 1], d[i + 1][j]);
			}
			if (d[i + 1][j + 1] > ans) ans = d[i + 1][j + 1];
		}
	}

	cout << ans << "\n";
}