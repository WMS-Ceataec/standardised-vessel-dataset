add_executable(svd_tests
    test_main.cpp
    models/test_general_information.cpp
    models/test_standardised_vessel_dataset.cpp
    exporters/test_svd_json_exporter.cpp
)

target_link_libraries(svd_tests
    PRIVATE
        svd
        GTest::gtest
        GTest::gtest_main
)

target_include_directories(svd_tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

# Discover tests
include(GoogleTest)
gtest_discover_tests(svd_tests)
