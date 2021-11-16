//https://www.geeksforgeeks.org/set-bits-n-equals-m-given-range/

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

bool getBit(int num, int i)
{
	// create a mask
	int mask = (1 << i);
	int result = num & mask;
	return result > 0;  // >0 => 1 ,,, ==0 =>0
}

int setBit(int num, int i)
{
	int mask = (1 << i);
	int result = num | mask;
	return result;
}

int clearBit(int num, int i)
{
	int mask = ~(1 << i);
	int result = num & mask;
	return result;
}




int main()
{	
	int n, m, i, j;
	cin >> n >> m >> i >> j;
	int m_index = 0;
	for (int position = i; position <= j; position++)
	{
		// at each position in n the bit will be set or cleared according to m
		bool bit = getBit(m, m_index);
		if (bit) // bit=1
		{
			n = setBit(n, position);
		}
		else
		{
			n = clearBit(n, position);
		}
		m_index++;
	}
	cout << n << endl;


	return 0;
}