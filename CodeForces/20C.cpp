#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int, long long int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > wgraph;

typedef vector<long long int> vi;
typedef vector<vector<int> > vvi;

/*
El objeto wgraph es un vector<vector<pair<int, int> > >, el cual se utiliza para representar un grafo con peso,
se puede considerar como una lista de adyacencia, pero para grafos con peso en las aristas.
Otra forma de definir wgraph para facilitar su manejo seria reemplazando pair<int, int> por un vector<int>
de tamaño 2.

IMPORTANTE: sea G un wgraph, sea u un nodo en el grafo, los pair<int, int> que se encuentran en el 
			vector G[u], son tales que, G[u].second es un nodo del grafo y G[u].first contiene el 
			peso de la arista que une el nodo u al nodo G[u].second

IMPORTANTE: Recordar que el vector dist tiene que estar inicializado con distancia infinita para todo
			nodo distinto de s.

IMPORTANTE: Lea el codigo y entiendalo, no siempre se le pedira el menor costo para ir del nodo A al nodo B,
			puede que le pidan cual es el CAMINO mas corto entre el nodo A y el nodo B o puede que el grafo 
			sea una matriz (laberinto) o un grafo implicito.

Despues de utlizar la funcion, el vector de enteros dist contiene las distancia minima desde el nodo s, hacia 
todos los demas nodos.
*/
void Dijsktra(int s, wgraph &M, vi &dist, vi &p) {
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if ((d > dist[u]) && (dist[u] >= 0)) continue;

		for (long long int j = 0; j < M[u].size(); j++) {
			ii v = M[u][j];
			if (((dist[u] + v.first < dist[v.second]) && (dist[u] >= 0)) || (dist[v.second]==-1)) {
				dist[v.second] = dist[u] + v.first;
				pq.push(ii(dist[v.second], v.second));

				p[v.second] = u;
			}
		}
	}
}

int main() {
	long long int n, m, a, b, w, wMAX;
	wMAX = -1;
	wgraph grafo;
	vi dist, p;
	vii auxVII;

	cin >> n >> m;
	for (long long int i = 0; i < n; i++) {
		grafo.push_back(auxVII);
		dist.push_back(wMAX);
		p.push_back(-1);
	}

	for (long long int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		grafo[a-1].push_back(ii(w,b-1));
		grafo[b-1].push_back(ii(w,a-1));
	}

	Dijsktra(0, grafo, dist, p);

	vi camino;
	// Reciclamos a n como puntero de vectores:
	n = n-1;
	while (n != 0) {
		if (p[n] == -1) {
			cout << -1 << endl;
			return 0;
		}
		camino.push_back(n+1);
		n = p[n];
	}
	camino.push_back(1);

	// Reciclamos a n como largo del vector camino:
	n = camino.size();
	for (long long int i = 0; i < n; i++) {
		cout << camino[n-i-1];
		if (i == n-1) {
			cout << endl;
		} else {
			cout << " ";
		}
	}

	return 0;
}