set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__FILE_NAME__='\"$(notdir $(abspath $<))\"'")


add_executable(
        unit_tests
        main.cpp
        test_elogger.cpp
        test_emsgbus.cpp)

target_link_libraries(
        unit_tests
        gtest_main
        eframework
        qlibc
        dl
)

add_compile_options(-Wl -verbose)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/Scripts/x86_gcc/linkerscript.ld")

add_test(NAME unit COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)

