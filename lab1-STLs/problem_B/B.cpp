/*
A left rotation operation on a circular array shifts each of the array's elements one unit to the left.
The elements that fall off the left end reappear at the right end. 
Given an integer , rotate the array that many steps to the left and return the result
*/


#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    while(d--){
        int temp = arr[0];
        for(int i = 1; i < n; i++){
            arr[i - 1] = arr[i];
        }
        arr[n] = temp;
    }

    for(int i = 0; i < n; ++i){
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}