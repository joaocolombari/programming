/* File generated by /opt/nordic/ncs/v2.5.0-rc1/nrf/scripts/partition_manager_output.py, do not modify */
#ifndef PM_CONFIG_H__
#define PM_CONFIG_H__
#define PM__MCUBOOT_OFFSET 0x0
#define PM__MCUBOOT_ADDRESS 0x0
#define PM__MCUBOOT_END_ADDRESS 0x10000
#define PM__MCUBOOT_SIZE 0x10000
#define PM__MCUBOOT_NAME mcuboot
#define PM__MCUBOOT_ID 0
#define PM__mcuboot_ID PM_MCUBOOT_ID
#define PM__mcuboot_IS_ENABLED 1
#define PM_0_LABEL _MCUBOOT
#define PM__MCUBOOT_DEV flash_controller
#define PM__MCUBOOT_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM__MCUBOOT_PRIMARY_1_OFFSET 0x0
#define PM__MCUBOOT_PRIMARY_1_ADDRESS 0x0
#define PM__MCUBOOT_PRIMARY_1_END_ADDRESS 0x40000
#define PM__MCUBOOT_PRIMARY_1_SIZE 0x40000
#define PM__MCUBOOT_PRIMARY_1_NAME mcuboot_primary_1
#define PM__MCUBOOT_PRIMARY_1_ID 1
#define PM__mcuboot_primary_1_ID PM_MCUBOOT_PRIMARY_1_ID
#define PM__mcuboot_primary_1_IS_ENABLED 1
#define PM_1_LABEL _MCUBOOT_PRIMARY_1
#define PM__MCUBOOT_PRIMARY_1_DEV nordic_ram_flash_controller
#define PM__MCUBOOT_PRIMARY_1_DEFAULT_DRIVER_KCONFIG CONFIG_FLASH_SIMULATOR
#define PM__MCUBOOT_SECONDARY_OFFSET 0x0
#define PM__MCUBOOT_SECONDARY_ADDRESS 0x0
#define PM__MCUBOOT_SECONDARY_END_ADDRESS 0xe0000
#define PM__MCUBOOT_SECONDARY_SIZE 0xe0000
#define PM__MCUBOOT_SECONDARY_NAME mcuboot_secondary
#define PM__MCUBOOT_SECONDARY_ID 2
#define PM__mcuboot_secondary_ID PM_MCUBOOT_SECONDARY_ID
#define PM__mcuboot_secondary_IS_ENABLED 1
#define PM_2_LABEL _MCUBOOT_SECONDARY
#define PM__MCUBOOT_SECONDARY_DEV DT_CHOSEN(nordic_pm_ext_flash)
#define PM__MCUBOOT_SECONDARY_DEFAULT_DRIVER_KCONFIG CONFIG_PM_EXTERNAL_FLASH_HAS_DRIVER
#define PM__MCUBOOT_PAD_OFFSET 0x10000
#define PM__MCUBOOT_PAD_ADDRESS 0x10000
#define PM__MCUBOOT_PAD_END_ADDRESS 0x10200
#define PM__MCUBOOT_PAD_SIZE 0x200
#define PM__MCUBOOT_PAD_NAME mcuboot_pad
#define PM__MCUBOOT_PAD_ID 3
#define PM__mcuboot_pad_ID PM_MCUBOOT_PAD_ID
#define PM__mcuboot_pad_IS_ENABLED 1
#define PM_3_LABEL _MCUBOOT_PAD
#define PM__MCUBOOT_PAD_DEV flash_controller
#define PM__MCUBOOT_PAD_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM__MCUBOOT_PRIMARY_OFFSET 0x10000
#define PM__MCUBOOT_PRIMARY_ADDRESS 0x10000
#define PM__MCUBOOT_PRIMARY_END_ADDRESS 0xf0000
#define PM__MCUBOOT_PRIMARY_SIZE 0xe0000
#define PM__MCUBOOT_PRIMARY_NAME mcuboot_primary
#define PM__MCUBOOT_PRIMARY_ID 4
#define PM__mcuboot_primary_ID PM_MCUBOOT_PRIMARY_ID
#define PM__mcuboot_primary_IS_ENABLED 1
#define PM_4_LABEL _MCUBOOT_PRIMARY
#define PM__MCUBOOT_PRIMARY_DEV flash_controller
#define PM__MCUBOOT_PRIMARY_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM__TFM_SECURE_OFFSET 0x10000
#define PM__TFM_SECURE_ADDRESS 0x10000
#define PM__TFM_SECURE_END_ADDRESS 0x1c000
#define PM__TFM_SECURE_SIZE 0xc000
#define PM__TFM_SECURE_NAME tfm_secure
#define PM__TFM_SECURE_ID 5
#define PM__tfm_secure_ID PM_TFM_SECURE_ID
#define PM__tfm_secure_IS_ENABLED 1
#define PM_5_LABEL _TFM_SECURE
#define PM__TFM_SECURE_DEV flash_controller
#define PM__TFM_SECURE_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM__MCUBOOT_PRIMARY_APP_OFFSET 0x10200
#define PM__MCUBOOT_PRIMARY_APP_ADDRESS 0x10200
#define PM__MCUBOOT_PRIMARY_APP_END_ADDRESS 0xf0000
#define PM__MCUBOOT_PRIMARY_APP_SIZE 0xdfe00
#define PM__MCUBOOT_PRIMARY_APP_NAME mcuboot_primary_app
#define PM__MCUBOOT_PRIMARY_APP_ID 6
#define PM__mcuboot_primary_app_ID PM_MCUBOOT_PRIMARY_APP_ID
#define PM__mcuboot_primary_app_IS_ENABLED 1
#define PM_6_LABEL _MCUBOOT_PRIMARY_APP
#define PM__MCUBOOT_PRIMARY_APP_DEV flash_controller
#define PM__MCUBOOT_PRIMARY_APP_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM__TFM_OFFSET 0x10200
#define PM__TFM_ADDRESS 0x10200
#define PM__TFM_END_ADDRESS 0x1c000
#define PM__TFM_SIZE 0xbe00
#define PM__TFM_NAME tfm
#define PM__TFM_ID 7
#define PM__tfm_ID PM_TFM_ID
#define PM__tfm_IS_ENABLED 1
#define PM_7_LABEL _TFM
#define PM__TFM_DEV flash_controller
#define PM__TFM_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM__APP_OFFSET 0x1c000
#define PM__APP_ADDRESS 0x1c000
#define PM__APP_END_ADDRESS 0xf0000
#define PM__APP_SIZE 0xd4000
#define PM__APP_NAME app
#define PM__APP_ID 8
#define PM__app_ID PM_APP_ID
#define PM__app_IS_ENABLED 1
#define PM_8_LABEL _APP
#define PM__APP_DEV flash_controller
#define PM__APP_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM__TFM_NONSECURE_OFFSET 0x1c000
#define PM__TFM_NONSECURE_ADDRESS 0x1c000
#define PM__TFM_NONSECURE_END_ADDRESS 0xf0000
#define PM__TFM_NONSECURE_SIZE 0xd4000
#define PM__TFM_NONSECURE_NAME tfm_nonsecure
#define PM__TFM_NONSECURE_ID 9
#define PM__tfm_nonsecure_ID PM_TFM_NONSECURE_ID
#define PM__tfm_nonsecure_IS_ENABLED 1
#define PM_9_LABEL _TFM_NONSECURE
#define PM__TFM_NONSECURE_DEV flash_controller
#define PM__TFM_NONSECURE_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM__RAM_FLASH_OFFSET 0x40000
#define PM__RAM_FLASH_ADDRESS 0x40000
#define PM__RAM_FLASH_END_ADDRESS 0x40000
#define PM__RAM_FLASH_SIZE 0x0
#define PM__RAM_FLASH_NAME ram_flash
#define PM__RAM_FLASH_ID 10
#define PM__ram_flash_ID PM_RAM_FLASH_ID
#define PM__ram_flash_IS_ENABLED 1
#define PM_10_LABEL _RAM_FLASH
#define PM__RAM_FLASH_DEV nordic_ram_flash_controller
#define PM__RAM_FLASH_DEFAULT_DRIVER_KCONFIG CONFIG_FLASH_SIMULATOR
#define PM__MCUBOOT_SECONDARY_1_OFFSET 0xe0000
#define PM__MCUBOOT_SECONDARY_1_ADDRESS 0xe0000
#define PM__MCUBOOT_SECONDARY_1_END_ADDRESS 0x120000
#define PM__MCUBOOT_SECONDARY_1_SIZE 0x40000
#define PM__MCUBOOT_SECONDARY_1_NAME mcuboot_secondary_1
#define PM__MCUBOOT_SECONDARY_1_ID 11
#define PM__mcuboot_secondary_1_ID PM_MCUBOOT_SECONDARY_1_ID
#define PM__mcuboot_secondary_1_IS_ENABLED 1
#define PM_11_LABEL _MCUBOOT_SECONDARY_1
#define PM__MCUBOOT_SECONDARY_1_DEV DT_CHOSEN(nordic_pm_ext_flash)
#define PM__MCUBOOT_SECONDARY_1_DEFAULT_DRIVER_KCONFIG CONFIG_PM_EXTERNAL_FLASH_HAS_DRIVER
#define PM__NONSECURE_STORAGE_OFFSET 0xf0000
#define PM__NONSECURE_STORAGE_ADDRESS 0xf0000
#define PM__NONSECURE_STORAGE_END_ADDRESS 0x100000
#define PM__NONSECURE_STORAGE_SIZE 0x10000
#define PM__NONSECURE_STORAGE_NAME nonsecure_storage
#define PM__NONSECURE_STORAGE_ID 12
#define PM__nonsecure_storage_ID PM_NONSECURE_STORAGE_ID
#define PM__nonsecure_storage_IS_ENABLED 1
#define PM_12_LABEL _NONSECURE_STORAGE
#define PM__NONSECURE_STORAGE_DEV flash_controller
#define PM__NONSECURE_STORAGE_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM__SETTINGS_STORAGE_OFFSET 0xf0000
#define PM__SETTINGS_STORAGE_ADDRESS 0xf0000
#define PM__SETTINGS_STORAGE_END_ADDRESS 0x100000
#define PM__SETTINGS_STORAGE_SIZE 0x10000
#define PM__SETTINGS_STORAGE_NAME settings_storage
#define PM__SETTINGS_STORAGE_ID 13
#define PM__settings_storage_ID PM_SETTINGS_STORAGE_ID
#define PM__settings_storage_IS_ENABLED 1
#define PM_13_LABEL _SETTINGS_STORAGE
#define PM__SETTINGS_STORAGE_DEV flash_controller
#define PM__SETTINGS_STORAGE_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM__EXTERNAL_FLASH_OFFSET 0x120000
#define PM__EXTERNAL_FLASH_ADDRESS 0x120000
#define PM__EXTERNAL_FLASH_END_ADDRESS 0x800000
#define PM__EXTERNAL_FLASH_SIZE 0x6e0000
#define PM__EXTERNAL_FLASH_NAME external_flash
#define PM__EXTERNAL_FLASH_ID 14
#define PM__external_flash_ID PM_EXTERNAL_FLASH_ID
#define PM__external_flash_IS_ENABLED 1
#define PM_14_LABEL _EXTERNAL_FLASH
#define PM__EXTERNAL_FLASH_DEV DT_CHOSEN(nordic_pm_ext_flash)
#define PM__EXTERNAL_FLASH_DEFAULT_DRIVER_KCONFIG CONFIG_PM_EXTERNAL_FLASH_HAS_DRIVER
#define PM__OTP_OFFSET 0x0
#define PM__OTP_ADDRESS 0xff8100
#define PM__OTP_END_ADDRESS 0xff83fc
#define PM__OTP_SIZE 0x2fc
#define PM__OTP_NAME otp
#define PM__PCD_SRAM_OFFSET 0x0
#define PM__PCD_SRAM_ADDRESS 0x20000000
#define PM__PCD_SRAM_END_ADDRESS 0x20002000
#define PM__PCD_SRAM_SIZE 0x2000
#define PM__PCD_SRAM_NAME pcd_sram
#define PM__MCUBOOT_SRAM_OFFSET 0x2000
#define PM__MCUBOOT_SRAM_ADDRESS 0x20002000
#define PM__MCUBOOT_SRAM_END_ADDRESS 0x20080000
#define PM__MCUBOOT_SRAM_SIZE 0x7e000
#define PM__MCUBOOT_SRAM_NAME mcuboot_sram
#define PM__SRAM_SECURE_OFFSET 0x2000
#define PM__SRAM_SECURE_ADDRESS 0x20002000
#define PM__SRAM_SECURE_END_ADDRESS 0x2000a000
#define PM__SRAM_SECURE_SIZE 0x8000
#define PM__SRAM_SECURE_NAME sram_secure
#define PM__TFM_SRAM_OFFSET 0x2000
#define PM__TFM_SRAM_ADDRESS 0x20002000
#define PM__TFM_SRAM_END_ADDRESS 0x2000a000
#define PM__TFM_SRAM_SIZE 0x8000
#define PM__TFM_SRAM_NAME tfm_sram
#define PM__SRAM_NONSECURE_OFFSET 0xa000
#define PM__SRAM_NONSECURE_ADDRESS 0x2000a000
#define PM__SRAM_NONSECURE_END_ADDRESS 0x20080000
#define PM__SRAM_NONSECURE_SIZE 0x76000
#define PM__SRAM_NONSECURE_NAME sram_nonsecure
#define PM__SRAM_PRIMARY_OFFSET 0xa000
#define PM__SRAM_PRIMARY_ADDRESS 0x2000a000
#define PM__SRAM_PRIMARY_END_ADDRESS 0x20070000
#define PM__SRAM_PRIMARY_SIZE 0x66000
#define PM__SRAM_PRIMARY_NAME sram_primary
#define PM__RPMSG_NRF53_SRAM_OFFSET 0x70000
#define PM__RPMSG_NRF53_SRAM_ADDRESS 0x20070000
#define PM__RPMSG_NRF53_SRAM_END_ADDRESS 0x20080000
#define PM__RPMSG_NRF53_SRAM_SIZE 0x10000
#define PM__RPMSG_NRF53_SRAM_NAME rpmsg_nrf53_sram
#define PM__NUM 15
#define PM__ALL_BY_SIZE "ram_flash mcuboot_pad otp pcd_sram tfm_sram sram_secure tfm tfm_secure mcuboot rpmsg_nrf53_sram settings_storage nonsecure_storage mcuboot_primary_1 mcuboot_secondary_1 sram_primary sram_nonsecure mcuboot_sram app tfm_nonsecure mcuboot_primary_app mcuboot_secondary mcuboot_primary external_flash"
#define PM_B0N_OFFSET 0x0
#define PM_B0N_ADDRESS 0x1000000
#define PM_B0N_END_ADDRESS 0x1008580
#define PM_B0N_SIZE 0x8580
#define PM_B0N_NAME b0n
#define PM_B0N_ID 15
#define PM_b0n_ID PM_B0N_ID
#define PM_b0n_IS_ENABLED 1
#define PM_15_LABEL B0N
#define PM_B0N_DEV flash_controller
#define PM_B0N_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_B0N_CONTAINER_OFFSET 0x0
#define PM_B0N_CONTAINER_ADDRESS 0x1000000
#define PM_B0N_CONTAINER_END_ADDRESS 0x1008800
#define PM_B0N_CONTAINER_SIZE 0x8800
#define PM_B0N_CONTAINER_NAME b0n_container
#define PM_B0N_CONTAINER_ID 16
#define PM_b0n_container_ID PM_B0N_CONTAINER_ID
#define PM_b0n_container_IS_ENABLED 1
#define PM_16_LABEL B0N_CONTAINER
#define PM_B0N_CONTAINER_DEV flash_controller
#define PM_B0N_CONTAINER_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_PROVISION_OFFSET 0x8580
#define PM_PROVISION_ADDRESS 0x1008580
#define PM_PROVISION_END_ADDRESS 0x1008800
#define PM_PROVISION_SIZE 0x280
#define PM_PROVISION_NAME provision
#define PM_PROVISION_ID 17
#define PM_provision_ID PM_PROVISION_ID
#define PM_provision_IS_ENABLED 1
#define PM_17_LABEL PROVISION
#define PM_PROVISION_DEV flash_controller
#define PM_PROVISION_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_APP_OFFSET 0x8800
#define PM_APP_ADDRESS 0x1008800
#define PM_APP_END_ADDRESS 0x1040000
#define PM_APP_SIZE 0x37800
#define PM_APP_NAME app
#define PM_APP_ID 18
#define PM_app_ID PM_APP_ID
#define PM_app_IS_ENABLED 1
#define PM_18_LABEL APP
#define PM_APP_DEV flash_controller
#define PM_APP_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_HCI_RPMSG_OFFSET 0x8800
#define PM_HCI_RPMSG_ADDRESS 0x1008800
#define PM_HCI_RPMSG_END_ADDRESS 0x1040000
#define PM_HCI_RPMSG_SIZE 0x37800
#define PM_HCI_RPMSG_NAME hci_rpmsg
#define PM_HCI_RPMSG_ID 19
#define PM_hci_rpmsg_ID PM_HCI_RPMSG_ID
#define PM_hci_rpmsg_IS_ENABLED 1
#define PM_19_LABEL HCI_RPMSG
#define PM_HCI_RPMSG_DEV flash_controller
#define PM_HCI_RPMSG_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_SRAM_PRIMARY_OFFSET 0x0
#define PM_SRAM_PRIMARY_ADDRESS 0x21000000
#define PM_SRAM_PRIMARY_END_ADDRESS 0x21010000
#define PM_SRAM_PRIMARY_SIZE 0x10000
#define PM_SRAM_PRIMARY_NAME sram_primary
#define PM_NUM 20
#define PM_ALL_BY_SIZE "provision b0n b0n_container sram_primary hci_rpmsg app"
#define PM_ADDRESS 0x1000000
#define PM_SIZE 0x8580
#define PM_SRAM_ADDRESS 0x21000000
#define PM_SRAM_SIZE 0x10000
#endif /* PM_CONFIG_H__ */