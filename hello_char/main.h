/**
 * @file hello_char.h
 * @author Antonio Riccio <hi@ariccio.me>
 * @brief Definitions for the hello_char device
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
#ifndef HELLO_CHAR_H
#define HELLO_CHAR_H

#include <linux/cdev.h>

#define MODULE_NAME             "hello_char"
#define HELLO_CHAR_FIRST_MINOR  0U
#define HELLO_CHAR_TOTAL_MINORS 1U

struct hello_char_device
{
    int         major;
    int         minor;
    struct cdev cdev;
};

#endif /* HELLO_CHAR_H */