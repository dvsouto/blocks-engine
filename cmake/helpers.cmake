function(add_default_includes target)
    # Add this target to application with VCPKG
    target_include_directories(${target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${VCPKG_INCLUDE} ${CMAKE_TOOLCHAIN_FILE})
endfunction()

function(add_module MODULE_NAME)
    file(GLOB MODULE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/${MODULE_NAME}/*.cpp")

    add_library(${MODULE_NAME} ${MODULE_SOURCES})
    target_include_directories(${MODULE_NAME} PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}
            ${VCPKG_INCLUDE}
            ${CMAKE_TOOLCHAIN_FILE}
            ${CMAKE_CURRENT_SOURCE_DIR}/src/include/${MODULE_NAME}
    )

    add_default_includes(${MODULE_NAME})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${MODULE_NAME})
endfunction()