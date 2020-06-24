cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(BinarySearchTree VERSION 1.0)

# add the executable
add_executable(Main main.cpp
                    )

configure_file(BSTconfig.h.in BSTconfig.h)




target_include_directories(Main PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            )