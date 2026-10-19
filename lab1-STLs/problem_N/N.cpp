/*
Implement a simple text editor. The editor initially contains an empty string, S . Perform Q operations of the following  types:

1.append(w) - Append string w to the end of S .
2.delete(k) - Delete the last k characters of S .
3.print(k) - Print the kth character of S .
4.undo - Undo the last (not previously undone) operation of type  or , reverting S to the state it was in prior to that operation.
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    cin >> Q;

    string S;
    stack<string> history;

    while (Q--)
    {
        int operation;
        cin >> operation;

        switch (operation)
        {
            case 1:
                {
                    string w;
                    cin >> w;
                    history.push(S);
                    S += w;
                }
                break;
            case 2:
                {
                    int k;
                    cin >> k;
                    history.push(S);
                    S = S.substr(0, S.length() - k);
                }
                break;
            case 3:
                {
                    int k;
                    cin >> k;
                    cout << S[k - 1] << "\n";
                }
                break;
            case 4:
                {
                    if (!history.empty())
                    {
                        S = history.top();
                        history.pop();
                    }
                }
                break;
        }
    } 
}