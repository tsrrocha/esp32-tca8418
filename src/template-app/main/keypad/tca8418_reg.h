#ifndef _TCA8418_REG_H_
#define _TCA8418_REG_H_

// Configuration Register
#define TCA8418_CFG_REG                 0x01
#define CFG_KE_IEN                      0x01
#define CFG_GPI_IEN                     0x02
#define CFG_K_LCK_IEN                   0x04
#define CFG_OVR_FLOW_IEN                0x08
#define CFG_INT_CFG                     0x10
#define CFG_OVR_FLOW_M                  0x20
#define CFG_GPI_E_CGF                   0x40
#define CFG_AI                          0x80

// Interrupt Status Register
#define TCA8418_INT_STAT_REG            0x02
#define INT_STAT_K_INT                  0x01
#define INT_STAT_GPI_INT                0x02
#define INT_STAT_K_LCK_INT              0x04
#define INT_STAT_OVR_FLOW_INT           0x08
#define INT_STAT_CAD_INT                0x10

// Key lock and Event counter Register [ NA, K_LCK_EN, LCK2, LCK1, KLEC3, KLEC2, KLEC1, KLEC0]
#define TCA8418_KEY_LCK_EC_REG          0x03
#define KLEC0                           0x01
#define KLEC1                           0x02
#define KLEC2                           0x04
#define KLEC3                           0x08
#define LCK1                            0x10
#define LCK2                            0x20
#define K_LCK_EN                        0x40

// Key Event Register A
#define TCA8418_KEY_EVENT_A_REG         0x04
#define KEA0                            0x01
#define KEA1                            0x02
#define KEA2                            0x04
#define KEA3                            0x08
#define KEA4                            0x10
#define KEA5                            0x20
#define KEA6                            0x40
#define KEA7                            0x80

// Key Event Register B
#define TCA8418_KEY_EVENT_B_REG         0x05
#define KEB0                            0x01
#define KEB1                            0x02
#define KEB2                            0x04
#define KEB3                            0x08
#define KEB4                            0x10
#define KEB5                            0x20
#define KEB6                            0x40
#define KEB7                            0x80

// Key Event Register C
#define TCA8418_KEY_EVENT_C_REG         0x06
#define KEC0                            0x01
#define KEC1                            0x02
#define KEC2                            0x04
#define KEC3                            0x08
#define KEC4                            0x10
#define KEC5                            0x20
#define KEC6                            0x40
#define KEC7                            0x80

// Key Event Register D
#define TCA8418_KEY_EVENT_D_REG         0x07
#define KED0                            0x01
#define KED1                            0x02
#define KED2                            0x04
#define KED3                            0x08
#define KED4                            0x10
#define KED5                            0x20
#define KED6                            0x40
#define KED7                            0x80

// Key Event Register E
#define TCA8418_KEY_EVENT_E_REG         0x08
#define KEE0                            0x01
#define KEE1                            0x02
#define KEE2                            0x04
#define KEE3                            0x08
#define KEE4                            0x10
#define KEE5                            0x20
#define KEE6                            0x40
#define KEE7                            0x80

// Key Event Register F
#define TCA8418_KEY_EVENT_F_REG         0x09
#define KEF0                            0x01
#define KEF1                            0x02
#define KEF2                            0x04
#define KEF3                            0x08
#define KEF4                            0x10
#define KEF5                            0x20
#define KEF6                            0x40
#define KEF7                            0x80

// Key Event Register G
#define TCA8418_KEY_EVENT_G_REG         0x0A
#define KEG0                            0x01
#define KEG1                            0x02
#define KEG2                            0x04
#define KEG3                            0x08
#define KEG4                            0x10
#define KEG5                            0x20
#define KEG6                            0x40
#define KEG7                            0x80

// Key Event Register H
#define TCA8418_KEY_EVENT_H_REG         0x0B
#define KEH0                            0x01
#define KEH1                            0x02
#define KEH2                            0x04
#define KEH3                            0x08
#define KEH4                            0x10
#define KEH5                            0x20
#define KEH6                            0x40
#define KEH7                            0x80

// Key Event Register I
#define TCA8418_KEY_EVENT_I_REG         0x0C
#define KEI0                            0x01
#define KEI1                            0x02
#define KEI2                            0x04
#define KEI3                            0x08
#define KEI4                            0x10
#define KEI5                            0x20
#define KEI6                            0x40
#define KEI7                            0x80

