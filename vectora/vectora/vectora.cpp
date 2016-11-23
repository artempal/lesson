// vectora.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	vector<int>arr(10);

	//vector <int> arr;
	//arr.resize(300);
	//arr.clear();
	//arr.reserve(10);
	for (int i = 0; i < 10; i++)
		arr.at(i) = i;
	//arr.push_back(5);
	
	//arr[2] = 5;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
		arr.at(i);
	}
	vector<int>::iterator it;
	for (auto it = arr.rbegin(); it != arr.rend(); it++)
		cout << *it << " ";
	cout << endl;
	arr.insert(arr.begin()+2, 8);
	sort(arr.begin(), arr.end());
	//arr.erase(b + 2, b + 2);
	for (auto it : arr) cout << it;
    return 0;
}