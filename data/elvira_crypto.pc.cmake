prefix=@PREFIX@
exec_prefix=@DOLLAR@{prefix}
libdir=@DOLLAR@{prefix}/lib
includedir=@DOLLAR@{prefix}/include

Name: @PKG_NAME@_crypto
Description: @PKG_DESCRIPTION@
Version: @PKG_VERSION@
Libs: -L@DOLLAR@{libdir} -l@PKG_NAME@_crypto
Cflags: -I@DOLLAR@{includedir}/${PKG_NAME}
Requires: @PKG_DEPS@