// Key Event Register J
#define TCA8418_KEY_EVENT_J_REG         0x0D
#define KEJ0                            0x01
#define KEJ1                            0x02
#define KEJ2                            0x04
#define KEJ3                            0x08
#define KEJ4                            0x10
#define KEJ5                            0x20
#define KEJ6                            0x40
#define KEJ7                            0x80

// Keypad lock 1  to lock 2 timer [KL7, KL6, KL5, KL4, KL3, KL2, KL1, KL0]
#define TCA8418_KP_LCK_TIMER_REG        0x0E
#define LOCK_TIMER_KL0                  0x01
#define LOCK_TIMER_KL1                  0x02
#define LOCK_TIMER_KL2                  0x04
#define LOCK_TIMER_KL3                  0x08
#define LOCK_TIMER_KL4                  0x10
#define LOCK_TIMER_KL5                  0x20
#define LOCK_TIMER_KL6                  0x40
#define LOCK_TIMER_KL7                  0x80

// Unlock Key 1 [UK1_7, UK1_6, UK1_5, UK1_4, UK1_3, UK1_2, UK1_1, UK1_0]
#define TCA8418_UNLOCK1_REG             0x0F
// Unlock Key 2 [UK2_7, UK2_6, UK2_5, UK2_4, UK2_3, UK2_2, UK2_1, UK2_0]
#define TCA8418_UNLOCK2_REG             0x10
#define UNLOCK_UK0                      0x01
#define UNLOCK_UK1                      0x02
#define UNLOCK_UK2                      0x04
#define UNLOCK_UK3                      0x08
#define UNLOCK_UK4                      0x10
#define UNLOCK_UK5                      0x20
#define UNLOCK_UK6                      0x40
#define UNLOCK_UK7                      0x80

// GPIO Interrupt Status [R7DS, R6DS, R5DS, R4DS, R3DS, R2DS, R1DS, R0DS]
#define TCA8418_GPIO_INT_STAT1_REG      0x11
// GPIO Interrupt Status [C7IS, C6IS, C5IS, C4IS, C3IS, C2IS, C1IS, C0IS]
#define TCA8418_GPIO_INT_STAT2_REG      0x12
// GPIO Interrupt Status [  NA,   NA,   NA,   NA,   NA,   NA, C9IS, C8IS]
#define TCA8418_GPIO_INT_STAT3_REG      0x13
#define INT_STATUS_R0IS                0x01
#define INT_STATUS_R1IS                0x02
#define INT_STATUS_R2IS                0x04
#define INT_STATUS_R3IS                0x08
#define INT_STATUS_R4IS                0x10
#define INT_STATUS_R5IS                0x20
#define INT_STATUS_R6IS                0x40
#define INT_STATUS_R7IS                0x80
#define INT_STATUS_C0IS                0x01
#define INT_STATUS_C1IS                0x02
#define INT_STATUS_C2IS                0x04
#define INT_STATUS_C3IS                0x08
#define INT_STATUS_C4IS                0x10
#define INT_STATUS_C5IS                0x20
#define INT_STATUS_C6IS                0x40
#define INT_STATUS_C7IS                0x80
#define INT_STATUS_C8IS                0x01
#define INT_STATUS_C9IS                0x02

// GPIO Data Status [R7DS, R6DS, R5DS, R4DS, R3DS, R2DS, R1DS, R0DS]
#define TCA8418_GPIO_DAT_STAT1_REG      0x14
// GPIO Data Status [C7DS, C6DS, C5DS, C4DS, C3DS, C2DS, C1DS, C0DS]
#define TCA8418_GPIO_DAT_STAT2_REG      0x15
// GPIO Data Status [  NA,   NA,   NA,   NA,   NA,   NA, C9DS, C8DS]
#define TCA8418_GPIO_DAT_STAT3_REG      0x16
#define DATA_STATUS_R0DS                0x01
#define DATA_STATUS_R1DS                0x02
#define DATA_STATUS_R2DS                0x04
#define DATA_STATUS_R3DS                0x08
#define DATA_STATUS_R4DS                0x10
#define DATA_STATUS_R5DS                0x20
#define DATA_STATUS_R6DS                0x40
#define DATA_STATUS_R7DS                0x80
#define DATA_STATUS_C0DS                0x01
#define DATA_STATUS_C1DS                0x02
#define DATA_STATUS_C2DS                0x04
#define DATA_STATUS_C3DS                0x08
#define DATA_STATUS_C4DS                0x10
#define DATA_STATUS_C5DS                0x20
#define DATA_STATUS_C6DS                0x40
#define DATA_STATUS_C7DS                0x80
#define DATA_STATUS_C8DS                0x01
#define DATA_STATUS_C9DS                0x02

