#include<iostream>
#include<vector>
#include<string>
using namespace std;



vector<int> sortArray(vector<int>& nums)
{

	for (int i = 0; i < nums.size(); i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[j] < nums[min_idx])
			{
				min_idx = j;
			}
		}
		swap(nums[i], nums[min_idx]);
	}
	return nums;
}

int main()
{
	vector<int>v = { -1,2,-8,-10 };
	v = sortArray(v);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	
	system("pause");
	return 0;
}