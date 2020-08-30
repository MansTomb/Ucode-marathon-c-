#pragma once

#include <thread>
#include <vector>
#include <iostream>
#include <future>

class Worker {
 public:
    Worker() = default;
    Worker(const Worker &) = delete;
    Worker(const Worker &&) = delete;
    virtual ~Worker() = default;

    void start();
    void stop();
    void join();
    bool isRunning() const;
 protected:
    virtual void run() = 0;
 private:
    std::atomic_bool m_isRunning{ false };
    std::thread m_worker;
};
