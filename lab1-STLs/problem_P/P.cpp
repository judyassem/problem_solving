/*
There are n potions in a line, with potion 1 on the far left and potion n on the far right. 
Each potion increases your health by ai when drunk. 
ai can be negative, meaning that the potion decreases your health.
You start with 0 health, and you will walk from left to right, from the first potion to the last one. 
At each potion, you may choose to drink it or ignore it. You must ensure that your health is always non-negative.

What is the largest number of potions you can drink?

Input
The first line contains a single integer 
n (1≤n≤200000) — the number of potions.
The next line contains n integers a1, a2, ..., an (−109 ≤ ai ≤ 109)
which represent the change in health after drinking that potion.
Output a single integer, the maximum number of potions you can drink without your health becoming negative.
*/

#include <iostream>
#include <vector>
#include <queue> // for priority_queue
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> potions(n);
    for (int i = 0; i < n; ++i) {
        cin >> potions[i];
    }

    long long health = 0;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    int count = 0;

    for (long long potion : potions) {
        health += potion;
        minHeap.push(potion);
        count++;

        if (health < 0) {
            health -= minHeap.top();
            minHeap.pop();
            count--;
        }
    }

    cout << count << '\n';

    return 0;
}

