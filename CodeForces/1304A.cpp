#include <iostream>
using namespace std;

int main() {
	int t; int x; int y; int a; int b; int s1; int s2;
	cin >> t;
	while (t>0) {
		cin >> x >> y >> a >> b;
		if (x==y) {
			cout << 0 << endl;
		}
		if (x<y) {
			s1 = y-x; s2 = a+b;
			if (s1%s2 == 0) {
				cout << s1/s2 << endl;
			} else {
				cout << -1 << endl;
			}
		} else {
			cout << -1 << endl;
		}
		t = t - 1;
	}
	return 0;
}