#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//dfs로 위상정렬 하는거 연습해보는 용


int n, m;
int a[100000], b[100000];

int visited[100'001];
vector<int> edge[100'001];

stack<int> sorted;

void dfs()
{

    sorted.push();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    for(int i=0; i<m; ++i)
    {
        edge[a[i]].push_back(b[i]);
    }


    while(!sorted.empty())
    return 0;
}