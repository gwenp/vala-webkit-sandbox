# If not 1, append revision to the version number and enable other development stuff
m4_define([valawebkitsandbox_released], [0])

m4_define([valawebkitsandbox_major_version], [0])
m4_define([valawebkitsandbox_minor_version], [0])
m4_define([valawebkitsandbox_micro_version], [0])
m4_define([valawebkitsandbox_nano_version], [1])

# If library source has changed since last release, increment revision
# If interfaces have been added, removed or changed since last release,
#  increment current and set revision to 0
# If interfaces have been added since last release, increment age
# If interfaces have been removed since last release, set age to 0
m4_define([valawebkitsandbox_lt_current], [0])
m4_define([valawebkitsandbox_lt_revision], [0])
m4_define([valawebkitsandbox_lt_age], [0])

# Display the nano_version only if it's not '0'
m4_define([valawebkitsandbox_base_version],
          valawebkitsandbox_major_version.valawebkitsandbox_minor_version.valawebkitsandbox_micro_version)
m4_define([valawebkitsandbox_full_version],
          [m4_if(valawebkitsandbox_nano_version, [0],
                 valawebkitsandbox_base_version, valawebkitsandbox_base_version.valawebkitsandbox_nano_version)])

# Extend version with bzr revision for non-release builds
#m4_define([valawebkitsandbox_version], m4_if(valawebkitsandbox_released, [1],
#          [valawebkitsandbox_full_version], [m4_esyscmd([build-aux/bzr-version-gen valawebkitsandbox_full_version])]))
#m4_define([valawebkitsandbox_major_minor_version], valawebkitsandbox_major_version.valawebkitsandbox_minor_version)
#m4_define([valawebkitsandbox_module_version], valawebkitsandbox_lt_current)

