/*
We have an empty sequence A. 
You will be given Q queries, which should be processed in the order they are given. Each query is of one of the three kinds below:

1 x : Append x to the end of A
2 : Print the element at the beginning of A. Then, delete that element. It is guaranteed that A will not empty when this query is given.
3 : Sort A in ascending order.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int Q;
    cin >> Q;
    queue<int> A;
    priority_queue<int, vector<int>, greater<>> pq;

    while (Q--)
    {
        int n;
        cin >> n;

        switch (n)
        {
        case 1:
            {
                int x;
                cin >> x;
                A.push(x);
            }
            break;
        case 2:
            {
                if(!pq.empty()){
                    cout << pq.top() << "\n";
                    pq.pop();
                }else{
                    cout << A.front() << "\n";
                    A.pop();
                }   
            }
            break;
        case 3:
            {
                while (!A.empty())
                {
                    pq.push(A.front());
                    A.pop();
                }
                
            }
        default:
            break;
        }
    }
    
    return 0;
}