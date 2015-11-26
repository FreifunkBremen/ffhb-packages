include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-autoupdater-switcher
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/gluon-autoupdater-switcher
  SECTION:=ffhb
  CATEGORY:=Gluon
  TITLE:=Switch the autoupdater to another branch
  DEPENDS:=+gluon-autoupdater
endef

define Package/gluon-autoupdater-switcher/description
This package changes the release branch on which the autoupdater looks for new updates.

To change the branch, a section like the following is inserted into the site.conf:
    autoupdater_switcher = {
        date = '20140324',
        branch = 'testing',
    }
The date field is essentially a version: It must be incremented each time this package should change the branch. It then changes the branch and stores the last date (version) it was changed for, so that the end user can still change the branch back to whatever he wants.
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
