#include "FileChunkReader.hpp"

// Constructor
// @param fileName The name of the file being opened
FileChunkReader::FileChunkReader(const char* fileName) {
    m_fileName = fileName;
    m_fileStream.open(m_fileName, std::fstream::in|std::ifstream::binary);
    if (fileExists()) {
        std::filesystem::path p(fileName);
        m_fileSize = std::filesystem::file_size(p);
    }
}

// Updates provided buffer with the next chunk of the file and how many bytes were read into it
// @param buffer The buffer to update
// @param buffSize The size of <buffer>
// @param bytesRead The number of bytes read into <buffer>
void FileChunkReader::getNextChunk(char* &buffer, int buffSize, std::streamsize &bytesRead) {
    m_fileStream.read(buffer, buffSize);
    bytesRead = m_fileStream.gcount();
    return; 
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