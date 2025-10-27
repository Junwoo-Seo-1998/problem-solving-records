#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string s;
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
	int l;
	long long m = 1234567891;
	long long r = 1;
	long long sum = 0;
	cin >> l;
	cin >> s;
	for (int i = 0; i < l; i++)
	{
		sum += ((long(s[i]) - 96) * r)%m;
		r = (r*31)%m;
	}
	cout << sum % m;
}