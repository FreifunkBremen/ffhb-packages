include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-speedtest
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/gluon-speedtest
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Support for downloading /dev/zero via http for speed testing + /usr/sbin/speedtest
endef

define Package/gluon-speedtest/description
	Support for downloading /dev/zero via http for speed testing + /usr/sbin/speedtest
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/gluon-speedtest/install
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,gluon-speedtest))
