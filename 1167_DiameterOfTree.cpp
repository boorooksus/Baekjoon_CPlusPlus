#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
#define INF 10001
using namespace std;

vector<pair<int, int> > arr[MAX];
//int visit[MAX];
int maxV;


int dijkstra(int x) {
	int d[MAX];
	for (int i = 1; i < MAX; i++) {
		d[i] = INF;
	}
	priority_queue<pair<int, int> > pq;
	d[x] = 0;
	pq.push(make_pair(0, x));

	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (dist > d[cur]) continue;
		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].second;
			int nd = arr[cur][i].first + dist;
			if (nd < d[next]) {
				d[next] = nd;
				pq.push(make_pair(-nd, next));
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < MAX; i++) {
		if (d[i] == INF) break;
		if (d[i] > ans) {
			ans = d[i];
			maxV = i;
		}
	}
	return ans;
}

int main() {
	int v;
	cin >> v;
	for (int i = 0; i < v; i++) {
		int a, b = 0, c;
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) break;
			cin >> c;
			arr[a].push_back(make_pair(c, b));
			arr[b].push_back(make_pair(c, b));
		}	
	}
	int ans = 0;
	dijkstra(1);

	cout << dijkstra(maxV) << "\n";
}