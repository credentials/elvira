cmake_minimum_required(VERSION 2.8)

project(clib)

set(PKG_NAME "credentials")
set(PKG_DESCRIPTION "Fast and portable C library which provides both high-level and low-level (cryptographic) credential operations")
set(PKG_AUTHOR "Peter Schwabe <peter@cryptojedi.org>, Pim Vullers <pim@cs.ru.nl>")
set(PKG_VERSION_MAJOR "0")
set(PKG_VERSION_MINOR "1")
set(PKG_VERSION_PATCH "0")
set(PKG_VERSION_INFO "Release")

set(PKG_VERSION "${PKG_VERSION_MAJOR}.${PKG_VERSION_MINOR}.${PKG_VERSION_PATCH}")

set(CPACK_PACKAGE_NAME ${PKG_NAME})
set(CPACK_PACKAGE_VENDOR ${PKG_AUTHOR})
set(CPACK_PACKAGE_CONTACT ${PKG_AUTHOR})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PKG_DESCRIPTION})
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_SOURCE_DIR}/README")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR ${PKG_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PKG_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PKG_VERSION_PATCH})

set(CPACK_SOURCE_GENERATOR "TGZ;TBZ2;ZIP")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${PKG_NAME}-${PKG_VERSION}")
set(CPACK_SOURCE_IGNORE_FILES "/build/;~$;${CPACK_SOURCE_IGNORE_FILES}")

set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6, libgmp10")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE ${ARCH})
set(CPACK_DEBIAN_PACKAGE_SECTION  "libs")

set(CPACK_RPM_PACKAGE_LICENSE "CC0-1.0")
set(CPACK_RPM_PACKAGE_REQUIRES "gmp")
include(CPack)

add_custom_target(dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)
add_custom_target(deb COMMAND ${CMAKE_CPACK_COMMAND} -G DEB)
add_custom_target(rpm COMMAND ${CMAKE_CPACK_COMMAND} -G RPM)

option(BUILD_LIBRARIES "Build the libraries" ON)
if(BUILD_LIBRARIES)
  add_subdirectory(data)
  add_subdirectory(src)
endif(BUILD_LIBRARIES)

option(BUILD_TESTS "Build the test applications" ON)
if(BUILD_TESTS)
  add_subdirectory(test)
endif(BUILD_TESTS)
