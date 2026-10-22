/*
Given two strings, determine if they share a common substring. A substring may be as small as one character.

Input Format
The first line contains a single integer p, the number of test cases.

The following p pairs of lines are as follows:

The first line contains string s1.
The second line contains string s2.

Output Format
For each pair of strings, return YES or NO.

*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int p;
    cin >> p;

    while (p--) {
        string s1, s2;
        cin >> s1 >> s2;

        set<char> charsInS2(s2.begin(), s2.end());

        bool found = false;

        for (char c : s1) {
            if (charsInS2.count(c)) {
                found = true;
                break;
            }
        }

        cout << (found ? "YES" : "NO") << '\n';
    }

    return 0;
}