/*
Mad scientist Mike has just finished constructing a new device to search for extraterrestrial intelligence! 
He was in such a hurry to launch it for the first time that he plugged in the power wires without giving it a proper glance 
and started experimenting right away. After a while Mike observed that the wires ended up entangled and now have to be untangled again.

The device is powered by two wires "plus" and "minus". 
The wires run along the floor from the wall (on the left) to the device (on the right). 
Both the wall and the device have two contacts in them on the same level, into which the wires are plugged in some order. 
The wires are considered entangled if there are one or more places where one wire runs above the other one. 
For example, the picture below has four such places (top view):


Mike knows the sequence in which the wires run above each other. 
Mike also noticed that on the left side, the "plus" wire is always plugged into the top contact (as seen on the picture). 
He would like to untangle the wires without unplugging them and without moving the device. 
Determine if it is possible to do that. A wire can be freely moved and stretched on the floor, but cannot be cut.

Input
The single line of the input contains a sequence of characters "+" and "-" of length n (1 ≤ n ≤ 100000). 
The i-th (1 ≤ i ≤ n) position of the sequence contains the character "+", if on the i-th step from the wall the "plus" wire runs above the "minus" wire, 
and the character "-" otherwise.

Output
Print either "Yes" (without the quotes) if the wires can be untangled or "No" (without the quotes) if the wires cannot be untangled.

*/

// if there is equal number of + and - 

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    stack<char> st;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    cout << (st.empty() ? "Yes" : "No") << '\n';

    return 0;
}