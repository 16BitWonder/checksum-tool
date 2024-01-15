#pragma once
#include <filesystem>
#include <fstream>

class FileChunkReader {
    private:
        std::string m_fileName;
        unsigned long long int m_fileSize = 0;
        std::ifstream m_fileStream;

    public:
        FileChunkReader(const char* fileName);

        bool fileExists() { return m_fileStream.is_open(); }
        void getNextChunk(char* &buffer, int buffSize, std::streamsize &bytesRead);
        unsigned long long int getFileSize() { return m_fileSize; }
        bool isEOF() { return m_fileStream.eof(); }
        void reset();
        bool close();
        std::string getFileName() { return m_fileName; }
};