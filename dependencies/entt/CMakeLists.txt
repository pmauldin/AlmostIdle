#add_library(EnTT INTERFACE "include/entt.hpp")

#target_include_directories(EnTT INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

message(STATUS "Fetching EnTT...")

FetchContent_MakeAvailable(entt)
