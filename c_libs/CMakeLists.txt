cmake_minimum_required(VERSION 3.12)
project(c_libs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Debug)
include_directories(Release)
include_directories(/Library/Java/JavaVirtualMachines/jdk1.8.0_101.jdk/Contents/Home/include)
include_directories(/Library/Java/JavaVirtualMachines/jdk1.8.0_101.jdk/Contents/Home/include/darwin)


add_executable(c_libs
        Debug/makefile
        Debug/objects.mk
        Debug/sources.mk
        Debug/subdir.mk
        Release/libc_libs.dylib
        Release/makefile
        Release/objects.mk
        Release/sources.mk
        Release/subdir.mk
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
