#include <iostream>
using namespace std;

int wire[501];
int d[501][501];
int d2[501][501];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		wire[a] = b;
		for (int j = a + 1; j <= 10; j++) {
			for (int k = 1; k < b; k++) {
				d[j][k]++;
			}
		}
		for (int j = 1; j < a; j++) {
			for (int k = b + 1; k <= 10; k++) {
				d2[j][k]++;
			}
		}
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j < 11; j++) {
			if (j == wire[i]) {
				cout << "!";
			}
			cout << d2[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j < 11; j++) {
			if (j == wire[i]) {
				cout << "!";
			}
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}