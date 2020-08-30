#include <string>
#include "src/MultithreadedFileHandle.h"
#include "src/Worker.h"
#include <regex>

static void Validate(int ar, char **arg) {
    if (ar != 3) {
        std::cerr << "usage: ./multithreadedFileHandler [file1] [file2]" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::ifstream f1(arg[1]);
    std::ifstream f2(arg[2]);

    if (!f1.is_open() || !f2.is_open()) {
        std::cerr << "error" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    Validate(argc, argv);
    Worker worker;
    MultithreadedFileHandler handler;
    std::string filename(argv[1]);
    std::string filename2(argv[2]);


    worker.startNewThread(&MultithreadedFileHandler::loadFile, std::ref(handler), std::ref(filename));
    worker.startNewThread(&MultithreadedFileHandler::processFile, std::ref(handler));
    worker.startNewThread(&MultithreadedFileHandler::loadFile, std::ref(handler), std::ref(filename2));
    worker.startNewThread(&MultithreadedFileHandler::processFile, std::ref(handler));
    worker.joinAllThreads();
}
