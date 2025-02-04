# Makefile for the focaltech touchscreen drivers.

KERNEL_SRC ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

obj-m += focaltech_core.o
obj-m += focaltech_ex_fun.o
obj-m += focaltech_ex_mode.o
obj-m += focaltech_gesture.o
obj-m += focaltech_esdcheck.o
obj-m += focaltech_point_report_check.o
obj-m += focaltech_test/
obj-m += focaltech_flash.o
obj-m += focaltech_flash/
obj-m += focaltech_i2c.o

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) clean