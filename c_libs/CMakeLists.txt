cmake_minimum_required(VERSION 3.12)
project(c_libs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(/Library/Java/JavaVirtualMachines/jdk1.8.0_101.jdk/Contents/Home/include)
include_directories(/Library/Java/JavaVirtualMachines/jdk1.8.0_101.jdk/Contents/Home/include/darwin)



add_executable(c_exec
        CUnit.c
        CUnit.h
        de_lab4inf_wrb_Differentiator.cpp
        de_lab4inf_wrb_Integrator.cpp
        Differentiator.cpp
        Differentiator.h
        Function.cpp
        Function.h
        Integrator.cpp
        Integrator.h
        JavaFunction.cpp
        JavaFunction.h
        main.cpp)

add_library(c_libs SHARED
        CUnit.c
        CUnit.h
        de_lab4inf_wrb_Differentiator.cpp
        de_lab4inf_wrb_Integrator.cpp
        Differentiator.cpp
        Differentiator.h
        Function.cpp
        Function.h
        Integrator.cpp
        Integrator.h
        JavaFunction.cpp
        JavaFunction.h
        main.cpp)
