#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include <algorithm>
#include "fft.h"


int main(){

	std::ifstream fin;
	fin.open(R"(C:\Users\hr3q2\source\repos\fft_signal_processing\resources\signal.txt)");

	if (!fin.is_open())
		return 1;
	
	std::string str;
	std::vector<double> signal;
	while(std::getline(fin, str)){
		signal.push_back(std::stod(str));
	}

	fin.close();

	double max = 0;
	int pos;
	for (int j = 0; j < 30000; j += 2048){
		std::vector<std::complex<double>> window = {};
		for (int i = 0; i < 4096; i++){
			window.push_back(signal[i] * SignalProcess::hann_function(i - j, 4096));
		}
		auto spectrum = SignalProcess::FFT(window);
		auto tmp = std::max_element(spectrum.begin(), spectrum.end());
		if (*tmp > max){
			max = *tmp;
			auto it = std::find(spectrum.begin(), spectrum.end(), max);
			pos = it - spectrum.begin();
		}
	}


	std::cout << "Frequency with max amplitude: " << (double) pos / 4.096  << " Hz" << std::endl;

	/*std::ofstream fout;
	fout.open("../resources/spectrum.txt");

	for (int i = 0; auto val : spectrum){
		fout << i * 1.0 / 4.096 / 2 << " " << std::abs(val) << std::endl;
		i++;
	}*/

	system("pause");


	return 0;
}

