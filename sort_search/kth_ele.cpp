// find kth smallest and kth largest element in unsorted array
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool findKthSmallest(vector<int> arr, int k, int &value)
{
	// Boundary condition check
	if(k >= arr.size() || (k <= 0))
	{
		return -1;
	}

	// sort the array -- In ascending order
	sort(arr.begin(), arr.end());
	value = arr[k-1];
	return 0;
}

bool compare(int &x, int &y)
{
	return x > y;
}
bool findKthLargest(vector<int> arr, int k, int &value)
{
	// Boundary condition check
	if(k >= arr.size() || (k <= 0))
	{
		return -1;
	}

	// sort the array -- In ascending order
	sort(arr.begin(), arr.end(), greater<int>());
	//sort(arr.begin(), arr.end(), compare);

	value = arr[k-1];
	return 0;
}

int main()
{
	vector<int> arr{5, 2, 8, 1, 0, 10};

	int value = 0;
	int k;
	cin>>k;
	if(findKthSmallest(arr, k, value) != -1)
	{
		cout<<"kth smallest element : "<<value<<endl;
	}
	else
	{
		cout<<"Invalid kth index "<<k<<endl;
	}
	if(findKthLargest(arr, k, value) != -1)
	{
		cout<<"kth largest element : "<<value<<endl;
	}
	else
	{
		cout<<"Invalid kth index "<<k<<endl;
	}

	return 0;
}
