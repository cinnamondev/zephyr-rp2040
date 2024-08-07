/*
 * Copyright (c) 2018 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <lvgl_input_device.h>
#include <lv_demos.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(app, LOG_LEVEL_DBG);


int main(void)
{
	LOG_DBG("test");
	const struct device *display_dev;
	lv_obj_t *hello_world_label;

	display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display_dev)) {
		LOG_ERR("Device not ready, aborting test");
		return 0;
	}
	//	LOG_DBG("test");
	//hello_world_label = lv_label_create(lv_scr_act());
	//lv_label_set_text(hello_world_label, "Hello world!");
	//lv_obj_align(hello_world_label, LV_ALIGN_CENTER, 0, 0);
	lv_demo_music();
	LOG_DBG("test");
	lv_task_handler();
	display_blanking_off(display_dev);
		LOG_DBG("test");

	while (1) {
		k_msleep(lv_task_handler());
	}
}
