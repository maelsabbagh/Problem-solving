#include <iostream>

using namespace std;

int partition(int arr[], int p, int r)
{
	
	int q = arr[r]; //pivot
	int i = p-1;
	for (int j = p; j < r; j++)
	{
		if (arr[j] < q)
		{
			swap(arr[i + 1], arr[j]);
			i++;
		}
	}
	swap(arr[i + 1], arr[r]);
	return (i + 1);
}

void QuickSort(int arr[], int p, int r)
{
	
	if (p >= r) return;

	int q = partition(arr, p, r);
	QuickSort(arr, p, q-1);
	QuickSort(arr, q + 1, r);
}


int main()
{
	int n;
	cout << "Enter the number of elements" << endl;
	cin >> n;
	cout << "Enter the elements" << endl;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	QuickSort(arr, 0, n - 1);
	cout << "Sorted array: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	//system("pause");
	return 0;
}