//****************************************************************************
// @Module        Parallel Ports
// @Filename      IO.C
// @Project       Motorsteuerung.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Tasking Classic
//
// @Codegenerator 2.2
//
// @Description   This file contains functions that use the IO module.
//
//----------------------------------------------------------------------------
// @Date          9/28/2023 11:34:04
//
//****************************************************************************

// USER CODE BEGIN (IO_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (IO_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (IO_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (IO_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (IO_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (IO_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (IO_General,9)

// USER CODE END


//****************************************************************************
// @Function      void IO_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the IO function 
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

// USER CODE BEGIN (IO_Function,1)

// USER CODE END

void IO_vInit(void)
{
  // USER CODE BEGIN (IO_Function,2)

  // USER CODE END


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P0:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P0 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P1:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P1 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P2:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P2 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P3:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P3 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P4:
  ///  -----------------------------------------------------------------------
  ///  P4.6 is used as alternate input for the GPT12E  timer4Count input(T4IN)

  ///  P4.0 - P4.3 output driver characteristic: strong driver
  ///  P4.4 - P4.7 output driver characteristic: strong driver

  ///  P4.0 - P4.3 output edge characteristic: sharp edge mode
  ///  P4.4 - P4.7 output edge characteristic: sharp edge mode


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P5:
  ///  -----------------------------------------------------------------------
  ///  P5.6 is used as alternate input for the  Analog Input Pin (AN56)


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P6:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P6 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P7:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P7 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P8:
  ///  -----------------------------------------------------------------------
  ///  P8.0 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P8.1 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level

  ///  P8.0 - P8.3 output driver characteristic: strong driver
  ///  P8.4 - P8.6 output driver characteristic: strong driver

  ///  P8.0 - P8.3 output edge characteristic: sharp edge mode
  ///  P8.4 - P8.6 output edge characteristic: sharp edge mode

  P8_IOCR00      =  0x0080;      // load port control register 0
  P8_IOCR01      =  0x0080;      // load port control register 1

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P9:
  ///  -----------------------------------------------------------------------
  ///  P9.0 is used as alternate output for the CCU63 output(CC60)
  ///  - push/pull output is selected
  ///  P9.1 is used as alternate output for the CCU63 output(CC61)
  ///  - push/pull output is selected
  ///  P9.2 is used as alternate output for the CCU63 output(CC62)
  ///  - push/pull output is selected
  ///  P9.3 is used as alternate output for the CCU63 output(COUT60)
  ///  - push/pull output is selected
  ///  P9.4 is used as alternate output for the CCU63 output(COUT61)
  ///  - push/pull output is selected
  ///  P9.5 is used as alternate output for the CCU63 output(COUT62)
  ///  - push/pull output is selected

  ///  P9.0 - P9.3 output driver characteristic: strong driver
  ///  P9.4 - P9.7 output driver characteristic: strong driver

  ///  P9.0 - P9.3 output edge characteristic: sharp edge mode
  ///  P9.4 - P9.7 output edge characteristic: sharp edge mode


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P10:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P10 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P11:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P11 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P15:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P15 is used
  ///  - Port15 Data register P15(Read only)



  // USER CODE BEGIN (IO_Function,3)

  // USER CODE END

} //  End of function IO_vInit




// USER CODE BEGIN (IO_General,10)

// USER CODE END

