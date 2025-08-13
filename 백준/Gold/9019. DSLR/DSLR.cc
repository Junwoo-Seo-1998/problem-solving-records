#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <cstring>
using namespace std;


function<int(int)> DSLR[4]={
    //D
    [](int val)->int {
        return (val<<1)%10000;
    },
    //S
    [](int val)->int { 
        return (val == 0) ? 9999 : val-1;
    },
    //L
    [](int val)->int { 
        int temp=val*10;
        return temp%10000+temp/10000;
    },
    //R
    [](int val)->int { 
        return (val/10)+1000*(val%10);
    },
};

char letter[4]={
    'D','S','L','R'
};

bool v[10000];

void bfs(int start, int end) {
	memset(v, 0, sizeof(v));

    queue<pair<int, string>> q;
	q.push({start, ""});

    

	while (!q.empty()) 
    {
		int cur = q.front().first;
        string& str = q.front().second;
		if (cur == end)
		{
            cout<<str<<'\n';
            return;
        }
        
        for(int i=0; i<4; ++i)
        {
            int val=DSLR[i](cur);
            if(v[val]) continue;
            v[val]=true;
            q.push({val, str+letter[i]});
        }

        q.pop();
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
    
    int N; 
    cin>>N;
    for(int n=0; n<N; ++n)
    {
        int s, e;
        cin>>s>>e;
        bfs(s, e);
    }

	return 0;
}