include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-respondd-wifisettings
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)
PKG_BUILD_DEPENDS := respondd

include $(GLUONDIR)/include/package.mk

define Package/gluon-respondd-wifisettings
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Add wifisettings to respondd
  DEPENDS:=+gluon-core +libgluonutil
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/gluon-respondd-wifisettings/install
	$(INSTALL_DIR) $(1)/lib/gluon/respondd
	$(CP) $(PKG_BUILD_DIR)/respondd.so $(1)/lib/gluon/respondd/wifi-settings.so
endef

$(eval $(call BuildPackage,gluon-respondd-wifisettings))
