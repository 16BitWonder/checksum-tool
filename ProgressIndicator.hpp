#include <iostream>
#include <string>

class ProgressIndicator {
    private:
        unsigned long long int m_stepInterval = 0;
        int m_currentStep = -1;

    public:
        ProgressIndicator(unsigned long long int totalBytes) { m_stepInterval = totalBytes / 100;  }
        void printProgress(unsigned long long int processedBytes, std::string prependString);
};