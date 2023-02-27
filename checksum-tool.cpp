#include "crc32.h"

#include <algorithm>
#include <iostream>

// TODO:
// Rename this file to checksum.cpp
// Create a header file containing all functions in here
// Use this as a place to store all functions related to generating checksums off provided file handles to keep it out of main

std::string strToupper(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
    return str;
}

int test(int argc, char* argv[]) {

    // create a crc32 hashing object
    CRC32 crc32;
    crc32("Quick Test");
    std::string crcText = strToupper(crc32.getHash());
    std::string crcCheckAgainst = "806930C1";

    // Quick Test
    std::cout << "Calculated: " + crcText << std::endl;
    std::cout << "Expected: " + crcCheckAgainst << std::endl;

    if (crcText.compare(crcCheckAgainst) == 0) {
        std::cout << "Checksums Match" << std::endl;
    } else {
        std::cout << "Checksums Do Not Match" << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
