/*-------------------------------------------------------------------
/*      (C) Copyright 2023, PSYM. All Rights Reserved
/*-------------------------------------------------------------------
/* File name   : LED.c
/* Description :
/* Author      : PSYM
/*-------------------------------------------------------------------
/* Update note:
/* -----------   -----------   --------------------------------------
/*    Date         Author                       Note
/* -----------   -----------   --------------------------------------
/* 2023-05-23,     psym
/*   17:04
**/

/* ����ͷ�ļ� -------------------------------------------------------*/
#include "LED.h"

/* ˽�����Ͷ��� -----------------------------------------------------*/
/* None. */

/* ˽�к궨�� -------------------------------------------------------*/
#define LED8X_COL P6 // 8x8��������ɨ��˿�
#define LED8X_ROW P7 // 8x8��������ɨ��˿�

/* ˽�б��� ---------------------------------------------------------*/
code uint8 IMAGES[][8] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00},
    {0x00, 0x40, 0x40, 0x40, 0xc0, 0x40, 0x40, 0x00},
    {0x00, 0x20, 0x20, 0x20, 0xe0, 0x20, 0x20, 0x00},
    {0x00, 0x90, 0x90, 0x90, 0xf0, 0x90, 0x90, 0x00},
    {0x00, 0x48, 0x48, 0x48, 0x78, 0x48, 0x48, 0x00},
    {0x00, 0x24, 0x24, 0x24, 0x3c, 0x24, 0x24, 0x00},
    {0x00, 0xa4, 0x24, 0x24, 0x3c, 0x24, 0xa4, 0x00},
    {0x00, 0xd2, 0x92, 0x92, 0x9e, 0x92, 0xd2, 0x00},
    {0x00, 0xe9, 0x49, 0x49, 0xcf, 0x49, 0xe9, 0x00},
    {0x00, 0xf4, 0x24, 0x24, 0xe7, 0x24, 0xf4, 0x00},
    {0x00, 0xfa, 0x12, 0x12, 0xf3, 0x12, 0xfa, 0x00},
    {0x00, 0x7d, 0x09, 0x09, 0x79, 0x09, 0x7d, 0x00},
    {0x00, 0xbe, 0x84, 0x84, 0xbc, 0x84, 0xbe, 0x00},
    {0x00, 0xde, 0x42, 0x42, 0x5e, 0x42, 0x5e, 0x00},
    {0x00, 0xef, 0x21, 0x21, 0x2f, 0x21, 0x2f, 0x00},
    {0x00, 0xf7, 0x10, 0x10, 0x17, 0x10, 0x17, 0x00},
    {0x00, 0x7b, 0x88, 0x08, 0x0b, 0x08, 0x0b, 0x00},
    {0x00, 0x3c, 0x44, 0x04, 0x04, 0x04, 0x04, 0x00},
    {0x00, 0x9e, 0xa2, 0x82, 0x82, 0x82, 0x82, 0x00},
    {0x00, 0xcf, 0x51, 0x41, 0x41, 0x41, 0x41, 0x00},
    {0x00, 0xe7, 0x28, 0x20, 0x20, 0x20, 0x20, 0x00},
    {0x00, 0xf3, 0x14, 0x10, 0x10, 0x10, 0x10, 0x00},
    {0x00, 0x79, 0x8a, 0x08, 0x08, 0x08, 0x08, 0x00},
    {0x00, 0x3c, 0x45, 0x04, 0x04, 0x04, 0x04, 0x00},
    {0x00, 0x1e, 0xa2, 0x82, 0x82, 0x82, 0x02, 0x00},
    {0x00, 0x8f, 0x51, 0x41, 0x41, 0x41, 0x81, 0x00},
    {0x00, 0xc7, 0x28, 0x20, 0x20, 0x20, 0xc0, 0x00},
    {0x00, 0xe3, 0x14, 0x10, 0x10, 0x10, 0xe0, 0x00},
    {0x00, 0x71, 0x8a, 0x88, 0x88, 0x88, 0x70, 0x00},
    {0x00, 0x38, 0x45, 0x44, 0x44, 0x44, 0x38, 0x00},
    {0x00, 0x1c, 0x22, 0x22, 0x22, 0x22, 0x1c, 0x00},
    {0x00, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00},
    {0x00, 0x07, 0x08, 0x08, 0x08, 0x08, 0x07, 0x00},
    {0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00},
    {0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00},
    {0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x00},
    {0x00, 0x00, 0x80, 0x80, 0xc0, 0x40, 0x60, 0x00},
    {0x00, 0x80, 0x40, 0x40, 0x60, 0x20, 0x30, 0x00},
    {0x00, 0xc0, 0xa0, 0xa0, 0x30, 0x10, 0x18, 0x00},
    {0x00, 0x60, 0x50, 0xd0, 0x98, 0x88, 0x0c, 0x00},
    {0x00, 0x30, 0x28, 0xe8, 0xcc, 0xc4, 0x06, 0x00},
    {0x00, 0x98, 0x94, 0xf4, 0x66, 0x62, 0x03, 0x00},
    {0x00, 0xcc, 0x4a, 0x7a, 0x33, 0x31, 0x01, 0x00},
    {0x00, 0x66, 0xa5, 0xbd, 0x99, 0x18, 0x00, 0x00},
    {0x00, 0x33, 0x52, 0x5e, 0xcc, 0x8c, 0x80, 0x00},
    {0x00, 0x19, 0x29, 0x2f, 0x66, 0x46, 0xc0, 0x00},
    {0x00, 0x0c, 0x14, 0x17, 0x33, 0x23, 0x60, 0x00},
    {0x00, 0x06, 0x8a, 0x8b, 0x99, 0x91, 0x30, 0x00},
    {0x00, 0x83, 0x45, 0x45, 0x4c, 0x48, 0x98, 0x00},
    {0x00, 0xc1, 0x22, 0x22, 0x26, 0x24, 0xcc, 0x00},
    {0x00, 0xe0, 0x11, 0x11, 0x13, 0x12, 0xe6, 0x00},
    {0x00, 0x70, 0x88, 0x88, 0x89, 0x89, 0x73, 0x00},
    {0x00, 0x38, 0x44, 0x44, 0x44, 0x44, 0x39, 0x00},
    {0x00, 0x9c, 0x22, 0x22, 0x22, 0x22, 0x9c, 0x00},
    {0x00, 0xce, 0x91, 0x91, 0x91, 0x91, 0xce, 0x00},
    {0x00, 0xe7, 0x48, 0xc8, 0x48, 0x48, 0xe7, 0x00},
    {0x00, 0x73, 0x24, 0xe4, 0x24, 0x24, 0xf3, 0x00},
    {0x00, 0x39, 0x12, 0xf2, 0x92, 0x12, 0xf9, 0x00},
    {0x00, 0x9c, 0x89, 0xf9, 0x49, 0x89, 0x7c, 0x00},
    {0x00, 0xce, 0x44, 0x7c, 0x24, 0x44, 0x3e, 0x00},
    {0x00, 0x67, 0x22, 0x3e, 0x12, 0x22, 0x1f, 0x00},
    {0x00, 0xb3, 0x91, 0x9f, 0x89, 0x91, 0x8f, 0x00},
    {0x00, 0xd9, 0x48, 0x4f, 0x44, 0x48, 0x47, 0x00},
    {0x00, 0xec, 0x24, 0x27, 0x22, 0x24, 0x23, 0x00},
    {0x00, 0xf6, 0x12, 0x13, 0x11, 0x12, 0x11, 0x00},
    {0x00, 0x7b, 0x89, 0x09, 0x08, 0x09, 0x08, 0x00},
    {0x00, 0x3d, 0x44, 0x04, 0x04, 0x04, 0x04, 0x00},
    {0x00, 0x9e, 0x22, 0x02, 0x02, 0x02, 0x82, 0x00},
    {0x00, 0xcf, 0x91, 0x81, 0x81, 0x81, 0xc1, 0x00},
    {0x00, 0xe7, 0x48, 0x40, 0x40, 0x40, 0xe0, 0x00},
    {0x00, 0xf3, 0x24, 0x20, 0x20, 0x20, 0xf0, 0x00},
    {0x00, 0x79, 0x92, 0x90, 0x90, 0x90, 0x78, 0x00},
    {0x00, 0x3c, 0x49, 0x48, 0x48, 0x48, 0x3c, 0x00},
    {0x00, 0x1e, 0x24, 0x24, 0x24, 0x24, 0x1e, 0x00},
    {0x00, 0x0f, 0x12, 0x12, 0x12, 0x12, 0x0f, 0x00},
    {0x00, 0x07, 0x09, 0x09, 0x09, 0x09, 0x07, 0x00},
    {0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00},
    {0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00},
    {0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
};
const int IMAGES_LEN = sizeof(IMAGES)/8;

