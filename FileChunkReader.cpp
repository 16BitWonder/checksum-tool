#include "FileChunkReader.h"

string m_fileName;
ifstream m_fileStream;

// Constructor
// @param fileName The name of the file being opened
FileChunkReader::FileChunkReader(const char* fileName)
{
    m_fileName = fileName;
    m_fileStream.open(m_fileName, fstream::in|ifstream::binary);
}

// Checks if the file exists
// @return true if file exists, false otherwise
bool FileChunkReader::fileExists() {
    return m_fileStream.is_open();
}

// Updates provided buffer with the next chunk of the file and how many bytes were read into it
// @param buffer The buffer to update
// @param buffSize The size of <buffer>
// @param bytesRead The number of bytes read into <buffer>
// @return true if read was successful, false otherwise
bool FileChunkReader::getNextChunk(char* &buffer, int buffSize, streamsize &bytesRead) {
    m_fileStream.read(buffer, buffSize);
    bytesRead = m_fileStream.gcount();
    bool tmp = m_fileStream.eofbit;
    return tmp; //Change this to return if successful read
}

// Checks whether m_fileStream has reached EOF
// @return true if EOF, false otherwise
bool FileChunkReader::isEOF() {
    return m_fileStream.eof();
}

// Resets m_fileBuffer to the start of the file
void FileChunkReader::reset() {
    m_fileStream.clear();
    m_fileStream.seekg(0);
    return;
}

// Closes m_fileBuffer
// @return true if closed, false otherwise
bool FileChunkReader::close() {
    m_fileStream.close();
    return !m_fileStream.is_open();
}