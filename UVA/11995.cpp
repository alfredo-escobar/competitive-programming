#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int n, tipo, x;

	while (cin>>n) {
		stack<int> st;
		queue<int> qu;
		priority_queue<int> pq;

		bool puedeSerST = true;
		bool puedeSerQU = true;
		bool puedeSerPQ = true;

		while (n>0) {
			cin >> tipo >> x;
			if (tipo == 1) {
				st.push(x);
				qu.push(x);
				pq.push(x);
			}
			else {
				if (not st.empty() && (st.top() == x)) {
					st.pop();
				} else {
					puedeSerST = false;
				}

				if (not qu.empty() && (qu.front() == x)) {
					qu.pop();
				} else {
					puedeSerQU = false;
				}

				if (not pq.empty() && (pq.top() == x)) {
					pq.pop();
				} else {
					puedeSerPQ = false;
				}
			}
			n--;
		}
		if (puedeSerST && not puedeSerQU && not puedeSerPQ) {
			cout << "stack" << endl;
		} else if (not puedeSerST && puedeSerQU && not puedeSerPQ) {
			cout << "queue" << endl;
		} else if (not puedeSerST && not puedeSerQU && puedeSerPQ) {
			cout << "priority queue" << endl;
		} else if (not puedeSerST && not puedeSerQU && not puedeSerPQ) {
			cout << "impossible" << endl;
		} else {
			cout << "not sure" << endl;
		}
	}
	return 0;
}