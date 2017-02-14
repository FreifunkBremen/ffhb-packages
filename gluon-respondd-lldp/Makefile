include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-respondd-lldp
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)
PKG_BUILD_DEPENDS := respondd lldpd

include $(INCLUDE_DIR)/package.mk

define Package/gluon-respondd-lldp
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Add airtime to respondd
  DEPENDS:=+respondd +lldpd
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Configure
endef

define Build/Compile
	CFLAGS="$(TARGET_CFLAGS)" CPPFLAGS="$(TARGET_CPPFLAGS)" $(MAKE) -C $(PKG_BUILD_DIR) $(TARGET_CONFIGURE_OPTS)
endef


define Package/gluon-respondd-lldp/install
	$(INSTALL_DIR) $(1)/lib/gluon/respondd
	$(CP) $(PKG_BUILD_DIR)/respondd.so $(1)/lib/gluon/respondd/lldp.so
endef

$(eval $(call BuildPackage,gluon-respondd-lldp))
