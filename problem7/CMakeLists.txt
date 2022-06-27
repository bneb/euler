cmake_minimum_required(VERSION 3.22)

# set the project name
project(Problem)

# add the executable
add_executable(Problem problem.cc)
target_compile_features(Problem PRIVATE cxx_std_17)
