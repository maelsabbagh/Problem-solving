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


bool canCook(vector<int>&ranks, int pratas, int barrier)
{
	int total_pratas_cooked = 0;
	for (int i = 0; i < ranks.size(); i++)
	{
		int totaltime = 0;
		int current_rank = ranks[i];
		int j = 1;
		while (totaltime + (j*current_rank) <= barrier)
		{
			totaltime += j * current_rank;
			j++;
			total_pratas_cooked++;
			if (total_pratas_cooked >= pratas)return true;
		}
	}

	return total_pratas_cooked >= pratas;
}


int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int pratas;
		int no_of_cooks;
		vector<int>rank;

		// take input 
		cin >> pratas;
		cin >> no_of_cooks;

		for (int i = 0; i < no_of_cooks; i++)
		{
			int r;
			cin >> r;
			rank.push_back(r);
		}

		// create a search space

		int start = 1, end = 2e9;

		// perform binary search
		int answer = -1;
		while (start <= end)
		{
			int middle = (start + end) / 2; // middle represent time

			if (canCook(rank, pratas, middle))
			{
				answer = middle;
				end = middle - 1;
			}
			else
			{
				start = middle + 1;
			}


		}
		cout << answer << endl;
	}

	return 0;
}