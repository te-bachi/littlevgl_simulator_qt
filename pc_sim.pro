TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L$$PWD/SDL2/lib/ -lmingw32 -lSDL2main -lSDL2

INCLUDEPATH += $$PWD/SDL2
DEPENDPATH += $$PWD/SDL2

### HEADERS_LV ################################################################
HEADERS_LV = \
    lvgl/lvgl.h \
    lvgl/src/lv_conf_checker.h \
    lvgl/src/lv_core/lv_debug.h \
    lvgl/src/lv_core/lv_disp.h \
    lvgl/src/lv_core/lv_group.h \
    lvgl/src/lv_core/lv_indev.h \
    lvgl/src/lv_core/lv_obj.h \
    lvgl/src/lv_core/lv_refr.h \
    lvgl/src/lv_core/lv_style.h \
    lvgl/src/lv_draw/lv_draw.h \
    lvgl/src/lv_draw/lv_draw_arc.h \
    lvgl/src/lv_draw/lv_draw_basic.h \
    lvgl/src/lv_draw/lv_draw_img.h \
    lvgl/src/lv_draw/lv_draw_label.h \
    lvgl/src/lv_draw/lv_draw_line.h \
    lvgl/src/lv_draw/lv_draw_rect.h \
    lvgl/src/lv_draw/lv_draw_triangle.h \
    lvgl/src/lv_draw/lv_img_cache.h \
    lvgl/src/lv_draw/lv_img_decoder.h \
    lvgl/src/lv_font/lv_font.h \
    lvgl/src/lv_font/lv_font_fmt_txt.h \
    lvgl/src/lv_font/lv_symbol_def.h \
    lvgl/src/lv_hal/lv_hal.h \
    lvgl/src/lv_hal/lv_hal_disp.h \
    lvgl/src/lv_hal/lv_hal_indev.h \
    lvgl/src/lv_hal/lv_hal_tick.h \
    lvgl/src/lv_misc/lv_anim.h \
    lvgl/src/lv_misc/lv_area.h \
    lvgl/src/lv_misc/lv_async.h \
    lvgl/src/lv_misc/lv_bidi.h \
    lvgl/src/lv_misc/lv_circ.h \
    lvgl/src/lv_misc/lv_color.h \
    lvgl/src/lv_misc/lv_fs.h \
    lvgl/src/lv_misc/lv_gc.h \
    lvgl/src/lv_misc/lv_ll.h \
    lvgl/src/lv_misc/lv_log.h \
    lvgl/src/lv_misc/lv_math.h \
    lvgl/src/lv_misc/lv_mem.h \
    lvgl/src/lv_misc/lv_printf.h \
    lvgl/src/lv_misc/lv_task.h \
    lvgl/src/lv_misc/lv_templ.h \
    lvgl/src/lv_misc/lv_txt.h \
    lvgl/src/lv_misc/lv_types.h \
    lvgl/src/lv_misc/lv_utils.h \
    lvgl/src/lv_objx/lv_arc.h \
    lvgl/src/lv_objx/lv_bar.h \
    lvgl/src/lv_objx/lv_btn.h \
    lvgl/src/lv_objx/lv_btnm.h \
    lvgl/src/lv_objx/lv_calendar.h \
    lvgl/src/lv_objx/lv_canvas.h \
    lvgl/src/lv_objx/lv_cb.h \
    lvgl/src/lv_objx/lv_chart.h \
    lvgl/src/lv_objx/lv_cont.h \
    lvgl/src/lv_objx/lv_cpicker.h \
    lvgl/src/lv_objx/lv_ddlist.h \
    lvgl/src/lv_objx/lv_gauge.h \
    lvgl/src/lv_objx/lv_img.h \
    lvgl/src/lv_objx/lv_imgbtn.h \
    lvgl/src/lv_objx/lv_kb.h \
    lvgl/src/lv_objx/lv_label.h \
    lvgl/src/lv_objx/lv_led.h \
    lvgl/src/lv_objx/lv_line.h \
    lvgl/src/lv_objx/lv_list.h \
    lvgl/src/lv_objx/lv_lmeter.h \
    lvgl/src/lv_objx/lv_mbox.h \
    lvgl/src/lv_objx/lv_objx_templ.h \
    lvgl/src/lv_objx/lv_page.h \
    lvgl/src/lv_objx/lv_preload.h \
    lvgl/src/lv_objx/lv_roller.h \
    lvgl/src/lv_objx/lv_slider.h \
    lvgl/src/lv_objx/lv_spinbox.h \
    lvgl/src/lv_objx/lv_sw.h \
    lvgl/src/lv_objx/lv_ta.h \
    lvgl/src/lv_objx/lv_table.h \
    lvgl/src/lv_objx/lv_tabview.h \
    lvgl/src/lv_objx/lv_tileview.h \
    lvgl/src/lv_objx/lv_win.h \
    lvgl/src/lv_themes/lv_theme.h \
    lvgl/src/lv_themes/lv_theme_alien.h \
    lvgl/src/lv_themes/lv_theme_default.h \
    lvgl/src/lv_themes/lv_theme_material.h \
    lvgl/src/lv_themes/lv_theme_mono.h \
    lvgl/src/lv_themes/lv_theme_nemo.h \
    lvgl/src/lv_themes/lv_theme_night.h \
    lvgl/src/lv_themes/lv_theme_templ.h \
    lvgl/src/lv_themes/lv_theme_zen.h \
    lvgl/src/lv_version.h

