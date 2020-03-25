//      This library provides the high-level functions needed to use the I2C
//	serial interface supported by the hardware of several AVR processors.

#define TPS65217_ADDR 		0x24

#define CHIPID_REG 			0x00
#define PPATH_REG 			0x01
#define INT_REG 			0x02
#define CHGCONFIG0_REG 		0x03
#define CHGCONFIG1_REG 		0x04
#define CHGCONFIG2_REG 		0x05
#define CHGCONFIG3_REG 		0x06
#define WLEDCTRL1_REG 		0x07
#define WLEDCTRL2_REG 		0x08
#define MUXCTRL_REG 		0x09
#define STATUS_REG 			0x0A
#define PASSWORD_REG 		0x0B
#define PGOOD_REG 			0x0C
#define DEFPG_REG 			0x0D
#define DEFDCDC1_REG 		0x0E
#define DEFDCDC2_REG 		0x0F
#define DEFDCDC3_REG 		0x10
#define DEFSLEW_REG 		0x11
#define DEFLDO1_REG 		0x12
#define DEFLDO1_REG 		0x13
#define DEFLS1_REG 			0x14
#define DEFLS2_REG 			0x15
#define ENABLE_REG 			0x16
#define DEFUVLO_REG 		0x18
#define SEQ1_REG 			0x19
#define SEQ2_REG 			0x1A
#define SEQ3_REG 			0x1B
#define SEQ4_REG 			0x1C
#define SEQ5_REG 			0x1D
#define SEQ6_REG 			0x1E

#define TW_START					0x08
#define TW_REP_START				0x10
// Master Transmitter
#define TW_MT_SLA_ACK				0x18
#define TW_MT_SLA_NACK				0x20
#define TW_MT_DATA_ACK				0x28
#define TW_MT_DATA_NACK				0x30
#define TW_MT_ARB_LOST				0x38
// Master Receiver
#define TW_MR_ARB_LOST				0x38
#define TW_MR_SLA_ACK				0x40
#define TW_MR_SLA_NACK				0x48
#define TW_MR_DATA_ACK				0x50
#define TW_MR_DATA_NACK				0x58
// Slave Transmitter
#define TW_ST_SLA_ACK				0xA8
#define TW_ST_ARB_LOST_SLA_ACK		0xB0
#define TW_ST_DATA_ACK				0xB8
#define TW_ST_DATA_NACK				0xC0
#define TW_ST_LAST_DATA				0xC8
// Slave Receiver
#define TW_SR_SLA_ACK				0x60
#define TW_SR_ARB_LOST_SLA_ACK		0x68
#define TW_SR_GCALL_ACK				0x70
#define TW_SR_ARB_LOST_GCALL_ACK	0x78
#define TW_SR_DATA_ACK				0x80
#define TW_SR_DATA_NACK				0x88
#define TW_SR_GCALL_DATA_ACK		0x90
#define TW_SR_GCALL_DATA_NACK		0x98
#define TW_SR_STOP					0xA0
// Misc
#define TW_NO_INFO					0xF8
#define TW_BUS_ERROR				0x00

// defines and constants
#define TWCR_CMD_MASK		0x0F
#define TWSR_STATUS_MASK	0xF8

// return values
#define I2C_OK				0x00
#define I2C_ERROR_NODEV		0x01
