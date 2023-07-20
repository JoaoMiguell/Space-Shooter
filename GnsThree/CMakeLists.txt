# CMakeList.txt : CMake project for GnsThree, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (GnsThree "GnsThree.cpp" "GnsThree.h" "Entities/Player.cpp" "Entities/Player.h")
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy_directory
			${PROJECT_SOURCE_DIR}/GnsThree/Assets
			${PROJECT_BINARY_DIR}/GnsThree/Assets)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GnsThree PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
find_package(raylib CONFIG REQUIRED)
target_link_libraries(GnsThree PRIVATE raylib)