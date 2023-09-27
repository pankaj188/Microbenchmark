#include "OrderBook.h"

OrderBook::OrderBook() {
    buyOrders.clear();
    sellOrders.clear();
    // Initialize order book data structures here
}

void OrderBook::addOrder(const Order& order) {
     if (order.quantity <= 0) {
        cout<<"Order quantity Should be a Positive Value"<<endl;
        // Ignore orders with non-positive quantities
        return;
    }

    if (order.price <= 0.0) {
        cout<<"Order price Should be a Positive Value"<<endl;
        // Ignore orders with non-positive prices
        return;
    }

    if (order.price < 1.0 || order.price > 1000.0) {
        cout<<"Order price Should be within a range"<<endl;
        // Implement price range checks based on  market rules
        return;
    }

    // Add the order to the appropriate side of the order book (buy or sell)
    if (order.price >= 1.0 && order.price <= 500.0 /* condition to determine if it's a buy order */) {
        // This is a buy order
        buyOrders.push_back(order);
    } else {
        // This is a sell order
        sellOrders.push_back(order);
    }
   
}

bool OrderBook::modifyOrder(int orderId, const Order& modifiedOrder) {
    // Find the order in the order book based on its orderId
    for (auto& order : buyOrders) {
        if (order.orderId == orderId) {
            // Modify the order with the new information
            order.price = modifiedOrder.price;
            order.quantity = modifiedOrder.quantity;
            // Modify other fields as needed
            return true; // Order was modified
        }
    }

    for (auto& order : sellOrders) {
        if (order.orderId == orderId) {
            // Modify the order with the new information
            order.price = modifiedOrder.price;
            order.quantity = modifiedOrder.quantity;
            // Modify other fields as needed
            return true; // Order was modified
        }
    }

    // If the order with the specified orderId was not found
    return false; // Order was not modified
}

bool OrderBook::cancelOrder(int orderId) {
    // Find the order in the order book based on its orderId
    for (auto it = buyOrders.begin(); it != buyOrders.end(); ++it) {
        if (it->orderId == orderId) {
            // Erase the order from the buyOrders vector
            buyOrders.erase(it);
            return true; // Order was canceled
        }
    }

    for (auto it = sellOrders.begin(); it != sellOrders.end(); ++it) {
        if (it->orderId == orderId) {
            // Erase the order from the sellOrders vector
            sellOrders.erase(it);
            return true; // Order was canceled
        }
    }

    // If the order with the specified orderId was not found
    return false; // Order was not canceled
}

