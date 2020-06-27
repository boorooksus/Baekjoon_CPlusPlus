#include <iostream>
#include <queue>
using namespace std;

int d[1000000];

int main() {
	int x;
	cin >> x;
	int ans = 0;
	queue<int> q;
	d[2] = 1;
	d[3] = 1;
	for (int i = 4; i <= x; i++) {
		if (i % 3 == 0) {
			q.push(d[i / 3]);
		}
		if (i % 2 == 0) {
			q.push(d[i / 2]);
		}
		q.push(d[i - 1]);
		int minCnt = 1000000;
		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			if (temp < minCnt) {
				minCnt = temp;
			}
		}
		d[i] = minCnt + 1;
	}
	cout << d[x] << "\n";
}
