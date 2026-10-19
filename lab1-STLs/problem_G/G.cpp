// /*
// Ada the Ladybug has many things to do. She puts them into her queue.
// Anyway she is very indecisive, so sometime she uses the top, sometime the back and sometime she decides to reverses it.
//
// Input
// The first line consists of 1 ≤ Q ≤ 106, number of queries. Each of them contains one of following commands
//
// back - Print number from back and then erase it
//
// front - Print number from front and then erase it
//
// reverse - Reverses all elements in queue
//
// push_back N - Add element N to back
//
// toFront N - Put element N to front
//
// All numbers will be 0 ≤ N ≤ 100
//
// Output
// For each back/front query print appropriate number.
//
// If you would get this type of query and the queue would be empty, print "No job for Ada?" instead.
// */
//
// #include <iostream>
// #include <deque>
// using namespace std;
//
// int main(){
//     int q;
//     cin >> q;
//     deque<int> dq;
//     bool reversed = false;
//
//     for(int i = 0; i < q; i++){
//         string command;
//         cin >> command;
//         if (command == "reverse") {
//             reversed = !reversed;
//         } else if (command == "push_back") {
//             int n;
//             cin >> n;
//             if (!reversed) dq.push_back(n);
//             else dq.push_front(n);
//         } else if (command == "toFront") {
//             int n;
//             cin >> n;
//             if (!reversed) dq.push_front(n);
//             else dq.push_back(n);
//         } else if (command == "front") {
//             if (dq.empty()) {
//                 cout << "No job for Ada?\n";
//             } else if (!reversed) {
//                 cout << dq.front() << '\n';
//                 dq.pop_front();
//             } else {
//                 cout << dq.back() << '\n';
//                 dq.pop_back();
//             }
//         } else if (command == "back") {
//             if (dq.empty()) {
//                 cout << "No job for Ada?\n";
//             } else if (!reversed) {
//                 cout << dq.back() << '\n';
//                 dq.pop_back();
//             } else {
//                 cout << dq.front() << '\n';
//                 dq.pop_front();
//             }
//         }
//     }
// }