// GPIO Data Out [R7DO, R6DO, R5DO, R4DO, R3DO, R2DO, R1DO, R0DO]
#define TCA8418_GPIO_DAT_OUT1_REG       0x17
// GPIO Data Out [C7DO, C6DO, C5DO, C4DO, C3DO, C2DO, C1DO, C0DO]
#define TCA8418_GPIO_DAT_OUT2_REG       0x18
// GPIO Data Out [  NA,   NA,   NA,   NA,   NA,   NA, C9DO, C8DO]
#define TCA8418_GPIO_DAT_OUT3_REG       0x19
#define DATA_OUT_R0DO                   0x01
#define DATA_OUT_R1DO                   0x02
#define DATA_OUT_R2DO                   0x04
#define DATA_OUT_R3DO                   0x08
#define DATA_OUT_R4DO                   0x10
#define DATA_OUT_R5DO                   0x20
#define DATA_OUT_R6DO                   0x40
#define DATA_OUT_R7DO                   0x80
#define DATA_OUT_C0DO                   0x01
#define DATA_OUT_C1DO                   0x02
#define DATA_OUT_C2DO                   0x04
#define DATA_OUT_C3DO                   0x08
#define DATA_OUT_C4DO                   0x10
#define DATA_OUT_C5DO                   0x20
#define DATA_OUT_C6DO                   0x40
#define DATA_OUT_C7DO                   0x80
#define DATA_OUT_C8DO                   0x01
#define DATA_OUT_C9DO                   0x02

// GPIO Interrupt enable () [R7IE, R6IE, R5IE, R4IE, R3IE, R2IE, R1IE, R0IE]
#define TCA8418_GPIO_INT_EN1_REG        0x1A
// GPIO Interrupt enable () [C7IE, C6IE, C5IE, C4IE, C3IE, C2IE, C1IE, C0IE]
#define TCA8418_GPIO_INT_EN2_REG        0x1B
// GPIO Interrupt enable () [  NA,   NA,   NA,   NA,   NA,   NA, C9IE, C8IE]
#define TCA8418_GPIO_INT_EN3_REG        0x1C
#define GPIO_INT_R0IE                   0x01
#define GPIO_INT_R1IE                   0x02
#define GPIO_INT_R2IE                   0x04
#define GPIO_INT_R3IE                   0x08
#define GPIO_INT_R4IE                   0x10
#define GPIO_INT_R5IE                   0x20
#define GPIO_INT_R6IE                   0x40
#define GPIO_INT_R7IE                   0x80
#define GPIO_INT_C0IE                   0x01
#define GPIO_INT_C1IE                   0x02
#define GPIO_INT_C2IE                   0x04
#define GPIO_INT_C3IE                   0x08
#define GPIO_INT_C4IE                   0x10
#define GPIO_INT_C5IE                   0x20
#define GPIO_INT_C6IE                   0x40
#define GPIO_INT_C7IE                   0x80
#define GPIO_INT_C8IE                   0x01
#define GPIO_INT_C9IE                   0x02

// Keypad or GPIO selection (0: GPIO, 1: Keypad matrix) [ROW7, ROW6, ROW5, ROW4, ROW3, ROW2, ROW1, ROW0]
#define TCA8418_KP_GPIO1_REG            0x1D
// Keypad or GPIO selection (0: GPIO, 1: Keypad matrix) [COL7, COL6, COL5, COL4, COL3, COL2, COL1, COL0]
#define TCA8418_KP_GPIO2_REG            0x1E
// Keypad or GPIO selection (0: GPIO, 1: Keypad matrix) [  NA,   NA,   NA,   NA,   NA,   NA, COL9, COL8]
#define TCA8418_KP_GPIO3_REG            0x1F
#define KP_GPIO_ROW0                 0x01
#define KP_GPIO_ROW1                 0x02
#define KP_GPIO_ROW2                 0x04
#define KP_GPIO_ROW3                 0x08
#define KP_GPIO_ROW4                 0x10
#define KP_GPIO_ROW5                 0x20
#define KP_GPIO_ROW6                 0x40
#define KP_GPIO_ROW7                 0x80
#define KP_GPIO_COL0                 0x01
#define KP_GPIO_COL1                 0x02
#define KP_GPIO_COL2                 0x04
#define KP_GPIO_COL3                 0x08
#define KP_GPIO_COL4                 0x10
#define KP_GPIO_COL5                 0x20
#define KP_GPIO_COL6                 0x40
#define KP_GPIO_COL7                 0x80
#define KP_GPIO_COL8                 0x01
#define KP_GPIO_COL9                 0x02

