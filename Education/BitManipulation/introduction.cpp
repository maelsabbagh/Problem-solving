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

int getBit(int num, int i) // i=> ith position for the bit
{
	/*
	1- create mask
	2- mask and with the number
	3- if result ==0 => bit=0
	4- if result >0 => bit=1
	*/
	int mask = 1 << i;
	int result = mask & num;
	return result > 0;
}

int setBit(int num, int i) //i = > ith position for the bit
// set bit and return a number after setting the bit
{
	/*
	create a mask
	number or with the mask

	*/

	int mask = (1 << i);
	int answer = num | mask;
	return answer;
}

void setBitByRef(int &num, int i) //i = > ith position for the bit
{
	int mask = (1 << i);
	num = num | mask;
}





int main()
{
	// test for get bit
	/*  
	int n;
	cin >> n;
	while (n--)
	{

		int num, i;
		cin >> num >> i;
		cout << getBit(num, i) << endl;
	}

	*/

	// test for set bit
	
	/*
	int n;
	cin >> n;
	while (n--)
	{

		int num, i;
		cin >> num >> i;
		cout << setBit(num, i) << endl;
	}
	*/
	
	// test for set bit by reference
	int n;
	cin >> n;
	while (n--)
	{

		int num, i;
		cin >> num >> i;
		setBitByRef(num, i);
		cout << getBit(num, i) << endl;
		
	}



	return 0;
}