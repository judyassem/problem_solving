/*
You have an empty stack and you are given some queries. These queries are the basic stack operations such as Push, Pop, 
and printing the Top element. Now, you should process the given queries.

Input
First line contains an integer T (0 <= T <= 106).
Each of the next T lines contains a query based on these formats.
1 n : Push n (0 < n <= 109) to the top of the stack.
2 : Pop an element from the top of the stack. If the stack is empty, do nothing.
3 : Print the top element of the stack (see Output Format).

Output
For each query 3, print the top element of the stack. If the stack is empty, print 'Empty!' without quotes.
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    stack<int> s;

    while(T--){
        int query;
        cin >> query;

        if(query == 1){
            int n;
            cin >> n;
            s.push(n);
        }
        else if(query == 2){
            if(!s.empty()){
                s.pop();
            }
        }
        else if(query == 3){
            if(!s.empty()){
                cout << s.top() << '\n';
            }
            else{
                cout << "Empty!\n";
            }
        }   
    }
}