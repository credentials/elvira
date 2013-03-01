# generate and install pkg-config file
set (DOLLAR "$")
set (PREFIX ${CMAKE_INSTALL_PREFIX})

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/${PKG_NAME}.pc.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PKG_NAME}.pc
)

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/${PKG_NAME}_crypto.pc.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PKG_NAME}_crypto.pc
)

install(FILES
          ${CMAKE_CURRENT_BINARY_DIR}/${PKG_NAME}.pc
          ${CMAKE_CURRENT_BINARY_DIR}/${PKG_NAME}_crypto.pc
        DESTINATION lib/pkgconfig/
)
