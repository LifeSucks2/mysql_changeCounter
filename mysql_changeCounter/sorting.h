#ifndef _SORTING_H_
#define _SORTING_H_

#include <vector>
#include <iostream>
#include <string>

using namespace std;

namespace sorting
{

	//************
	// QuickSort *
	//************
	void QuickSort(vector<int>& arr, int left, int right);

	//*******************
	// Helper functions *
	//*******************
	void swapVersionAli(vector<int>& arr, int element1, int element2);

}
#endif 
