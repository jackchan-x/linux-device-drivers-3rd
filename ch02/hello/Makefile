obj-m := hello.o

KERVER := $(shell uname -r)
KERDIR := /usr/lib/modules/$(KERVER)/build
MAKE := make

modules:
	$(MAKE) -C $(KERDIR) M=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.c *.order *.symvers .*.cmd .tmp*
