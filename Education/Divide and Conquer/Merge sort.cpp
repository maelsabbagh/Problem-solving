// Merge sort O(N log(N))
// Enter the number of elements then enter the elements of the array
// ouptut: sorted array


#include <iostream>
using namespace std;


void merge(int arr[],int s,int m,int e)
{
	int s1 = (m - s) + 1;
	int s2 = (e - (m +1)) + 1;
	int *arr1 = new int[s1]; // create a temp1 array
	int *arr2 = new int[s2]; // create a temp2 array
	int a = 0;
	for (int i = s; i <= m; i++) // copy the first half into temp1 array
	{
		arr1[a] = arr[i];
		a++;
	}
	a = 0;
	for (int i = m + 1; i <= e; i++) // copy the second half into temp2 array
	{
		arr2[a] = arr[i];
		a++;
	}
	int i = 0, j = 0;
	for (int k = s; k <= e; k++) // merging the 2 temp arrays into the original one
	{
		if (i == s1)
		{
			arr[k] = arr2[j];
			j++;
			continue;
		}
		if (j == s2)
		{
			arr[k] = arr1[i];
			i++;
			continue;
		}
		if (arr1[i] < arr2[j])
		{
			arr[k] = arr1[i];
			i++;
		}
		else
		{
			arr[k] = arr2[j];
			j++;
		}
	}
}
void merge_sort( int arr[],int s, int e)
{
	if (s == e)return;
	int m = (s + e) / 2;
	merge_sort(arr,s, m);
	merge_sort(arr, m + 1, e);
	merge(arr, s, m, e);
}


int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	merge_sort(arr,0, n-1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}


	//system("pause");
	return 0;
}
