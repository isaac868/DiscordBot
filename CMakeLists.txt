# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("DiscordBot")

include_directories("include")
file(GLOB SOURCES "source/*.cpp")

include(FetchContent)
FetchContent_Declare(
  sleepy-discord
  GIT_REPOSITORY https://github.com/yourWaifu/sleepy-discord.git
  GIT_TAG        develop
)

FetchContent_MakeAvailable(sleepy-discord)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sleepy-discord)