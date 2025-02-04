/*
 *
 * FocalTech TouchScreen driver.
 *
 * Copyright (c) 2012-2020, FocalTech Systems, Ltd., all rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
/*****************************************************************************
*
* File Name: focaltech_core.c
*
* Author: Focaltech Driver Team
* Author: Frankie Yuen <frankie.yuen@me.com>
*
* Created: 2025-02-04
*
* Abstract: Wrapper for Focaltech FT3519 I2C Touchscreen Driver
*
* Version: V1.0
*
*****************************************************************************/

/*****************************************************************************
* Included header files
*****************************************************************************/
#include <linux/module.h>
#include <linux/kernel.h>

/*****************************************************************************
* Include the original source files
*****************************************************************************/

#include "focaltech_core.c"
#include "focaltech_esdcheck.c"
#include "focaltech_ex_fun.c"
#include "focaltech_ex_mode.c"
#include "focaltech_flash.c"
#include "focaltech_gesture.c"
#include "focaltech_i2c.c"
#include "focaltech_point_report_check.c"
#include "focaltech_test/focaltech_test.c"
#include "focaltech_test/focaltech_test_ini.c"
#include "focaltech_test/supported_ic/focaltech_test_ft5452i.c"
#include "focaltech_flash/focaltech_upgrade_ft5452i.c"

// Declare the initialization and cleanup functions
extern int focaltech_core_init(void);
extern void focaltech_core_exit(void);
extern int focaltech_gesture_init(void);
extern void focaltech_gesture_exit(void);

// Module initialization function
static int __init focaltech_ft3519_init(void) {
    int ret;

    // Call initialization functions of individual components
    ret = focaltech_core_init();
    if (ret) {
        printk(KERN_ERR "Failed to initialize focaltech_core\n");
        return ret;
    }

    ret = focaltech_gesture_init();
    if (ret) {
        printk(KERN_ERR "Failed to initialize focaltech_gesture\n");
        focaltech_core_exit();
        return ret;
    }

    // Add other initialization calls as needed

    printk(KERN_INFO "Focaltech FT3519 module initialized\n");
    return 0;
}

// Module cleanup function
static void __exit focaltech_ft3519_exit(void) {
    // Call cleanup functions of individual components
    focaltech_gesture_exit();
    focaltech_core_exit();

    // Add other cleanup calls as needed

    printk(KERN_INFO "Focaltech FT3519 module exited\n");
}

module_init(focaltech_ft3519_init);
module_exit(focaltech_ft3519_exit);

MODULE_AUTHOR("Author: Focaltech Driver Team");
MODULE_AUTHOR("Frankie Yuen <frankie.yuen@me.com>");
MODULE_DESCRIPTION("FocalTech FT3519 I2C Touchscreen Driver");
MODULE_LICENSE("GPL v2");