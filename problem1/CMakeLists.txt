cmake_minimum_required(VERSION 3.22)

# set the project name
project(Problem1)

# add the executable
add_executable(Problem1 problem1.cc)
target_compile_features(Problem1 PRIVATE cxx_std_17)
