# SPDX-License-Identifier: GPL-2.0

KVER	?= $(shell uname -r)
KDIR	?= /lib/modules/$(KVER)/build/
DEPMOD	= /sbin/depmod -a

obj-m	:= streebog_generic.o

all: streebog_generic.ko

streebog_generic.ko: streebog_generic.c streebog.h
	make -C $(KDIR) M=$(CURDIR) modules CONFIG_DEBUG_INFO=y

install: install-mod

install-mod: streebog_generic.ko
	make -C $(KDIR) M=$(CURDIR) modules_install INSTALL_MOD_PATH=$(DESTDIR)

uninstall:
	-rm -f $(DESTDIR)/lib/modules/$(KVER)/extra/streebog_generic.ko

clean:
	-make -C $(KDIR) M=$(CURDIR) clean
	-rm -f *.so *.o modules.order

load: streebog_generic.ko
	sysctl kernel.printk=8
	insmod ./streebog_generic.ko

unload:
	-rmmod streebog_generic.ko


.PHONY: clean all install install-mod uninstall load unload test
