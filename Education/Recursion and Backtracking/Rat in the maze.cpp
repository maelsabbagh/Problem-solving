#include <iostream>
#include <string>
using namespace std;

/*
A rat is located in the cell (0,0) and it want to reach the end of the maze where at some points there are blocks
the rat only moves right or down
show all the paths that a rabbit can move
*/
const int N = 10;
int n;
char maze[N][N];
bool isValid(int r, int c)
{
	if (r >= 0 && r < n && c >= 0 && c < n && maze[r][c] != 'X')
		return true;
	return false;
}

void find_path(int r, int c, string sol) //O(2^n)
{
	if (maze[r][c] == 'E') // base case
	{
		cout << sol << endl;
		return;
	}

	if (isValid(r, c + 1))
	{
		sol = sol + 'R';
		find_path(r, c + 1, sol);
		sol.pop_back();
	}
	if (isValid(r + 1, c))
	{
		sol = sol + 'D';
		find_path(r + 1, c, sol);
		sol.pop_back();
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
		}
	}
	string ans;
	find_path(0, 0, ans);

	//system("pause");
	return 0;
}

/*
3
R.X
...
..E
*/

/*
4
R...
XXX.
....
...E
*/