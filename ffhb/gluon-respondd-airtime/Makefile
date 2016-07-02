include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-respondd-airtime
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)
PKG_BUILD_DEPENDS := respondd

include $(GLUONDIR)/include/package.mk

define Package/gluon-respondd-airtime
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Add airtime to respondd
  DEPENDS:=+libnl-tiny +respondd
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/gluon-respondd-airtime/install
	$(INSTALL_DIR) $(1)/lib/gluon/respondd
	$(CP) $(PKG_BUILD_DIR)/respondd.so $(1)/lib/gluon/respondd/airtime.so
endef

$(eval $(call BuildPackage,gluon-respondd-airtime))
