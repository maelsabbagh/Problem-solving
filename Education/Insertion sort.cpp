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



int main()
{
	
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	insertion_sort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}