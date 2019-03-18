# User
add_library(utility
        src/utils.cpp
)

target_include_directories(utility
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${Boost_INCLUDE_DIR}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(utility
        ${Boost_LIBRARIES}
)

set_target_properties(utility
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS utility
  ARCHIVE DESTINATION lib
)
