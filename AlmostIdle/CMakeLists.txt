cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

# Add source to this project's executable.
add_executable (AlmostIdle 
    "AlmostIdle.cpp"  "room.cpp"   
    "Scene/Scene.cpp" "Scene/RenderSystem.cpp" "Scene/PlayerSystem.cpp" "Scene/Components.h" "Scene/DebugSystem.cpp" "Scene/MovementSystem.cpp"
    "MapLoader.h" "MapLoader.cpp"
)
target_link_libraries(AlmostIdle PRIVATE ImGui-SFML::ImGui-SFML EnTT::EnTT)

# Copy DLLs needed for runtime on Windows
if(WIN32)
  if (BUILD_SHARED_LIBS)
    add_custom_command(TARGET AlmostIdle POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_FILE:ImGui-SFML::ImGui-SFML>
          $<TARGET_FILE:sfml-graphics>
          $<TARGET_FILE:sfml-window>
          $<TARGET_FILE:sfml-system>
          $<TARGET_FILE_DIR:AlmostIdle>)
  endif()
endif()


file(COPY assets DESTINATION .)
