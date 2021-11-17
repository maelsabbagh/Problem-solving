#include <iostream>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include <string>
using namespace std;

int fastPower(int a, int n) // O(log N)
{
	int answer = 1;
	while (n)
	{
		if (n & 1)
		{
			answer = answer * a;
		}
		a = a * a;
		n=n >> 1;
	}
	return answer;
	
}



int main()
{	
	int a, n;
	cin >> a >> n;
	cout << fastPower(a, n) << endl;

	return 0;
}