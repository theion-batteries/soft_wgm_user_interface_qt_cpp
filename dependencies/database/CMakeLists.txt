add_subdirectory(sqlite3-cmake)
#This is necessary for MSVC to create a symbol file, .lib, besides a shared library, .dll
if (MSVC)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_library(database STATIC
Idatabase.h
Idatabase.cpp
sinkingDB.h
sinkingDB.cpp
coolingDB.h
coolingDB.cpp
heatingDB.h
heatingDB.cpp
extractingDB.h
extractingDB.cpp
aligningDB.h
aligningDB.cpp
dbIncludeAll.h
)
target_link_libraries(database PUBLIC sqlite3)
target_include_directories(database 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sqlite3-cmake/src
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
add_executable(dbTest
Idatabase.h
Idatabase.cpp
sinkingDB.h
sinkingDB.cpp
coolingDB.h
coolingDB.cpp
heatingDB.h
heatingDB.cpp
extractingDB.h
extractingDB.cpp
aligningDB.h
aligningDB.cpp
dbIncludeAll.h

main.cpp
)
target_link_libraries(dbTest PUBLIC sqlite3)
target_include_directories(dbTest 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sqlite3-cmake/src
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

