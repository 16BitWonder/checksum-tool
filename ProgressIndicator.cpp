#include "ProgressIndicator.hpp"

void ProgressIndicator::printProgress(unsigned long long int processedBytes, std::string prependString) {

	int currentStep = processedBytes / m_stepInterval;

	if (m_currentStep != currentStep) {
		m_currentStep = currentStep;
		std::cout << '\r' << prependString << currentStep << '%';
	}
	return;
}