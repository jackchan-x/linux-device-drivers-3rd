#include <linux/module.h>
#include <linux/init.h>

static char *whom = "world";
static int howmany = 1;
module_param(whom, charp, S_IRUGO);
module_param(howmany, int, S_IRUGO);

static int __init hello_init(void)
{
    printk(KERN_INFO "Hello, module!\n");
    printk(KERN_INFO "whom: %s, howmany: %d\n", whom, howmany);

    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Goodbye, module!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jack Chan");
MODULE_DESCRIPTION("just for test");
