#include <iostream>
using namespace std;

int main() {
	// your code goes here
	float n,m;
	cin >> n >> m;
	if( n < m && (int)n % 5 == 0){
	    
	    float temp = m - n - 0.5;
	    cout << temp;
	}
	else {
	    cout << m;
	}
	return 0;
}
