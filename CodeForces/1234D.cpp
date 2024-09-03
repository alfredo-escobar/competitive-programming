#include<bits/stdc++.h>
#include <string>
#include <map>
 
using namespace std;
typedef long long ll;
 
template <class T>
struct DynamicSegmentTree {
  vector<T> ST;
  vector<int>L, R;
  long long n;
  int n_count;
  T (*merge) (T, T);
  T (*init) (ll, ll);
  DynamicSegmentTree (
      long long n, 
      T (*merge) (T, T), 
      T (*init)(long long ,long long)
    ) : 
    n(n),n_count(1),L(1),R(1),merge(merge),ST(1), init(init) {
    ST[0] = init(0, n - 1);
  }
 
  int addNode(long long l, long long r){
    L.push_back(0);
    R.push_back(0);
    ST.push_back(init(l, r));
    n_count ++;
    return n_count - 1;
  }
  
  T query(int i, ll l, ll r, ll a, ll b) {
    if (a <= l and r <= b)
      return ST[i];
    ll mid = (l + r) >> 1LL;
    if (b <= mid) 
      return query(L[i] != 0 ? L[i] : L[i] = addNode(l, mid), l, mid, a, b);
    else if (a > mid)
      return query(R[i] != 0 ? R[i] : R[i] = addNode(mid + 1, r), mid + 1, r, a, b);
    if (L[i] == 0) L[i] = addNode(l, mid);
    if (R[i] == 0) R[i] = addNode(mid + 1, r);
    return merge(query(L[i], l, mid, a, b), query(R[i], mid + 1, r, a, b));
  }
 
  T query(ll a, ll b) {
    return query(0, 0, n - 1, a, b);
  }
 
  void update(int i, ll l, ll r, ll p, T v) {
    if (l == r){
      ST[i] = v;
      return ;
    }
    ll mid = (l + r) >> 1LL;
    if (p <= mid)
      update(L[i] != 0 ? L[i] : L[i] = addNode(l, mid), l, mid, p, v);
    else 
      update(R[i] != 0 ? R[i] : R[i] = addNode(mid + 1, r), mid + 1, r, p, v);
    ST[i] = merge(
        L[i] != 0 ? ST[L[i]] : init(l, mid), 
        R[i] != 0 ? ST[R[i]] : init(mid + 1, r)
      );
  }
 
  void update(ll pos, T v) {
    update(0, 0, n - 1, pos, v);
  }
};


// el merge
int merge(int a, int b){
  return a | b;
}

// la query para un rango que no ha sido modificado.
// asumimos que el vector parte con 0.
int init(ll l, ll r){
  return 0;
}


int charABits(char c) {
    return 1 << c-1;
}


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;

  // se le entrega el tamano, el merge y el init
  DynamicSegmentTree<int> ST(1e15, merge, init);
  for (int i = 0; i < s.length(); i ++){
    int x = charABits(s[i]);
    ST.update(i, x);
    // cout << i << x << '\n';
  }

  int q;
  cin >> q;
  while(q --){
    int a;
    cin >> a;
    if (a==1) {
        int b; char c;
        cin >> b >> c;
        ST.update(b-1, charABits(c));
    } else {
        int l, r, x;
        cin >> l >> r;
        x = ST.query(l-1, r-1);
        cout << __builtin_popcount(x) << "\n";
    }
  }
  return 0;
} 