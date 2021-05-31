cmake_minimum_required(VERSION 3.19)
project(GraphProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphProject main.cpp src/SeriousGraphTools/SimpleGraph.cpp src/SeriousGraphTools/SimpleGraph.h src/SeriousGraphTools/Graph/Node.h src/SeriousGraphTools/Graph/Edge.h src/SeriousGraphTools/Tools.h src/SeriousGraphTools/Import/Import.h src/SeriousGraphTools/Import/Import.cpp)