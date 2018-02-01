#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void bubbleSort(vector<int> &arr)
{
	bool swap_happened = true;
	for(int i = 0; i < arr.size() - 1 && swap_happened; i++)
	{
        swap_happened = false;
		// Every iteration finalizes the position of one more element
		for(int j = 0; (j < arr.size() - 1 - i); j++)
		{
			if(arr[j+1] < arr[j])
			{
				swap(arr[j], arr[j+1]);
				swap_happened = true;
			}
		}
	}
}

void printArray(const vector<int> &arr)
{
	for(auto &ele : arr)
	{
		cout<<ele<<" ";
	}
	cout<<endl;
}
int main()
{
	// Will create vector to be sorted and call the sorting function
	vector<int> arr {5, 7, 2, 10, 4, 1};
	printArray(arr);
	bubbleSort(arr);
	printArray(arr);
	return 0;
}
