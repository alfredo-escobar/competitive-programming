#include <iostream>
using namespace std;

int N, A, R, M;
long long h[100000];

long long obtCosto(long long x) {
	// Entrega costo de dejar el muro a altura x
	long long costo=0, aSacar=0, aPoner=0, aMover;
	if (M < A+R) {
		// Mover es "más barato"
		for (int i=0; i<N; i++) {
			if (x < h[i]) {
				// Pilar más alto
				aSacar += h[i]-x;
			} else if (h[i] < x) {
				// Pilar más bajo
				aPoner += x-h[i];
			}
		}
		if (aSacar < aPoner) {
			aMover = aSacar;
		} else {
			aMover = aPoner;
		}
		// Movemos todos los ladrillos posibles
		costo += aMover * M;
		// Luego agregamos o removemos los que quedan
		costo += (aSacar - aMover)*R + (aPoner - aMover)*A;

	} else {
		// Añadir y remover es más barato
		for (int i=0; i<N; i++){
			if (x < h[i]) {
				// Pilar más alto
				costo += (h[i]-x)*R;
			} else if (h[i] < x) {
				// Pilar más bajo
				costo += (x-h[i])*A;
			}
		}
	}
	return costo;
}

int main() {
	long long l=1000000000, r=0, m1, m2, auxIn;

	cin >> N >> A >> R >> M;
	for (int i=0; i<N; i++) {
		cin >> auxIn;
		h[i] = auxIn;
		if (auxIn < l) {
			// Nueva cota inferior
			l = auxIn;
		}
		if (r < auxIn) {
			// Nueva cota superior
			r = auxIn;
		}
	}

	// Buscaremos la altura ideal (más barata) del muro
	while (l<r) {
		m1 = ((r-l)/3) + l;
		m2 = r - ((r-l)/3);

		// cout << "l:" << l << " m1:" << m1 << " m2:" << m2 << " r:" << r << endl;

		if (obtCosto(m1)>obtCosto(m2)) {
			l = m1 + 1;
		} else {
			r = m2 - 1;
		}
	}

	l = obtCosto(l);
	r = obtCosto(r);
	if (l<r) {
		cout << l << endl;
	} else {
		cout << r << endl;
	}
	return 0;
}