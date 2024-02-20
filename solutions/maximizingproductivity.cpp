// Source: https://usaco.guide/general/io

/*
TEST CASES:
* 1. 3.4mb2ms * 2. 3.4mb4ms * 3. 3.4mb4ms * 4. 3.4mb4ms * 5. 4.9mb437ms * 6. 4.9mb438ms * 7. 4.9mb437ms * 8. 4.9mb432ms * 9. 4.9mb433ms * 10. 4.9mb514ms * 11. 4.9mb514ms * 12. 4.9mb514ms * 13. 4.9mb513ms * 14. 4.9mb514ms * 15. 4.9mb513ms * 16. 4.9mb512ms * 17. 4.9mb511ms
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q, temp; cin >> n >> q;
	int c[n], t[n];
	for(int &i: c){
		cin >> i;
	}

	for(int i = 0; i < n; i++){
		cin >> temp;
		t[i] = max(0, c[i] - temp);
		
	}
	sort(t, t + n);
	for(int query = 0; query < q; query++){
		int s, v;cin >> v >> s;
		//visit v farms
		//after s time

		if(t[n - max(1, min(n, v))] > s){
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;

	}
	return 0;

}
