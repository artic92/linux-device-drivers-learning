# If KERNELRELEASE is defined, we've been invoked from the
# kernel build system and can use its language.
ifneq ($(KERNELRELEASE),)

	module-objs := hello.o
	obj-m := hello.o

	CFLAGS_hello_world.o := -DDEBUG

# Otherwise we were called firectly from the command line;
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