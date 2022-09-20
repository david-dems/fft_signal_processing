#pragma once
#include <complex>
#include <vector>

class SignalProcess{
public:
	static std::complex<double>* fft(std::complex<double>* signal, std::complex<double>* result, int size, int idx, std::complex<double> w);
	static std::vector<double> FFT(std::vector<std::complex<double>> signal);
    static double hannFunction(int n, int N);
    static std::vector<std::complex<double>> makeWindow(std::vector<double> signal, double (*w_func)(int, int), int w_size);
};
