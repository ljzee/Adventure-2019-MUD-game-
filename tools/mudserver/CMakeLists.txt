add_executable(mudserver
        mudserver.cpp
        )

set_target_properties(mudserver
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)

find_package(Threads REQUIRED)

target_link_libraries(mudserver
  networking
  ${CMAKE_THREAD_LIBS_INIT}
        user
)

install(TARGETS mudserver
  RUNTIME DESTINATION bin
)

