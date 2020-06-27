#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > weight_value;
int d[100][100001];


int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		weight_value.push_back(make_pair(w, v));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i == 0) {
				if(weight_value[0].first <= j)
					d[0][j] = weight_value[0].second;
				continue;
			}

			if (weight_value[i].first <= j) {
				d[i][j] = max(d[i - 1][j], d[i - 1][j - weight_value[i].first] + weight_value[i].second);
			}

			else {
				d[i][j] = d[i - 1][j];
			}
		}
	}

	cout << d[n - 1][k] << "\n";
}