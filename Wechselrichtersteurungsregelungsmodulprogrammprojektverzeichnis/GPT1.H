//****************************************************************************
// @Module        General Purpose Timer Unit (GPT1)
// @Filename      GPT1.H
// @Project       Motorsteuerung.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Tasking Classic
//
// @Codegenerator 2.2
//
// @Description   This file contains all function prototypes and macros for 
//                the GPT1 module.
//
//----------------------------------------------------------------------------
// @Date          9/28/2023 11:34:05
//
//****************************************************************************

// USER CODE BEGIN (GPT1_Header,1)

// USER CODE END



#ifndef _GPT1_H_
#define _GPT1_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (GPT1_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (GPT1_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   This parameter identifies GPT1 timer 2
#define GPT1_TIMER_2 2

//   This parameter identifies GPT1 timer 3
#define GPT1_TIMER_3 3

//   This parameter identifies GPT1 timer 4
#define GPT1_TIMER_4 4


// USER CODE BEGIN (GPT1_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (GPT1_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT1_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT1_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void GPT1_vInit(void);


// USER CODE BEGIN (GPT1_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         GPT1_vStartTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro starts the selected GPT1 timer. The timer 
//                continues to count from where it had stopped. The following 
//                definitions are available for TimerNr:
//                GPT1_TIMER_2
//                GPT1_TIMER_3
//                GPT1_TIMER_4
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                the name of the timer to be started
//
//----------------------------------------------------------------------------
// @Date          9/28/2023
//
//****************************************************************************

#define GPT1_vStartTmr(TimerNr) GPT1_vStartTmr_##TimerNr()
#define GPT1_vStartTmr_GPT1_TIMER_2() GPT12E_T2CON_T2R = 1
#define GPT1_vStartTmr_GPT1_TIMER_3() GPT12E_T3CON_T3R = 1
#define GPT1_vStartTmr_GPT1_TIMER_4() GPT12E_T4CON_T4R = 1


//****************************************************************************
// @Macro         GPT1_vStopTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected GPT1 timer. The contents of 
//                the timer register remain unchanged. The remote control of 
//                the selected timer is cleared. The following definitions 
//                are available for TimerNr:
//                GPT1_TIMER_2
//                GPT1_TIMER_3
//                GPT1_TIMER_4
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                The name of the timer to be stopped
//
//----------------------------------------------------------------------------
// @Date          9/28/2023
//
//****************************************************************************

#define GPT1_vStopTmr(TimerNr) GPT1_vStopTmr_##TimerNr()
#define GPT1_vStopTmr_GPT1_TIMER_2() GPT12E_T2CON_T2R = 0; GPT12E_T2CON_T2RC = 0
#define GPT1_vStopTmr_GPT1_TIMER_3() GPT12E_T3CON_T3R = 0
#define GPT1_vStopTmr_GPT1_TIMER_4() GPT12E_T4CON_T4R = 0; GPT12E_T4CON_T4RC = 0


//****************************************************************************
// @Macro         GPT1_vClearTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected GPT1 timer and sets the timer 
//                register to 0. The remote control of the selected timer is 
//                cleared. The following definitions are available for 
//                TimerNr:
//                GPT1_TIMER_2
//                GPT1_TIMER_3
//                GPT1_TIMER_4
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                The name of the timer to be cleared
//
//----------------------------------------------------------------------------
// @Date          9/28/2023
//
//****************************************************************************

#define GPT1_vClearTmr(TimerNr) GPT1_vClearTmr_##TimerNr()
#define GPT1_vClearTmr_GPT1_TIMER_2() GPT12E_T2CON_T2R = 0; GPT12E_T2 = 0x0000; GPT12E_T2CON_T2RC = 0
#define GPT1_vClearTmr_GPT1_TIMER_3() GPT12E_T3CON_T3R = 0; GPT12E_T3 = 0x0000
#define GPT1_vClearTmr_GPT1_TIMER_4() GPT12E_T4CON_T4R = 0; GPT12E_T4 = 0x0000; GPT12E_T4CON_T4RC = 0


