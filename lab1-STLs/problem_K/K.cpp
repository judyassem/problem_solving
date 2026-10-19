/*
You have an empty queue and your boss has some queries. These queries are queue's basic operations such as Enqueue, Dequeue, and printing some values. Now, your boss asks you to process his queries.

Input
First line contains an integer T (0 <= T <= 106).

Each of the T next lines contains a query based on these formats.

1 n : Enqueue n (-109 <= n <= 109) to the queue.

2 : Dequeue an element from the queue. If the queue is empty, do nothing.

3 : Print the queue's first element's value (see Output).

Output
For each query 3, print the queue's first element's value. If the queue is empty, print 'Empty!' without quotes.
*/


#include <iostream>
#include <queue>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    queue<int> q;

    while(T--){
        int query;
        cin >> query;

        if(query == 1){
            int n;
            cin >> n;
            q.push(n);
        }
        else if(query == 2){
            if(!q.empty()){
                q.pop();
            }
        }
        else if(query == 3){
            if(!q.empty()){
                cout << q.front() << '\n';
            }
            else{
                cout << "Empty!\n";
            }
        }
    }
}
