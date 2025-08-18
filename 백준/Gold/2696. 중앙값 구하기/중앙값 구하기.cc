#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        int M;
        cin >> M;
        priority_queue<int, vector<int>> lower; // -> maxHeap
        priority_queue<int, vector<int>, greater<>> upper; // -> minHeap

        if( M & 1 ) cout << M/2 + 1 << '\n';
        else cout << M/2 << '\n';

        for(int i=0; i<M; i++){
            int elem;
            cin >> elem ;
            upper.push(elem);
            lower.push(upper.top()); upper.pop();
            if( lower.size() > upper.size() ) {
                upper.push(lower.top()); lower.pop();
            }
            if( i % 2 == 0 )
                cout << upper.top() << ' ';
        }
        cout << '\n';
    }

    return 0;
}