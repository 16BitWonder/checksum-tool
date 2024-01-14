#include "checksum.hpp"

int bufferSize = 67108864; // 64MB

string strToupper(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return toupper(c); });
    return str;
}

string generateCrc32(FileChunkReader &reader) {
    CRC32 crc32;
    streamsize readBytes = -1;
    char* buffer = new char[bufferSize];

    while (readBytes != 0) {
        reader.getNextChunk(buffer, bufferSize, readBytes);
        crc32.add(buffer, readBytes);
    }

    return strToupper(crc32.getHash());
}

string generateMd5(FileChunkReader &reader)
{
    MD5 md5;
    streamsize readBytes = -1;
    char* buffer = new char[bufferSize];

    while (readBytes != 0) {
        reader.getNextChunk(buffer, bufferSize, readBytes);
        md5.add(buffer, readBytes);
    }

    return strToupper(md5.getHash());
}

string generateSha1(FileChunkReader &reader)
{
    SHA1 sha1;
    streamsize readBytes = -1;
    char* buffer = new char[bufferSize];

    while (readBytes != 0) {
        reader.getNextChunk(buffer, bufferSize, readBytes);
        sha1.add(buffer, readBytes);
    }

    return strToupper(sha1.getHash());
}

string generateSha256(FileChunkReader &reader)
{
    SHA256 sha256;
    streamsize readBytes = -1;
    char* buffer = new char[bufferSize];

    while (readBytes != 0) {
        reader.getNextChunk(buffer, bufferSize, readBytes);
        sha256.add(buffer, readBytes);
    }

    return strToupper(sha256.getHash());
}
