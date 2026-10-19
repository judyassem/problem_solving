/*
There are n children in Jzzhu's school. Jzzhu is going to give some candies to them. 
Let's number all the children from 1 to n. The i-th child wants to get at least ai candies.

Jzzhu asks children to line up. 
Initially, the i-th child stands at the i-th place of the line. Then Jzzhu start distribution of the candies. 
He follows the algorithm:

Give m candies to the first child of the line.
If this child still haven't got enough candies, then the child goes to the end of the line, else the child go home.
Repeat the first two steps while the line is not empty.
Consider all the children in the order they go home. Jzzhu wants to know, which child will be the last in this order?

Input
The first line contains two integers n, m (1 ≤ n ≤ 100; 1 ≤ m ≤ 100). 
The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 100).

Output
Output a single integer, representing the number of the last child.
*/


#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> queue;

    for (int i = 0; i < n; i++){
        if(arr[i] > m){
            arr[i] -= m;
            queue.push_back(i + 1);
        }
    }

    if(queue.empty()){
        cout << n << endl;
        return 0;
    }

    while (queue.size() > 1) {
        int child = queue.front();
        queue.erase(queue.begin());

        if (arr[child - 1] > m) {
            arr[child - 1] -= m;
            queue.push_back(child);
        }
    }

    cout << queue.front() << endl;
}