#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> v[MAX];
int parent[MAX];
bool visit[MAX];

void getParent(int x) {
	//if (parent[x] != 0) return;
	visit[x] = true;

	for (int i = 0; i < v[x].size(); i++) {
		/*if (v[x][i] == 1) {
			parent[x] = 1;
			return;
		}
		else if (parent[v[x][i]] != 0) {
			parent[x] = v[x][i];
			return;
		}*/
		int next = v[x][i];
		if (!parent[next]) {
			parent[next] = x;
			getParent(next);
		}
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	getParent(1);

	for (int i = 2; i < n + 1; i++) {
		cout << parent[i] << "\n";
	}
}