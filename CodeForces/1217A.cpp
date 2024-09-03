#include <iostream>
using namespace std;

int main() {
	int t; int s; int i; int e; int dif1; int dif2;
	cin >> t;
	while (t>0) {
		cin >> s >> i >> e;

		dif1 = s - i;
		if (dif1 > e) {
			cout << e+1 << endl;
		} else {
			dif2 = e - dif1;
			if ((e - (dif2/2)) >= 0) {
				cout << e - (dif2/2) << endl;
			} else {
				cout << 0 << endl;
			}
			
		}
		
		t = t - 1;
	}
	return 0;
}