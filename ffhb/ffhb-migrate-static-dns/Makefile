include $(TOPDIR)/rules.mk

PKG_NAME:=ffhb-migrate-static-dns
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/ffhb-migrate-static-dns
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Migrate static DNS server config
  DEPENDS:=+gluon-wan-dnsmasq
endef

define Package/ffhb-migrate-static-dns/description
	Migrate DNS server config
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/ffhb-migrate-static-dns/install
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,ffhb-migrate-static-dns))
