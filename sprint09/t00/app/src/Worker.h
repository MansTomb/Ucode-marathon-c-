#pragma once

#include <thread>
#include <iostream>

class Worker {
 public:
    Worker() = default;
    Worker(const Worker &) = delete;
    Worker(const Worker &&) = delete;
    Worker& operator=(const Worker&) = delete;
    ~Worker();
    template<typename Function, class... Args>
    void startWorker(Function &&func, Args &&...args);
    void joinThread();
 private:
    std::thread *m_thread{nullptr};
};

template<typename Function, class... Args>
void Worker::startWorker(Function &&func, Args &&... args) {
    joinThread();
    m_thread = new std::thread(func, std::forward<Args>(args)...);
}

void Worker::joinThread() {
    if (m_thread) {
        m_thread->join();
        delete m_thread;
        m_thread = nullptr;
    }
}

Worker::~Worker() {
    joinThread();
}

class TestClass {
 public:
    TestClass() = default;
    ~TestClass() = default;
    void testMember1() {
        std::cout << "testMember1" << std::endl;
    }
    void testMember2(int i) {
        std::cout << "testMember2 " << i << std::endl;
    }
};
