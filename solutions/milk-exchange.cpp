// Source: https://usaco.guide/general/io

/*
TEST CASES:
* 1. 3.4mb2ms * 2. 3.4mb2ms * 3. 3.4mb2ms * 4. 3.4mb2ms * 5. 3.4mb2ms * 6. 3.4mb2ms * 7. 3.4mb2ms * 8. 3.4mb2ms * 9. 7.8mb58ms * 10. 7.8mb58ms * 11. 7.8mb68ms * 12. 7.8mb63ms * 13. 7.8mb85ms * 14. 7.8mb85ms * 15. 7.8mb72ms * 16. 7.8mb64ms
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main() {
	ll n, m, sum = 0;cin >> n >> m;
    int sharepos[n];
    fill(sharepos, sharepos + n, 0);

    char c;
    bool dir[n];
    short net[n];
    ll cows[n], milks[n];
    fill(net, net + n, -1);

    cin >> c;
    dir[0] = c == 'R';

    for(int i = 1; i < n; i++){
        cin >> c;
        // cout << c << endl;
        dir[i] = c == 'R';
        if(dir[i - 1] && !dir[i]){
            sharepos[i - 1] = true;
            sharepos[i] = true;
        }
    }

    if(dir[n - 1] && !dir[0]){
        sharepos[n - 1] = true;
        sharepos[0] = true;
    }


    for(int i = 0; i < n; i++){
        cin >> cows[i];
        milks[i] = cows[i];
    }

    for(int cow = 0; cow < n; cow++){
        net[(cow + (dir[cow] ? 1 : -1) + n) % n]++;
    }

    // for(int i: sharepos){
    //     cout << i << ' ' << endl;
    // }

    for(int cow = 0; cow < n; cow++){
        if(net[cow] == -1){
            int ind = cow;
            while(!sharepos[ind]){
                int lost = max((ll)0, min(m, milks[ind]));
                milks[(ind + (dir[ind] ? 1 : -1) + n) % n] += lost;
                milks[ind] -= lost;
                ind = (ind + n + (dir[ind] ? 1 : -1)) % n;
                
            }
            
        }
        // cout << cow << endl;
    }



    for(int cow = 0; cow < n; cow++){
        milks[cow] = min(milks[cow], cows[cow]);
        // cout << milks[cow] << endl;
        sum += milks[cow];
    }

    cout << sum << endl;

    return 0;
}
