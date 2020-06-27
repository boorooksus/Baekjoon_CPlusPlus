#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

stack<int> s;

void save(int x) {
	if (x == 0 && s.size()) {
		s.pop();
		return;
	}
	else if (x == 0 && !s.size()) {
		return;
	}
	else {
		s.push(x);
		return;
	}
}

int main() {
	int k;
	cin >> k; // number of integers
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		save(x);
	}
	int ans = 0;
	while (s.size()) {
		ans += s.top();
		s.pop();
	}
	cout << ans << "\n";
}