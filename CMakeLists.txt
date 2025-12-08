cmake_minimum_required(VERSION 3.14)

project(Gearsimulation VERSION 0.0.1 LANGUAGES CXX)

set(SOURCES src/main.cpp) 
set(HEADER_FILES include/Gear.hpp)

add_library(MyLibrary src/Gear.cpp ${HEADER_FILES})

target_include_directories(MyLibrary PRIVATE include)

add_executable(Gearsimulation ${SOURCES} ${HEADER_FILES})

target_include_directories(Gearsimulation PRIVATE src)

target_sources(MyLibrary
	PRIVATE
		src/Gear.cpp

	PUBLIC
		FILE_SET HEADERS
		BASE_DIRS
			include
		FILES
			include/Gear.hpp
)

target_link_libraries(Gearsimulation PRIVATE MyLibrary sfml-graphics sfml-window sfml-system)
