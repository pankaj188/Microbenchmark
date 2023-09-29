#include <iostream>
#include <fstream>
#include <ctime>

class Logger {
public:
    Logger(const std::string& logOrderBook) {
        logFile_.open(logOrderBook, std::ios::out | std::ios::app);
    }

    ~Logger() {
        logFile_.close();
    }

    template <typename T>
    void log(const T& message) {
        std::time_t now = std::time(nullptr);
        char timestamp[64];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        logFile_ << "[" << timestamp << "] " << message << std::endl;
        std::cout << "[" << timestamp << "] " << message << std::endl;
    }

private:
    std::ofstream logFile_;
};
