include $(TOPDIR)/rules.mk

PKG_NAME:=reghack
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/reghack
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Regulatory domain hack
  DEPENDS:=+kmod-ath +kmod-cfg80211 +base-files
endef

define Package/reghack/description
	Regulatory domain hack
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/reghack/install
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,reghack))
