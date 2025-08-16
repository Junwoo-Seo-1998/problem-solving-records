#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;

int main() {
    cin >> str;

    stack<bool> s;

    for(int i=0; i<str.size(); ++i)
    {
        char c=str[i];
        if(c=='(')
        {
            s.push(true);
        }
        else
        {
            if(s.empty())
            {
                cout<<"No\n";
                return 0;
            }

            s.pop();
        }
    }

    if(s.empty())
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}
