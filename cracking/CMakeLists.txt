cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project("cracking"
  VERSION 0.0.1
  DESCRIPTION "cracking the coding interview"
  LANGUAGES C 
)

file(GLOB srcs src/*.c)
foreach(src ${srcs})
  get_filename_component(bin ${src} NAME_WE)
  add_executable(${bin} ${src})
endforeach(src ${srcs})
