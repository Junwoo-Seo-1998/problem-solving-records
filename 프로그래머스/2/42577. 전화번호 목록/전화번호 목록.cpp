#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> phone_set(phone_book.begin(), phone_book.end());

    for (const string& number : phone_book) {
        string prefix = "";
        for (int i = 0; i < number.size() - 1; ++i) {  // 접두사 만들기
            prefix += number[i];
            if (phone_set.count(prefix)) {
                return false;
            }
        }
    }

    return true;
}
