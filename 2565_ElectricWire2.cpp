#include <iostream>
#include <algorithm>
using namespace std;

int wire[501];
int d[501];

int main() {
	//fill_n(wire, 501, 501);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		wire[a] = b;
		cnt++;
	}
	d[1] = 1;
	int max = 0;
	for (int i = 2; i < 501; i++) {
		for (int j = 1; j < i; j++) {
			// ==== 1 ====================================
			if (wire[j] < wire[i] && d[j] > d[i] && wire[j] != 0) {
				d[i] = d[j];
			}
		}
		d[i]++;
		if (d[i] > max) max = d[i];
	}
	cout << cnt - max << "\n";
}

//동적할당, LIS
// 1 : wire[j] != 0 이 조건 추가해 줘야 선이 없는 wire[j]를 포함 안시킨다.