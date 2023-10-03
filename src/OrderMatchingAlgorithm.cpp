#include<bits/stdc++.h>
#include "OrderMatchingAlgorithm.h"

void OrderMatchingAlgorithm::matchOrders(OrderBook& orderBook) {
    // Simplified example of a basic order matching algorithm

    // Sort the buy and sell orders by price and time priority
    std::sort(orderBook.buyOrders.begin(), orderBook.buyOrders.end(),
              [](const Order& a, const Order& b) {
                  if (a.price == b.price) {
                      return a.orderId < b.orderId; // Time priority
                  }
                  return a.price > b.price; // Price priority
              });

    std::sort(orderBook.sellOrders.begin(), orderBook.sellOrders.end(),
              [](const Order& a, const Order& b) {
                  if (a.price == b.price) {
                      return a.orderId < b.orderId; // Time priority
                  }
                  return a.price < b.price; // Price priority
              });

    // Match buy and sell orders
    auto buyIt = orderBook.buyOrders.begin();
    auto sellIt = orderBook.sellOrders.begin();

    while (buyIt != orderBook.buyOrders.end() && sellIt != orderBook.sellOrders.end()) {
        if (sellIt->price >= buyIt->price) {
            // Match the orders
            int matchedQuantity = std::min(buyIt->quantity, sellIt->quantity);

            // Update the remaining quantities of the buy and sell orders
            buyIt->quantity -= matchedQuantity;
            sellIt->quantity -= matchedQuantity;

            // Remove orders with zero quantity
            if (buyIt->quantity == 0) {
                buyIt = orderBook.buyOrders.erase(buyIt);
            }

            if (sellIt->quantity == 0) {
                sellIt = orderBook.sellOrders.erase(sellIt);
            }
        } else {
            break; // No more matches at this price level
        }
    }
}
