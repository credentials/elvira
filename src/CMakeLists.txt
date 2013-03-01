set(PKG_VERSION 0.1.0) # increase when you break the API
set(PKG_SOVERSION 0) # increase when you add functionality

# includes
set(PKG_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include)

# sources
set(SOURCES
        credential.c
        credential_card.c
	credential_terminal.c
)
set(SOURCES_CRYPTO
	credential_crypto.c
)

# dependencies
set(PKG_DEPS gmp ${PKG_DEPS})

# verifiy dependencies
#find_package(PkgConfig)
#pkg_check_modules(DEPS REQUIRED ${PKG_DEPS})

# generate and install pkg-config file
#set(DOLLAR "$")
#set(PREFIX ${CMAKE_INSTALL_PREFIX})
#configure_file(
#        ${CMAKE_SOURCE_DIR}/data/${PKG_NAME}.pc.cmake
#        ${CMAKE_BINARY_DIR}/data/${PKG_NAME}.pc
#)
#install(
#        FILES ${CMAKE_BINARY_DIR}/data/${PKG_NAME}.pc
#        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig/
#)

# compiler configuration
set(CFLAGS ${DEPS_CFLAGS} ${DEPS_CFLAGS_OTHER})
set(LIBS ${DEPS_LIBRARIES})
set(LIBS ${LIBS} -lgmp)
set(LIB_PATHS ${DEPS_LIBRARY_DIRS})
set(INC_PATHS ${DEPS_INCLUDE_DIRS} ${PKG_INCLUDE_DIRS})
add_definitions(${CFLAGS})
link_directories(${LIB_PATHS})
include_directories(${INC_PATHS})

# gcc configuration
IF(CMAKE_COMPILER_IS_GNUCC)
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0")
ENDIF(CMAKE_COMPILER_IS_GNUCC)
IF(CMAKE_COMPILER_IS_GNUCXX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

# generate and install the library
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
#configure_file(
#        ${CMAKE_SOURCE_DIR}/include/${PKG_NAME}.h.cmake
#        ${CMAKE_BINARY_DIR}/include/${PKG_NAME}.h
#)
add_library(${PKG_NAME} SHARED ${SOURCES})
add_library(${PKG_NAME}_crypto SHARED ${SOURCES_CRYPTO})
add_dependencies(${PKG_NAME} ${PKG_NAME}_crypto)
target_link_libraries(${PKG_NAME}_crypto ${LIBS})
target_link_libraries(${PKG_NAME} ${LIBS} ${PKG_NAME}_crypto)
set_target_properties(${PKG_NAME} PROPERTIES
  VERSION ${PKG_VERSION}
  SOVERSION ${PKG_SOVERSION}
  PUBLIC_HEADER "${CMAKE_SOURCE_DIR}/include/credential.h"
)
set_target_properties(${PKG_NAME}_crypto PROPERTIES
  VERSION ${PKG_VERSION}
  SOVERSION ${PKG_SOVERSION}
  PUBLIC_HEADER "${CMAKE_SOURCE_DIR}/include/credential_crypto.h"
)
install(
  TARGETS ${PKG_NAME} ${PKG_NAME}_crypto
  LIBRARY DESTINATION ${INSTALL_LIB_DIR} COMPONENT shlib
  PUBLIC_HEADER DESTINATION ${INSTALL_INCLUDE_DIR}/${PKG_NAME} COMPONENT dev
)
