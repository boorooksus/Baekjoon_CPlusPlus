#include <iostream>
using namespace std;

int arr[1000];
int d[1000];

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && temp < d[j]) {
				temp = d[j];
			}
		}
		d[i] = temp + 1;
		if (d[i] > ans) ans = d[i];
	}
	cout << ans << "\n";
}