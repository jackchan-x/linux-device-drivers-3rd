#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

static int scull_major = 0;
static int scull_minor_first = 0;
static int scull_count = 1;
dev_t scull_dev;
module_param(scull_major, int, 0);

static int __init scull_init(void)
{
    int ret = -1;

    scull_dev = MKDEV(scull_major, scull_minor_first);

    if (scull_major != 0) {
        ret = register_chrdev_region(scull_dev, scull_count, "scull");
    } else {
        ret = alloc_chrdev_region(&scull_dev, scull_minor_first, scull_count, "scull");
        scull_major = MAJOR(scull_dev);
    }

    if (ret < 0) {
        printk(KERN_WARNING "scull: unable to get major %d\n", scull_major);
        return ret;
    }
    
    printk(KERN_INFO "Hello, scull major: %d, minor: %d!\n", MAJOR(scull_dev), MINOR(scull_dev));

    return 0;
}

static void __exit scull_exit(void)
{
    unregister_chrdev_region(scull_dev, scull_count);
    printk(KERN_INFO "Goodbye, scull!\n");
}

module_init(scull_init);
module_exit(scull_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Jack Chan");
