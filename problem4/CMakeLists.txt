cmake_minimum_required(VERSION 3.22)

# set the project name
project(Problem4)

# add the executable
add_executable(Problem4 problem4.cc)
target_compile_features(Problem4 PRIVATE cxx_std_17)
