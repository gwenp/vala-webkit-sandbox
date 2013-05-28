include $(top_srcdir)/Makefile.common

AM_CFLAGS = \
	-DWNCK_I_KNOW_THIS_IS_UNSTABLE \
	$(VALAWEBKITSANDBOX_CORE_CFLAGS) \
	-w \
	$(NULL)

AM_LDFLAGS = \
	$(LIBM) \
	$(NULL)

AM_VALAFLAGS = \
	$(VALAWEBKITSANDBOX_CORE_VALAFLAGS) \
	--vapidir $(top_srcdir)/vapi \
	$(top_srcdir)/vapi/compat.vapi \
	--basedir $(srcdir) \
	--directory $(builddir) \
	-C \
	$(NULL)

BUILT_SOURCES = \
	libvalawebkitsandbox_internal_la_vala.stamp \
	libvalawebkitsandbox_la_vala.stamp \
	valawebkitsandbox.h \
	valawebkitsandbox-resources.c \
	$(NULL)

libvalawebkitsandboxincludedir = $(includedir)/valawebkitsandbox
nodist_libvalawebkitsandboxinclude_HEADERS = valawebkitsandbox.h

vapidir = $(datadir)/vala/vapi
nodist_vapi_DATA = \
	valawebkitsandbox.vapi \
	valawebkitsandbox.deps \
	$(NULL)

pkgconfigdir = $(libdir)/pkgconfig
nodist_pkgconfig_DATA = valawebkitsandbox.pc


lib_LTLIBRARIES = libvalawebkitsandbox.la

libvalawebkitsandboxdir = $(libdir)

libvalawebkitsandbox_la_LDFLAGS = \
	$(AM_LDLAGS) \
	-no-undefined \
	-version-info "$(LT_CURRENT)":"$(LT_REVISION)":"$(LT_AGE)" \
	-export-dynamic \
	-export-symbols-regex '^valawebkitsandbox_.*' \
	$(NULL)

libvalawebkitsandbox_la_VALAFLAGS = \
	$(builddir)/valawebkitsandbox-internal.vapi \
	$(NULL)

libvalawebkitsandbox_la_LIBADD = \
	$(VALAWEBKITSANDBOX_CORE_LIBS) \
	$(builddir)/libvalawebkitsandbox-internal.la \
	$(NULL)

libvalawebkitsandbox_la_VALASOURCES = \
	Factories/AbstractMain.vala \
	Factories/Factory.vala \
	DockController.vala \
	System/Paths.vala \
	System/Logger.vala \
	Widgets/DockWindow.vala \
	Widgets/CompositedWindow.vala \
	$(NULL)

nodist_libvalawebkitsandbox_la_SOURCES = \
	$(BUILT_SOURCES) \
	$(libvalawebkitsandbox_la_VALASOURCES:.vala=.c) \
	$(NULL)

valawebkitsandbox-resources.c: valawebkitsandbox.gresource.xml Makefile $(shell $(GLIB_COMPILE_RESOURCES) --generate-dependencies --sourcedir $(top_srcdir)/data $(srcdir)/valawebkitsandbox.gresource.xml)
	$(AM_V_GEN) XMLLINT=$(XMLLINT) $(GLIB_COMPILE_RESOURCES) --target $@ --sourcedir $(top_srcdir)/data --generate --c-name valawebkitsandbox $<

valawebkitsandbox.h valawebkitsandbox.vapi: libvalawebkitsandbox_la_vala.stamp

libvalawebkitsandbox_la_vala.stamp build-abi: libvalawebkitsandbox_internal_la_vala.stamp $(libvalawebkitsandbox_la_VALASOURCES) Makefile
	$(AM_V_VALA)$(VALAC) \
		$(AM_VALAFLAGS) $(libvalawebkitsandbox_la_VALAFLAGS) \
		-H valawebkitsandbox.h \
		--library valawebkitsandbox \
		--symbols build-abi \
		--vapi valawebkitsandbox.vapi \
		$(filter %.vala %.c,$^)
	$(AM_V_at)touch $@

symbols: build-abi
	@cat $(builddir)/build-abi | sort > $(srcdir)/libvalawebkitsandbox.symbols


noinst_LTLIBRARIES = libvalawebkitsandbox-internal.la

libvalawebkitsandbox_internal_la_CFLAGS = \
	$(AM_CFLAGS) \
	-fvisibility=internal \
	$(NULL)

libvalawebkitsandbox_internal_la_LDFLAGS = \
	-avoid-version \
	-non_shared \
	-static \
	$(NULL)

libvalawebkitsandbox_internal_la_LIBADD = \
	$(VALAWEBKITSANDBOX_CORE_LIBS) \
	$(NULL)

libvalawebkitsandbox_internal_la_VALASOURCES = \
	$(NULL)

nodist_libvalawebkitsandbox_internal_la_SOURCES = \
	$(libvalawebkitsandbox_internal_la_VALASOURCES:.vala=.c) \
	$(NULL)

valawebkitsandbox-internal.h valawebkitsandbox-internal.vapi: libvalawebkitsandbox_internal_la_vala.stamp

libvalawebkitsandbox_internal_la_vala.stamp: $(libvalawebkitsandbox_internal_la_VALASOURCES) Makefile
	$(AM_V_VALA)$(VALAC) \
		$(AM_VALAFLAGS) \
		-H valawebkitsandbox-internal.h \
		--library valawebkitsandbox-internal \
		--vapi valawebkitsandbox-internal.vapi \
		$(filter %.vala %.c,$^)
	$(AM_V_at)touch $@


TESTS = abicheck.sh

CLEANFILES = \
	$(nodist_libvalawebkitsandbox_la_SOURCES) \
	$(nodist_libvalawebkitsandbox_internal_la_SOURCES) \
	build-abi \
	valawebkitsandbox.deps \
	valawebkitsandbox.pc \
	valawebkitsandbox.vapi \
	valawebkitsandbox.h \
	valawebkitsandbox-internal.vapi \
	valawebkitsandbox-internal.h \
	$(NULL)

EXTRA_DIST = \
	$(libvalawebkitsandbox_la_VALASOURCES) \
	$(libvalawebkitsandbox_internal_la_VALASOURCES) \
	abicheck.sh \
	libvalawebkitsandbox.symbols \
	valawebkitsandbox.deps.in \
	valawebkitsandbox.gresource.xml \
	valawebkitsandbox.pc.in \
	$(NULL)

