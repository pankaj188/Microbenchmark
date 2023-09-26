#ifndef MARKETDATAGENERATOR_H
#define MARKETDATAGENERATOR_H

#include <vector>
#include <random>
#include "OrderBook.h"

class MarketDataGenerator {
public:
    MarketDataGenerator();

    Order generateOrder();

    // Add more methods for generating market data as needed

private:
    std::default_random_engine generator;
     std::uniform_int_distribution<int> orderIdDistribution;
    std::uniform_real_distribution<double> priceDistribution;
    std::uniform_int_distribution<int> quantityDistribution;

    // Define parameters for generating random market data
};

#endif
