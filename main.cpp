#include "FileChunkReader.hpp"
#include "checksum.hpp"

std::string version = "1.1.0";

void printHelp() {
    std::cout << "Usage: checksum-tool [options...] <file>" << std::endl << std::endl;
    std::cout << "-h, --help            Display help info." << std::endl;
    std::cout << "-i, --info            Display version and license info." << std::endl;
    std::cout << "--crc32               Calculate CRC32." << std::endl;
    std::cout << "--md5                 Calculate MD5." << std::endl;
    std::cout << "--sha1                Calculate SHA-1." << std::endl;
    std::cout << "--sha256              Calculate SHA-256." << std::endl;
}

void printInfo() {
    std::cout << "checksum-tool v" << version << std::endl << std::endl;
    std::cout << "Licenses:" << std::endl;
    std::cout << "checksum-tool: GPL v2.0" << std::endl;
    std::cout << "hash-library:  zlib" << std::endl;
}

int getArg(char* argv[], int& i) {

    int ret = -1;

    std::string currentArg = argv[i];

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
                    std::cout << "Unrecognized option: " << argv[argcStep - 1] << std::endl << std::endl;
                    printHelp();
                    return 1;
                }
                break;
        }
    }

    FileChunkReader file (argv[argc - 1]);
    if (!file.fileExists()) {
        std::cout << "Could not open file: " << argv[argc - 1] << std::endl << std::endl;
        printHelp();
        return 1;
    }

    if (crc32) {
        std::cout << generateChecksum(file, CHECKSUM_CRC32) << std::endl;
    }
    if (md5) {
        if (file.isEOF())
            file.reset();
        std::cout << generateChecksum(file, CHECKSUM_MD5) << std::endl;
    }
    if (sha1) {
        if (file.isEOF())
            file.reset();
        std::cout << generateChecksum(file, CHECKSUM_SHA1) << std::endl;
    }
    if (sha256) {
        if (file.isEOF())
            file.reset();
        std::cout << generateChecksum(file, CHECKSUM_SHA256) << std::endl;
    }
    file.close();

    std::cout << std::endl << "Done!" << std::endl;

    return 0;
}
