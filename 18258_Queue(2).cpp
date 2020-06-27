#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q;

void push(string order) {
	int x = 0;
	for (int i = 5; i < order.size() ; i++) {
		x = x * 10 + int(order[i]);
	}
	q.push(x);
}

void pop(string order) {
	if (q.empty()) {
		cout << "-1\n";
		return;
	}
	q.pop();
}
void size(string order) {
	cout << q.size() << "\n";
}
void empty(string order) {
	if (q.empty()) cout << "1\n";
	else cout << "0\n";
}
void front(string order) {
	if (q.empty()) {
		cout << "-1\n";
		return;
	}
	cout << q.front() << "\n";
}
void back(string order) {
	if (q.empty()) {
		cout << "-1\n";
		return;
	}
	cout << q.back() << "\n";
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char order;
		//getline(cin, order);
		cin.getline()
		if (order[1] == 'u') {
			push(order);
		}
		else if (order[1] == 'o') {
			pop(order);
		}
		else if (order[1] == 'i') {
			size(order);
		}
		else if (order[0] == 'e') {
			empty(order);
		}
		else if (order[0] == 'f') {
			front(order);
		}
		else if (order[0] == 'b') {
			back(order);
		}
	}
}