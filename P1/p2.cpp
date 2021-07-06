#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
	    int k = 0;
        int arr[3];
	    for(int j =0; j < 3; j++){
	        cin >> arr[j];
	    }
        if(arr[0] + arr[1] == arr[2]){
            cout << "YES" << endl;
            continue;
        }
        else if(arr[0] + arr[2] == arr[1]){
            cout << "YES" << endl;
            continue;
        }
        else if(arr[2] + arr[1] == arr[0]){
            cout << "YES" << endl;
            continue;
        }
        else
            cout << "NO" << endl;
	}
	return 0;
}
