
add_executable (
    untitled
    b64.cpp
    main.cpp
)

target_include_directories(
    untitled
    PRIVATE
        $ENV{PROJECT_SRC_DIR}
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries (
	untitled
    PRIVATE
    pthread
)

install (
    TARGETS untitled
    DESTINATION $ENV{PROJECT_BIN_DIR}/
)
