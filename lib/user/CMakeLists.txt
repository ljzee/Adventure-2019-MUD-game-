# User
add_library(user
        src/User.cpp
        src/RegistrationManager.cpp
        src/UserManager.cpp
)

target_include_directories(user
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${Boost_INCLUDE_DIR}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(user
        networking
        ${Boost_LIBRARIES}
)

set_target_properties(user
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS user
  ARCHIVE DESTINATION lib
)

# Login
#[[
add_library(login
        src/Login.cpp
)

target_include_directories(login
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${Boost_INCLUDE_DIR}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/tools/chatclient #include ChatWindow.h
)

target_link_libraries(login
        networking
)
set_target_properties(login
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS login
  ARCHIVE DESTINATION lib
)
]]
