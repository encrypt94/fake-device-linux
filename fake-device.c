#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>

static char *name = "fake-device";

static struct platform_device *pdev;

static int __init fake_device_init(void)
{
  pdev = platform_device_register_simple(name, 0, NULL, 0);
  if (IS_ERR(pdev))
    return PTR_ERR(pdev);  
  printk(KERN_INFO "%s: connected", name);
  
  return 0;
}

static void __exit fake_device_exit(void)
{
  platform_device_unregister(pdev);
  printk(KERN_INFO "%s: disconnected", name);
}

module_param(name, charp, 0644);
MODULE_PARM_DESC(name, "Device name");

module_init(fake_device_init)
module_exit(fake_device_exit)
MODULE_LICENSE("GPL");
