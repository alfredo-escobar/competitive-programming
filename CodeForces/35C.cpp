#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

typedef int si;
typedef vector<bool> vi;

/*
IMPORTANTE: Recordar BFS tambien sirve para obtener distancia minima en grafos sin peso, pero esta implementacion 
			es para saber los nodos que estan en la misma componente conexa que el nodo s, por lo que el vector 
			visited esta inicializado con 0.

Despues de ejecutar la funcion, sea v un nodo en el grafo, si visited[v] es uno, entonces v esta en la misma componente
conexa que s, en caso contrario, visited[v] es cero.
*/
queue<int> q;

int BFS(si n, si m, vi &visited) {
	int u, v; si x, y;
	while(!q.empty()) {
		u = q.front(); q.pop();
		y = u/n;
		x = u - y*n;

		// arriba
		if (y<m-1) {
			v = u+n;
			if(visited[v] == false) {
				visited[v] = true;
				q.push(v);
			}
		}

		// der
		if (x<n-1) {
			v = u+1;
			if(visited[v] == false) {
				visited[v] = true;
				q.push(v);
			}
		}

		// abajo
		if (y>0) {
			v = u-n;
			if(visited[v] == false) {
				visited[v] = true;
				q.push(v);
			}
		}

		// izq
		if (x>0) {
			v = u-1;
			if(visited[v] == false) {
				visited[v] = true;
				q.push(v);
			}
		}
	}
	return u;
}

int main() {
	si n, m, k, x, y; int last;
	vi visited;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//cin >> n >> m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n*m; i++) {
		visited.push_back(false);
	}

	//cin >> k;
	scanf("%d", &k);
	for (si t = 0; t < k; t++) {
		//cin >> x >> y;
		scanf("%d%d", &x, &y);
		x -= 1; y -= 1;
		q.push(x + y*n);
		visited[x + y*n] = true;
	}

	last = BFS(n, m, visited);
	y = last/n;
	x = last - y*n;
	cin >> x;
	printf("%d %d", x+1, y+1);

	return 0;
}