cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(zephyr-rp2040 LANGUAGES C)  # set to your own name if desired.

#zephyr_syscall_include_directories(include)
zephyr_include_directories(include)

target_sources(app PRIVATE 
    src/main.c
)