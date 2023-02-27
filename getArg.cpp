#include <iostream>
#include "getArg.h"
using namespace std;

int getArg(char* argv[], int &i) {

    int ret = -1;

    string currentArg = argv[i];

    if (currentArg == "-h" || currentArg == "--help")
        ret = 0;
    else if (currentArg == "-i" || currentArg == "--info")
        ret = 1;
    else if (currentArg == "--crc32")
        ret = 2;
    else if (currentArg == "--md5")
        ret = 3;
    else if (currentArg == "--sha1")
        ret = 4;
    else if (currentArg == "--sha256")
        ret = 5;

    i++;
    return ret;
}