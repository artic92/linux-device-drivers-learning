/**
 * @file hello_char.c
 * @author Antonio Riccio <hi@ariccio.me>
 * @brief Template character device
 * @version 0.1
 * @date 2025-01-12
 *
 * @copyright (c) 2025
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3 of the License, or any later version. This
 * program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>

#include "main.h"
#include "fops.h"

static struct file_operations hello_char_fops =
{
    .owner   = THIS_MODULE,
    .open    = hello_char_open,
    .release = hello_char_release,
    .read    = hello_char_read,
    .write   = hello_char_write,
};

static struct hello_char_device* hello_char_dev = NULL;

static int __init hello_char_init(void)
{
    int   ret   =  0;
    dev_t devno = {0};

    (void)pr_warn("ENTERING function init\n");

    /* allocate data for storing the device structure */
    hello_char_dev = kmalloc(sizeof(struct hello_char_device), GFP_KERNEL);
    if(!hello_char_dev)
    {
        (void)pr_warn("allocation not successfull\n");
        goto no_dev_struct;
    }

    /* request major and minor numbers dinamically */
    ret = alloc_chrdev_region(&devno, HELLO_CHAR_FIRST_MINOR, HELLO_CHAR_TOTAL_MINORS, MODULE_NAME);
    if(ret < 0)
    {
        (void)pr_warn("error allocating major/minor numbers\n");
        goto no_err_numbers;
    }
    hello_char_dev->major = MAJOR(devno);
    hello_char_dev->minor = MINOR(devno);

    /* initialise the character device with cdev_init() */
    (void)cdev_init(&(hello_char_dev->cdev), &hello_char_fops);

    /* register the character device with cdev_add() */
    ret = cdev_add(&(hello_char_dev->cdev), devno, 1);
    if(ret < 0)
    {
        (void)pr_warn("error adding cdev structure\n");
        goto no_cdev_add;
    }

    (void)pr_warn("EXITING function init\n");

    return 0; /* success */

no_cdev_add:
    (void)unregister_chrdev_region(devno, HELLO_CHAR_TOTAL_MINORS);
no_err_numbers:
    kfree(hello_char_dev);
no_dev_struct:
    return -1; /* error */
}

static void __exit hello_char_exit(void)
{
    dev_t devno = {0};

    (void)pr_warn("ENTERING function exit\n");

    devno = MKDEV(hello_char_dev->major, hello_char_dev->minor);

    /* deregister character device with cdev_del() */
    (void)cdev_del(&(hello_char_dev->cdev));

    /* deregister the character device */
    (void)unregister_chrdev_region(devno, HELLO_CHAR_TOTAL_MINORS);

    /* deallocate all the memory used to allocate device structure */
    kfree(hello_char_dev);

    (void)pr_warn("EXITING function exit\n");
}

module_init(hello_char_init);
module_exit(hello_char_exit);

MODULE_LICENSE("Dual BSD/GPL\n");
MODULE_AUTHOR("Antonio Riccio\n");
MODULE_DESCRIPTION("First character device module\n");