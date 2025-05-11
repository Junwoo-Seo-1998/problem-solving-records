#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> people(3, vector<int>());
    people[0] = {1, 2, 3, 4, 5};
    people[1] = {2, 1, 2, 3, 2, 4, 2, 5};
    people[2] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int indexFirstPeople = 0;
    int indexSecondPeople = 0;
    int indexThirdPeople = 0;
    
    vector<int> correct(3, 0);
    
    
    for (int i : answers) {

        i == people[0][indexFirstPeople] ? correct[0]++ : 0;
        i == people[1][indexSecondPeople] ? correct[1]++ : 0;
        i == people[2][indexThirdPeople] ? correct[2]++ : 0;

        ++indexFirstPeople == people[0].size() ? indexFirstPeople = 0 : 0;
        ++indexSecondPeople == people[1].size() ? indexSecondPeople = 0 : 0;
        ++indexThirdPeople == people[2].size() ? indexThirdPeople = 0 : 0;
    }
    int max = *max_element(correct.begin(), correct.end());
    
    vector<int> answer;
    for (int i = 0; i < correct.size(); i++) {
        if (correct[i] == max) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}