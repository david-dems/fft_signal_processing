#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include "fft.h"


int main(){

	std::ifstream fin;
	fin.open("../resources/signal.txt");

	if (!fin.is_open())
		return 1;
	
	std::string str;
	std::vector<double> signal;
	while(std::getline(fin, str)){
		signal.push_back(std::stod(str));
	}

	//auto res = FFT({1, 4, 3, 4, 5, 6, 7, 4});
	auto res = SignalProcess::FFT({1,2,3,4,5,6,7,8});

	for (auto val : res){
		std::cout << std::abs(val) << std::endl;
	}


	fin.close();

	return 0;
}

