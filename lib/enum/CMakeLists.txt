add_library(enum INTERFACE)
#target_sources(enum INTERFACE "string_enum.h")


target_include_directories(enum INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)