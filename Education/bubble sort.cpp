#include<iostream>
#include<vector>
#include<string>
using namespace std;

void insertion_sort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int e = arr[i];
		int j = i-1;
		while (e < arr[j] && j>=0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = e;
	}
}

void bubble_sort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}


/*void Insertion_sort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int e = arr[i];
		int j = i - 1;
		while (e < arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = e;
	}
}
*/


int main()
{
	
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	bubble_sort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}