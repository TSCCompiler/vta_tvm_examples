if (NOT VERILATOR_DIR)
    set(VERILATOR_DIR /usr/local/bin/)
endif ()
set(VERILATOR_BIN "${VERILATOR_DIR}/verilator")
if (NOT VERILATOR_INC_DIR)
    set(VERILATOR_INC_DIR "${VERILATOR_DIR}/../share/verilator/include")
endif ()

set(TOP_NAME "Top")
set(LIB_NAME "verilator")
set(VERILOG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/verilog")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
option(LANES 1)
set(BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_CXX_STANDARD 14)


include_directories("${TVM_DIR}/src/runtime/contrib/verilator")
include_directories("${TVM_DIR}/include")
include_directories("${TVM_DIR}/3rdparty/dlpack/include")
include_directories(${BUILD_DIR})
include_directories(${VERILATOR_INC_DIR})
add_definitions("-DLANES=${LANES}")


if (IS_WINDOWS)
    MESSAGE(STATUS "in windows")
    include_directories("${CMAKE_CURRENT_SOURCE_DIR}/verilog/include")
    include_directories("${CMAKE_CURRENT_SOURCE_DIR}/verilog/build")
    set(BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/verilog/build")
    add_library(${LIB_NAME} SHARED
            ${VERILATOR_INC_DIR}/verilated.cpp
            ${VERILATOR_INC_DIR}/verilated_vcd_c.cpp
            src/driver.cc
            src/kernel.cc
            ${BUILD_DIR}/${TOP_NAME}.cpp
            ${BUILD_DIR}/${TOP_NAME}__Slow.cpp
            ${BUILD_DIR}/${TOP_NAME}__Syms.cpp
            ${BUILD_DIR}/${TOP_NAME}__Trace.cpp
            ${BUILD_DIR}/${TOP_NAME}__Trace__Slow.cpp
            )
else()
    add_custom_command(OUTPUT ${BUILD_DIR}/${TOP_NAME}.cpp
            ${BUILD_DIR}/${TOP_NAME}__Slow.cpp
            ${BUILD_DIR}/${TOP_NAME}__Syms.cpp
            ${BUILD_DIR}/${TOP_NAME}__Trace.cpp
            ${BUILD_DIR}/${TOP_NAME}__Trace__Slow.cpp
            ${VERILATOR_INC_DIR}/verilated.cpp
            ${VERILATOR_INC_DIR}/verilated_vcd_c.cpp
            COMMAND "${VERILATOR_BIN}"
            ARGS "-Wno-BLKANDNBLK"
            -Wno-PINMISSING
            -Wno-STMTDLY
            -Wno-WIDTH
            -Wno-UNOPTFLAT
            "-DLANES=${LANES}"
            --cc
            --trace
            --prefix
            "${TOP_NAME}"
            --top-module "driver"
            --Mdir ${BUILD_DIR}
            ${VERILOG_DIR}/*.v


            )
    add_custom_target(build_verilator
            DEPENDS
            ${BUILD_DIR}/${TOP_NAME}.cpp
            )
    add_library(${LIB_NAME} SHARED
            ${VERILATOR_INC_DIR}/verilated.cpp
            ${VERILATOR_INC_DIR}/verilated_vcd_c.cpp
            src/driver.cc
            src/kernel.cc
            ${BUILD_DIR}/${TOP_NAME}.cpp
            ${BUILD_DIR}/${TOP_NAME}__Slow.cpp
            ${BUILD_DIR}/${TOP_NAME}__Syms.cpp
            ${BUILD_DIR}/${TOP_NAME}__Trace.cpp
            ${BUILD_DIR}/${TOP_NAME}__Trace__Slow.cpp
            )
    add_dependencies(${LIB_NAME}
            build_verilator
            )
endif ()

