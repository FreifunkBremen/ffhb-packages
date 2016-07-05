include $(TOPDIR)/rules.mk

PKG_NAME:=ffhb-breminale
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/ffhb-breminale
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Breminale
  DEPENDS:=+respondd +lua-deflate +gluon-neighbour-info +gluon-ebtables +gluon-ebtables-filter-ra-dhcp +gluon-ebtables-filter-multicast +wpad-mini
endef

define Package/ffhb-breminale/description
	Breminale
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/ffhb-breminale/install
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,ffhb-breminale))
