#include <string>
#include <vector>
#include <numeric>   // accumulate는 직접 사용 안하지만, numeric 헤더에 유용한 함수들이 많습니다.
#include <algorithm> // max 함수 사용을 위해

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int last_house_idx = n - 1;
    while (last_house_idx >= 0) {
        if (deliveries[last_house_idx] == 0 && pickups[last_house_idx] == 0) {
            last_house_idx--;
        } else {
            break;
        }
    }
    
    if (last_house_idx < 0) {
        return 0;
    }

    long long current_deliveries_needed = 0; 
    long long current_pickups_to_make = 0;

    for (int i = last_house_idx; i >= 0; --i) {
        current_deliveries_needed += deliveries[i];
        current_pickups_to_make += pickups[i];
        while (current_deliveries_needed > 0 || current_pickups_to_make > 0) {
            answer += (long long)(i + 1) * 2;
            
            current_deliveries_needed -= cap;
            current_pickups_to_make -= cap;
        }
    }

    return answer;
}