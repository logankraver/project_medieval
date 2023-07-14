cmake_minimum_required(VERSION 3.0)

project(Medieval_Sim)

set(PERSON_DIR src/person)

add_executable(
    Medieval_Sim 
    src/main.cpp
    ${PERSON_DIR}/person.cpp
    ${PERSON_DIR}/farmer.cpp
    ${PERSON_DIR}/merchant.cpp
    src/world/world.cpp
    src/world/chunk.cpp
    src/dice.cpp
)



