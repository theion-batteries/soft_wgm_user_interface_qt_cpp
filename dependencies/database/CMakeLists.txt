add_subdirectory(sqlite3-cmake)
#This is necessary for MSVC to create a symbol file, .lib, besides a shared library, .dll
if (MSVC)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_library(databaseLib STATIC
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
userDB.h
userDB.cpp
)
target_link_libraries(databaseLib PUBLIC sqlite3Lib)
target_include_directories(databaseLib 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sqlite3-cmake/src/
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

install(TARGETS databaseLib DESTINATION lib)
FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
INSTALL(FILES ${files} DESTINATION include/database/)


add_executable(dbBin
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
userDB.h
userDB.cpp
main.cpp
)
target_link_libraries(dbBin PUBLIC sqlite3Lib)
target_include_directories(dbBin 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sqlite3-cmake/src/
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

