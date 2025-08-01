#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin >> T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N = 0;
        cin >> N;

        vector<int> a_prefs(N);
        vector<int> b_prefs(N);

        for(int i = 0; i < N; ++i)
        {
            cin >> a_prefs[i];
        }

        for(int i = 0; i < N; ++i)
        {
            cin >> b_prefs[i];
        }

        vector<bool> is_selected(N + 1, false);
        vector<char> result(N + 1);             
        
        int a_idx = 0;
        int b_idx = 0;

        for(int turn = 0; turn < N; ++turn)
        {
            if (turn % 2 == 0)
            {
               
                while (is_selected[a_prefs[a_idx]])
                {
                    a_idx++;
                }
                int selected_player = a_prefs[a_idx];
                is_selected[selected_player] = true;
                result[selected_player] = 'A';
            }
            else 
            {
   
                while (is_selected[b_prefs[b_idx]])
                {
                    b_idx++;
                }
                int selected_player = b_prefs[b_idx];
                is_selected[selected_player] = true;
                result[selected_player] = 'B';
            }
        }

        for(int i = 1; i <= N; ++i)
        {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}