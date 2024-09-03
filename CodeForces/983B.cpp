#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll n, q, aux;

void put(vll* vec, ll x, ll y, ll val) {
    ll pos = ((x-1)*n) + y-1;
    (*vec)[pos] = val;
}

ll get(vll* vec, ll x, ll y) {
    ll pos = ((x-1)*n) + y-1;
    return (*vec)[pos];
}

ll XOR(ll a, ll b) {
    return a^b;
}

int main() {
    cin >> n;
    vll a(n*n, 0);
    vll maximos(n*n, 0);
    for (ll i=1; i<=n; i++) {
        cin >> aux;
        put(&a, i, i, aux);
        put(&maximos, i, i, aux);
    }

    for (ll rango = 1; rango<n; rango++) {
        for (ll l=1; l+rango<=n; l++) {
            ll r = l+rango;
            ll fL = get(&a, l, r-1);
            ll fR = get(&a, l+1, r);
            put(&a, l, r, XOR(fL, fR));
        }
    }

    for (ll rango = 1; rango<n; rango++) {
        for (ll l=1; l+rango<=n; l++) {
            ll r = l+rango;
            ll maxL = get(&maximos, l, r-1);
            ll maxR = get(&maximos, l+1, r);
            ll resF = get(&a, l, r);
            put(&maximos, l, r, max({maxL, maxR, resF}));
        }
    }
/*
    cout << endl << "a:" << endl;
    for (ll l=1; l<=2; l++) {
        for (ll r=1; r<=n; r++) {
            cout << get(&a, l, r) << "  ";
        }
        cout << endl;
    }

    cout << endl << "f:" << endl;
    for (ll l=1; l<=n; l++) {
        for (ll r=1; r<=n; r++) {
            if (l>r) {
                cout << "x  ";
            } else {
                cout << f(&a, l, r) << "  ";
            }
        }
        cout << endl;
    }

    cout << endl << "maximos:" << endl;
    for (ll l=1; l<=n; l++) {
        for (ll r=1; r<=n; r++) {
            if (l>r) {
                cout << "x  ";
            } else {
                cout << get(&maximos, l, r) << "  ";
            }
        }
        cout << endl;
    }
*/
    cin >> q;
    for (ll i=0; i<q; i++) {
        ll l, r;
        cin >> l >> r;
        aux = get(&maximos, l, r);
        cout << aux << endl;
    }
    return 0;
}