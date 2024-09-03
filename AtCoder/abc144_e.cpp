#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll N, K;
vector<ll> A, F;

bool esPosibleObtener(ll X) {
	ll trainTotal=0, trainIndiv;

	for (ll i=0; i<N; i++) {
		// Entrenamiento que necesitaría i para alcanzar X
		// X = (A[i] - trainIndiv) * F[x]
		trainIndiv = A[i] - (X/F[i]);
		if (trainIndiv < 0) {
			trainIndiv = 0;
		}
		trainTotal += trainIndiv;
	}
	return trainTotal <= K;
}

int main() {
	cin >> N >> K;
	ll maxA=0, maxF=0, auxIn, l=0, r, m;

	for (ll i=0; i<N; i++) {
		cin >> auxIn;
		A.push_back(auxIn);
		if (maxA < auxIn) {
			maxA = auxIn;
		}
	}

	for (ll i=0; i<N; i++) {
		cin >> auxIn;
		F.push_back(auxIn);
		if (maxF < auxIn) {
			maxF = auxIn;
		}
	}

	// Participante con menos A come mayor F, y viceversa
	sort(A.begin(), A.end());
	sort(F.begin(), F.end());
	reverse(F.begin(), F.end());
	
	r = maxA*maxF;
	while (l<r) {
		m = (l + r) >> 1;

		// cout << "l:" << l << " m:" << m << " r:" << r << endl;

		if (esPosibleObtener(m)) {
			// Veremos si podemos obtener menos
			r = m;
		} else {
			// Se deberá buscar obtener un puntaje más alto
			l = m + 1;
		}
	}
	cout << r << endl;
	return 0;
}