
add_executable(mudclient
        mudclient.cpp
  ChatWindow.cpp
)

set_target_properties(mudclient
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)

find_package(Curses REQUIRED)
find_package(Threads REQUIRED)

target_include_directories(mudclient
  PRIVATE
  ${CURSES_INCLUDE_DIR}
)

target_link_libraries(mudclient
  networking
  ${CURSES_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
)

install(TARGETS mudclient
  RUNTIME DESTINATION bin
)

