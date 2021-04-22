cmake_minimum_required(VERSION 3.15)

project ("HashTable Example" VERSION 0.0.1 LANGUAGES CXX)

add_executable(HashTableExample
                    src/main.cpp src/dshashtable.h)