include $(top_srcdir)/Makefile.common

valawebkitsandbox_VALAFLAGS = \
	$(VALAWEBKITSANDBOX_CORE_VALAFLAGS) \
	$(top_builddir)/lib/valawebkitsandbox.vapi \
	--vapidir $(top_srcdir)/vapi \
	$(top_srcdir)/vapi/config.vapi \
	-C \
	$(NULL)

valawebkitsandboxdir = $(bindir)

BUILT_SOURCES = valawebkitsandbox_vala.stamp

valawebkitsandbox_PROGRAMS = valawebkitsandbox

valawebkitsandbox_CFLAGS = \
	$(VALAWEBKITSANDBOX_CORE_CFLAGS) \
	-include config.h \
	-I$(top_builddir)/lib \
	$(NULL)

valawebkitsandbox_LDADD = \
	$(VALAWEBKITSANDBOX_CORE_LIBS) \
	$(top_builddir)/lib/libvalawebkitsandbox.la \
	$(NULL)

valawebkitsandbox_VALASOURCES = \
	AppMain.vala \
	$(NULL)

nodist_valawebkitsandbox_SOURCES = \
	valawebkitsandbox_vala.stamp \
	$(valawebkitsandbox_VALASOURCES:.vala=.c) \
	$(NULL)

valawebkitsandbox_vala.stamp: $(valawebkitsandbox_VALASOURCES) Makefile
	$(AM_V_VALA)$(VALAC) \
		$(valawebkitsandbox_VALAFLAGS) \
		$(filter %.vala %.c,$^)
	$(AM_V_at)touch $@

CLEANFILES = \
	$(nodist_valawebkitsandbox_SOURCES) \
	$(NULL)

EXTRA_DIST = \
	$(valawebkitsandbox_VALASOURCES) \
	$(NULL)

