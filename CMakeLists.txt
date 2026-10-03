cmake_minimum_required(VERSION 3.27)
project(my_end)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(my_end
        Address.cpp
        Address.h
        main.cpp
        MedicalCenter.cpp
        MedicalCenter.h
        PersonInfo.cpp
        PersonInfo.h
        Pet.cpp
        Pet.h
        Petinfo.cpp
        Petinfo.h
        VetClinic.cpp
        VetClinic.h
        Date.h
        Date.cpp
        Disease.cpp
        Cat.cpp
        Cat.h)
