include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-wan-dnsmasq-static
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/gluon-wan-dnsmasq-static
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Support for a secondary DNS server using the WAN interface with static master DNS server config
  DEPENDS:=+gluon-wan-dnsmasq
endef

define Package/gluon-wan-dnsmasq-static/description
	Gluon community wifi mesh firmware framework: Support for a secondary DNS server using the WAN interface
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/gluon-wan-dnsmasq-static/install
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,gluon-wan-dnsmasq-static))
