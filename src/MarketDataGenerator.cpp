#include "MarketDataGenerator.h"

MarketDataGenerator::MarketDataGenerator() {
    // Initialize your random number generator and set parameters here
    std::random_device rd;
    generator = std::default_random_engine(rd());
    orderIdDistribution = std::uniform_int_distribution<int>(1, 1000); // Adjust range as needed
    priceDistribution = std::uniform_real_distribution<double>(50.0, 200.0); // Adjust range as needed
    quantityDistribution = std::uniform_int_distribution<int>(1, 10); // Adjust range as needed
}

Order MarketDataGenerator::generateOrder() {
    // Implement logic to generate random order data Order order;
    // Set order fields based on your requirements
     order.orderId = orderIdDistribution(generator);
    order.price = priceDistribution(generator);
    order.quantity = quantityDistribution(generator);
    return order;
}
