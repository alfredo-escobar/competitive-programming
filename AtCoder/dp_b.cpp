#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, K, aux, calsIJ;
vector<int> a;
vector<int> cals;

int main() {
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> aux;
        a.push_back(aux);
        cals.push_back(2147483643);
    }
    cals[0] = 0;
    for (int j=1; j<N; j++) {
        for (int i=j-1; (i>=j-K) && (i>=0); i--) {
            calsIJ = cals[i] + abs(a[i]-a[j]);
            if (calsIJ < cals[j]) {
                cals[j] = calsIJ;
            }
        }
    }
    cout << cals[N-1] << endl;    
    return 0;
}