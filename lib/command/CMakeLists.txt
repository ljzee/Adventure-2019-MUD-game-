add_library(command
  src/command.cpp
  src/commander.cpp
        src/commandDeclaration.cpp
)

find_package(Boost 1.68 COMPONENTS system REQUIRED)

target_include_directories(command
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(command
  PRIVATE
    mud
    networking
    user
    ${Boost_LIBRARIES}
)

set_target_properties(command
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS command
  ARCHIVE DESTINATION lib
)

