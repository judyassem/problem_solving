/*
In this task you need to process a set of stock exchange orders and use them to create order book.

An order is an instruction of some participant to buy or sell stocks on stock exchange. The order number i has price pi, direction di — buy or sell, and integer qi. This means that the participant is ready to buy or sell qi stocks at price pi for one stock. A value qi is also known as a volume of an order.

All orders with the same price p and direction d are merged into one aggregated order with price p and direction d. The volume of such order is a sum of volumes of the initial orders.

An order book is a list of aggregated orders, the first part of which contains sell orders sorted by price in descending order, the second contains buy orders also sorted by price in descending order.

An order book of depth s contains s best aggregated orders for each direction. A buy order is better if it has higher price and a sell order is better if it has lower price. If there are less than s aggregated orders for some direction then all of them will be in the final order book.

You are given n stock exhange orders. Your task is to print order book of depth s for these orders.

Input
The input starts with two positive integers n and s (1 ≤ n ≤ 1000, 1 ≤ s ≤ 50), the number of orders and the book depth.

Next n lines contains a letter di (either 'B' or 'S'), an integer pi (0 ≤ pi ≤ 105) and an integer qi (1 ≤ qi ≤ 104) — direction, price and volume respectively. The letter 'B' means buy, 'S' means sell. The price of any sell order is higher than the price of any buy order.

Output
Print no more than 2s lines with aggregated orders from order book of depth s. The output format for orders should be the same as in input.
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int n ,s;
    cin >> n >> s;

    map <int, int, greater<int>> sell;
    map <int, int> buy;
    while (n--) {
       char d;
       int p, q;
       cin >> d >> p >> q;

       if(d == 'S'){
            sell[p] += q;
        }
         else{
            buy[p] += q;
        }
    }
    int sellCount = min<int>(s, sell.size());

    auto it = prev(sell.end(), sellCount);
    for (; it != sell.end(); ++it) {
        cout << "S " << it->first << " " << it->second << endl;
    }

    for (auto it = buy.rbegin(); it != buy.rend() && s > 0; ++it, --s) {
        cout << "B " << it->first << " " << it->second << endl;
    }
    
    return 0;
}