### HEADERS_LV_DRIVERS ########################################################
HEADERS_LV_DRIVERS = \
    lv_drivers/display/fbdev.h \
    lv_drivers/display/monitor.h \
    lv_drivers/display/R61581.h \
    lv_drivers/display/SHARP_MIP.h \
    lv_drivers/display/SSD1963.h \
    lv_drivers/display/ST7565.h \
    lv_drivers/display/UC1610.h \
    lv_drivers/indev/AD_touch.h \
    lv_drivers/indev/evdev.h \
    lv_drivers/indev/FT5406EE8.h \
    lv_drivers/indev/keyboard.h \
    lv_drivers/indev/libinput.h \
    lv_drivers/indev/mouse.h \
    lv_drivers/indev/mousewheel.h \
    lv_drivers/indev/XPT2046.h \
    lv_drivers/lv_drv_conf_templ.h \
    lv_drivers/win_drv.h

### HEADERS_LV_EXAMPLES #######################################################
HEADERS_LV_EXAMPLES = \
    lv_examples/lv_apps/benchmark/benchmark.h \
    lv_examples/lv_apps/demo/demo.h \
    lv_examples/lv_apps/sysmon/sysmon.h \
    lv_examples/lv_apps/terminal/terminal.h \
    lv_examples/lv_apps/tpcal/tpcal.h \
    lv_examples/lv_examples.h \
    lv_examples/lv_tests/lv_test.h \
    lv_examples/lv_tests/lv_test_group/lv_test_group.h \
    lv_examples/lv_tests/lv_test_misc/lv_test_task.h \
    lv_examples/lv_tests/lv_test_obj/lv_test_obj.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_arc/lv_test_arc.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_bar/lv_test_bar.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_btn/lv_test_btn.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_btnm/lv_test_btnm.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_canvas/lv_test_canvas.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_cb/lv_test_cb.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_chart/lv_test_chart.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_cont/lv_test_cont.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_cpicker/lv_test_cpicker.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_ddlist/lv_test_ddlist.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_gauge/lv_test_gauge.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_img/lv_test_img.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_imgbtn/lv_test_imgbtn.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_kb/lv_test_kb.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_label/lv_test_label.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_led/lv_test_led.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_line/lv_test_line.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_list/lv_test_list.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_lmeter/lv_test_lmeter.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_mbox/lv_test_mbox.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_page/lv_test_page.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_preload/lv_test_preload.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_roller/lv_test_roller.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_slider/lv_test_slider.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_sw/lv_test_sw.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_ta/lv_test_ta.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_table/lv_test_table.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_tabview/lv_test_tabview.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_tileview/lv_test_tileview.h \
    lv_examples/lv_tests/lv_test_objx/lv_test_win/lv_test_win.h \
    lv_examples/lv_tests/lv_test_theme/lv_test_theme_1.h \
    lv_examples/lv_tests/lv_test_theme/lv_test_theme_2.h \
    lv_examples/lv_tutorial/10_keyboard/lv_tutorial_keyboard.h \
    lv_examples/lv_tutorial/1_hello_world/lv_tutorial_hello_world.h \
    lv_examples/lv_tutorial/2_objects/lv_tutorial_objects.h \
    lv_examples/lv_tutorial/3_styles/lv_tutorial_styles.h \
    lv_examples/lv_tutorial/4_themes/lv_tutorial_themes.h \
    lv_examples/lv_tutorial/5_antialiasing/lv_tutorial_antialiasing.h \
    lv_examples/lv_tutorial/6_images/lv_tutorial_images.h \
    lv_examples/lv_tutorial/7_fonts/lv_tutorial_fonts.h \
    lv_examples/lv_tutorial/9_responsive/lv_tutorial_responsive.h

