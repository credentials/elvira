# includes
set(PKG_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include)

# sources
set(SOURCES_CRYPTO
        test_crypto.c
        test_vectors_crypto.c
)

# sources
set(SOURCES_CRED
        test_credential.c
)

# dependencies
set(PKG_DEPS gmp ${PKG_NAME}_crypto ${PKG_DEPS})

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
set(INSTALL_TEST_DIR bin CACHE PATH "Installation directory for test executables")

add_executable(test_crypto ${SOURCES_CRYPTO})
add_dependencies(test_crypto ${PKG_NAME}_crypto)
target_link_libraries(test_crypto ${LIBS} ${PKG_NAME}_crypto)

add_executable(test_credential ${SOURCES_CRED})
add_dependencies(test_credential ${PKG_NAME}_crypto)
target_link_libraries(test_credential ${LIBS} ${PKG_NAME}_crypto)

install(
  TARGETS test_crypto test_credential
  RUNTIME DESTINATION ${INSTALL_TEST_DIR}
)