//****************************************************************************
// @Macro         GPT1_uwReadTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the contents of the selected GPT1 timer. 
//                The timer is not stopped. Access of the CPU to the 
//                registers of the timer is of higher priority than a timer 
//                increment, a reload or a capture event. The following 
//                definitions are available for TimerNr:
//                GPT1_TIMER_2
//                GPT1_TIMER_3
//                GPT1_TIMER_4
//
//----------------------------------------------------------------------------
// @Returnvalue   Current 16-bit value of the timer
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                The name of the timer to be readed
//
//----------------------------------------------------------------------------
// @Date          9/28/2023
//
//****************************************************************************

#define GPT1_uwReadTmr(TimerNr) GPT1_uwReadTmr_##TimerNr()
#define GPT1_uwReadTmr_GPT1_TIMER_2() GPT12E_T2
#define GPT1_uwReadTmr_GPT1_TIMER_3() GPT12E_T3
#define GPT1_uwReadTmr_GPT1_TIMER_4() GPT12E_T4


//****************************************************************************
// @Macro         GPT1_vLoadTmr(TimerNr, Value) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the selected GPT1 timer with the forwarded 
//                value. The timer is not stopped. The access of the CPU to 
//                the registers of the timers is of higher priority than a 
//                timer increment, a reload or a capture event. The following 
//                definitions are available for TimerNr:
//                GPT1_TIMER_2
//                GPT1_TIMER_3
//                GPT1_TIMER_4
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                The name of the timer to be loaded
// @Parameters    Value: 
//                16-bit value to be loaded
//
//----------------------------------------------------------------------------
// @Date          9/28/2023
//
//****************************************************************************

#define GPT1_vLoadTmr(TimerNr, Value) GPT1_vLoadTmr_##TimerNr(Value)
#define GPT1_vLoadTmr_GPT1_TIMER_2(Value) GPT12E_T2 = Value
#define GPT1_vLoadTmr_GPT1_TIMER_3(Value) GPT12E_T3 = Value
#define GPT1_vLoadTmr_GPT1_TIMER_4(Value) GPT12E_T4 = Value


//****************************************************************************
// @Macro         GPT1_vCountUp(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro sets the counter direction of the selected timer 
//                to up. The timer is not stopped.
//                Note:
//                Concerning timer x it is possible to make the counter 
//                direction dependent on the level at TxEUD. If this 
//                functionality has been selected, then function 
//                GPT1_vCountUp() set a  0 at TxEUD enabling counting up of 
//                timer x and a 1 at TxEUD enabling counting down of timer x. 
//                The following definitions are available for TimerNr:
//                GPT1_TIMER_2
//                GPT1_TIMER_3
//                GPT1_TIMER_4
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                The name of the timer to be used
//
//----------------------------------------------------------------------------
// @Date          9/28/2023
//
//****************************************************************************

#define GPT1_vCountUp(TimerNr) GPT1_vCountUp_##TimerNr()
#define GPT1_vCountUp_GPT1_TIMER_2() GPT12E_T2CON_T2UD = 0
#define GPT1_vCountUp_GPT1_TIMER_3() GPT12E_T3CON_T3UD = 0
#define GPT1_vCountUp_GPT1_TIMER_4() GPT12E_T4CON_T4UD = 0


//****************************************************************************
// @Macro         GPT1_vCountDown(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro sets the counter direction of the selected timer 
//                to down. The timer is not stopped.
//                Note:
//                Concerning timer x it is possible to make the counter 
//                direction dependent on the level at TxEUD. If this 
//                functionality has been selected, then function 
//                GPT1_vCountDown() set a 0 at TxEUD enabling counting down 
//                of timer x and a 1 at TxEUD enabling counting up of timer 
//                x. The following definitions are available for TimerNr:
//                GPT1_TIMER_2
//                GPT1_TIMER_3
//                GPT1_TIMER_4
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                The name of the timer to be used
//
//----------------------------------------------------------------------------
// @Date          9/28/2023
//
//****************************************************************************

#define GPT1_vCountDown(TimerNr) GPT1_vCountDown_##TimerNr()
#define GPT1_vCountDown_GPT1_TIMER_2() GPT12E_T2CON_T2UD = 1
#define GPT1_vCountDown_GPT1_TIMER_3() GPT12E_T3CON_T3UD = 1
#define GPT1_vCountDown_GPT1_TIMER_4() GPT12E_T4CON_T4UD = 1


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define T2INT 0x20
#define T3INT 0x21

// USER CODE BEGIN (GPT1_Header,9)

// USER CODE END


#endif  // ifndef _GPT1_H_
