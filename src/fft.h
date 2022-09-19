#pragma once
#include <complex>
#include <vector>

class SignalProcess{
public:
	static std::complex<double>* fft(std::complex<double>* signal, std::complex<double>* result, int size, int idx, std::complex<double> w);
	static std::vector<std::complex<double>> FFT(std::vector<std::complex<double>> signal);
};
