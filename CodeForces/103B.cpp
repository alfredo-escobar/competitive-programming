#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> graph;

/*
IMPORTANTE: Recordar DFS NO SIRVE (repito NO SIRVE) para obtener distancia minima en grafos sin peso, las implementaciones
			que estan acá son para determinar los nodos que estan en la componente conexa del nodo s.

A diferencia de BFS, DFS se puede implementar de forma recursiva o iterativa (con un stack).
La mayor diferencia entre las dos implementaciones es la facilidad para modificarla y usabilidad en distintos casos.
La implementacion iterativa es la mas rapida.
La implementacion recursiva es mas facil de entender y de modificar para los distintos usos de DFS (eg: toposort y
calculo de componentes fuertemente conexas).

Despues de ejecutar la funcion, sea v un nodo en el grafo, si visited[v] es uno, entonces v esta en la misma componente
conexa que s, en caso contrario, visited[v] es cero.
*/

void DFS_recursive(int s, graph &M, vi &visited) {
	visited[s] = 1;
	for(int v : M[s]) {
		if(visited[v] == 0) {
			DFS_recursive(v, M, visited);
		}
	}
}

int main() {
	int n, m, u, v;
	graph M;
	vi visited;
	vi auxVI;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		M.push_back(auxVI);
		visited.push_back(0);
	}

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		M[u-1].push_back(v-1);
		M[v-1].push_back(u-1);
	}

	if (n != m) {
		cout << "NO" << endl;
		return 0;
	}

	DFS_recursive(0, M, visited);
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "FHTAGN!" << endl;
	return 0;
}