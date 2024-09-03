#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	long long n, k, ti, bi, setLength=0, pleasure=0;

	vector<pair<long long, long long>> ve;
	multiset<long long> ms;

	cin >> n >> k;
	for (long long i=0; i<n; i++) {
		cin >> ti >> bi;
		ve.push_back({bi, ti});
	}

	sort(ve.begin(), ve.end());
	// cout << ve[0].first << ve[0].second << endl;

    while (n>0) {
    	n--;
        setLength += ve[n].second;
        ms.insert(ve[n].second);

        if (ms.size()>k) {
            setLength -= *(ms.begin());
            ms.erase(ms.begin());
        }
        pleasure = max(pleasure, setLength * ve[n].first);
    }
    cout << pleasure << endl;
	return 0;
}