#include "validate.h"

std::vector<std::string> GetCommandArgs(std::string &command) {
    std::stringstream ss(command);
    std::string argument;
    std::vector<std::string> args;

    while (getline(ss, argument, ' ')) {
        if (argument.size())
            args.push_back(argument);
    }
    return args;
}

bool IfBookExist(std::string &book) {
    std::vector<std::string> files;
    DIR* dirp = opendir("./library");
    struct dirent *dp = NULL;

    if (dirp) {
        dp = readdir(dirp);
        dp = readdir(dirp);
        while ((dp = readdir(dirp)) != NULL) {
            files.push_back(dp->d_name);
        }
        closedir(dirp);
    }

    if (std::find(files.begin(), files.end(), book) != files.end())
        return true;
    return false;
}
