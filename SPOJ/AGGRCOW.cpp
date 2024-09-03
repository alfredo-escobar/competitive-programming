#include <iostream>
#include <queue>
using namespace std;

int main() {
	long long t, N, C, pos, izq, der, centr, res, prevPos, cantVacas;
	cin >> t;
	while (t>0) {
		res = 0;

		priority_queue<long long> cola;
		cin >> N >> C;
		for (long long i=0; i<N; i++) {
			cin >> pos;
			cola.push(pos);
		}

		vector<long long> lista(N, 0);
		for (long long i=N-1; i>=0; i--) {
			lista[i] = cola.top();
			cola.pop();
		}

		izq = 1; //menor distancia posible entre vacas
		der = lista[N-1]-1; //mayor distancia posible entre vacas

		while(1) {
			if (izq>der) {break;}
			else {
				centr = (izq+der)>>1; //distancia a comprobar entre vacas
				cantVacas = 1;
				prevPos = lista[0];

				for (long long i=1; i<N; i++) {
					if (centr <= (lista[i] - prevPos)) {
						prevPos = lista[i];
						cantVacas++;
						if (cantVacas == C) {
							//se puede colocar todas las vacas
							break;
						}
					}
				}

				if (cantVacas == C) {
					//se puede colocar todas las vacas
					res = centr;
					izq = centr + 1;
				} else {
					//no se puede colocar todas las vacas
					der = centr - 1;
				}
			}
		}
		cout << res << endl;
		t--;
	}
	return 0;
}