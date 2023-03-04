#include <iostream>
#include <filesystem>
#include "FileChunkReader.h"
#include "checksum.h"
using namespace std;

string const version = "1.0.0";

void printHelp() {
    printf("Usage: checksum-tool [options...] <file>\n\n");
    printf("-h, --help            Display help info.\n");
    printf("-i, --info            Display version and license info.\n");
    printf("--crc32               Calculate CRC32.\n");
    printf("--md5                 Calculate MD5.\n");
    printf("--sha1                Calculate SHA-1.\n");
    printf("--sha256              Calculate SHA-256.\n");
}

void printInfo() {
    printf("checksum-tool v%s\n\n", version);
    printf("Licenses:\n");
    printf("checksum-tool: GPL v2.0\n");
    printf("hash-library:  zlib\n");
}

int getArg(char* argv[], int& i) {

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

int main(int argc, char* argv[]) {

    if (argc == 1) {
        printHelp();
        return 0;
    }

    int argcStep = 1;
    bool crc32, md5, sha1, sha256;
    crc32 = md5 = sha1 = sha256 = false;

    while (argcStep < argc) {
        int arg = getArg(argv, argcStep);

        switch (arg) {
            case 0:
                printHelp();
                return 0;
                break;
            case 1:
                printInfo();
                return 0;
                break;
            case 2:
                crc32 = true;
                break;
            case 3:
                md5 = true;
                break;
            case 4:
                sha1 = true;
                break;
            case 5:
                sha256 = true;
                break;
            default:
                if (argcStep != argc) {
                    printf("Unrecognized option: %s\n\n", argv[argcStep - 1]);
                    printHelp();
                    return 1;
                }
                break;
        }
    }

    FileChunkReader file (argv[argc-1]);
    if (!file.fileExists()) {
        printf("Could not open file: %s\n\n", argv[argc-1]);
        printHelp();
        return 1;
    }

    if (crc32) {
        cout << "CRC32: " + generateCrc32(file) << endl;
    }
    if (md5) {
        if (file.isEOF())
            file.reset();
        cout << "MD5: " + generateMd5(file) << endl;
    }
    if (sha1) {
        if (file.isEOF())
            file.reset();
        cout << "SHA-1: " + generateSha1(file) << endl;
    }
    if (sha256) {
        if (file.isEOF())
            file.reset();
        cout << "SHA-256: " + generateSha256(file) << endl;
    }
    file.close();

    printf("\nDone!\n");

    return 0;
}
