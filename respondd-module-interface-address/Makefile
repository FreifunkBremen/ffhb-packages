include $(TOPDIR)/rules.mk

PKG_NAME:=respondd-module-interface-address
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_LICENSE:=BSD-2-Clause

PKG_BUILD_DEPENDS := respondd

include $(INCLUDE_DIR)/package.mk

define Package/respondd-module-interface-address
  SECTION:=net
  CATEGORY:=Network
  TITLE:=Add simple interface address to respondd
  DEPENDS:=+respondd
endef

define Package/respondd-module-interface-address/install
	$(INSTALL_DIR) $(1)/usr/lib/respondd
	$(CP) $(PKG_BUILD_DIR)/respondd.so $(1)/usr/lib/respondd/interface-address.so
endef

$(eval $(call BuildPackage,respondd-module-interface-address))
