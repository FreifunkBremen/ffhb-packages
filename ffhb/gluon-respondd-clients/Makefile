include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-respondd-clients
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)
PKG_BUILD_DEPENDS := respondd clients

include $(GLUONDIR)/include/package.mk

define Package/gluon-respondd-clients
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Add clients to respondd
  DEPENDS:=+gluon-core +libgluonutil +gluon-client-bridge +firewall +libiwinfo
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

define Package/gluon-respondd-clients/install
	$(INSTALL_DIR) $(1)/lib/gluon/respondd
	$(CP) $(PKG_BUILD_DIR)/respondd.so $(1)/lib/gluon/respondd/clients.so
endef

$(eval $(call BuildPackage,gluon-respondd-clients))