code uint8 IMAGES1[][8] =
{
    {0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x00},
    {0x7e, 0x06, 0x06, 0x3e, 0x06, 0x06, 0x7e, 0x00},
    {0x7e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00},
    {0x7e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00},
    {0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00},
    {0xc6, 0xee, 0xfe, 0xd6, 0xc6, 0xc6, 0xc6, 0x00},
    {0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00},
    {0x66, 0x36, 0x1e, 0x3e, 0x66, 0x66, 0x3e, 0x00},
    {0x7e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00},
    {0x3e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3e, 0x00},
};
const int IMAGES1_LEN = sizeof(IMAGES1)/8;

uint8 index;

/* ��չ���� ---------------------------------------------------------*/
/* None. */

/* ˽�к���ԭ�� -----------------------------------------------------*/
/* None. */

/* ������ -----------------------------------------------------------*/

/**
 * @brief  LED8X8��������ʾ
 * @param  column: �к�
 * @retval None
 * @note   None
 */
void LED(uint8 column)
{
    for (index = 0; index < 8; index++)
    {
        LED8X_ROW = 0xFF; // ��Ӱ
        LED8X_COL = IMAGES[column][index];
        LED8X_ROW = _crol_(0xFE, index); // ��ɨ��
        Delay_ms(2);
    }
}

void LED1(uint8 column)
{
    for (index = 0; index < 8; index++)
    {
        LED8X_ROW = 0xFF; // ��Ӱ
        LED8X_COL = IMAGES1[column][index];
        LED8X_ROW = _crol_(0xFE, index); // ��ɨ��
        Delay_ms(2);
    }
}
/*>>>>>>>>>> (C) COPYRIGHT PSYM <<<<<< >>>>>> END OF FILE <<<<<<<<<<*/