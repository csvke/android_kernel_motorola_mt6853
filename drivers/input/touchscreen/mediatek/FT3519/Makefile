# Makefile for the focaltech touchscreen drivers.

obj-m   +=  focaltech_core.o
obj-m   +=  focaltech_esdcheck.o
obj-m   +=  focaltech_ex_fun.o
obj-m   +=  focaltech_ex_mode.o
obj-m   +=  focaltech_flash.o
obj-m   +=  focaltech_gesture.o
obj-m   +=  focaltech_i2c.o
obj-m   +=  focaltech_point_report_check.o

obj-m   +=  focaltech_test/focaltech_test.o
obj-m   +=  focaltech_test/focaltech_test_ini.o
obj-m   +=  focaltech_test/supported_ic/focaltech_test_ft5452i.o

obj-m   +=  focaltech_flash/focaltech_upgrade_ft5452i.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
EXTRA_CFLAGS := -I$(KDIR)/include -I$(KDIR)/drivers/input/touchscreen -fno-sanitize=all
KCOV_INSTRUMENT := n

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	# Ensure these files are not deleted
	touch include/firmware/fw_sample.i include/pramboot/FT5452i_Pramboot_v4.1_20210427.i

install:
	find . -name "*.ko" -exec sudo cp {} /lib/modules/$(shell uname -r)/kernel/drivers/input/touchscreen/ \;
	cd /lib/modules/$(shell uname -r)/kernel/drivers/input/touchscreen/ && sudo find . -name "*.ko" -exec xz -f {} \;
	sudo depmod -a || true