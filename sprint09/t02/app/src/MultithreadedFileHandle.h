#pragma once

#include <thread>
#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>

class MultithreadedFileHandler {
 public:
    MultithreadedFileHandler() = default;
    ~MultithreadedFileHandler() = default;
    void processFile() {
        std::unique_lock lck(m_mutex);
        m_condVar.wait(lck, [this]{return this->m_fileLoaded;});
        std::cout << m_file;
        m_fileLoaded = false;
    }
    void loadFile(const std::string& fileName) {
        std::unique_lock lck(m_mutex);
        std::ifstream file(fileName);
        std::istreambuf_iterator<char> eos;
        if (!m_file.empty()) {
            std::cout << "-----1 second sleep-----" << std::endl;
            m_condVar.wait_for(lck, std::chrono::seconds(1));
        }
        m_file = std::string(std::istreambuf_iterator<char>(file), eos);
        file.close();
        m_fileLoaded = true;
    }
 private:
    std::string m_file;
    std::mutex m_mutex;
    std::condition_variable m_condVar;
    bool m_fileLoaded{ false };
};
