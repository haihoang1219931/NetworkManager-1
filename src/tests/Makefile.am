AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_builddir)/include \
	-I$(top_srcdir)/libnm-util \
	-I$(top_builddir)/libnm-util \
	-I$(top_srcdir)/src/platform \
	-I$(top_srcdir)/src/dhcp-manager \
	-I$(top_srcdir)/src \
	-I$(top_builddir)/src \
	-DNM_VERSION_MAX_ALLOWED=NM_VERSION_NEXT_STABLE \
	$(GLIB_CFLAGS) \
	$(DBUS_CFLAGS)

noinst_PROGRAMS = \
	test-dhcp-options \
	test-general \
	test-policy-hosts \
	test-wifi-ap-utils \
	test-ip4-config \
	test-ip6-config \
	test-dcb \
	test-resolvconf-capture

####### DHCP options test #######

test_dhcp_options_SOURCES = \
	test-dhcp-options.c

test_dhcp_options_CPPFLAGS = \
	$(AM_CPPFLAGS) \
	-DDHCLIENT_PATH=\"$(DHCLIENT_PATH)\" \
	-DDHCPCD_PATH=\"$(DHCPCD_PATH)\"

test_dhcp_options_LDADD = \
	$(top_builddir)/src/libNetworkManager.la

####### policy /etc/hosts test #######

test_policy_hosts_SOURCES = \
	test-policy-hosts.c

test_policy_hosts_LDADD = \
	$(top_builddir)/src/libNetworkManager.la

####### wifi ap utils test #######

test_wifi_ap_utils_SOURCES = \
	test-wifi-ap-utils.c

test_wifi_ap_utils_LDADD = \
	$(top_builddir)/src/libNetworkManager.la

####### ip4 config test #######

test_ip4_config_SOURCES = \
	test-ip4-config.c

test_ip4_config_LDADD = \
	$(top_builddir)/src/libNetworkManager.la

####### ip6 config test #######

test_ip6_config_SOURCES = \
	test-ip6-config.c

test_ip6_config_LDADD = \
	$(top_builddir)/src/libNetworkManager.la

####### DCB test #######

test_dcb_SOURCES = \
	test-dcb.c

test_dcb_LDADD = \
	$(top_builddir)/src/libNetworkManager.la

####### resolv.conf capture test #######

test_resolvconf_capture_SOURCES = \
	test-resolvconf-capture.c

test_resolvconf_capture_LDADD = \
	$(top_builddir)/src/libNetworkManager.la

####### general test #######

test_general_SOURCES = \
	test-general.c

test_general_LDADD = \
	$(top_builddir)/src/libNetworkManager.la

####### secret agent interface test #######

EXTRA_DIST = test-secret-agent.py

###########################################

check-local: test-dhcp-options test-policy-hosts test-wifi-ap-utils test-ip4-config test-ip6-config
	$(abs_builddir)/test-dhcp-options
	$(abs_builddir)/test-policy-hosts
	$(abs_builddir)/test-wifi-ap-utils
	$(abs_builddir)/test-ip4-config
	$(abs_builddir)/test-ip6-config
	$(abs_builddir)/test-dcb
	$(abs_builddir)/test-resolvconf-capture
	$(abs_builddir)/test-general

