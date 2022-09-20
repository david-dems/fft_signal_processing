#include "fft.h"
#include <cmath>
#include <iostream>
#define pi 3.14159265358979323846

std::complex<double>* SignalProcess::fft(std::complex<double>* signal, std::complex<double>* result, int size, int idx, std::complex<double> w){
	if (size == 1){
		return signal;
	}
	
	auto odd  = fft(&signal[0], &result[0], size / 2, idx * 2, w * w);
	auto even = fft(&signal[idx], &result[idx], size / 2, idx * 2, w * w);

	std::complex<double> wt = 1;
	
	for (int i = 0; i < size / 2; i++){
		result[i * idx] = odd[i * idx * 2] + wt * even[i * idx * 2];
		result[(i + size / 2) * idx] = odd[i * idx * 2] - wt * even[i * idx * 2];
		wt *= w;		
	}

	for (int i = 0; i < size; i++){
		signal[i * idx] = result[i * idx];
	}
	
	return signal;
}

 
std::vector<double> SignalProcess::FFT(std::vector<std::complex<double>> signal){
	int n;
	std::complex<double>* sig;
	std::complex<double>* arr;
	if ( int(signal.size() & (signal.size()-1))){
		n = std::pow(2, ceil(log2(signal.size())));
		sig = new std::complex<double>[n];
		arr = new std::complex<double>[n];
		for (int i = signal.size(); i < n; i++){
			sig[i] = 0;
		}
	} else {
		n = signal.size();
		sig = new std::complex<double>[n];
		arr = new std::complex<double>[n];
	}

	for (int i = 0; auto val : signal){
		sig[i] = val;
		i++;
	}
	auto res = SignalProcess::fft(sig, arr, n, 1, std::polar(1., 2 * pi / n));
	std::vector<double> result;
	
	for (int i = 0; i < n; i++){
		result.push_back(std::abs(res[i]));
	}

	delete[] sig;
	delete[] arr;

	return result;
}


double SignalProcess::hannFunction(int n, int N){
	if (n >= 0 && n <= N)
		return std::pow(sin(pi * (double)n / (double) N), 2);
	else 
		return 0;
}

std::vector<std::complex<double>> SignalProcess::makeWindow(std::vector<double> signal, double (*w_func)(int, int), int w_size){
	std::vector<std::complex<double>> window;
	for (int i = 0; auto val : signal){
		window.push_back(val * w_func(i, w_size));
		i++;
	}

	return window;
}