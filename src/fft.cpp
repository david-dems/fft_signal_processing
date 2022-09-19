#include "fft.h"
#include <cmath>
#include <iostream>
const double pi = acos(-1);

std::complex<double>* SignalProcess::fft(std::complex<double>* signal, std::complex<double>* result, int size, int idx, std::complex<double> w){
	if (size == 1){
		return signal;
	}
	
	auto odd  = fft(&signal[0], &result[0], size / 2, idx * 2, w * w);
	auto even = fft(&signal[idx], &result[idx], size / 2, idx * 2, w * w);

	std::complex<double> wt = {1, 0};

	int k = size / 2;
	
	for (int i = 0; i < size; i++){
		result[i * idx] = odd[i % k * idx * 2] + wt * even[i % k * idx * 2];
		wt *= w;		
	}

	for (int i = 0; i < size; i++){
		signal[i * idx] = result[i * idx];
	}
	
	return signal;
}

 
std::vector<double> SignalProcess::FFT(std::vector<std::complex<double>> signal){
	int n = signal.size();
	std::complex<double>* sig = new std::complex<double>[n];
	std::complex<double>* arr = new std::complex<double>[n];

	for (int i = 0; auto val : signal){
		sig[i] = val;
		i++;
	}
	auto res = SignalProcess::fft(sig, arr, n, 1, std::polar(1., 2 * pi / signal.size()));
	std::vector<double> result;
	
	for (int i = 0; i < n; i++){
		result.push_back(std::abs(res[i]));
	}

	delete[] sig;
	delete[] arr;

	return result;
}


double SignalProcess::hann_function(int n, int N){
	if (n >= 0 && n <= N)
		return std::pow(sin(pi * (double)n / (double) N), 2);
	else 
		return 0;
}
