#include <iostream>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
    int y;
 
    cin >> y;
 
    if (y % 4 == 0) {
        if (y % 400 == 0) {     // 4의 배수이면서 400의 배수일 때(=윤년)
            cout << 1;
        } 
        else if (y % 100 != 0) {    // 4의 배수이면서 100의 배수가 아닐 때(=윤년) 
            cout << 1;
        } 
        else {
            cout << 0;
        }
    } else {
        cout << 0;
    }
 
    return 0;
}