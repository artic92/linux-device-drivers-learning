# If KERNELRELEASE is defined, we've been invoked from the
# kernel build system and can use its language.
ifneq ($(KERNELRELEASE),)

	hello_char-objs := main.o fops.o
	obj-m := hello_char.o

	CFLAGS_hello_char.o := -DDEBUG

# Otherwise we were called directly from the command line;
# invoke the kernel build system of the running kernel
#
# NOTE: kernel version of the build system and running kernel
# 		must be the same.
else

	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

.PHONY: modules
modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

.PHONY: clean
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

endif