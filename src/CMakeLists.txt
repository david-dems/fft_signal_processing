set( SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/fft.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )

target_sources(spectrum PRIVATE ${SOURCES})
