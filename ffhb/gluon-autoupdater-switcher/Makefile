include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-autoupdater-switcher
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/gluon-autoupdater-switcher
  SECTION:=ffhb
  CATEGORY:=Gluon
  TITLE:=Move system.location to gluon-location
  DEPENDS:=+gluon-autoupdater
endef

define Package/gluon-autoupdater-switcher/description
This packages moves the location information to the new config path.
endef

define Build/Prepare
mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/gluon-autoupdater-switcher/install
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,gluon-autoupdater-switcher))
