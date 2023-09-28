//****************************************************************************
// @Module        General Purpose Timer Unit (GPT2)
// @Filename      GPT2.C
// @Project       Motorsteuerung.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Tasking Classic
//
// @Codegenerator 2.2
//
// @Description   This file contains functions that use the GPT2 module.
//
//----------------------------------------------------------------------------
// @Date          9/28/2023 11:34:05
//
//****************************************************************************

// USER CODE BEGIN (GPT2_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (GPT2_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (GPT2_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (GPT2_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (GPT2_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT2_General,6)
   extern unsigned int omega_el;
   extern unsigned int counter;
   extern unsigned int trajectory;
// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT2_General,7)
   unsigned int increments = 0;
// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (GPT2_General,8)

// USER CODE END



//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (GPT2_General,9)

// USER CODE END


//****************************************************************************
// @Function      void GPT2_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the GPT2 function 
//                library. It is assumed that the SFRs used by this library 
//                are in reset state. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          9/28/2023
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void GPT2_vInit(void)
{

  // USER CODE BEGIN (Init,2)

  // USER CODE END
  ///  -----------------------------------------------------------------------
  ///  Configuration of Timer Block Prescaler 1:
  ///  -----------------------------------------------------------------------
  GPT12E_KSCCFG  =  0x0003;      // Module Enable


  _nop();  // one cycle delay 

  _nop();  // one cycle delay 


  ///  -----------------------------------------------------------------------
  ///  Configuration of Timer Block Prescaler 2:
  ///  -----------------------------------------------------------------------
  ///  - prescaler for timer block 2 is 16


  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT2 Core Timer 5:
  ///  -----------------------------------------------------------------------
  ///  - timer 5 works in timer mode
  ///  - prescaler factor is 16
  ///  - up/down control bit is reset
  ///  - external up/down control is disabled
  ///  - timer 5 run bit is reset
  ///  - timer 5 remote control is disabled

  GPT12E_T5CON   =  0x0000;      // load timer 5 control register
  GPT12E_T5      =  0x0000;      // load timer 5 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT2 Core Timer 6:
  ///  -----------------------------------------------------------------------
  ///  - timer 6 works in timer mode
  ///  - prescaler factor is 256
  ///  - up/down control bit is set
  ///  - external up/down control is disabled
  ///  - alternate output function T6OUT (P6.2) is disabled
  ///  - alternate output function T6OUT (P7.0) is disabled
  ///  - timer 6 output toggle latch (T6OTL) is set to 0
  ///  - timer 6 run bit is reset
  ///  - timer 6 is not cleared on a capture

  GPT12E_T6CON   =  0x1084;      // load timer 6 control register
  GPT12E_T6      =  0x07EE;      // load timer 6 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT2 CAPREL:
  ///  -----------------------------------------------------------------------
  ///  - capture T5 into CAPREL is disabled
  ///  - capture trigger from pin CAPIN
  ///  - capure is disabled
  ///  - timer 5 is not cleared on a capture
  ///  - timer 5 is just captured without any correction

  GPT12E_T5CON  |=  0x0000;      // load timer 5 control register
  GPT12E_CAPREL  =  0x0000;      // load CAPREL register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used GPT2 Port Pins:
  ///  -----------------------------------------------------------------------


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used GPT2 Interrupts:
  ///  -----------------------------------------------------------------------
  ///  timer 6 service request node configuration:
  ///  - timer 6 interrupt priority level (ILVL) = 3
  ///  - timer 6 interrupt group level (GLVL) = 0
  ///  - timer 6 group priority extension (GPX) = 0

  GPT12E_T6IC    =  0x004C;     



  // USER CODE BEGIN (GPT2_Function,3)

  // USER CODE END

} //  End of function GPT2_viCAPREL

//****************************************************************************
// @Function      void GPT2_viTmr6(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the GPT2 timer 6. 
//                It is called up in the case of over or underflow of the 
//                timer 6 register.
//                
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          9/28/2023
//
//****************************************************************************

// USER CODE BEGIN (Tmr6,1)

// USER CODE END

_interrupt(T6INT)  void GPT2_viTmr6(void)
{
  // USER CODE BEGIN (Tmr6,2)
  GPT1_vStopTmr(GPT1_TIMER_4);
  increments = GPT1_uwReadTmr(GPT1_TIMER_4);	 	//Incremental-Zähler (T4) auslesen	
  GPT1_vClearTmr(GPT1_TIMER_4);
  GPT1_vStartTmr(GPT1_TIMER_4);
  GPT2_vLoadTmr(GPT2_TIMER_6, TIMER_T6_PERIOD);		//Zeitbasis 8ms (während der Inkremente gezählt werden)
  omega_el = (increments*TIMER_T6_PERIOD_INVERS)/INCREMENTS_PR_HALF;	// f = n*p; n = Inkremente/(Inkremente_pro_Runde*Zeitbasis); p = 2
  if(counter >= 500 && trajectory < CONTROL){
		trajectory++;		// alle 500*8ms = 4s Trajektorie weiterschalten
		counter=0;
	}
  if(trajectory != CONTROL){
	counter++;
  }
  // USER CODE END

} //  End of function GPT2_viTmr6




// USER CODE BEGIN (GPT2_General,10)

// USER CODE END

