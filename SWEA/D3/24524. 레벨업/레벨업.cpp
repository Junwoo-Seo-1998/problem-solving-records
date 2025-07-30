#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N=0;
        cin>>N;
        vector<int> arr(N, 0);
        for(int i=0; i<N; ++i)
        {
            cin>>arr[i];
        }

        int totalCost=0;
        for(int i=0; i<N-1; ++i)
        {
            totalCost+=abs(arr[i+1]-arr[i]);
        }

        int optimalSaved=-1;
        for(int i=1; i<N-1; ++i)
        {
            int normalCost=abs(arr[i+1]-arr[i])+abs(arr[i]-arr[i-1]);
            int skipCost=abs(arr[i+1]-arr[i-1]);
            int saved=normalCost-skipCost;
            optimalSaved=max(optimalSaved, saved);
        }

        cout<<totalCost-optimalSaved<<endl;
	}
	return 0;
}