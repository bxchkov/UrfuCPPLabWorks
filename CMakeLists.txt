cmake_minimum_required(VERSION 3.27)
project(LabWorks)

set(CMAKE_CXX_STANDARD 17)

# Добавляем флаг статической линковки, чтобы exe не требовал dll
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(LabWork1.1 labWork1.1.cpp)
add_executable(LabWork1.2 labWork1.2.cpp)
add_executable(LabWork1.3 labWork1.3.cpp)

add_executable(LabWork2   labWork2.cpp)

add_executable(LabWork3.1 labWork3.1.cpp)
add_executable(LabWork3.2 labWork3.2.cpp)
add_executable(LabWork3.3 labWork3.3.cpp)
add_executable(LabWork3.4 labWork3.4.cpp)
add_executable(LabWork3.5 labWork3.5.cpp)
add_executable(LabWork3.6 labWork3.6.cpp)

add_executable(LabWork4.1 labWork4.1.cpp)
add_executable(LabWork4.2 labWork4.2.cpp)
add_executable(LabWork4.3 labWork4.3.cpp)
add_executable(LabWork4.4 labWork4.4.cpp)
add_executable(LabWork4.5 labWork4.5.cpp)

add_executable(LabWork5.1 labWork5.1.cpp)
add_executable(LabWork5.2 labWork5.2.cpp)
add_executable(LabWork5.3 labWork5.3.cpp)
add_executable(LabWork5.4 labWork5.4.cpp)
add_executable(LabWork5.5 labWork5.5.cpp)
add_executable(LabWork5.6 labWork5.6.cpp)

add_executable(LabWork6.1-2 labWork6.1-2.cpp
                            labWork6.1-2_string_class.h
                            labWork6.1-2_string_class.cpp)
add_executable(LabWork6.3   labWork6.3.cpp
                            labWork6.3_string_class.h
                            labWork6.3_string_class.cpp)
add_executable(LabWork6.4   labWork6.4.cpp
                            labWork6.4_string_class.cpp
                            labWork6.4_string_class.h)

add_executable(LabWork7   labWork7.cpp)
# Явно подключаем библиотеку GDI32 для LabWork7, так как она использует Windows Graphics API
target_link_libraries(LabWork7 gdi32)

add_executable(LabWork8.1 labWork8.1.cpp)
add_executable(LabWork8.2 labWork8.2.cpp)
add_executable(LabWork8.3 labWork8.3.cpp)
add_executable(LabWork8.4 labWork8.4.cpp)