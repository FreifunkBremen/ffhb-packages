ifeq ($(origin CC),default)
CC             = gcc
endif

# standard compliance
CFLAGS         += -std=c99

# warnings
CFLAGS         += -Wall -Wextra -Wformat=2 -Wshadow -Wpointer-arith -Wcast-qual
CFLAGS         += -Wmissing-prototypes -pedantic

LDFLAGS = -L${GLUON_DIR}/build/ar71xx-generic/openwrt/staging_dir/target-mips_34kc_uClibc-0.9.33.2_gluon-ar71xx-generic/usr/lib \
					-L${GLUON_DIR}/build/ar71xx-generic/openwrt/staging_dir/target-mips_34kc_uClibc-0.9.33.2_gluon-ar71xx-generic/lib \
					-L${GLUON_DIR}/build/ar71xx-generic/openwrt/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/usr/lib \
					-L${GLUON_DIR}/build/ar71xx-generic/openwrt/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/lib \
					-L${GLUON_DIR}/build/ar71xx-generic/openwrt/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/lib \
					-L${GLUON_DIR}/openwrt/staging_dir/target-mips_34kc_uClibc-0.9.33.2_gluon-ar71xx-generic/usr/lib \
					-I${GLUON_DIR}/openwrt/staging_dir/target-mips_34kc_uClibc-0.9.33.2_gluon-ar71xx-generic/usr/include \
					-I${GLUON_DIR}/openwrt/staging_dir/target-mips_34kc_uClibc-0.9.33.2_gluon-ar71xx-generic/usr/include/libnl-tiny

all: respondd.so

# sudo apt install libnl-3-dev
demo:	demo.c airtime.c airtime.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -fPIC -D_GNU_SOURCE -lnl-tiny -o $@ airtime.c demo.c $(LDLIBS)

respondd.so: respondd.c airtime.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -shared -fPIC -D_GNU_SOURCE -o $@ respondd.c airtime.c $(LDLIBS)

clean:
	rm -rf *.so demo
