#include <string>
#include <vector>
#include <cmath> 

using namespace std;

int get_col(int number, const char numpad[]) {
    if (number == 1 || number == 4 || number == 7) return 0; 
    if (number == 3 || number == 6 || number == 9) return 2;
    if (number == 2 || number == 5 || number == 8 || number == 0) return 1;

    if (numpad[number] == 'L') return 0;
    if (numpad[number] == 'R') return 2;
    return 1; 
}


string solution(vector<int> numbers, string hand_pref_str) {
    string answer = "";

    char numpad_info[10] = {0, 'L', 0, 'R', 'L', 0, 'R', 'L', 0, 'R'};

    int pos_info[10] = {4, 1, 1, 1, 2, 2, 2, 3, 3, 3};
    
    char prefer_hand = (hand_pref_str == "right" ? 'R' : 'L');

    int left_hand_row = 4;
    int left_hand_col = 0;
    
    int right_hand_row = 4;
    int right_hand_col = 2;
    
    for (int num : numbers) { 
        char hand_to_use;
        int target_row = pos_info[num];
        int target_col = get_col(num, numpad_info);

        if (numpad_info[num] == 'L') {
            hand_to_use = 'L';
        } else if (numpad_info[num] == 'R') {
            hand_to_use = 'R';
        } else {
            int dist_l = abs(left_hand_row - target_row) + abs(left_hand_col - target_col);
            int dist_r = abs(right_hand_row - target_row) + abs(right_hand_col - target_col);
            
            if (dist_l < dist_r) {
                hand_to_use = 'L';
            } else if (dist_r < dist_l) {
                hand_to_use = 'R';
            } else {
                hand_to_use = prefer_hand;
            }
        }
        
        if (hand_to_use == 'L') {
            left_hand_row = target_row;
            left_hand_col = target_col;
        } else {
            right_hand_row = target_row;
            right_hand_col = target_col;
        }
        answer += hand_to_use;
    }
    
    return answer;
}