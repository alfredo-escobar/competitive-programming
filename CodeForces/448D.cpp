#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll hayKMenoresA(ll x, ll n, ll m, ll k) {

	ll cont = 0;
	x -= 1;

	while (m>0) {
		if (x/m >= n) {
			break;
		}
		cont += x/m;
		m-=1;
	}

	cont += (n*m);

	return (k <= cont);
}


int main() {
	ll n, m, k, supIzq, infDer, pivote;

	cin >> n >> m >> k;

	supIzq = 1;
	infDer = n*m +1;

	while ((infDer-supIzq) > 0) {
		pivote = (supIzq + infDer)/2;

		if (hayKMenoresA(pivote,n,m,k)) {
			infDer = pivote;
		} else {
			supIzq = pivote + 1;
		}
	}

	cout << infDer-1 << endl;
	return 0;
}