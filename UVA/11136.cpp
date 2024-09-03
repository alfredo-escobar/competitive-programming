#include <iostream>
#include <set>
using namespace std;

int main() {
	long long n, k, b;
	while (1) {
		cin >> n;
		if (n==0) {
			break;
		} else {
			long long costo = 0;
			multiset<long long> bills;
			while (n>0) {
				cin >> k;
				while (k>0) {
					cin >> b;
					bills.insert(b);
					k--;
				}
				//cout << "max=" << *(--bills.end()) << " min=" << *(bills.begin()) << endl;
				costo += *(bills.rbegin()) - *(bills.begin());
				bills.erase(bills.begin());
				bills.erase(--bills.end());
				n--;
			}
			cout << costo << endl;
		}
	}
	return 0;
}