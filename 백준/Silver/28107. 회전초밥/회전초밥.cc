#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> whoWants[200001];
int nextCustomerIdx[200001] = {0};
unordered_set<int> ateList[100001];
int eatCount[100001] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numCustomers, numSushi;
    cin >> numCustomers >> numSushi;

    for (int i = 1; i <= numCustomers; ++i)
    {
        int numOrders;
        cin >> numOrders;
        for (int j = 0; j < numOrders; ++j)
        {
            int sushiType;
            cin >> sushiType;
            whoWants[sushiType].push_back(i);
        }
    }

    for (int i = 0; i < numSushi; ++i)
    {
        int currentSushi;
        cin >> currentSushi;

        vector<int>& candidates = whoWants[currentSushi];
        int& customerPointer = nextCustomerIdx[currentSushi];

        bool eaten = false;

        while (customerPointer < candidates.size())
        {
            int customerId = candidates[customerPointer];

            if (ateList[customerId].count(currentSushi) == 0)
            {
                ateList[customerId].insert(currentSushi);
                eatCount[customerId]++;
                eaten = true;
                customerPointer++;
                break;
            }
            else
            {
                customerPointer++;
            }
        }
    }

    for (int i = 1; i <= numCustomers; ++i)
    {
        cout << eatCount[i] << " ";
    }
    cout << "\n";

    return 0;
}