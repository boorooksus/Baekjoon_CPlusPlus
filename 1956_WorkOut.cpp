#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<pair<int, int> > city[401];
int d[401];
int id;
bool finished[401];
stack<pair<int, int> > s;
int result = 4000001;

int cycle(int, int, int, int);

int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a].push_back(make_pair(c, b));
	}

	for (int i = 0; i < v; i++) {
		if (d[i] == 0) {
			cycle(i, 0, v, e);
		}
	}
	cout << result << "\n";
}

int cycle(int x, int dist, int v, int e) {
	d[x] = ++id;
	int parent = id;
	s.push(make_pair(dist, x));

	for (int i = 0; i < city[x].size(); i++) {
		int next = city[x][i].second;
		int nd = city[x][i].first;
		if (d[next] == 0) {
			parent = min(parent, cycle(next, nd, v, e));
		}
		else if (finished[next] == 0) {
			parent = min(parent, d[next]);
		}
	}

	if (parent == d[x]) {
		vector<pair<int, int> > scc;
		int sv = 0, se = 0;
		while (1) {
			sv = s.top().second;
			se += s.top().first;
			s.pop();
			scc.push_back(make_pair(se, sv));
			finished[sv] = 1;
			if (x == sv) break;
		}
		if (scc.size() > 1 && se < result) {
			result = se;
		}

	}
	return parent;

}