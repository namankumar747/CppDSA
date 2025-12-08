//Hacker Earth: Roy and Coin Boxes
//Method 1
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> f(n+1, 0);
    int m;
    cin>>m;
    vector<int> l(n+1, 0);
    vector<int> r(n+1, 0);
    for(int i = 0; i < m; i++){
        int L, R;
        cin>>L>>R;
        l[L]++;
        r[R]++;
    }
    f[1] = l[1];
    for(int i = 2; i <= n; i++){ 
        f[i] = l[i] - r[i-1] + f[i-1];
    }

    vector<int> c(10000005, 0);
    for(int i = 0; i <= n; i++){
        int coins = f[i];
        c[coins]++;
    }
    for(int i = c.size() - 2; i >= 0; i--){
        c[i] = c[i] + c[i+1];
    }
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<c[num]<<endl;
    }
}

/*
ALGORITHM:
1. Read n (number of boxes) and m (number of operations)
2. Create frequency arrays:
    - l[i]: count of ranges starting at position i
    - r[i]: count of ranges ending at position i
3. For each of m range queries [L, R]:
    - Increment l[L] (range starts at L)
    - Increment r[R] (range ends at R)
4. Calculate coins in each box using prefix sum technique:
    - f[1] = l[1] (coins in box 1)
    - f[i] = l[i] - r[i-1] + f[i-1] for i from 2 to n
      (adds new ranges starting at i, removes ranges ending at i-1, carries forward previous count)
5. Build frequency array c where c[coins] = count of boxes having that many coins
6. Convert c to suffix sum array:
    - c[i] = number of boxes with >= i coins
7. For each query q:
    - Output c[q] (number of boxes with at least q coins)

TIME COMPLEXITY: O(m + n + max_coins + queries)
SPACE COMPLEXITY: O(n + max_coins)
*/
