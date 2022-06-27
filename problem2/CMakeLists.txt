cmake_minimum_required(VERSION 3.22)

# set the project name
project(Problem2)

# add the executable
add_executable(Problem2 problem2.cc)
target_compile_features(Problem2 PRIVATE cxx_std_17)
