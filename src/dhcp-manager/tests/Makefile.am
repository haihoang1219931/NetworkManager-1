AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_builddir)/include \
	-I${top_srcdir}/libnm-util \
	-I${top_builddir}/libnm-util \
	-I$(top_srcdir)/src/dhcp-manager \
	-I$(top_srcdir)/src \
	-I$(top_srcdir)/src/platform \
	$(GLIB_CFLAGS) \
	-DTESTDIR="\"$(abs_srcdir)\""

noinst_PROGRAMS = test-dhcp-dhclient

####### policy /etc/hosts test #######

test_dhcp_dhclient_SOURCES = \
	test-dhcp-dhclient.c

test_dhcp_dhclient_LDADD = \
	$(top_builddir)/src/libNetworkManager.la

check-local: test-dhcp-dhclient
	$(abs_builddir)/test-dhcp-dhclient

EXTRA_DIST = \
	test-dhclient-duid.leases \
	test-dhclient-commented-duid.leases \
	leases/basic.leases \
	leases/malformed1.leases \
	leases/malformed2.leases \
	leases/malformed3.leases

