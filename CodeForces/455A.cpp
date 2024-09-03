#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll n, aux;
vector<ll> a;

int main() {
    ll max = 0;
    cin >> n;

    // O(n)
    for (ll i=0; i<n; i++) {
        cin >> aux;
        a.push_back(aux);
        if (aux>max) {
            max = aux;
        }
    }

    vector<ll> cant(max+1, 0);

    // O(n)
    for (ll i=0; i<n; i++) {
        cant[a[i]]++;
    }

    // Vector que indica el máximo puntaje obtenible al borrar
    // todas las instancias de i, sin considerar los valores
    // mayores a i.
    vector<ll> puntaje(max+1, 0);

    // Casos base:
    // puntaje[0] = 0, ya se tiene este valor
    puntaje[1] = cant[1];
    if (max==1) {
        cout << puntaje[1] << endl;
        return 0;
    }

    puntaje[2] = cant[2]<<1; //*2
    if (max==2) {
        cout << puntaje[2] << endl;
        return 0;
    }

    // Para obtener puntaje[i] para i>=3, tomaremos el puntaje
    // al borrar todos los i, y le sumaremos el máximo entre
    // puntaje[i-2] y puntaje[i-3] (sumarle directamente puntaje[i-4]
    // no sería ideal, puesto que no estaríamos considerando el
    // puntaje obtenido al borrar las instancias de i-2, las cuales
    // se podrían borrar sin perjuicio)
    for (ll i=3; i<=max; i++) {
        puntaje[i] += i*cant[i];
        if (puntaje[i-2] > puntaje[i-3]) {
            puntaje[i] += puntaje[i-2];
        } else {
            puntaje[i] += puntaje[i-3];
        }
    }

    if (puntaje[max] > puntaje[max-1]) {
        cout << puntaje[max] << endl;
    } else {
        cout << puntaje[max-1] << endl;
    }   
    return 0;
}