#include<iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;


int n, arr[N];
/*int partition(int arr[], int l, int r)
{
	int i = l - 1;
	int x = arr[r];
	for (int j = l; j < r; j++)
	{
		if (arr[j] < x)
		{
			swap(arr[i + 1], arr[j]);
			i++;
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}

void Quick_sort(int arr[], int l, int r)
{
	if (l >= r)return;
	int p = partition(arr, l, r);
	Quick_sort(arr, l, p - 1);
	Quick_sort(arr, p + 1, r);
}
*/
pair<int, int>partition3(int arr[], int l, int r)
{
	vector<int>idx;
	pair<int, int>pa;
	int ra = rand() % (r - l + 1) + l;
	swap(arr[r], arr[ra]);
	int i = l - 1;
	int x = arr[r];
	for (int j = l; j < r; j++)
	{
		if (arr[j] < x)
		{
			swap(arr[i + 1], arr[j]);
			i++;
		}
	}
	swap(arr[i + 1], arr[r]);
	int pivot_idx = i + 1;
	int last = pivot_idx - 1;
	bool canBe1 = false;
	for (int k = pivot_idx - 1; k >= l; k--)
	{
		if (arr[k] == arr[pivot_idx])
		{
			canBe1 = true;
			swap(arr[k], arr[last]);
			last--;
		}
	}
	if(canBe1)
	{
		pa.first = last + 1;
	}
	else
	{
		pa.first = pivot_idx;
	}
	
	last = pivot_idx + 1;
	bool canBe2 = false;
	for (int k = pivot_idx + 1; k <= r; k++)
	{
		if (arr[k] == arr[pivot_idx])
		{
			canBe2 = true;
			swap(arr[k], arr[last]);
			last++;
		}
	}
	if (canBe2)
	{
		pa.second = last - 1;
	}
	else
	{
		pa.second = pivot_idx;
	}
	return pa;
}

void Quick_sort3(int arr[], int l, int r)
{
	if (l >= r||l<0||r>=n)return;
	pair<int, int>m = partition3(arr, l, r);
	int m1 = m.first;
	int m2 = m.second;
	Quick_sort3(arr, l, m1 - 1);
	Quick_sort3(arr, m2 + 1, r);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	Quick_sort3(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	//system("pause");
	return 0;
}