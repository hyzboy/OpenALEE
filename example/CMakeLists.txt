add_executable(test test.cpp)

target_link_libraries(test CMCore CMPlatform CMAudio)

IF(MSVC)
    set_target_properties(test PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${OPENALEE_RUNTIME_PATH})
ENDIF()
