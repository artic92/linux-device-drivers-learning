/**
 * @file hello.c
 * @author Antonio Riccio <hi@ariccio.me>
 * @brief Template for a generic Linux Kernel's module
 * @version 0.1
 * @date 2024-11-06
 *
 * @copyright (c) 2024
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

static char *whom = "world";
static int howmany = 1;
module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int __init hello_init(void)
{
    for (int i = 0; i < howmany; i++)
    {
        printk(KERN_ALERT "Hello, %s!", whom);
    }
    return 0; /* success */
}

static void __exit hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, %s!", whom);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Antonio Riccio");
MODULE_DESCRIPTION("Hello world kernel module");