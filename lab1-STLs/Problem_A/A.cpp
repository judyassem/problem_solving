/*
Vitaly has an array of n distinct integers. Vitaly wants to divide this array into three non-empty sets so as the following conditions hold:

The product of all numbers in the first set is less than zero (< 0).
The product of all numbers in the second set is greater than zero (> 0).
The product of all numbers in the third set is equal to zero.
Each number from the initial array must occur in exactly one set.
Help Vitaly. Divide the given array.

Input
The first line of the input contains integer n (3 <= n <= 100). The second line contains n space-separated distinct integers a1, a2, ..., an (|ai| <= 103) — the array elements.

Output
Print the sizes and elements of the three sets. The sets must satisfy the conditions above.



#include<iostream>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    set<int> s1, s2, s3;
    set<int> negative;
    int negInS2 = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0) {
            negative.insert(a[i]);
        }
    }



    //number of negative numbers in s1 has to be odd
    //number of negative numbers in s2 has to be even
    //s3 has to have a zero
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0 && s1.empty())
        {
            s1.insert(a[i]);
        }
        else if (a[i] > 0) {
            s2.insert(a[i]);
        }
        else if (a[i] < 0 && s2.empty()) {
            s2.insert(a[i]);
            negInS2++;
        }
        else if (a[i] < 0 && negInS2 % 2 == 1) {
            s2.insert(a[i]);
            negInS2++;
        }
        else {
            s3.insert(a[i]);
        }
    }
    
    cout << s1.size() << " ";
    for (int x : s1)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << s2.size() << " ";
    for (int x : s2)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << s3.size() << " ";
    for (int x : s3)
    {
        cout << x << " ";
    }
    cout << endl;
}
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> negative, positive, zero;

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;

        if (value < 0) {
            negative.push_back(value);
        } else if (value > 0) {
            positive.push_back(value);
        } else {
            zero.push_back(value);
        }
    }

    if (negative.size() % 2 == 0) { //even number of negative numbers
        zero.push_back(negative.back()); //put one negative number in the zero set to make number of negative numbers in the negative set odd & the number of negative numbers in the positive set even
        negative.pop_back();
    }

    if (positive.empty()) { //no postive numbers
        positive.push_back(negative.back());
        negative.pop_back();
        positive.push_back(negative.back());
        negative.pop_back();
    }

    cout << negative.size();
    for (int value : negative) {
        cout << ' ' << value;
    }
    cout << '\n';

    cout << positive.size();
    for (int value : positive) {
        cout << ' ' << value;
    }
    cout << '\n';

    cout << zero.size();
    for (int value : zero) {
        cout << ' ' << value;
    }
    cout << '\n';

    return 0;
}
