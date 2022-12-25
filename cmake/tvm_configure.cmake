if (IS_WINDOWS)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_SCL_SECURE_NO_WARNINGS)
    add_definitions(-D_ENABLE_EXTENDED_ALIGNED_STORAGE)
    add_definitions(-DNOMINMAX)
    # regeneration does not work well with msbuild custom rules.
    set(CMAKE_SUPPRESS_REGENERATION ON)
    if (NOT IS_MINGW)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
    endif ()
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /bigobj")

    # MSVC already errors on undefined symbols, no additional flag needed.
    set(TVM_NO_UNDEFINED_SYMBOLS "")

    if(USE_MSVC_MT)
        foreach(flag_var
                CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
                CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
            if(${flag_var} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
            endif(${flag_var} MATCHES "/MD")
        endforeach(flag_var)
        MESSAGE(STATUS "begin to set MT")
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
        #    MESSAGE(STATUS "begin to set MT")
        #    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif()
    message(STATUS "cmake setting : ${CMAKE_C_FLAGS}")

    if (NOT IS_MINGW)
        # Disable common MSVC warnings
        # Integer conversion warnings(e.g. int64 to int)
        add_compile_options(/wd4244)
        add_compile_options(/wd4267)
        # Signed unsigned constant comparison
        add_compile_options(/wd4018)
        # Aligned alloc may not met(need c++17)
        add_compile_options(/wd4316)
        # unreferenced local variables(usually in exception catch)
        add_compile_options(/wd4101)
        # always inline keyword not necessary
        add_compile_options(/wd4180)
        # DLL interface warning in c++
        add_compile_options(/wd4251)
        # destructor was implicitly defined as deleted
        add_compile_options(/wd4624)
        # unary minus operator applied to unsigned type, result still unsigned
        add_compile_options(/wd4146)
        # 'inline': used more than once
        add_compile_options(/wd4141)
        # unknown pragma
        add_compile_options(/wd4068)
    else()
        if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
            message(STATUS "Build in Debug mode")
#            set(CMAKE_CXX_FLAGS "-O0 ${CMAKE_CXX_FLAGS}")
#            set(CMAKE_C_FLAGS "-O0  ${CMAKE_C_FLAGS}")
#            set(CMAKE_CXX_FLAGS "-O0  ${CMAKE_CXX_FLAGS}")
#            set(CMAKE_CUDA_FLAGS "-O0 -g -Xcompiler=-Wall -Xcompiler=-fPIC ${CMAKE_CUDA_FLAGS}")
        else()
            message(STATUS "Build in Release mode")
            set(CMAKE_C_FLAGS "-O2 ${WARNING_FLAG} -fPIC ${CMAKE_C_FLAGS}")
            set(CMAKE_CXX_FLAGS "-O2 ${WARNING_FLAG} -fPIC ${CMAKE_CXX_FLAGS}")
#            set(CMAKE_CUDA_FLAGS "-O2 -Xcompiler=-Wall -Xcompiler=-fPIC ${CMAKE_CUDA_FLAGS}")
            set(TVM_VISIBILITY_FLAG "")
            if (HIDE_PRIVATE_SYMBOLS)
                message(STATUS "Hide private symbols...")
                set(TVM_VISIBILITY_FLAG "-fvisibility=hidden")
            endif(HIDE_PRIVATE_SYMBOLS)
        endif ()
    endif ()

else()
    set(WARNING_FLAG -Wall)
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        message(STATUS "Build in Debug mode")
        set(CMAKE_C_FLAGS "-O0 -g ${WARNING_FLAG} -fPIC ${CMAKE_C_FLAGS}")
        set(CMAKE_CXX_FLAGS "-O0 -g ${WARNING_FLAG} -fPIC ${CMAKE_CXX_FLAGS}")
        set(CMAKE_CUDA_FLAGS "-O0 -g -Xcompiler=-Wall -Xcompiler=-fPIC ${CMAKE_CUDA_FLAGS}")
    else()
        message(STATUS "Build in Release mode")
        set(CMAKE_C_FLAGS "-O2 ${WARNING_FLAG} -fPIC ${CMAKE_C_FLAGS}")
        set(CMAKE_CXX_FLAGS "-O2 ${WARNING_FLAG} -fPIC ${CMAKE_CXX_FLAGS}")
        set(CMAKE_CUDA_FLAGS "-O2 -Xcompiler=-Wall -Xcompiler=-fPIC ${CMAKE_CUDA_FLAGS}")
        set(TVM_VISIBILITY_FLAG "")
        if (HIDE_PRIVATE_SYMBOLS)
            message(STATUS "Hide private symbols...")
            set(TVM_VISIBILITY_FLAG "-fvisibility=hidden")
        endif(HIDE_PRIVATE_SYMBOLS)
    endif ()
    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang" AND
            CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 7.0)
        set(CMAKE_CXX_FLAGS "-faligned-new ${CMAKE_CXX_FLAGS}")
    endif()

    # ld option to warn if symbols are undefined (e.g. libtvm_runtime.so
    # using symbols only present in libtvm.so).  Not needed for MSVC,
    # since this is already the default there.
    if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR ${CMAKE_SYSTEM_NAME} MATCHES "iOS")
        set(TVM_NO_UNDEFINED_SYMBOLS "-Wl,-undefined,error")
    else()
        set(TVM_NO_UNDEFINED_SYMBOLS "-Wl,--no-undefined")
    endif()
    message(STATUS "Forbidding undefined symbols in shared library, using ${TVM_NO_UNDEFINED_SYMBOLS} on platform ${CMAKE_SYSTEM_NAME}")
endif ()

include_directories("${TVM_DIR}/include")
include_directories("${TVM_DIR}/3rdparty/dmlc-core/include")
include_directories("${TVM_DIR}/3rdparty/dlpack/include/")
include_directories("${TVM_DIR}")
add_definitions("-DDMLC_USE_LOGGING_LIBRARY=<tvm/runtime/logging.h>")
