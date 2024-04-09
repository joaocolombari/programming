if(CONFIG_CUSTOM_ADXL345_DRIVER)
  # Add custom_adxl345_driver.h to the set of global include paths.
  zephyr_include_directories(.)

  zephyr_library()
  zephyr_library_sources(
    custom_adxl345_driver.c
    )
endif()