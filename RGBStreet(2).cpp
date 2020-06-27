#include <iostream>
#include <algorithm>
using namespace std;


int c[1001][3]; //각 집의 비용 저장
int d[10001][3]; //i번째가지 집의 페인트 비용을 동적할당

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i][0] >> c[i][1] >> c[i][2];
	}
	for (int i = 0; i < 3; i++) {
		d[0][i] = c[0][i];
	}
	for (int i = 1; i < n; i++) {
		d[i][0] = min(d[i - 1][1] + c[i][0], d[i - 1][2] + c[i][0]);
		d[i][1] = min(d[i - 1][0] + c[i][1], d[i - 1][2] + c[i][1]);
		d[i][2] = min(d[i - 1][0] + c[i][2], d[i - 1][1] + c[i][2]);
	}
	// ===== 1 ===========================================
	cout << min(d[n - 1][0], min(d[n - 1][1], d[n - 1][2]));
}

//동적할당
// 1 : min 함수는 인수를 2개만 받음