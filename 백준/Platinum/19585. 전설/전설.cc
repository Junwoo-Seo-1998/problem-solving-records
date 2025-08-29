#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
using namespace std;

struct ColorTrie {
    struct Node {
        //unordered_map<char, int> childIndex;
        int childIndex[26];
        bool isColorEnd; 

        Node() : isColorEnd(false) {
            memset(childIndex, -1, sizeof(childIndex));
        }
    };

    vector<Node> nodes;

    ColorTrie() {
        nodes.emplace_back(); 
    }

    void insert(const string& str) {
        int cur = 0;
        for (char c : str) {
            if (nodes[cur].childIndex[c-'a'] == -1) {
                nodes[cur].childIndex[c-'a'] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].childIndex[c-'a'];
        }
        nodes[cur].isColorEnd = true; 
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int C, N;
    cin >> C >> N;

    ColorTrie colorTrie;
    for (int i = 0; i < C; ++i) {
        string color;
        cin >> color;
        colorTrie.insert(color);
    }

    unordered_set<string> nicknameSet;
    for (int i = 0; i < N; ++i) {
        string nickname;
        cin >> nickname;
        nicknameSet.insert(nickname);
    }
  
    int Q;
    cin >> Q;
    while (Q--) {
        string word;
        cin >> word;

        bool found = false;
        int currentNodeIndex = 0; 

        for (int i = 0; i < word.length(); ++i) {

            if (colorTrie.nodes[currentNodeIndex].childIndex[word[i]-'a'] == -1) {
                break;
            }
            currentNodeIndex = colorTrie.nodes[currentNodeIndex].childIndex[word[i]-'a'];

            if (colorTrie.nodes[currentNodeIndex].isColorEnd) {

                string suffix = word.substr(i + 1);

                if (nicknameSet.count(suffix)) {
                    found = true;
                    break; 
                }
            }
        }

        if (found) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}