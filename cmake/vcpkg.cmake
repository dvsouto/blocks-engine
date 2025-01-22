if(DEFINED ENV{VCPKG_ROOT} AND NOT CMAKE_TOOLCHAIN_FILE)
    message("-- Reading VCPKG of $ENV{VCPKG_ROOT}")

    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
    set(VCPKG_MANIFEST_MODE ON CACHE BOOL "Enable vcpkg manifest mode")
endif()

# VCPKG environment
set(VCPKG_ROOT "$ENV{VCPKG_ROOT}")

# Select VCPKG installed dir by manifest mode
if(VCPKG_MANIFEST_MODE)
    message("-- [Info] Using VCPKG Manifest mode")

    set(VCPKG_MANIFEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed")
    set(VCPKG_INSTALLED_DIR "${VCPKG_MANIFEST_DIR}/x64-osx")
else()
    message("-- [Info] Using VCPKG Global mode")

    set(VCPKG_INSTALLED_DIR "$ENV{VCPKG_ROOT}/installed/x64-osx")
endif()

# All VCPKG includes
set(VCPKG_INCLUDE "${VCPKG_INSTALLED_DIR}/include")
set(VCPKG_LIB "${VCPKG_INSTALLED_DIR}/lib")
set(VCPKG_SHARE "${VCPKG_INSTALLED_DIR}/share")

# Add VCPKG to cmake paths
list(APPEND CMAKE_PREFIX_PATH "${VCPKG_INSTALLED_DIR}")
list(APPEND CMAKE_PREFIX_PATH "${VCPKG_SHARE}")

message("-- [Info] VCPKG_INSTALLED_DIR: ${VCPKG_INSTALLED_DIR}")
message("-- [Info] VCPKG_INCLUDE_DIR: ${VCPKG_INSTALLED_DIR}")
message("-- [Info] CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message("-- [Info] VCPKG_MANIFEST_MODE: ${VCPKG_MANIFEST_MODE}")
message("-- [Info] Using toolchain: ${CMAKE_TOOLCHAIN_FILE}")