// GPI Event Mode () [ROW7, ROW6, ROW5, ROW4, ROW3, ROW2, ROW1, ROW0]
#define TCA8418_GPI_EM1_REG             0x20
// GPI Event Mode () [COL7, COL6, COL5, COL4, COL3, COL2, COL1, COL0]
#define TCA8418_GPI_EM2_REG             0x21
// GPI Event Mode () [  NA,   NA,   NA,   NA,   NA,   NA, COL9, COL8]
#define TCA8418_GPI_EM3_REG             0x22
#define EVENT_MODE_ROW0                 0x01
#define EVENT_MODE_ROW1                 0x02
#define EVENT_MODE_ROW2                 0x04
#define EVENT_MODE_ROW3                 0x08
#define EVENT_MODE_ROW4                 0x10
#define EVENT_MODE_ROW5                 0x20
#define EVENT_MODE_ROW6                 0x40
#define EVENT_MODE_ROW7                 0x80
#define EVENT_MODE_COL0                 0x01
#define EVENT_MODE_COL1                 0x02
#define EVENT_MODE_COL2                 0x04
#define EVENT_MODE_COL3                 0x08
#define EVENT_MODE_COL4                 0x10
#define EVENT_MODE_COL5                 0x20
#define EVENT_MODE_COL6                 0x40
#define EVENT_MODE_COL7                 0x80
#define EVENT_MODE_COL8                 0x01
#define EVENT_MODE_COL9                 0x02

// GPIO Data Direction (0: Input, 1: Output) [R7DD, R6DD, R5DD, R4DD, R3DD, R2DD, R1DD, R0DD]
#define TCA8418_GPIO_DIR1_REG           0x23
// GPIO Data Direction (0: Input, 1: Output) [C7DD, C6DD, C5DD, C4DD, C3DD, C2DD, C1DD, C0DD]
#define TCA8418_GPIO_DIR2_REG           0x24
// GPIO Data Direction (0: Input, 1: Output) [  NA,   NA,   NA,   NA,   NA,   NA, C9DD, C8DD]
#define TCA8418_GPIO_DIR3_REG           0x25
#define DATA_DIR_R0DD                   0x01
#define DATA_DIR_R1DD                   0x02
#define DATA_DIR_R2DD                   0x04
#define DATA_DIR_R3DD                   0x08
#define DATA_DIR_R4DD                   0x10
#define DATA_DIR_R5DD                   0x20
#define DATA_DIR_R6DD                   0x40
#define DATA_DIR_R7DD                   0x80
#define DATA_DIR_C0DD                   0x01
#define DATA_DIR_C1DD                   0x02
#define DATA_DIR_C2DD                   0x04
#define DATA_DIR_C3DD                   0x08
#define DATA_DIR_C4DD                   0x10
#define DATA_DIR_C5DD                   0x20
#define DATA_DIR_C6DD                   0x40
#define DATA_DIR_C7DD                   0x80
#define DATA_DIR_C8DD                   0x01
#define DATA_DIR_C9DD                   0x02

