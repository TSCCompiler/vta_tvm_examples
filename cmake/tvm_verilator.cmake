if (NOT VERILATOR_DIR)
    set(VERILATOR_DIR /usr/local/bin/)
endif ()
set(VERILATOR_BIN "${VERILATOR_DIR}/verilator")
if (NOT VERILATOR_INC_DIR)
    set(VERILATOR_INC_DIR "${VERILATOR_DIR}/../share/verilator/include")
endif ()
message(STATUS "curr verilator inc ${VERILATOR_INC_DIR}")
#if (EXISTS  "${VERILATOR_INC_DIR}")
if (IS_WINDOWS)
    message(STATUS "got inc")
    set(VERILATOR_INC_DIR
            "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/verilator/include")
endif ()
message(STATUS "verilator inc dir ${VERILATOR_INC_DIR}")

if (NOT VTA_HW_PATH)
    if(NOT DEFINED ENV{VTA_HW_PATH})
        message(STATUS "setting vta to local")
        set(VTA_HW_PATH ${CMAKE_CURRENT_SOURCE_DIR})
    else()
        set(VTA_HW_PATH $ENV{VTA_HW_PATH})
    endif()
endif ()
message(STATUS "VTA HW PATH ${VTA_HW_PATH}")

include_directories("${TVM_DIR}/src/runtime/contrib/verilator")
include_directories("${TVM_DIR}/include")
include_directories("${TVM_DIR}/3rdparty/dlpack/include")
include_directories(${VERILATOR_INC_DIR})
