/* File generated by /opt/nordic/ncs/v2.5.0-rc1/nrf/scripts/partition_manager_output.py, do not modify */
#ifndef PM_CONFIG_H__
#define PM_CONFIG_H__
#define PM_APP_OFFSET 0x0
#define PM_APP_ADDRESS 0x0
#define PM_APP_END_ADDRESS 0x100000
#define PM_APP_SIZE 0x100000
#define PM_APP_NAME app
#define PM_APP_ID 0
#define PM_app_ID PM_APP_ID
#define PM_app_IS_ENABLED 1
#define PM_0_LABEL APP
#define PM_APP_DEV flash_controller
#define PM_APP_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_OTP_OFFSET 0x0
#define PM_OTP_ADDRESS 0xff8100
#define PM_OTP_END_ADDRESS 0xff83fc
#define PM_OTP_SIZE 0x2fc
#define PM_OTP_NAME otp
#define PM_SRAM_PRIMARY_OFFSET 0x0
#define PM_SRAM_PRIMARY_ADDRESS 0x20000000
#define PM_SRAM_PRIMARY_END_ADDRESS 0x20070000
#define PM_SRAM_PRIMARY_SIZE 0x70000
#define PM_SRAM_PRIMARY_NAME sram_primary
#define PM_RPMSG_NRF53_SRAM_OFFSET 0x70000
#define PM_RPMSG_NRF53_SRAM_ADDRESS 0x20070000
#define PM_RPMSG_NRF53_SRAM_END_ADDRESS 0x20080000
#define PM_RPMSG_NRF53_SRAM_SIZE 0x10000
#define PM_RPMSG_NRF53_SRAM_NAME rpmsg_nrf53_sram
#define PM_NUM 1
#define PM_ALL_BY_SIZE "otp rpmsg_nrf53_sram sram_primary app"
#define PM_CPUNET_APP_OFFSET 0x0
#define PM_CPUNET_APP_ADDRESS 0x1000000
#define PM_CPUNET_APP_END_ADDRESS 0x1040000
#define PM_CPUNET_APP_SIZE 0x40000
#define PM_CPUNET_APP_NAME app
#define PM_CPUNET_APP_ID 1
#define PM_CPUNET_app_ID PM_APP_ID
#define PM_CPUNET_app_IS_ENABLED 1
#define PM_1_LABEL CPUNET_APP
#define PM_CPUNET_APP_DEV flash_controller
#define PM_CPUNET_APP_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_CPUNET_HCI_RPMSG_OFFSET 0x0
#define PM_CPUNET_HCI_RPMSG_ADDRESS 0x1000000
#define PM_CPUNET_HCI_RPMSG_END_ADDRESS 0x1040000
#define PM_CPUNET_HCI_RPMSG_SIZE 0x40000
#define PM_CPUNET_HCI_RPMSG_NAME hci_rpmsg
#define PM_CPUNET_HCI_RPMSG_ID 2
#define PM_CPUNET_hci_rpmsg_ID PM_HCI_RPMSG_ID
#define PM_CPUNET_hci_rpmsg_IS_ENABLED 1
#define PM_2_LABEL CPUNET_HCI_RPMSG
#define PM_CPUNET_HCI_RPMSG_DEV flash_controller
#define PM_CPUNET_HCI_RPMSG_DEFAULT_DRIVER_KCONFIG CONFIG_SOC_FLASH_NRF
#define PM_CPUNET_SRAM_PRIMARY_OFFSET 0x0
#define PM_CPUNET_SRAM_PRIMARY_ADDRESS 0x21000000
#define PM_CPUNET_SRAM_PRIMARY_END_ADDRESS 0x21010000
#define PM_CPUNET_SRAM_PRIMARY_SIZE 0x10000
#define PM_CPUNET_SRAM_PRIMARY_NAME sram_primary
#define PM_CPUNET_NUM 3
#define PM_CPUNET_ALL_BY_SIZE "sram_primary hci_rpmsg app"
#define PM_ADDRESS 0x0
#define PM_SIZE 0x100000
#define PM_SRAM_ADDRESS 0x20000000
#define PM_SRAM_SIZE 0x70000
#endif /* PM_CONFIG_H__ */