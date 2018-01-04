#include "stm8s.h"
#include "stm8s_tim1.h"
#include "stm8s_adc1.h"
#include "stm8s_ds1307.h"
uint8_t data = 0;
u8* sec;

void Delay (uint16_t nCount);

void main(void)
{
    CLK_HSI_16MHz_Init();
    I2C_DS1307_init();
   
    while (1)
    {
      I2C_DS1307_ByteRead(0x00, sec);
      Delay(10000);
    }
}

/**
  * @brief Delay
  * @param nCount
  * @retval None
  */
void Delay(uint16_t nCount)
{
    /* Decrement nCount value */
    while (nCount != 0)
    {
        nCount--;
    }
}



#ifdef USE_FULL_ASSERT          

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
