#include<bits/stdc++.h>
using namespace std;
typedef int ll;

template<class T> 
struct SegmentTreeIterativo{
  int n; vector<T> ST; T (*m_)(T, T);
  SegmentTreeIterativo(vector<T> &a,T(*m_)(T,T)):m_(m_){
    n = a.size(); ST.resize(n << 1);
    for (int i=n;i<(n<<1);i++)ST[i]=a[i-n];
    for (int i=n-1;i>0;i--)ST[i]=m_(ST[i<<1],ST[i<<1|1]);
  }
  void update(int pos, T val){
    ST[pos += n] = val;
    for (pos >>= 1; pos > 0; pos >>= 1)
      ST[pos] = m_(ST[pos<<1], ST[pos<<1|1]);
  }
  T query(int l, int r){
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
};

int merge(int a, int b){
    return min(a, b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    vector<int> a(N);
    for (ll i=0; i<N; i++) {
        cin >> a[i];
    }

    SegmentTreeIterativo<int> S(a, merge);  // Segment tree de mínimos

    ll Q, l, r;
    cin >> Q;
    for (ll i=0; i<Q; i++) {
        cin >> l >> r;
        cout << S.query(l, r) << "\n";
    }

    return 0;
}