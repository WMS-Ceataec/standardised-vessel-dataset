add_executable(simple_exporter
    main.cpp
)

target_link_libraries(simple_exporter
    PRIVATE
        svd
)

target_include_directories(simple_exporter
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)
