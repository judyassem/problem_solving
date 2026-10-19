/*
Little girl Tanya climbs the stairs inside a multi-storey building. 
Every time Tanya climbs a stairway, she starts counting steps from 1 to the number of steps in this stairway.
She speaks every number aloud. For example, if she climbs two stairways, the first of which contains 3 steps, 
and the second contains 4 she will pronounce the numbers 1,2,3,1,2,3,4.
You are given all the numbers pronounced by Tanya. How many stairways did she climb? 
Also, output the number of steps in each stairway.
The given sequence will be a valid sequence that Tanya could have pronounced when climbing one or more stairways.


Input
The first line contains n (1 ≤ n ≤1000) — the total number of numbers pronounced by Tanya.

The second line contains integers a1,a2,…,an (1 ≤ ai ≤1000) — all the numbers Tanya pronounced while climbing the stairs, 
in order from the first to the last pronounced number. 
Passing a stairway with x steps, she will pronounce the numbers 1,2,…,x in that order.
The given sequence will be a valid sequence that Tanya could have pronounced when climbing one or more stairways.

Output
In the first line, output t — the number of stairways that Tanya climbed. 
In the second line, output t numbers — the number of steps in each stairway she climbed. 
Write the numbers in the correct order of passage of the stairways.
*/


#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //every 1 is a new stairway
    //number of steps is the number before the 1

    int stairways = 0;
    vector<int> steps;

    for (int i = 0; i < n; i++){
        if(arr[i] == 1){
            stairways++;
            if(i > 0){
                steps.push_back(arr[i - 1]);
            }
        }
    }

    steps.push_back(arr[n - 1]);

    cout << stairways << endl;
    for(int step : steps){
        cout << step << " ";
    }
    cout << endl;

}