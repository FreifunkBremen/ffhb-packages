include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-channel-survey
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/gluon-channel-survey
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Channel usage survey module
  DEPENDS:=+gluon-cron +luci-lib-json +alfred +iw
endef

define Package/gluon-channel-survey/description
	Gluon community wifi mesh firmware framework: channel usage survey module
endef

define Build/Prepare
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/gluon-channel-survey/install
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,gluon-channel-survey))
