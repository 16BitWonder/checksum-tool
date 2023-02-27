#pragma once
#include <fstream>
using namespace std;

class FileChunkReader {
    private:
        string m_fileName;
        ifstream m_fileStream;

    public:
        FileChunkReader(const char* fileName);

        bool fileExists();
        bool getNextChunk(char* &buffer, int buffSize, streamsize &bytesRead);
        bool isEOF();
        void reset();
        bool close();
        string getFileName() { return m_fileName; }
};