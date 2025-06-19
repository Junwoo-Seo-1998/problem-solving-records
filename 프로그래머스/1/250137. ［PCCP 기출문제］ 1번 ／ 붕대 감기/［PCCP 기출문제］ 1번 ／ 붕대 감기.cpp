#include <string>
#include <vector>
#include <algorithm> // std::min 사용

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {

    int t = bandage[0]; 
    int x = bandage[1]; 
    int y = bandage[2]; 

    int maxHealth = health;
    int currentHealth = health;
    int lastAttackTime = 0;

    for (const auto& attack : attacks) {
        int attackTime = attack[0];
        int damage = attack[1];

        int timeDiff = attackTime - lastAttackTime - 1;

        if (timeDiff > 0) {
            currentHealth += timeDiff * x;

            int bonusHealCount = timeDiff / t;
            if (bonusHealCount > 0) {
                currentHealth += bonusHealCount * y;
            }

            currentHealth = min(maxHealth, currentHealth);
        }

        currentHealth -= damage;

        if (currentHealth <= 0) {
            return -1;
        }

        lastAttackTime = attackTime;
    }

    return currentHealth;
}