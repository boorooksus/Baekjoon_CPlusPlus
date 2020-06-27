#include <iostream>
#include <vector>
#include <string.h>
#define INF 1000001
using namespace std;

int ans = INF;
vector<int> c[3];
int mc[1001];
int mi[10001];

int rgb(int x) {
	if (mc[x]) return mc[x];
	int comp[2];
	int idx[2];
	comp[0] = rgb(x - 1);
	if (c[x][(mi[x - 1] + 1) % 3] < c[x][(mi[x - 1] + 2) % 3]) {
		idx[0] = (mi[x - 1] + 1) % 3;
		comp[0] += c[x][(mi[x - 1] + 1) % 3];
	}
	else {
		idx[0] = (mi[x - 1] + 2) % 3;
		comp[0] += c[x][(mi[x - 1] + 2) % 3];
	}

	int temp = 0;
	comp[1] = rgb(x - 2);
	if ((mi[x - 2] + 1) % 3 == idx[0]) {
		temp = (mi[x - 2] + 2) % 3;
	}
	else {
		temp = (mi[x - 2] + 1) % 3;
	}
	comp[1] += c[x - 1][idx[1]];
	if (c[x][(mi[x - 1] + 1) % 3] < c[x][(mi[x - 1] + 2) % 3]) {
		idx[0] = (mi[x - 1] + 1) % 3;
		comp[0] += c[x][(mi[x - 1] + 1) % 3];
	}
	else {
		idx[0] = (mi[x - 1] + 2) % 3;
		comp[0] += c[x][(mi[x - 1] + 2) % 3];
	}

}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		c[0].push_back(r);
		c[1].push_back(g);
		c[2].push_back(b);
	}
	int temp = 0;
	for (int i = 0; i < 2; i++) {
		if (c[i][0] <= c[i][1] && c[i][0] <= c[i][2]) {
			mc[i] = temp + c[i][0];
			mi[i] = 0;
		}
		else if (c[i][1] <= c[i][0] && c[i][1] <= c[i][2]) {
			mc[i] = temp + c[i][1];
			mi[i] = 1;
		}
		else {
			mc[i] = temp + c[i][2];
			mi[i] = 2;
		}
		temp += mc[i];
	}
	cout << rgb(n) << "\n";
}

// 1 1
// 2 10000
//이전 집까지 최소값, 
//이전의 이전 집까지 최솟값-> 이전 집의 다른 색 값
//min(i, k) = min(min(i - 1, l), min(i - 2, m) + cost(i, n))