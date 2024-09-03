#include <iostream>
#include <algorithm>
using namespace std;

int maxEntre3(int n1, int n2, int n3) {
	int maxim;
	maxim = max(n1,n2);
	maxim = max(maxim, n3);
	return maxim;
}

int maxPorFila(int h, int w, int matriz[]) {
	int result; int maxPrevio;

	if (h==1) {
		result = 0;
		for (int j=0; j<w; j++){
			result = max(result, matriz[j]);
		}
		return result;

	} else {
		for (int fila=1; fila<h; fila++) {
			if (w==1) {
				matriz[fila*w] += matriz[(fila-1)*w];

			} else {
				for (int m=0; m<w; m++) {
					if (m==0) {
						maxPrevio = max(matriz[(fila-1)*w], matriz[(fila-1)*w + 1]);
					} else if (m == (w-1)) {
						maxPrevio = max(matriz[(fila-1)*w + (m-1)],matriz[(fila-1)*w + m]);
					} else {
						maxPrevio = maxEntre3(matriz[(fila-1)*w + (m-1)],matriz[(fila-1)*w + m],matriz[(fila-1)*w + (m+1)]);
					}
					matriz[fila*w + m] += maxPrevio;
				}
			}
		}
		result = 0;
		for (int j=0; j<w; j++){
			result = max(result, matriz[(h-1)*w + j]);
		}
		return result;
	}
}

int main() {
	int T; int h; int w;
	cin >> T;

	while (T > 0) {
		cin >> h >> w;
	 	int matriz[h * w];

	 	for (int i=0; i<h; i++) {
	 		for (int j=0; j<w; j++) {
	 			cin >> matriz[i*w + j];
	 		}
	 	}

		cout << maxPorFila(h,w,matriz) << endl;
		T = T - 1;
	}
	return 0;
}