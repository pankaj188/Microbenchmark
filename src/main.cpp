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
            orderBook.addOrder(marketOrder);
        } else {
            orderBook.modifyOrder(marketOrder);
        }

        // Implement any other simulation logic as needed
    }

    // Perform order matching
    OrderMatchingAlgorithm::matchOrders(orderBook);

    // Print results or perform additional operations

    return 0;
}
