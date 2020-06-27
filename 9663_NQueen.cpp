#include <iostream>
using namespace std;

int m[16][16];
int cnt;

void queen(int cur, int level, int n) {
	if (m[level][cur] != 0) return;
	if (level == n - 1) {
		cnt++;
		return;
	}
	for (int i = level; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (abs(i - level) == abs(j - cur)) {
				m[i][j]++;
			}
			if (j == cur) {
				m[i][j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		queen(i, level + 1, n);
	}
	for (int i = level; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (abs(i - level) == abs(j - cur)) {
				m[i][j]--;
			}
			if (j == cur) {
				m[i][j]--;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		queen(i, 0, n);
	}
	cout << cnt << "\n";
}