#include <iostream>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include <string>
#include<algorithm>
using namespace std;


bool canPlace(vector<int>&coordinates, int distance, int cows_number)
{
	int n = coordinates.size();
	int last_coordinate = coordinates[0];
	int placed_cows = 1;

	for (int i = 1; i < n; i++)
	{
		// check if we can place this cow here with a distance greater than or equal to the minimum distance
		if (coordinates[i] - last_coordinate >= distance)
		{
			last_coordinate = coordinates[i];
			placed_cows++;
		}
		if (placed_cows == cows_number)return true;
	}
	return false;
}


int main() {

	int t;
	cin >> t;
	while (t--)
	{
		// take input
		int stalls, cows;
		cin >> stalls >> cows;
		vector<int>coords; // coords -> coordinates
		for (int i = 0; i < stalls; i++)
		{
			int x;
			cin >> x;
			coords.push_back(x);
		}

		// sort coordinates
		sort(coords.begin(), coords.end());

		// create a search space
		int start = 1;
		int end = coords[stalls - 1] - 1;

		// perform binary search
		int ans = -1;

		while (start <= end)
		{
			int middle = (start + end) / 2;
			if (canPlace(coords, middle, cows))
			{
				ans = middle;
				start = middle + 1;
			}
			else
			{
				end = middle - 1;
			}


		}
		cout << ans << endl;
	}
	return 0;
}