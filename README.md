### To run the microbenchmark for HFT order book system, follow these steps:

1. Set Up Google Benchmark:

`First, make sure you have the Google Benchmark library installed. You can follow the installation instructions on `
![Google Benchmark GitHub page](https://github.com/google/benchmark)

2. Build Your Benchmark Project:
```
mkdir build
cd build
cmake ..
make
```
3. Run the Benchmarks:
./Microbenchmark

4. Analyze the Results:

| Benchmark  | Time | CPU | Iterations |
| ------------- | ------------- |------------- |------------- |
| BM_AddOrder  | 10.1 ns  |10.1 ns | 69023412 |
| BM_ModifyOrder  | 12.2 ns  |12.2 ns | 57700118 |
| BM_MatchOrders  | 18.3 ns  |18.3 ns | 38045870 |


