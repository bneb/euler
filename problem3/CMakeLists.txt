cmake_minimum_required(VERSION 3.22)

# set the project name
project(Problem3)

# add the executable
add_executable(Problem3 problem3.cc)
target_compile_features(Problem3 PRIVATE cxx_std_17)
