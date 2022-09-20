#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include <algorithm>
#include "fft.h"
const int window_size = 4000;  // size if window in samples
const double overlap = 0.5;
const double signal_duration = 30.0;   // in sec
const double highest_freq = 40;
const double lowest_freq = 1;

int main() {

	std::cout << "Please, enter path to inpout file *.txt:" << std::endl;

	std::string path;
	std::cin >> path;

	std::ifstream fin;
	fin.open(path);

	if (!fin.is_open()) {
		std::cout << "Failed to open file " << path << std::endl;
		std::cout << "Make sure, that file exists!" << std::endl;
		system("pause");
		return 1;
	}

	std::string str;
	std::vector<double> signal;
	int samples_count = 0;
	while(std::getline(fin, str)){
		signal.push_back(std::stod(str));
		samples_count++;
	}

	fin.close();

	
	double max = 0;
	int pos = 0;
	for (int j = 0; j <= samples_count; j += window_size * overlap){

		std::vector<std::complex<double>> window = SignalProcess::makeWindow(signal, &SignalProcess::hannFunction, window_size);
		auto spectrum = SignalProcess::FFT(window);
		
		auto tmp = std::max_element(spectrum.begin() + lowest_freq * signal_duration, spectrum.begin() + highest_freq * signal_duration);
		if (*tmp > max){
			max = *tmp;
			auto it = std::find(spectrum.begin() + lowest_freq * signal_duration, spectrum.begin() + highest_freq * signal_duration, max);
			pos = it - spectrum.begin();
		}
	}

	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << "Frequency with max amplitude: " << (double) pos / signal_duration  << " Hz" << std::endl;


	system("pause");


	return 0;
}

