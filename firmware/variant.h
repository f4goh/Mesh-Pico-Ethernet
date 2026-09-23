// Raspberry Pi Pico 2 + internal W5500 Ethernet module + RA-02
// RP2350

//
// W5500 Ethernet on SPI0:
//   MISO=GP16  CS=GP17  SCK=GP18  MOSI=GP19  RST=GP20
//
// See wiring.svg in this directory for a complete connection diagram.

// Community/DIY board - no dedicated Meshtastic HardwareModel
#define PRIVATE_HW

// Onboard LED (GP26 on Pico 2)
#define LED_POWER 26


// Power monitoring
// GP24: VBUS sense - HIGH when USB is present (digital read)
// GP29: ADC3 measures VSYS/3 (200 kO / 100 kO divider, same as standard Pico 2)
//#define EXT_PWR_DETECT 24
#define BATTERY_PIN 28
#define ADC_MULTIPLIER 3.0
#define BATTERY_SENSE_RESOLUTION_BITS 12
// No real battery - suppress false "battery at 100%" while USB powers VSYS
#define NO_BATTERY_LEVEL_ON_CHARGE

#define HAS_SCREEN 1
//#define WIRE_INTERFACES_COUNT (1)
//#define I2C_SDA (1)
//#define I2C_SCL (0)

#define USE_SSD1306

// Optional user button - connect a button between GP6 and GND
#define BUTTON_PIN 27
#define BUTTON_NEED_PULLUP

// GPS on UART1 (Serial2) - GP8 TX, GP9 RX
// GP8/GP9 belong to UART1, so we must use Serial2 (not the default Serial1/UART0).
// GP0/GP1 (UART0 defaults) are free but the firmware treats pin 0 as "not configured".
// GP4/GP5 occupied by I2C (SCL/SDA for BMP-280).

#define SERIAL_MODULE
#define SERIAL_RX_PIN 1   // RX du module Meshtastic (reçoit depuis Arduino TX)
#define SERIAL_TX_PIN 0   // TX du module Meshtastic (envoie vers Arduino RX)
#define SERIAL_BAUD 9600
#define UART_PORT Serial

//#define HAS_GPS 1
//#define GPS_RX_PIN (1u)
//#define GPS_TX_PIN (0u)

//#undef PIN_SDA
//#undef PIN_SCL

//#define PIN_SDA 2
//#define PIN_SCL 3


#define USE_RF95

#undef LORA_SCK
#undef LORA_MISO
#undef LORA_MOSI
#undef LORA_CS

#define LORA_SCK 10
#define LORA_MISO 8
#define LORA_MOSI 11
#define LORA_CS 9

#define LORA_DIO0 7
#define LORA_RESET 22
#define LORA_DIO1 RADIOLIB_NC
#define LORA_DIO2 RADIOLIB_NC
#define LORA_DIO3 RADIOLIB_NC

// ---- NEOPIXEL
#define HAS_NEOPIXEL
#define NEOPIXEL_COUNT 1
#define NEOPIXEL_DATA 25
#define NEOPIXEL_TYPE (NEO_GRB + NEO_KHZ800)

// ---- W5500 Ethernet on SPI0 --------------------------------------------
#define HAS_ETHERNET 1
#define HAS_NETWORKING 1
#define USE_ARDUINO_ETHERNET 1
#define USE_ETHERNET_DEFAULT 1

// W5500 connecté sur SPI0
//
// RP2350          W5500
// -------------------------
// GP16            MISO
// GP17            CS / SS
// GP18            SCK
// GP19            MOSI
// GP20            RESET
// GP21            INT
//

#define ETH_SPI0_MISO 16
#define ETH_SPI0_SCK  18
#define ETH_SPI0_MOSI 19

#define PIN_ETHERNET_SS    17
#define PIN_ETHERNET_RESET 20

// SPI utilisé par le W5500
#define ETH_SPI_PORT SPI

