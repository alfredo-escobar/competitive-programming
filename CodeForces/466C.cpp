#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
	int n, aux;
	vi a, b;
	long long total = 0, suma, formas = 0;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> aux;
		a.push_back(aux);
		total += aux;
	}

	if (total%3 != 0) {
		cout << 0 << endl;
	} else {

		total /= 3;
		if (a[0] == total) {
			b.push_back(1);
		} else {
			b.push_back(0);
		}

		suma = a[0];
		for (int i=1; i<n; i++) {
			b.push_back(b[i-1]);
			suma += a[i];
			if (suma == total) {
				b[i] += 1;
			}
		}

		suma = 0;
		for (int i=n-1; i>1; i--) {
			suma += a[i];
			if (suma == total) {
				formas += b[i-2];
			}
		}

		cout << formas << endl;
	}
	return 0;
}