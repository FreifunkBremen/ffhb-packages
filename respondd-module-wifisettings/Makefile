include $(TOPDIR)/rules.mk

PKG_NAME:=respondd-module-wifisettings
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)
PKG_BUILD_DEPENDS := respondd

include $(INCLUDE_DIR)/package.mk

define Package/respondd-module-wifisettings
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Add wifisettings to respondd
  DEPENDS:=+respondd +libuci
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/respondd-module-wifisettings/install
	$(INSTALL_DIR) $(1)/lib/gluon/respondd
	$(CP) $(PKG_BUILD_DIR)/respondd.so $(1)/lib/gluon/respondd/wifi-settings.so
endef

$(eval $(call BuildPackage,respondd-module-wifisettings))
