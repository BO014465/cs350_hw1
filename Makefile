
obj-m  := hello.o
KDIR    := /lib/modules/$(shell uname -r)/build
PWD     := $(shell pwd)
default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	rm -f *.o *.ko *.mod.* Module.* *.order
