#include "checksum.hpp"

const int BUFFER_SIZE = 67108864; // 64MB

std::string strToupper(std::string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return toupper(c); });
    return str;
}

std::string generateCrc32(FileChunkReader &reader) {
    CRC32 crc32;
    std::streamsize readBytes = -1;
    char* buffer = new char[BUFFER_SIZE];

    unsigned long long int totalReadBytes = 0;
    ProgressIndicator progressPrinter(reader.getFileSize());
    while (readBytes != 0) {
        reader.getNextChunk(buffer, BUFFER_SIZE, readBytes);
        crc32.add(buffer, readBytes);
        totalReadBytes += readBytes;
        progressPrinter.printProgress(totalReadBytes, "CRC32: ");
    }

    return "\rCRC32: " + strToupper(crc32.getHash());
}

std::string generateMd5(FileChunkReader &reader) {
    MD5 md5;
    std::streamsize readBytes = -1;
    char* buffer = new char[BUFFER_SIZE];

    unsigned long long int totalReadBytes = 0;
    ProgressIndicator progressPrinter(reader.getFileSize());
    while (readBytes != 0) {
        reader.getNextChunk(buffer, BUFFER_SIZE, readBytes);
        md5.add(buffer, readBytes);
        totalReadBytes += readBytes;
        progressPrinter.printProgress(totalReadBytes, "MD5: ");
    }

    return "\rMD5: " + strToupper(md5.getHash());
}

std::string generateSha1(FileChunkReader &reader) {
    SHA1 sha1;
    std::streamsize readBytes = -1;
    char* buffer = new char[BUFFER_SIZE];

    unsigned long long int totalReadBytes = 0;
    ProgressIndicator progressPrinter(reader.getFileSize());
    while (readBytes != 0) {
        reader.getNextChunk(buffer, BUFFER_SIZE, readBytes);
        sha1.add(buffer, readBytes);
        totalReadBytes += readBytes;
        progressPrinter.printProgress(totalReadBytes, "SHA1: ");
    }

    return "\rSHA1: " + strToupper(sha1.getHash());
}

std::string generateSha256(FileChunkReader &reader) {
    SHA256 sha256;
    std::streamsize readBytes = -1;
    char* buffer = new char[BUFFER_SIZE];

    unsigned long long int totalReadBytes = 0;
    ProgressIndicator progressPrinter(reader.getFileSize());
    while (readBytes != 0) {
        reader.getNextChunk(buffer, BUFFER_SIZE, readBytes);
        sha256.add(buffer, readBytes);
        totalReadBytes += readBytes;
        progressPrinter.printProgress(totalReadBytes, "SHA256: ");
    }

    return "\rSHA256: " + strToupper(sha256.getHash());
}

std::string generateChecksum(FileChunkReader& reader, Checksum checksumType) {
    switch (checksumType) {
    case CHECKSUM_CRC32:
        return generateCrc32(reader);
    case CHECKSUM_MD5:
        return generateMd5(reader);
    case CHECKSUM_SHA1:
        return generateSha1(reader);
    case CHECKSUM_SHA256:
        return generateSha256(reader);
    default:
        return "Unkown checksum type";
    }
}