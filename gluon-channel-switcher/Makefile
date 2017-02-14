include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-channel-switcher
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/gluon-channel-switcher
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Switch channel after specified deadline or when nearby nodes already switched
  DEPENDS:=+micrond +libiwinfo-lua
endef

define Package/gluon-channel-switcher/description
	Gluon community wifi mesh firmware framework: channel switcher module
endef

define Build/Prepare
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/gluon-channel-switcher/install
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,gluon-channel-switcher))
