#include<bits/stdc++.h>
#include<vector>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
template<class T> 
struct SegmentTreeIterativo{
  ll n; vector<T> ST; T (*m_)(T, T);

  // Constructor con vector y función merge
  SegmentTreeIterativo(vector<T> &a,T(*m_)(T,T)):m_(m_){
    n = a.size(); ST.resize(n << 1);
    for (ll i=n;i<(n<<1);i++)ST[i]=a[i-n];
    for (ll i=n-1;i>0;i--)ST[i]=m_(ST[i<<1],ST[i<<1|1]);
  }

  // Constructor con tamaño y función merge (árbol con 0s)
  SegmentTreeIterativo(ll t, T(*m_)(T,T)):m_(m_){
    n = t; ST.resize(n << 1);
    for (ll i=n;i<(n<<1);i++)ST[i]=0;
    for (ll i=n-1;i>0;i--)ST[i]=m_(ST[i<<1],ST[i<<1|1]);
  }

  void update(ll pos, T val){
    ST[pos += n] += val;
    for (pos >>= 1; pos > 0; pos >>= 1)
      ST[pos] = m_(ST[pos<<1], ST[pos<<1|1]);
  }
  T query(ll l, ll r){ 
    T ansL, ansR; bool hasL = 0, hasR = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) 
        ansL=(hasL?m_(ansL,ST[l++]):ST[l++]),hasL=1;
      if (r & 1) 
        ansR=(hasR?m_(ST[--r],ansR):ST[--r]),hasR=1;
    }
    if (!hasL) return ansR; if (!hasR) return ansL;
    return m_(ansL, ansR);
  }

  void printTree(){
    for (ll i=n;i<(n<<1);i++) {
      cout << ST[i] << ' ';
    }
    cout << '\n';
    for (ll i=n-1;i>0;i--) {
      cout << ST[i] << ' ';
    }
    cout << '\n';
  }
};


// el merge
ll merge(ll a, ll b){
  return a+b;
}

vector<ll> all_nums;

ll comp(ll x) {
  return (ll) (lower_bound(all_nums.begin(), all_nums.end(), x) - all_nums.begin());
}

void printVectores(vector<ll>* a) {
  cout << "\n\nVector all_nums:\n";
  for (ll i = 0; i < all_nums.size(); i++) {
    cout << all_nums[i] << ' ';
  }
  cout << "\n\ncomp:\n";
  for (ll i = 0; i < (*a).size(); i++) {
    cout << comp((*a)[i]) << ' ';
  }
  cout << "\n\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, aux, valL, valR, max=0, debilidad = 0;
  cin >> n;
  vector<ll> a(n);
  for (ll i=0; i<n; i++) {
      cin >> aux;
      a[i] = aux;
      all_nums.push_back(aux);
      if (aux>max){
        max = aux;
      }
  }
  sort(all_nums.begin(), all_nums.end());
  //printVectores(&a);

  // se le entrega el tamano, el merge y el init
  SegmentTreeIterativo<ll> LST(n, merge);
  SegmentTreeIterativo<ll> RST(n, merge);
  
  for (ll i = 0; i < n; i ++){
    RST.update(comp(a[i]), 1);
  }

  // RST.printTree();

  // i = 0
  RST.update(comp(a[0]), -1);
  LST.update(comp(a[0]), 1);

  for (ll i = 1; i < n-1; i ++){
    RST.update(comp(a[i]), -1);
    if (a[i]==max) {
      valL = 0;
    } else {
      valL = LST.query(comp(a[i])+1, comp(max));
    }
    if (comp(a[i])==0){
      valR = 0;
    } else {
      valR = RST.query(0, comp(a[i])-1);
    }
    debilidad += valL*valR;
    LST.update(comp(a[i]), 1);
  }
  cout << debilidad << '\n';
  return 0;
}