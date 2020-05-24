#include <linux/module.h>
#include <linux/init.h>

static int __init scull_init(void)
{
    printk(KERN_INFO "Hello, scull!\n");

    return 0;
}

static void __exit scull_exit(void)
{
    printk(KERN_INFO "Goodbye, scull!\n");
}

module_init(scull_init);
module_exit(scull_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Jack Chan");
