#include "stm8s.h"
#include "stm8s_clock.h"
#include "stm8s_uart1.h"
//#include "stdio.h"
//#include "string.h"
void putchars(char chuoi[]);
void main(void)
{
  //int fmaster;
    /* khoi tao thach anh noi toc do cao HSI 16MHz*/
    CLK_HSI_16MHz_Init();
    
    /* khoi tao thach anh ngoai toc do cao HSE 16MHz*/
    //CLK_HSE_16MHz_Init();
    
    /* khoi tao thach anh noi toc do thap LSI 128kHz*/
    //CLK_LSI_128kHz_Init();
    UART1_DeInit();
    UART1_Init((uint32_t)9600, UART1_WORDLENGTH_8D, 
                UART1_STOPBITS_1, UART1_PARITY_NO, 
                UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
    UART1_Cmd(ENABLE);
     putchars("hello");
    while (1)
    {
      
    }
}

void putchars(char chuoi[])
{                                                                                                                                                                                       
  int i=0;
  for(i=0; i<sizeof(chuoi);i++)
  {
    UART1_SendData8(chuoi[i]);
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