AC_INIT([valawebkitsandbox], valawebkitsandbox_version,
        [https://github.com/gwenp/valawebkitsandbox/issues], [valawebkitsandbox],
        [https://github.com/gwenp/valawebkitsandbox])
AC_DEFINE(RELEASE_NAME, "Stupidly simple.", Codename of this release)
AC_DEFINE(VERSION_INFO, m4_if(valawebkitsandbox_released, [1], "Release", "Development"), Version info for package)

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_PREREQ([2.65])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_HEADERS(config.h)
AC_CONFIG_SRCDIR([configure.ac])
AM_INIT_AUTOMAKE([1.11 tar-ustar dist-xz no-dist-gzip -Wno-portability])
AM_MAINTAINER_MODE

AC_PROG_CC
AM_PROG_CC_C_O
AC_DISABLE_STATIC
LT_INIT
PKG_PROG_PKG_CONFIG([0.21])

LT_LIB_M

AC_SUBST([CFLAGS])
AC_SUBST([CPPFLAGS])
AC_SUBST([LDFLAGS])

LT_CURRENT=valawebkitsandbox_lt_current
LT_REVISION=valawebkitsandbox_lt_revision
LT_AGE=valawebkitsandbox_lt_age
AC_SUBST([LT_CURRENT])
AC_SUBST([LT_REVISION])
AC_SUBST([LT_AGE])

VALAWEBKITSANDBOX_MAJOR_MINOR_VERSION=valawebkitsandbox_major_minor_version
AC_SUBST([VALAWEBKITSANDBOX_MAJOR_MINOR_VERSION])

API_VERSION=0.2
AC_SUBST([API_VERSION])


# -----------------------------------------------------------
# Vala
# -----------------------------------------------------------
VALA_MIN_VERSION=0.16.0

AM_PROG_VALAC([$VALA_MIN_VERSION])
if test "x$VALAC" = "x"; then
    AC_MSG_ERROR([Vala requested but valac >= $VALA_MIN_VERSION is not installed])
fi

AC_PATH_PROG([VAPIGEN], [vapigen], [])
if test "x$VAPIGEN" = "x"; then
    AC_MSG_ERROR([Vala must be built with --enable-vapigen])
fi

# -----------------------------------------------------------
# Dependencies
# -----------------------------------------------------------
GTK_MIN_VERSION=3.0.0
GLIB_MIN_VERSION=2.32.0
GDK_PIXBUF_MIN_VERSION=2.26.0
BAMF_MIN_VERSION=0.2.92

VALAWEBKITSANDBOX_CORE_PKGS="gobject-2.0 >= $GLIB_MIN_VERSION \
                 glib-2.0 >= $GLIB_MIN_VERSION \
                 gthread-2.0 >= $GLIB_MIN_VERSION \
                 gio-2.0 >= $GLIB_MIN_VERSION \
                 gio-unix-2.0 >= $GLIB_MIN_VERSION \
                 gtk+-3.0 >= $GTK_MIN_VERSION \
                 gdk-x11-3.0 >= $GTK_MIN_VERSION \
                 gdk-pixbuf-2.0 >= $GDK_PIXBUF_MIN_VERSION \
                 libbamf3 >= $BAMF_MIN_VERSION \
                 libwnck-3.0 \
                 webkitgtk-3.0 \
                 libsoup-2.4 \
                 x11"
VALAWEBKITSANDBOX_CORE_OPTIONAL_PKGS=""

VALAWEBKITSANDBOX_CORE_VALA_PKGS="--pkg gio-unix-2.0 \
                      --pkg gtk+-3.0 \
                      --pkg gdk-x11-3.0 \
                      --pkg gdk-pixbuf-2.0 \
                      --pkg libbamf3 \
                      --pkg libwnck-3.0 \
                      --pkg posix \
                      --pkg webkitgtk-3.0 \
                      --pkg libsoup-2.4 \
                      --pkg x11"

VALAFLAGS="--target-glib=2.32"
VALAFLAGS_CORE="--thread"

# -----------------------------------------------------------
# GLib Resources
# -----------------------------------------------------------

AC_ARG_VAR([GLIB_COMPILE_RESOURCES],[the glib-compile-resources program])
AC_PATH_PROG([GLIB_COMPILE_RESOURCES],[glib-compile-resources],[])
if test -z "$GLIB_COMPILE_RESOURCES"; then
  AC_MSG_ERROR([glib-compile-resources not found])
fi

AC_ARG_VAR([XMLLINT],[the xmllint program])
AC_PATH_PROG([XMLLINT],[xmllint],[])
if test -z "$XMLLINT"; then
  AC_MSG_ERROR([xmllint not found])
fi

# -----------------------------------------------------------
# Optional Dependencies
# -----------------------------------------------------------

# Check for newer BAMF
BAMF_MIN_VERSION=0.4.0
BAMF_PKGS="libbamf3 >= $BAMF_MIN_VERSION"
PKG_CHECK_MODULES(BAMF, $BAMF_PKGS, [enable_bamf_0_4=yes], [enable_bamf_0_4=no])
if test "x$enable_bamf_0_4" = "xyes" ; then
    VALAFLAGS="$VALAFLAGS --define HAVE_BAMF_0_4"
fi
AM_CONDITIONAL([HAVE_BAMF_0_4], [test "x$enable_bamf_0_4" = "xyes"])

# Check for gee-0.8 and use it if available, fallback to gee-1.0 (0.6) by default
AC_ARG_ENABLE([gee-0.8],
              AS_HELP_STRING([--enable-gee-0.8],
                             [Enable use of gee-0.8 instead of gee-1.0]),
              [enable_gee_0_8=$enableval],
              [PKG_CHECK_MODULES(GEE_0_8, gee-0.8, [enable_gee_0_8=yes], [enable_gee_0_8=no])])
if test "x$enable_gee_0_8" = "xyes" ; then
    GEE_DEPEND=gee-0.8
    VALAWEBKITSANDBOX_CORE_PKGS="$VALAWEBKITSANDBOX_CORE_PKGS gee-0.8"
    VALAWEBKITSANDBOX_CORE_VALA_PKGS="$VALAWEBKITSANDBOX_CORE_VALA_PKGS --pkg gee-0.8"
    VALAFLAGS="$VALAFLAGS --define HAVE_GEE_0_8"
else
    GEE_DEPEND=gee-1.0
    VALAWEBKITSANDBOX_CORE_PKGS="$VALAWEBKITSANDBOX_CORE_PKGS gee-1.0"
    VALAWEBKITSANDBOX_CORE_VALA_PKGS="$VALAWEBKITSANDBOX_CORE_VALA_PKGS --pkg gee-1.0"
fi
AM_CONDITIONAL([HAVE_GEE_0_8], [test "x$enable_gee_0_8" = "xyes"])
AC_SUBST(GEE_DEPEND)

# Support dynamic quicklists provided with dbusmenu
DBUSMENU_MIN_VERSION=0.4
DBUSMENU_PKGS="dbusmenu-glib-0.4 >= $DBUSMENU_MIN_VERSION dbusmenu-gtk3-0.4 >= $DBUSMENU_MIN_VERSION"
AC_ARG_ENABLE([dbusmenu],
              AS_HELP_STRING([--enable-dbusmenu],
                             [Enable dynamic quicklist support provided over dbusmenu]),
              [enable_dbusmenu=$enableval],
              [PKG_CHECK_MODULES(DBUSMENU, $DBUSMENU_PKGS, [enable_dbusmenu=yes], [enable_dbusmenu=no])])
if test "x$enable_dbusmenu" = "xyes" ; then
    VALAWEBKITSANDBOX_CORE_OPTIONAL_PKGS="$VALAWEBKITSANDBOX_CORE_OPTIONAL_PKGS $DBUSMENU_PKGS"
    VALAWEBKITSANDBOX_CORE_VALA_PKGS="$VALAWEBKITSANDBOX_CORE_VALA_PKGS --pkg Dbusmenu-0.4 --pkg DbusmenuGtk3-0.4"
    VALAFLAGS="$VALAFLAGS --define HAVE_DBUSMENU"
fi
AM_CONDITIONAL([HAVE_DBUSMENU], [test "x$enable_dbusmenu" = "xyes"])



AC_SUBST(VALAWEBKITSANDBOX_CORE_OPTIONAL_PKGS)
VALAWEBKITSANDBOX_CORE_PKGS="$VALAWEBKITSANDBOX_CORE_PKGS $VALAWEBKITSANDBOX_CORE_OPTIONAL_PKGS"
PKG_CHECK_MODULES(VALAWEBKITSANDBOX_CORE, $VALAWEBKITSANDBOX_CORE_PKGS)


# -----------------------------------------------------------
# Addional configure flags
# -----------------------------------------------------------

# Enable Vala debug-flag by default for non-release builds
AC_ARG_ENABLE([debug],
              AS_HELP_STRING([--disable-debug],[compile without debug code]),
              [enable_debug=$enableval], [m4_if(valawebkitsandbox_released, [1], [enable_debug=no], [enable_debug=yes])])
if test "x$enable_debug" = "xyes" ; then
    VALAFLAGS_CORE="$VALAFLAGS_CORE -g"
fi

# Enable output of benchmarking data
AC_ARG_ENABLE([benchmark],
              AS_HELP_STRING([--enable-benchmark],
                             [Enable output of benchmarking data in logs]),
              [enable_benchmark=$enableval],
              [enable_benchmark=no])
if test "x$enable_benchmark" = "xyes" ; then
    VALAFLAGS="$VALAFLAGS --define BENCHMARK"
fi

VALAWEBKITSANDBOX_CORE_VALAFLAGS="$VALAFLAGS_CORE $VALAFLAGS $VALAWEBKITSANDBOX_CORE_VALA_PKGS"
AC_SUBST(VALAWEBKITSANDBOX_CORE_VALAFLAGS)
VALAWEBKITSANDBOX_DOCS_VALAFLAGS="$VALAFLAGS $VALAWEBKITSANDBOX_CORE_VALA_PKGS"
AC_SUBST(VALAWEBKITSANDBOX_DOCS_VALAFLAGS)


# -----------------------------------------------------------
# Documentation
# -----------------------------------------------------------
VALADOC_MIN_VERSION=0.3.1

AC_ARG_ENABLE([docs],
              AS_HELP_STRING([--enable-docs],[Enable documentation generation]),
              [enable_docs=$enableval], [enable_docs=no])
AM_CONDITIONAL([ENABLE_DOCS], [test "x$enable_docs" = "xyes"])

have_valadoc=no
if test "x$enable_docs" = "xyes"; then
    # make sure the library is new enough and the program exists
    PKG_CHECK_MODULES([VALADOC], [valadoc-1.0 >= $VALADOC_MIN_VERSION])
    AC_PATH_PROG([VALADOC], [valadoc], [:])
    AS_IF([test "$VALADOC" != :], have_valadoc=yes)
fi
AM_CONDITIONAL([HAVE_VALADOC], [test "x$have_valadoc" = "xyes"])

if test "x$enable_docs" = "xyes" -a "x$have_valadoc" != "xyes"; then
    AC_MSG_ERROR([Doc building requested but valadoc not installed.])
fi


# -----------------------------------------------------------
# Test Dependencies
# -----------------------------------------------------------
AC_ARG_ENABLE([headless-tests],
              AS_HELP_STRING([--enable-headless-tests], [Enable running tests in headless mode]),
              [enable_headless_tests=$enableval], [enable_headless_tests=no])
if test "x$enable_headless_tests" != "xno"; then
    AC_PATH_PROG([XVFB_RUN], [xvfb-run], [:])
    AC_PATH_PROG([DBUS_LAUNCH], [dbus-launch], [:])
    AS_IF([test "$XVFB_RUN" != :], [have_xvfb_run=yes], [have_xvfb_run=no])
    AS_IF([test "$DBUS_LAUNCH" != :], [have_dbus_launch=yes], [have_dbus_launch=no])
fi
AM_CONDITIONAL(HAVE_HEADLESS_TESTS, [test "x$have_xvfb_run" == "xyes" -a "x$have_dbus_launch" == "xyes"])

if test "x$enable_headless_tests" = "xyes"; then
  if test "x$have_xvfb_run" != "xyes" -o "x$have_dbus_launch" != "xyes"; then
    AC_MSG_ERROR([Headless Tests requested but xvfb-run/dbus-launch not installed.])
  fi
fi


# -----------------------------------------------------------
# Gettext
# -----------------------------------------------------------
GETTEXT_PACKAGE=AC_PACKAGE_NAME
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, ["$GETTEXT_PACKAGE"], [Define the gettext package to be used])
IT_PROG_INTLTOOL([0.35.0])


# -----------------------------------------------------------
# Final output
# -----------------------------------------------------------
AC_CONFIG_FILES([
Makefile
data/Makefile
data/apport/Makefile
data/icons/Makefile
data/themes/Makefile
lib/Makefile
lib/valawebkitsandbox.deps
lib/valawebkitsandbox.pc
man/Makefile
src/Makefile
docs/Makefile
po/Makefile.in
tests/Makefile
vapi/Makefile
])

AC_OUTPUT

echo "
${PACKAGE} ${VERSION}

    Prefix......................:  ${prefix}
    Vala Compiler...............:  ${VALAC}
    Vala Flags..................:  ${VALAFLAGS}
    C Compiler Flags............:  ${CFLAGS}

    Use gee-0.8.................:  ${enable_gee_0_8}
    Dbusmenu support............:  ${enable_dbusmenu}

    Headless Tests..............:  ${enable_headless_tests}
    Documentation...............:  ${have_valadoc}
"
