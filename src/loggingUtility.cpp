#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

class Logger {
public:
    Logger(const std::string& LogOrderBook) {
        logFile_.open(LogOrderBook, std::ios::out | std::ios::app);
        if (!logFile_.is_open()) {
            std::cerr << "Failed to open the log file: "<< std::endl;
        }
    }

    ~Logger() {
        if (logFile_.is_open()) {
            logFile_.close();
        }
    }

    template <typename T>
    void log(const T& message) {
        if(logFile_.is_open()){
        std::time_t now = std::time(nullptr);
        char timestamp[64];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        logFile_ << "[" << timestamp << "] " << message << std::endl;
        std::cout << "[" << timestamp << "] " << message << std::endl;
        }
        else{
            std::cerr << "Log file not open. Failed to log message: " << message << std::endl;
        }
    }

private:
    std::ofstream logFile_;
};
