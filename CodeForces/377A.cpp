#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, k;
string maze[500];
long int nodos[250000] = {0};

int DFS(int i, int j) {
	if (maze[i][j] != '.') {
		return 0;
	}
	if (nodos[i*m +j]==1) {
		return 0;
	}
	nodos[i*m +j]=1;
	if (i<(n-1)) {
		DFS(i+1, j);
	}
	if (i>0) {
		DFS(i-1, j);
	}
	if (j<(m-1)) {
		DFS(i, j+1);
	}
	if (j>0) {
		DFS(i, j-1);
	}
	if (k>0) {
		maze[i][j]='X';
		k-=1;
	}
	return 0;
}

int main(){
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		cin >> maze[i];
	}

	for (int i=0; i<n; i++) {
		if (k==0) {break;}
		for (int j=0; j<m; j++) {
			if (k==0) {break;}
			DFS(i,j);
		}
	}

	for (int i=0; i<n; i++) {
		cout << maze[i] << endl;
	}
	return 0;
}