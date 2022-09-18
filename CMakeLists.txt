cmake_minimum_required(VERSION 3.10)

project(FFT LANGUAGES CXX C VERSION 0.1)

set(AUTHOR "David Demuriia")
set(DESCRIPTION "Homemade FFT")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(spectrum "")
add_subdirectory(src)

set_target_properties(spectrum
	PROPERTIES
	CXX_STANDARD 17
	)







