#include "src/validate.h"

std::string ReadBookContent(std::string &bookName) {
    std::ifstream contentStream("./library/" + bookName);
    std::string content;

    if (contentStream.is_open()) {
        content =
            std::string(std::istreambuf_iterator<char>(contentStream), {});
        if (content.size() != 0)
            return content;
        contentStream.close();
    }
    return content;
}

void Add(std::map<std::string, std::string> &books,
         std::vector<std::string> &args) {
    if (IfBookExist(args[1])) {
        std::string content = ReadBookContent(args[1]);
        if (content.size()) {
            books[args[1]] = content;
            std::cout << args[1] << " added\n";
        }
    } else {
        std::cerr << "invalid book\n";
    }
}

void Delete(std::map<std::string, std::string> &books,
            std::vector<std::string> &args) {
    if (books.count(args[1])) {
        books.erase(args[1]);
        std::cout << args[1] << " deleted\n";
    } else {
        std::cerr << "invalid book\n";
    }
}

void Read(std::map<std::string, std::string> &books,
          std::vector<std::string> &args) {
    if (books.count(args[1]))
        std::cout << books[args[1]];
}

void List(std::map<std::string, std::string> books) {
    for (auto &book : books) {
        std::cout << book.first << std::endl;
    }
}

int main(int argc, char *argv[]) {
    std::string command;
    std::map<std::string, std::string> books;

    while (1) {
        std::cout << "enter command:> ";
        std::getline(std::cin, command);
        std::vector<std::string> args = GetCommandArgs(command);

        if (args[0] == "add" && args.size() == 2) {
            Add(books, args);
        } else if (args[0] == "delete" && args.size() == 2) {
            Delete(books, args);
        } else if (args[0] == "read" && args.size() == 2) {
            Read(books, args);
        } else if (args[0] == "list" && args.size() == 1) {
            List(books);
        } else if (args[0] == "quit" && args.size() == 1) {
            std::cout << "bye\n";
            return EXIT_SUCCESS;
        } else {
            std::cerr << "invalid command\n";
        }
    }
}
