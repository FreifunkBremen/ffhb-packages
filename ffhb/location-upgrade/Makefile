include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-location-upgrade
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/gluon-location-upgrade
  SECTION:=ffhb
  CATEGORY:=Gluon
  TITLE:=Move system.location to gluon-location
  DEPENDS:=+gluon-location
endef

define Package/gluon-location-upgrade/description
	This packages moves the location information to the new config path.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/gluon-location-upgrade/install
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,gluon-location-upgrade))
