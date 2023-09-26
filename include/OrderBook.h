#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <vector>
#include <iostream>

// Define a structure for representing orders
struct Order {
    int orderId;
    double price;
    int quantity;
    // Add more fields as needed
};

class OrderBook {
public:
    OrderBook();

    void addOrder(const Order& order);
    bool modifyOrder(int orderId, const Order& modifiedOrder); // Returns true if order was modified, false otherwise
    bool cancelOrder(int orderId);
    
private:
    std::vector<Order> buyOrders;
    std::vector<Order> sellOrders;

    
};

#endif
