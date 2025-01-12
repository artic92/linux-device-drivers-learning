/**
 * @file fops.C
 * @author Antonio Riccio <hi@ariccio.me>
 * @brief Basic file operations for the hello_char device
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
#include <asm/uaccess.h>
#include <linux/kernel.h>

#include "main.h"
#include "fops.h"

int hello_char_open(struct inode *inodep, struct file *filep)
{
    struct hello_char_device *dev = NULL;

    pr_warn("hello_char_open called");

    dev = container_of(inodep->i_cdev, struct hello_char_device, cdev);
    filep->private_data = (void*)dev;

    return 0;
}

int hello_char_release(struct inode *inodep, struct file *filep)
{
    pr_warn("hello_char_release called");

    return 0;
}

ssize_t hello_char_read(struct file *filep, char __user *data_to_user, size_t count, loff_t  *loffp)
{
    struct hello_char_device *dev = NULL;

    pr_warn("hello_char_read called");

    dev = filep->private_data;

    return 0;
}

ssize_t hello_char_write(struct file *filep, const char __user *data_from_user, size_t count, loff_t *loffp)
{
    struct hello_char_device *dev = NULL;

    pr_warn("hello_char_write called");

    dev = filep->private_data;

    return count;
}