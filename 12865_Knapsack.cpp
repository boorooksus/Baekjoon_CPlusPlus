#include <iostream>
#include <algorithm>
using namespace std;

int item[100][2];
int d[100][2];
int ans = 0;


void dfs(int cur, int cur_w, int cur_v, int desti, int k) {
	if (cur > desti || cur_w + item[cur][0] > k) {
		if (d[desti][1] < cur_v) {
			d[desti][1] = cur_v;
			d[desti][0] = cur_w;
			ans = max(ans, d[desti][1]);
		}
		return;
	}

	for (int i = cur + 1; i <= desti + 1; i++) {
		dfs(i, cur_w + item[cur][0], cur_v + item[cur][1], desti, k);
	}

	return;
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> item[i][0] >> item[i][1];
	}

	d[0][0] = item[0][0];
	d[0][1] = item[0][1];
	for (int i = 1; i < n; i++) {
		if (d[i - 1][0] + item[i][0] <= k) {
			d[i][0] = d[i - 1][0] + item[i][0];
			d[i][1] = d[i - 1][1] + item[i][1];
			ans = max(ans, d[i][1]);
		}
		else {
			for (int j = 0; j <= i; j++) {
				dfs(j, 0, 0, i, k);
			}
		}
	}

	cout << ans << "\n";
}


//시간 초과