/*


*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n,m;
        cin >> n >> m;

        set<int> s;
        int count = 0;
        for(int i=0;i < n; i++){
            int x;
            cin >> x;
            s.insert(x);
        }

        for(int i=0;i < m; i++){
            int x;
            cin >> x;
            if(s.find(x) != s.end()){
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}