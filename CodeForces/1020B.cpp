#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n, alumno;
	cin >> n;
	int p[n];
	for (int i=0; i<n; i++) {
		cin >> p[i];
	}

	for (int a=0; a<n; a++) {
		int grafo[n] = {0};
		alumno = a;
		while (grafo[alumno]<=1) {
			grafo[alumno] += 1;
			alumno = p[alumno] -1;
		}
		cout << alumno + 1;
		if (a==n-1) {
			cout << endl;
		} else {
			cout << " ";
		}
	}
	return 0;
}