### SOURCES_LV ################################################################
SOURCES_LV = \
    lvgl/src/lv_core/lv_debug.c \
    lvgl/src/lv_core/lv_disp.c \
    lvgl/src/lv_core/lv_group.c \
    lvgl/src/lv_core/lv_indev.c \
    lvgl/src/lv_core/lv_obj.c \
    lvgl/src/lv_core/lv_refr.c \
    lvgl/src/lv_core/lv_style.c \
    lvgl/src/lv_draw/lv_draw.c \
    lvgl/src/lv_draw/lv_draw_arc.c \
    lvgl/src/lv_draw/lv_draw_basic.c \
    lvgl/src/lv_draw/lv_draw_img.c \
    lvgl/src/lv_draw/lv_draw_label.c \
    lvgl/src/lv_draw/lv_draw_line.c \
    lvgl/src/lv_draw/lv_draw_rect.c \
    lvgl/src/lv_draw/lv_draw_triangle.c \
    lvgl/src/lv_draw/lv_img_cache.c \
    lvgl/src/lv_draw/lv_img_decoder.c \
    lvgl/src/lv_font/lv_font.c \
    lvgl/src/lv_font/lv_font_fmt_txt.c \
    lvgl/src/lv_font/lv_font_roboto_12.c \
    lvgl/src/lv_font/lv_font_roboto_12_subpx.c \
    lvgl/src/lv_font/lv_font_roboto_16.c \
    lvgl/src/lv_font/lv_font_roboto_22.c \
    lvgl/src/lv_font/lv_font_roboto_28.c \
    lvgl/src/lv_font/lv_font_roboto_28_compressed.c \
    lvgl/src/lv_font/lv_font_unscii_8.c \
    lvgl/src/lv_hal/lv_hal_disp.c \
    lvgl/src/lv_hal/lv_hal_indev.c \
    lvgl/src/lv_hal/lv_hal_tick.c \
    lvgl/src/lv_misc/lv_anim.c \
    lvgl/src/lv_misc/lv_area.c \
    lvgl/src/lv_misc/lv_async.c \
    lvgl/src/lv_misc/lv_bidi.c \
    lvgl/src/lv_misc/lv_circ.c \
    lvgl/src/lv_misc/lv_color.c \
    lvgl/src/lv_misc/lv_fs.c \
    lvgl/src/lv_misc/lv_gc.c \
    lvgl/src/lv_misc/lv_ll.c \
    lvgl/src/lv_misc/lv_log.c \
    lvgl/src/lv_misc/lv_math.c \
    lvgl/src/lv_misc/lv_mem.c \
    lvgl/src/lv_misc/lv_printf.c \
    lvgl/src/lv_misc/lv_task.c \
    lvgl/src/lv_misc/lv_templ.c \
    lvgl/src/lv_misc/lv_txt.c \
    lvgl/src/lv_misc/lv_utils.c \
    lvgl/src/lv_objx/lv_arc.c \
    lvgl/src/lv_objx/lv_bar.c \
    lvgl/src/lv_objx/lv_btn.c \
    lvgl/src/lv_objx/lv_btnm.c \
    lvgl/src/lv_objx/lv_calendar.c \
    lvgl/src/lv_objx/lv_canvas.c \
    lvgl/src/lv_objx/lv_cb.c \
    lvgl/src/lv_objx/lv_chart.c \
    lvgl/src/lv_objx/lv_cont.c \
    lvgl/src/lv_objx/lv_cpicker.c \
    lvgl/src/lv_objx/lv_ddlist.c \
    lvgl/src/lv_objx/lv_gauge.c \
    lvgl/src/lv_objx/lv_img.c \
    lvgl/src/lv_objx/lv_imgbtn.c \
    lvgl/src/lv_objx/lv_kb.c \
    lvgl/src/lv_objx/lv_label.c \
    lvgl/src/lv_objx/lv_led.c \
    lvgl/src/lv_objx/lv_line.c \
    lvgl/src/lv_objx/lv_list.c \
    lvgl/src/lv_objx/lv_lmeter.c \
    lvgl/src/lv_objx/lv_mbox.c \
    lvgl/src/lv_objx/lv_objx_templ.c \
    lvgl/src/lv_objx/lv_page.c \
    lvgl/src/lv_objx/lv_preload.c \
    lvgl/src/lv_objx/lv_roller.c \
    lvgl/src/lv_objx/lv_slider.c \
    lvgl/src/lv_objx/lv_spinbox.c \
    lvgl/src/lv_objx/lv_sw.c \
    lvgl/src/lv_objx/lv_ta.c \
    lvgl/src/lv_objx/lv_table.c \
    lvgl/src/lv_objx/lv_tabview.c \
    lvgl/src/lv_objx/lv_tileview.c \
    lvgl/src/lv_objx/lv_win.c \
    lvgl/src/lv_themes/lv_theme.c \
    lvgl/src/lv_themes/lv_theme_alien.c \
    lvgl/src/lv_themes/lv_theme_default.c \
    lvgl/src/lv_themes/lv_theme_material.c \
    lvgl/src/lv_themes/lv_theme_mono.c \
    lvgl/src/lv_themes/lv_theme_nemo.c \
    lvgl/src/lv_themes/lv_theme_night.c \
    lvgl/src/lv_themes/lv_theme_templ.c \
    lvgl/src/lv_themes/lv_theme_zen.c

