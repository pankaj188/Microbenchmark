#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <OrderBook.h>
#include <MarketDataGenerator.h>
#include <OrderMatchingAlgorithm.h>


// Function to simulate order Addition
void simulateOrderAddition(OrderBook& orderBook, MarketDataGenerator& dataGenerator) {

    // order addition logic
    while (true) // primarily for simulation purposes, allowing to continuously simulate order-related operations in an HFT system.
    {
        Order marketOrder = dataGenerator.generateOrder();
        
        // Add the generated order to the order book
        orderBook.addOrder(marketOrder);
        logger.log("Added order: Order ID");
        
    }
}

// Function to simulate order Modification
void simulateOrderModification(OrderBook& orderBook, MarketDataGenerator& dataGenerator) {

        //order modification logic

        while (true) //allowing to continuously simulate order-related operations in an HFT system.
        {

        Order marketOrder = dataGenerator.generateOrder();

        bool modified = orderBook.modifyOrder(marketOrder.orderId, marketOrder);
        if (modified) {
            logger.log("Modified order: Order ID");
        } else {
            logger.log("Order not found for modification: Order ID");
        }
        
    }
}

// Function to simulate order cancellation
void simulateOrderCancellation(OrderBook& orderBook, MarketDataGenerator& dataGenerator) {

    // Simulate order modification logic

    while (true) //allowing to continuously simulate order-related operations in an HFT system.
    {
        Order cancelledOrder = dataGenerator.generateOrder();

        bool canceled = orderBook.cancelOrder(cancelledOrder.orderID);
        if (canceled) {
            logger.log("Canceled order: Order ID");
        } else {
            logger.log("Order not found for Cancellation: Order ID");
        }
        
    }
}



int main() {

    // Create instances of OrderBook , orderMatch,and MarketDataGenerator
    OrderBook orderBook;
    MarketDataGenerator dataGenerator;
    OrderMatchingAlgorithm orderMatch;

    Logger logger("LogOrderBook.txt");
    logger.log("Starting HFT order book system...");

    // Create thread to simulate order addition
    std::thread additionThread(simulateOrderAddition, std::ref(orderBook), std::ref(dataGenerator));

    // Create threads to simulate order modification
    std::thread modificationThread(simulateOrderModification, std::ref(orderBook), std::ref(dataGenerator));
    
    // Create a thread for order cancellation
    std::thread cancellationThread(simulateOrderCancellation, std::ref(orderBook), std::ref(dataGenerator));


    // Optionally, join (wait for) the addition thread to finish
    additionThread.join();

    // Optionally, join (wait for) the modification thread to finish
    modificationThread.join();

    // Optionally, join (wait for) the cancellation thread to finish
    cancellationThread.join();
    
    }

    // Perform order matching
    orderMatch.matchOrders(orderBook);

    return 0;
}
