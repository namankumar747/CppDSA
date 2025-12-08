//Hacker Earth: Roy and Coin Boxes
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> f(n+1, 0);
    int m;
    cin>>m;
    for(int i = 0; i < m; i++){
        int L, R;
        cin>>L>>R;
        f[L]++;
        f[R+1]--;
    }
    for(int i = 1; i < n; i++){ //prefix sum
        f[i] = f[i] + f[i-1];
    }
    vector<int> c(10000005, 0);
    for(int i = 0; i <= n; i++){
        int coins = f[i];
        c[coins]++;
    }
    for(int i = c.size() - 2; i >= 0; i--){ //Suffix sum
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
Algorithm: Roy and Coin Boxes

1. **Input**: Read number of boxes (n) and number of operations (m)
2. **Range Updates**: For each of m range operations [L, R]:
    - Increment f[L] by 1
    - Decrement f[R+1] by 1
    - (This uses difference array technique for efficient range updates)
3. **Convert to Actual Values**: Compute prefix sum on array f from index 1 to n:
    - f[i] = f[i] + f[i-1]
    - Now f[i] contains the count of coins in box i
4. **Count Frequencies**: Create array c where c[coins] = count of boxes having exactly 'coins' coins
5. **Compute Suffix Sum**: On array c from right to left:
    - c[i] = c[i] + c[i+1]
    - Now c[num] = count of boxes having at least 'num' coins
6. **Answer Queries**: For q queries, each with value num:
    - Output c[num] (boxes with at least num coins)
*/
