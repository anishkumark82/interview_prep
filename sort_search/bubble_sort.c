#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void bubbleSort(vector &arr)
{
	bool swap_happened = false;
	for(int i = 0; i < arr.size() - 1; i++)
	{

		// Every iteration finalizes the position of one more element
		for(int j = 0; (j < arr.size() - 1 - i) && swap_happened; j++)
		{
			swap_happened = false;
			if(a[j+1] < a[j])
			{
				swap(a[j], a[j+1]);
				swap_happened = true;
			}
		}
	}
}

void printArray(const vector &arr)
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
	vector arr(5) {5, 7, 2, 10, 4, 1};
	printArray(arr);
	bubbleSort(arr);
	printArray(arr);
	return 0;
}