### SOURCES_LV_DRIVERS ########################################################
SOURCES_LV_DRIVERS = \
    lv_drivers/display/fbdev.c \
    lv_drivers/display/monitor.c \
    lv_drivers/display/R61581.c \
    lv_drivers/display/SHARP_MIP.c \
    lv_drivers/display/SSD1963.c \
    lv_drivers/display/ST7565.c \
    lv_drivers/display/UC1610.c \
    lv_drivers/indev/AD_touch.c \
    lv_drivers/indev/evdev.c \
    lv_drivers/indev/FT5406EE8.c \
    lv_drivers/indev/keyboard.c \
    lv_drivers/indev/libinput.c \
    lv_drivers/indev/mouse.c \
    lv_drivers/indev/mousewheel.c \
    lv_drivers/indev/XPT2046.c \
    lv_drivers/win_drv.c

### SOURCES_LV_EXAMPLES #######################################################
SOURCES_LV_EXAMPLES = \
    lv_examples/lv_apps/benchmark/benchmark.c \
    lv_examples/lv_apps/benchmark/benchmark_bg.c \
    lv_examples/lv_apps/demo/demo.c \
    lv_examples/lv_apps/demo/img_bubble_pattern.c \
    lv_examples/lv_apps/sysmon/sysmon.c \
    lv_examples/lv_apps/terminal/terminal.c \
    lv_examples/lv_apps/tpcal/tpcal.c \
    lv_examples/lv_tests/lv_test_group/lv_test_group.c \
    lv_examples/lv_tests/lv_test_misc/lv_test_task.c \
    lv_examples/lv_tests/lv_test_obj/lv_test_obj.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_arc/lv_test_arc.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_bar/lv_test_bar.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_btn/lv_test_btn.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_btnm/lv_test_btnm.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_canvas/lv_test_canvas.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_cb/lv_test_cb.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_chart/lv_test_chart.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_cont/lv_test_cont.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_cpicker/lv_test_cpicker.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_ddlist/lv_test_ddlist.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_gauge/lv_test_gauge.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_img/img_flower_icon.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_img/lv_test_img.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_imgbtn/imgbtn_img_1.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_imgbtn/imgbtn_img_2.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_imgbtn/imgbtn_img_3.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_imgbtn/imgbtn_img_4.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_imgbtn/lv_test_imgbtn.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_kb/lv_test_kb.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_label/lv_test_label.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_led/lv_test_led.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_line/lv_test_line.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_list/lv_test_list.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_lmeter/lv_test_lmeter.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_mbox/lv_test_mbox.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_page/lv_test_page.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_preload/lv_test_preload.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_roller/lv_test_roller.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_slider/lv_test_slider.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_sw/lv_test_sw.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_ta/lv_test_ta.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_table/lv_test_table.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_tabview/lv_test_tabview.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_tileview/lv_test_tileview.c \
    lv_examples/lv_tests/lv_test_objx/lv_test_win/lv_test_win.c \
    lv_examples/lv_tests/lv_test_theme/lv_test_theme_1.c \
    lv_examples/lv_tests/lv_test_theme/lv_test_theme_2.c \
    lv_examples/lv_tutorial/10_keyboard/lv_tutorial_keyboard.c \
    lv_examples/lv_tutorial/1_hello_world/lv_tutorial_hello_world.c \
    lv_examples/lv_tutorial/2_objects/lv_tutorial_objects.c \
    lv_examples/lv_tutorial/3_styles/lv_tutorial_styles.c \
    lv_examples/lv_tutorial/4_themes/lv_tutorial_themes.c \
    lv_examples/lv_tutorial/5_antialiasing/apple_icon_alpha.c \
    lv_examples/lv_tutorial/5_antialiasing/apple_icon_chroma.c \
    lv_examples/lv_tutorial/5_antialiasing/lv_tutorial_antialiasing.c \
    lv_examples/lv_tutorial/6_images/flower_icon_alpha.c \
    lv_examples/lv_tutorial/6_images/lv_tutorial_images.c \
    lv_examples/lv_tutorial/6_images/red_flower.c \
    lv_examples/lv_tutorial/6_images/red_rose_16.c \
    lv_examples/lv_tutorial/7_fonts/arial_20.c \
    lv_examples/lv_tutorial/7_fonts/lv_tutorial_fonts.c \
    lv_examples/lv_tutorial/9_responsive/lv_tutorial_responsive.c

HEADERS += \
    $${HEADERS_LV} \
    $${HEADERS_LV_DRIVERS} \
    $${HEADERS_LV_EXAMPLES} \
    lv_conf.h \
    lv_drv_conf.h \
    lv_ex_conf.h

SOURCES += \
    $${SOURCES_LV} \
    $${SOURCES_LV_DRIVERS} \
    $${SOURCES_LV_EXAMPLES} \
    main.c \
    mouse_cursor_icon.c
