/*
    PD5(U1TX)
    PD6(U1RX)
*/
#include "stm8s.h"
//#include "stdio.h"
//#define PUTCHAR_PROTOTYPE int putchar (int c)
//#define GETCHAR_PROTOTYPE int getchar (void)
int l=0;
void puts(char*s);
void main(void)
{
    
    /*High speed internal clock prescaler: 1*/
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);

    UART1_DeInit();
    /* UART1 configuration ------------------------------------------------------*/
    /* UART1 configured as follow:
    - BaudRate = 115200 baud  
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity 
    - Receive and transmit enabled
    - UART1 Clock disabled
    */
    UART1_Init((uint32_t)9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
    UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);

    /* Output a message on Hyperterminal using printf function */
    //printf("\n\rUART1 Example :retarget the C library printf()/getchar() functions to the UART\n\r");
    //printf("\n\rEnter Text\n\r");
    
//    char a[]="Mai Trong Nhan\nKim Nga Lee";
      puts("Mai Trong Nhan");
//    int i=0;
//    for(i=0;i<sizeof(a)-1;i++)
//    {
//     UART1_SendData8(a[i]);
//      while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
//    }
    while (1)
    {
     //   ans = getchar();
    //    printf("%c", ans);  
    }
}


void puts(char*s)
{ 
  int i=0;
  l = sizeof(s)-1;
     for(i=0;i<l;i++)
    {
      UART1_SendData8(s[i]);
      while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
    }
}
/**
PUTCHAR_PROTOTYPE
{
    UART1_SendData8(c);
    while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);

    return (c);
}

GETCHAR_PROTOTYPE
{
#ifdef _COSMIC_
  char c = 0;
#else
  int c = 0;
#endif
  while (UART1_GetFlagStatus(UART1_FLAG_RXNE) == RESET);
    c = UART1_ReceiveData8();
  return (c);
}
**/
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
