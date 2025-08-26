#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> people;
int N, M;

vector<int> job;
vector<bool> asked;

bool match(int current)
{
    for(int j:people[current])
    {
        if(asked[j]) continue;
        asked[j]=true;
        if(job[j]==-1 || match(job[j]))
        {
            job[j]=current;
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    cin>>N>>M;

    job.assign(M+1, -1);
    people.assign(2*N+1, {});
    for(int i=1; i<=N; ++i)
    {
        int J;

        cin>>J;
        people[i].reserve(J);
        people[i*2].reserve(J);
        for(int j=0; j<J; ++j)
        {
            int job;
            cin>>job;
            people[i].push_back(job);
            people[N+i].push_back(job);
        }
    }

    int cnt=0;

    for(int i=1; i<=2*N; ++i)
    {
        asked.assign(M+1, false);
        if(match(i))
        {
            cnt++;
        }
    }

    cout<<cnt;

    return 0;
}