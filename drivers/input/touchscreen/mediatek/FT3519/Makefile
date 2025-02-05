# Makefile for the focaltech touchscreen drivers.

# run this to check if the module has been installed:
# ls /lib/modules/$(uname -r)/kernel/drivers/input/touchscreen/ -lah

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

# Define the main module and its components
obj-m += focaltech-ft3519.o

focaltech-ft3519-objs :=	focaltech_core.o \
							focaltech_ex_fun.o \
							focaltech_ex_mode.o \
							focaltech_gesture.o \
                         	focaltech_esdcheck.o \
                         	focaltech_point_report_check.o \
                         	focaltech_test/focaltech_test.o \
                         	focaltech_test/focaltech_test_ini.o \
                         	focaltech_test/supported_ic/focaltech_test_ft5452i.o \
                         	focaltech_flash.o \
                         	focaltech_flash/focaltech_upgrade_ft5452i.o \
                         	focaltech_i2c.o

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

# install:
# 	sudo $(MAKE) -C $(KDIR) M=$(PWD) modules_install
# 	sudo depmod -a

install:
	find . -name "*.ko" -exec sudo cp {} /lib/modules/$(shell uname -r)/kernel/drivers/input/touchscreen/ \;
	cd /lib/modules/$(shell uname -r)/kernel/drivers/input/touchscreen/ && sudo find . -name "*.ko" -exec xz -f {} \;
	sudo depmod -a

reinstall:
# Unload the module if it is currently loaded
	-sudo modprobe -r focaltech-ft3519
# Remove the module file from the kernel module folder
	sudo find /lib/modules/$(shell uname -r)/kernel/drivers/input/touchscreen/ -name "focaltech-ft3519.ko.xz" -exec rm -f {} \;
# Copy the new module file to the kernel module folder
	find . -name "*.ko" -exec sudo cp {} /lib/modules/$(shell uname -r)/kernel/drivers/input/touchscreen/ \;
# Compress the module file
	cd /lib/modules/$(shell uname -r)/kernel/drivers/input/touchscreen/ && sudo find . -name "*.ko" -exec xz -f {} \;
# Update module dependencies
	sudo depmod -a
# Load the new module
	sudo modprobe focaltech-ft3519

package:
	MODULE_DIR="/lib/modules/$(shell uname -r)/kernel/drivers/input/touchscreen/"
	TAR_FILE="focaltech-ft3519.tar"
	tar -cvf $(TAR_FILE) -C $(MODULE_DIR) .
	xz -z $(TAR_FILE)

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
# Ensure these files are not deleted
	touch include/firmware/fw_sample.i include/pramboot/FT5452i_Pramboot_v4.1_20210427.i