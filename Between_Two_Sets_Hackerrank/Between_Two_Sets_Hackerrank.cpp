/** 
* Between_Two_Sets_Hackerrank.cpp 
* Author: Walt Iddings
* Date: 12/3/20
* 
* This program has two arrays as inputs. It then determines the integers of the
* first array that are factors of the integers between the last element of the
* first array and the first element of the second array. It then determines  and 
* counts which integers of the last step that are factors of the integers in the 2nd 
* array. The instructions on HackerRank are in the ReadMe file.
**/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void getTotalX(vector<int> a, vector<int> b) {  // Return should be an int
	// Initialize iterators
	auto it1 = a.begin();
	auto it2 = b.begin();

	bool isFactor = false;  // Used to keep track if it is a factor
	int count = 0;  // Keeps track of answer
	
	
	vector<int> factors1{};  // Vector for storing integers in the first step
	vector<int> factors2{};  // Vector for storing integers in the second step

	// Declare vector to store integers that are factors of integers between arrays
	vector<int> firstArrayFactors{};

	// Calculate firstArrayFactors elements
	// int i = a.back();
	for (int i = a.back(); i <= b.front() ; i++) {
		isFactor = false;  // Reset the value
		it1 = a.begin();  // Initialize factors iterator
		
		// Check if integer between array has factors of array a
		while (it1 != a.end()) {
			if (i % *it1 == 0)
				isFactor = true;
			else {
				isFactor = false;
				break;
			}
				
			++it1;
		}
		if (isFactor)
			factors1.push_back(i);
	}

	// Output first factors
	cout << "The factors for the first step is/are: ";
	auto it3 = factors1.begin();  // Initialize factors iterator
	while (it3 != factors1.end()) {
		cout << *it3 << " ";
		++it3;
	}
	cout << endl;

	// Calculate secondArrayFactor elements
	it2 = b.begin();
	it3 = factors1.begin();
	while (it3 != factors1.end()) {
		it2 = b.begin();  // Initialize iterator
		isFactor = false;
		while (it2 != b.end()) {
			if (*it2 % *it3 == 0)
				isFactor = true;
			else {
				isFactor = false;
				break;
			}
			++it2;
		}
		if (isFactor) {
			factors2.push_back(*it3);
			++count;
		}
		++it3;
	}

	// Output second factors
	cout << "The factors for the second step is/are: ";
	auto it4 = factors2.begin();  // Initialize factors iterator
	while (it4 != factors2.end()) {
		cout << *it4 << " ";
		++it4;
	}
	cout << endl;

	cout << "The number of integers that are factors between the two arrays is: " << count << endl;
}


int main()
{
	// Declare and initialize two vectors
	vector<int> vec1{ 1 };
	vector<int> vec2{ 72, 48 };

	getTotalX(vec1, vec2);
}

