#include <iostream>
#include <string> 
#include <algorithm>
#include <vector> 
#include <set>
using namespace std;

const int MAX = 51; 
int arr[MAX]; 
int N, S;

void input() {
	cin >> N; 

	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}

	cin >> S; 
}

void solution() {
	int start = 0;

	// S번 이하의 스왑으로 
	// 최댓값을 start 위치로 끌어오기
	while(start < N && S > 0) {
		int maxIdx = start; 

		// [start, start + S] 범위의 원소들 중에서 
		// 최댓값의 인덱스 저장 
		for(int i = start; i <= min(N - 1, start + S); i++){
			if(arr[maxIdx] < arr[i]) maxIdx = i; 
		}

		// 최댓값을 start 위치로 한칸씩 앞당기면서 S값 차감 
		for(int i = maxIdx; i > start; i--){
			swap(arr[i], arr[i - 1]);
			S--; 
		}

		start++;
	}

	for(int i = 0; i < N; i++){
		cout << arr[i] << " ";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	solution(); 

	return 0;
}