cmake_minimum_required(VERSION 3.0)
project(algorithms)

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach(file ${files})
     string(FIND ${file} "." endIndex REVERSE)
     string(FIND ${file} "/" beginIndex REVERSE)

     math(EXPR length ${endIndex}-${beginIndex}-1)
     math(EXPR begin ${beginIndex}+1)
     string(SUBSTRING ${file} ${begin} ${length} filename)
     message("Generating: " ${filename})
     add_executable(${filename} ${file})
endforeach()
