#include "stm8s_ds1307.h"
#include "stm8s_i2c.h"


/****************************************************
* Function name: I2C_DS1307_init
* Description:
* Input:
* Output:
* Return:
*******************************************************/
void I2C_DS1307_init(void)
{
  //Get system clock frequecy
  uint8_t clock_input = 0;
  clock_input = CLK_GetClockFreq()/1000000;
  //Enable I2C peripheral
  I2C_Cmd(ENABLE);
  //configure I2C
  I2C_Init(I2C_Speed,ADDRESS_STM8,I2C_DUTYCYCLE_2,I2C_ACK_CURR,I2C_ADDMODE_7BIT,clock_input);

}

/****************************************************
* Function name: I2C_DS1307_ByteWrite
* Description: this will write one byte data
* Input:
* Output:
* Return:
*******************************************************/
void I2C_DS1307_ByteWrite(uint8_t idata)
{
  //send START condition
  I2C_GenerateSTART(ENABLE);
  // test on VE5 and clear it
  while(!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
  //send address for write
  I2C_Send7bitAddress(ADDRESS_SLAVE, I2C_DIRECTION_TX);
  //test on EV5 and clear it
  while(!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
  //send the byte to be written 
  I2C_SendData(idata);
  //test on EV5 and clear it 
  while(!I2C_CheckEvent(I2C_EVENT_SLAVE_BYTE_TRANSMITTED));
  // send a STOP condition
  I2C_GenerateSTOP(ENABLE); 
}

/****************************************************
* Function name: I2C_DS1307_ByteRead
* Description: this will read one byte data
* Input:
* Output:
* Return:
*******************************************************/
void I2C_DS1307_ByteRead(u8 ReadAddr, u8* pBuffer)
{
  // while the bus is busy
  while(I2C_GetFlagStatus(I2C_FLAG_BUSBUSY));
  // Generate start condition and wait event detection
  I2C_GenerateSTART(ENABLE);
  // test on EV5 and clear it
  while(!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
  //send slave address 
  I2C_Send7bitAddress(ADDRESS_SLAVE, I2C_DIRECTION_TX);
  //test on EV6 and clear it
 while(!I2C_CheckEvent(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
 // while(!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
 // while(!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTING));
 // while(!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_ADDRESS10));
 // while(!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
 // while(!I2C_CheckEvent(I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
 // while(!I2C_CheckEvent(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
  //while(!I2C_CheckEvent(I2C_EVENT_SLAVE_ACK_FAILURE));
 // while(!I2C_CheckEvent(I2C_EVENT_SLAVE_BYTE_RECEIVED));
 // while(!I2C_CheckEvent(I2C_EVENT_SLAVE_BYTE_TRANSMITTED));
 // loi  while(!I2C_CheckEvent(I2C_EVENT_SLAVE_BYTE_TRANSMITTING));
 // while(!I2C_CheckEvent(I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED));
 // while(!I2C_CheckEvent(I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED));
 // while(!I2C_CheckEvent(I2C_EVENT_SLAVE_STOP_DETECTED));
  //send address of first byte to be read and wait event detection
  I2C_SendData((u8)ReadAddr);//LSB
  //test on EV5 and clear it
  while(!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
  // send START condition to restart
  I2C_GenerateSTART(ENABLE);
  //test on EV5 and clear it 
  while(!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));
  I2C_Send7bitAddress(ADDRESS_SLAVE, I2C_DIRECTION_RX);
  //test on EV6 and clear it
  while(!I2C_CheckEvent(I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
  while(!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_RECEIVED));
  
  *pBuffer = I2C_ReceiveData();
  
  I2C_AcknowledgeConfig(I2C_ACK_NONE);
  
  //send STOP condition
  I2C_GenerateSTOP(ENABLE);
  
  
}
