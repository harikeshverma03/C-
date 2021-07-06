// CPP program to illustrate
// std::find
// CPP program to illustrate
// std::find
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	vector<int> vec { 10, 20, 30, 40, 50, 60, 70 };
	
	// Iterator used to store the position
	// of searched element
	// vector<int>::iterator it;
	
	// Print Original Vector
	std::cout << "Original vector :";
	for (int i=0; i<vec.size(); i++)
		cout << " " << vec[i];	
	cout << "\n";
	
	auto const it1 = upper_bound (vec.begin(), vec.end(), 50); //returns strictly greater than value <
    auto const it2 = lower_bound (vec.begin(), vec.end(), 50); // returns greater than or equal to <=
	if (it1 != vec.end() || it2 != vec.end())
	{
		cout << "Element " << 60 <<" found at position : " ;
		cout << it1 - vec.begin() << " (counting from zero) \n" ;
        cout << it2 - vec.begin() << " (counting from zero) \n" ;
	}
	else
		cout << "Element not found.\n\n";
		
	return 0;
}
