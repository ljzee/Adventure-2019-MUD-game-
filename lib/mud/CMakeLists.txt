add_library(mud
        src/room.cpp
        src/world.cpp
        src/area.cpp
        src/Character.cpp
        src/object.cpp
        src/JSONParser.cpp
        src/clonable.cpp
        src/RoomController.cpp
        src/CharacterController.cpp
        src/AssociationController.cpp
        )

find_package(Boost 1.68 COMPONENTS system filesystem REQUIRED)

target_include_directories(mud
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIR}
        )

target_link_libraries(mud
        PRIVATE
        command
        user
        ${Boost_LIBRARIES}
        )


set_target_properties(mud
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        )

install(TARGETS mud
        ARCHIVE DESTINATION lib
        )

