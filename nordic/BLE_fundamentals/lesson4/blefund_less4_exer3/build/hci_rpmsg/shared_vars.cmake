add_custom_target(hci_rpmsg_shared_property_target)
add_custom_target(CPUNET_shared_property_target)
set_property(TARGET hci_rpmsg_shared_property_target  PROPERTY KERNEL_HEX_NAME;zephyr.hex)
set_property(TARGET hci_rpmsg_shared_property_target  PROPERTY ZEPHYR_BINARY_DIR;/Users/joaovitor/Documents/VSCode/nordic/BLE_fundamentals/lesson4/blefund_less4_exer3/build/hci_rpmsg/zephyr)
set_property(TARGET hci_rpmsg_shared_property_target  PROPERTY KERNEL_ELF_NAME;zephyr.elf)
set_property(TARGET hci_rpmsg_shared_property_target  PROPERTY BUILD_BYPRODUCTS;/Users/joaovitor/Documents/VSCode/nordic/BLE_fundamentals/lesson4/blefund_less4_exer3/build/hci_rpmsg/zephyr/zephyr.hex;/Users/joaovitor/Documents/VSCode/nordic/BLE_fundamentals/lesson4/blefund_less4_exer3/build/hci_rpmsg/zephyr/zephyr.elf)
set_property(TARGET CPUNET_shared_property_target  PROPERTY PM_DOMAIN_PARTITIONS;/Users/joaovitor/Documents/VSCode/nordic/BLE_fundamentals/lesson4/blefund_less4_exer3/build/hci_rpmsg/partitions_CPUNET.yml)
set_property(TARGET CPUNET_shared_property_target  PROPERTY PM_DOMAIN_REGIONS;/Users/joaovitor/Documents/VSCode/nordic/BLE_fundamentals/lesson4/blefund_less4_exer3/build/hci_rpmsg/regions_CPUNET.yml)
set_property(TARGET CPUNET_shared_property_target  PROPERTY PM_DOMAIN_HEADER_FILES;/Users/joaovitor/Documents/VSCode/nordic/BLE_fundamentals/lesson4/blefund_less4_exer3/build/hci_rpmsg/zephyr/include/generated/pm_config.h)
set_property(TARGET CPUNET_shared_property_target  PROPERTY PM_DOMAIN_IMAGES;CPUNET:hci_rpmsg)
set_property(TARGET CPUNET_shared_property_target  PROPERTY PM_HEX_FILE;/Users/joaovitor/Documents/VSCode/nordic/BLE_fundamentals/lesson4/blefund_less4_exer3/build/hci_rpmsg/zephyr/merged_CPUNET.hex)
set_property(TARGET CPUNET_shared_property_target  PROPERTY PM_DOTCONF_FILES;/Users/joaovitor/Documents/VSCode/nordic/BLE_fundamentals/lesson4/blefund_less4_exer3/build/hci_rpmsg/pm_CPUNET.config)
set_property(TARGET CPUNET_shared_property_target  PROPERTY PM_APP_HEX;/Users/joaovitor/Documents/VSCode/nordic/BLE_fundamentals/lesson4/blefund_less4_exer3/build/hci_rpmsg/zephyr/app.hex)
set_property(TARGET hci_rpmsg_shared_property_target APPEND PROPERTY BUILD_BYPRODUCTS;/Users/joaovitor/Documents/VSCode/nordic/BLE_fundamentals/lesson4/blefund_less4_exer3/build/hci_rpmsg/zephyr/merged_CPUNET.hex)
