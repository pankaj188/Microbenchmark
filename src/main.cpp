#include <iostream>
#include "OrderBook.h"
#include "MarketDataGenerator.h"
#include "OrderMatchingAlgorithm.h"

int main() {
    // Create instances of OrderBook and MarketDataGenerator
    OrderBook orderBook;
    MarketDataGenerator dataGenerator;

    // Simulate market data and order book operations
    for (int i = 0; i < 1000; ++i) {
        Order marketOrder = dataGenerator.generateOrder();

        if (i % 2 == 0) {
            // Add order
            orderBook.addOrder(marketOrder);
            std::cout << "Added order: Order ID " << marketOrder.orderId << std::endl;
        } else {
            // Modify order (for demonstration purposes)
            marketOrder.quantity = 10; // Modify quantity
            bool modified = orderBook.modifyOrder(marketOrder.orderId, marketOrder);
            if (modified) {
                std::cout << "Modified order: Order ID " << marketOrder.orderId << std::endl;
            } else {
                std::cout << "Order not found for modification: Order ID " << marketOrder.orderId << std::endl;
            }
        }

        // Perform other simulation logic as needed
    }

    // Perform order matching
    OrderMatchingAlgorithm::matchOrders(orderBook);

    // Print order book or perform additional operations

    return 0;
}
