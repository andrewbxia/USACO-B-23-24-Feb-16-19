// Source: https://usaco.guide/general/io

/*
TEST CASES:
* 1. 3.3mb2ms * 2. 3.3mb2ms * 3. 3.3mb2ms * 4. 3.3mb2ms * 5. 3.3mb2ms * 6. 3.3mb2ms * 7. 3.3mb2ms * 8. 3.3mb1ms * 9. 3.3mb1ms * 10. 3.3mb2ms * 11. 3.5mb16ms * 12. 3.5mb16ms * 13. 3.5mb16ms
*/

#include <bits/stdc++.h>
using namespace std;

bool wins(string s){
	//true if bessie wins, false otherwise
	int strsize = s.size();
	if(strsize == 1){
		return true;
	}
	if(s[strsize - 1] == '0'){
		return false;
	}
	return true;
}

int main() {
	int t; cin >> t;
	string s;
	getline(cin, s);
	for(int test = 0; test < t; test++){
		getline(cin, s);
		cout << (wins(s) ? "B":"E") << endl;
		// wins(s);
	}
	return 0;
}
