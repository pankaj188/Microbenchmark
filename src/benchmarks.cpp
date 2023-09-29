#include <iostream>
#include <benchmark/benchmark.h>
#include "OrderBook.h"
#include "MarketDataGenerator.h"
#include "OrderMatchingAlgorithm.h"

static void BM_AddOrder(benchmark::State& state) {
    OrderBook orderBook;
    MarketDataGenerator dataGenerator;

    for (auto _ : state) {
        Order marketOrder = dataGenerator.generateOrder();
        orderBook.addOrder(marketOrder);
    }
}
BENCHMARK(BM_AddOrder);

static void BM_ModifyOrder(benchmark::State& state) {
    OrderBook orderBook;
    MarketDataGenerator dataGenerator;

    // Add an order to the order book for modification
    Order initialOrder = dataGenerator.generateOrder();
    orderBook.addOrder(initialOrder);

    for (auto _ : state) {
        Order modifiedOrder = initialOrder; // Create a copy of the initial order
        modifiedOrder.quantity = 10; // Modify quantity (or other fields as needed)
        orderBook.modifyOrder(initialOrder.orderId, modifiedOrder);
    }
}
BENCHMARK(BM_ModifyOrder);


static void BM_MatchOrders(benchmark::State& state) {
    OrderBook orderBook;
    MarketDataGenerator dataGenerator;

    // Add a set of buy and sell orders to the order book
    for (int i = 0; i < 1000; ++i) {
        Order marketOrder = dataGenerator.generateOrder();
        if (i % 2 == 0) {
            marketOrder.price = 100.0; // Set a fixed price for buy orders
        } else {
            marketOrder.price = 110.0; // Set a fixed price for sell orders
        }
        orderBook.addOrder(marketOrder);
    }

    for (auto _ : state) {
        OrderMatchingAlgorithm::matchOrders(orderBook);
    }
}
BENCHMARK(BM_MatchOrders);

BENCHMARK_MAIN();