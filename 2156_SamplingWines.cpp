#include <iostream>
#include <algorithm>
using namespace std;

//������ �� ����
int wine[10001];
//i��° ���� ������ ���ô� ��� �� i��°�� �ȸ��ô� �ִ� �� : d[i][0]
//i��° ���� ������ ���ô� ��� �� i��°�� ���ô� �ִ� �� : d[i][1]
int d[10001][2];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}

	d[0][0] = 0;
	d[0][1] = wine[0];
	d[1][0] = wine[0];
	d[1][1] = wine[0] + wine[1];
	d[2][0] = wine[0] + wine[1];
	d[2][1] = wine[0] + wine[2];

	for (int i = 2; i < n; i++) {
		d[i][0] = max(d[i - 2][1], d[i - 1][1]);
		d[i][1] = max(d[i - 1][0], max(d[i - 3][1], max(d[i - 2][0] + wine[i - 1], d[i - 2][1]))) + wine[i];
	}
	cout << max(d[n - 1][0], d[n - 1][1]) << "\n";
}
