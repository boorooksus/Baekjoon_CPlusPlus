#include <iostream>
#include <string>
#include <vector>;
#include <queue>;
using namespace std;

int d[1000];
vector<pair<int, int> > v;

int main() {
	string a, b;
	cin >> a >> b;
	int ans = 0;

	d[0] = 1;
	for (int i = 0; b[i] != '\0'; i++) {
		if (a[0] == b[i]) {
			d[0] = 1;
		}
	}
	queue<int> q;
	for (int i = 1; a[i] != '\0'; i++) {
		for (int j = 0; b[j] != '\0'; j++) {
			if (a[i] == b[j]) {
				q.push(j);
			}
		}
		if (q.empty()) continue;
		while (!q.empty()) {
			int idx = q.front();
			q.pop();
			for (int j = 0; j < idx; j++) {
				if (d[j] > d[idx]) {
					d[idx] = d[j];
				}
			}
		}
		d[i]++;
		if (ans < d[i]) ans = d[i];

	}
	for (int i = 0; i < b.length(); i++) {
		cout << d[i] << " ";
	}
	cout << "\n";
	cout << ans;
}