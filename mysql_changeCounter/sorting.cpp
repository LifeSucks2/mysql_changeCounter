#include "sorting.h"

namespace sorting {
	void swapVersionAli(vector<int>& arr, int element1, int element2)
	{
		int tmp = arr[element1];
		arr[element1] = arr[element2];
		arr[element2] = tmp;
	}
	//************
	// QuickSort *
	//************      
	void QuickSort(vector<int>& arr, int left, int right)
	{
		if (left < right)
		{
			int l = left, r = right - 1, pivot = right;
			while (l < r)
			{
				while (arr[l] <= arr[pivot] && l < right)
					l++;
				while (arr[r] > arr[pivot] && r > left)
					r--;
				if (l < r)
					swapVersionAli(arr, l, r);
			}
			if (l < arr.size() && arr[l] > arr[pivot])
			{
				swapVersionAli(arr, l, pivot);
			}
			QuickSort(arr, left, l - 1);
			QuickSort(arr, l + 1, right);
		}
	}
}


