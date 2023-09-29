#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "OrderBook.h"
#include "MarketDataGenerator.h"
#include "OrderMatchingAlgorithm.h"

// Function to simulate order Addition
void simulateOrderAddition(OrderBook& orderBook, MarketDataGenerator& dataGenerator) {

    // order addition logic
    while (true) {
        Order marketOrder = dataGenerator.generateOrder();
        
        // Add the generated order to the order book
        orderBook.addOrder(marketOrder);
        logger.log("Added order: Order ID");
        
    }
}

// Function to simulate order Modification
void simulateOrderModification(OrderBook& orderBook) {

        //order modification logic

        while (true) {

        Order marketOrder.quantity = 10; // Modify quantity

        bool modified = orderBook.modifyOrder(marketOrder.orderId, marketOrder);
        if (modified) {
            logger.log("Modified order: Order ID");
        } else {
            logger.log("Order not found for modification: Order ID");
        }
        
        // Modify the order in the order book using the order ID
        orderBook.modifyOrder(marketOrder.orderId, marketOrder);
        
    }
}

// Function to simulate order cancellation
void simulateOrderCancellation(OrderBook& orderBook, MarketDataGenerator& dataGenerator) {

    // Simulate order modification logic
    
    while (true) {
        Order cancelledOrder = dataGenerator.generateOrder();

        orderBook.cancelOrder(cancelledOrder.orderID);
        
    }
}


int main() {
    // Create instances of OrderBook and MarketDataGenerator
    OrderBook orderBook;
    MarketDataGenerator dataGenerator;

    Logger logger("logOrderBook.txt");

    // Create a thread to simulate order addition
    std::thread additionThread(simulateOrderAddition, std::ref(orderBook), std::ref(dataGenerator));

    // Create threads for order modification
    std::thread modificationThread(simulateOrderModification, std::ref(orderBook));
    // Create a thread for order cancellation

    std::thread cancellationThread(simulateOrderCancellation, std::ref(orderBook), std::ref(dataGenerator));



    // Optionally, join (wait for) the modification and matching threads to finish
    additionThread.join();

    // Optionally, join (wait for) the modification and matching threads to finish
    modificationThread.join();

    // Optionally, join (wait for) the cancellation thread to finish
    cancellationThread.join();

    
    }

    // Perform order matching
    OrderMatchingAlgorithm::matchOrders(orderBook);

    // Print order book or perform additional operations

    return 0;
}
