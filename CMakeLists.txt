cmake_minimum_required(VERSION 3.14)

project(Gearsimulation VERSION 0.0.1 LANGUAGES CXX)

add_executable(Gearsimulation src/main.cpp src/Gear.cpp include/Gear.hpp)

add_library(MyLibrary)

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
