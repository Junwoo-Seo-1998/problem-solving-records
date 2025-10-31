#include <iostream>

int main(){
    int n, sum = 0;
    for (int i = 0; i < 5; i++){
        std::cin>>n;
        sum += n * n;
    }
    std::cout<<sum%10;
    return 0;
}