// GPIO Edge / Level Detect (0: Falling/Low, 1: Rising/High) [R7IL, R6IL, R5IL, R4IL, R3IL, R2IL, R1IL, R0IL]
#define TCA8418_GPIO_INT_LVL1_REG       0x26
// GPIO Edge / Level Detect (0: Falling/Low, 1: Rising/High) [C7IL, C6IL, C5IL, C4IL, C3IL, C2IL, C1IL, C0IL]
#define TCA8418_GPIO_INT_LVL2_REG       0x27
// GPIO Edge / Level Detect (0: Falling/Low, 1: Rising/High) [  NA,   NA,   NA,   NA,   NA,   NA, C9IL, C8IL]
#define TCA8418_GPIO_INT_LVL3_REG       0x28
#define INT_LVL_R0IL                    0x01
#define INT_LVL_R1IL                    0x02
#define INT_LVL_R2IL                    0x04
#define INT_LVL_R3IL                    0x08
#define INT_LVL_R4IL                    0x10
#define INT_LVL_R5IL                    0x20
#define INT_LVL_R6IL                    0x40
#define INT_LVL_R7IL                    0x80
#define INT_LVL_C0IL                    0x01
#define INT_LVL_C1IL                    0x02
#define INT_LVL_C2IL                    0x04
#define INT_LVL_C3IL                    0x08
#define INT_LVL_C4IL                    0x10
#define INT_LVL_C5IL                    0x20
#define INT_LVL_C6IL                    0x40
#define INT_LVL_C7IL                    0x80
#define INT_LVL_C8IL                    0x01
#define INT_LVL_C9IL                    0x02

// Debounce disable (0: debounce enabled) [R7DD, R6DD, R5DD, R4DD, R3DD, R2DD, R1DD, R0DD]
#define TCA8418_DEBOUNCE_DIS1_REG       0x29
// Debounce disable (0: debounce enabled) [C7DD, C6DD, C5DD, C4DD, C3DD, C2DD, C1DD, C0DD]
#define TCA8418_DEBOUNCE_DIS2_REG       0x2A
// Debounce disable (0: debounce enabled) [  NA,   NA,   NA,   NA,   NA,   NA, C9DD, C8DD]
#define TCA8418_DEBOUNCE_DIS3_REG       0x2B
#define DEBOUNCE_DIS_R0DD               0x01
#define DEBOUNCE_DIS_R1DD               0x02
#define DEBOUNCE_DIS_R2DD               0x04
#define DEBOUNCE_DIS_R3DD               0x08
#define DEBOUNCE_DIS_R4DD               0x10
#define DEBOUNCE_DIS_R5DD               0x20
#define DEBOUNCE_DIS_R6DD               0x40
#define DEBOUNCE_DIS_R7DD               0x80
#define DEBOUNCE_DIS_C0DD               0x01
#define DEBOUNCE_DIS_C1DD               0x02
#define DEBOUNCE_DIS_C2DD               0x04
#define DEBOUNCE_DIS_C3DD               0x08
#define DEBOUNCE_DIS_C4DD               0x10
#define DEBOUNCE_DIS_C5DD               0x20
#define DEBOUNCE_DIS_C6DD               0x40
#define DEBOUNCE_DIS_C7DD               0x80
#define DEBOUNCE_DIS_C8DD               0x01
#define DEBOUNCE_DIS_C9DD               0x02

// GPIO Pull-UP disable (0: pull-up enabled) [R7PD, R6PD, R5PD, R4PD, R3PD, R2PD, R1PD, R0PD]
#define TCA8418_GPIO_PULL1_REG          0x2C
// GPIO Pull-UP disable (0: pull-up enabled) [C7PD, C6PD, C5PD, C4PD, C3PD, C2PD, C1PD, C0PD]
#define TCA8418_GPIO_PULL2_REG          0x2D
// GPIO Pull-UP disable (0: pull-up enabled) [  NA,   NA,   NA,   NA,   NA,   NA, C9PD, C8PD]
#define TCA8418_GPIO_PULL3_REG          0x2E
#define GPIO_PULL_R0PD                  0x01
#define GPIO_PULL_R1PD                  0x02
#define GPIO_PULL_R2PD                  0x04
#define GPIO_PULL_R3PD                  0x08
#define GPIO_PULL_R4PD                  0x10
#define GPIO_PULL_R5PD                  0x20
#define GPIO_PULL_R6PD                  0x40
#define GPIO_PULL_R7PD                  0x80
#define GPIO_PULL_C0PD                  0x01
#define GPIO_PULL_C1PD                  0x02
#define GPIO_PULL_C2PD                  0x04
#define GPIO_PULL_C3PD                  0x08
#define GPIO_PULL_C4PD                  0x10
#define GPIO_PULL_C5PD                  0x20
#define GPIO_PULL_C6PD                  0x40
#define GPIO_PULL_C7PD                  0x80
#define GPIO_PULL_C8PD                  0x01
#define GPIO_PULL_C9PD                  0x02


#endif  // _TCA8418_REG_H_