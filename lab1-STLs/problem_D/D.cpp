/*
There will be a launch of a new, powerful and unusual collider very soon, which located along a straight line.
n particles will be launched inside it. 
All of them are located in a straight line and there can not be two or more particles located in the same point.
The coordinates of the particles coincide with the distance in meters from the center of the collider, 
xi is the coordinate of the i-th particle and its position in the collider at the same time. 
All coordinates of particle positions are even integers.

You know the direction of each particle movement — it will move to the right or to the left after the collider's launch start. 
All particles begin to move simultaneously at the time of the collider's launch start. 
Each particle will move straight to the left or straight to the right with the constant speed of 1 meter per microsecond. 
The collider is big enough so particles can not leave it in the foreseeable time.

Write the program which finds the moment of the first collision of any two particles of the collider. 
In other words, find the number of microseconds before the first moment when any two particles are at the same point.

Input
The first line contains the positive integer n (1 ≤ n ≤ 200 000) — the number of particles.

The second line contains n symbols "L" and "R". If the i-th symbol equals "L", then the i-th particle will move to the left, 
otherwise the i-th symbol equals "R" and the i-th particle will move to the right.

The third line contains the sequence of pairwise distinct even integers x1, x2, ..., xn (0 ≤ xi ≤ 109) — 
the coordinates of particles in the order from the left to the right. 
It is guaranteed that the coordinates of particles are given in the increasing order.

Output
In the first line print the only integer — the first moment (in microseconds) when two particles are at the same point
and there will be an explosion.

Print the only integer -1, if the collision of particles doesn't happen.
*/


#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<char> directions(n);
    vector<int> positions(n);
    for(int i = 0; i < n; i++){
        cin >> directions[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    // collision happens when RL
    int min_time = -1;
    for(int i = 0; i < n - 1; i++){
        if(directions[i] == 'R' && directions[i + 1] == 'L'){
            int time = (positions[i + 1] - positions[i]) / 2;
            if(min_time == -1 || time < min_time){
                min_time = time;
            }
        }
    }

    cout << min_time << endl;
}