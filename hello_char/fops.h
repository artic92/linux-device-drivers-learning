/**
 * @file fops.h
 * @author Antonio Riccio <hi@ariccio.me>
 * @brief Definitions for the hello_char file operations
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
#ifndef FOPS_H
#define FOPS_H

#include <linux/fs.h>

int     hello_char_open(struct inode *inodep, struct file *filep);
int     hello_char_release(struct inode *inodep, struct file *filep);
ssize_t hello_char_read(struct file *filep, char __user *data_to_user, size_t count, loff_t *loffp);
ssize_t hello_char_write(struct file *filep, const char __user *data_from_user, size_t count, loff_t *loffp);

#endif /* FOPS_H */