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
	while (placed_cows<cows_number)
	{
		auto it = lower_bound(coordinates.begin(), coordinates.end(), last_coordinate + distance);
		if (it == coordinates.end())return false;
		last_coordinate =coordinates[ it - coordinates.begin()];
		placed_cows++;
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