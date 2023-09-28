//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.C
// @Project       Motorsteuerung.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Tasking Classic
//
// @Codegenerator 2.2
//
// @Description   This file contains the project initialization function.
//
//----------------------------------------------------------------------------
// @Date          9/28/2023 11:34:01
//
//****************************************************************************

// USER CODE BEGIN (MAIN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (MAIN_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (MAIN_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,7)
   unsigned int OUTPUT_FREQUENCY = 0;			// Sinusfrequenz Startwert
   long int sinsuTableLongInt[TABLE_SIZE];
   long int TYLER = 100000;
   long int sinus[] = {0, 0, 0};
   long int sinusOffset = 0;
   unsigned int u_car = 1;
   unsigned int sinusTimerPeriod = 0xFB3D;
   unsigned int triangle_period = 0x06FA;	   
   unsigned int amplitude = 1;
   unsigned int f_target = 0;
   unsigned int newFrequency = 0;
   unsigned int direction = 0;			// 0: rechtslauf, 1: linkslauf

   unsigned int resultADC = 0;
   unsigned int readADC = 0;

   unsigned int DC_brake = 0;
   
   unsigned int omega_el = 0;
   
   int y_I_k_minus1 = 0;
   int e_k_minus1 = 0;

   unsigned int counter = 0;
   unsigned int trajectory = 0;
// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (MAIN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (MAIN_General,9)
   void generateSinus();
   //unsigned int measuredFrequency();
   unsigned int calculateTrianglePeriod(unsigned int frequency);
   unsigned int calculateNewFrequency(unsigned int ADC_value);
   unsigned int calculateTimerPeriod(unsigned int frequency);
   unsigned int calculateAmplitude(unsigned int frequency, unsigned int u_car);
   unsigned int PI_controller(unsigned int f_target, unsigned int f_real);
// USER CODE END


//****************************************************************************
// @Function      void MAIN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This function initializes the microcontroller.
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

void MAIN_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  //   globally disable interrupts
  PSW_IEN        =  0;          


  ///  -----------------------------------------------------------------------
  ///  Configuration of the System Clock:
  ///  -----------------------------------------------------------------------
  ///  - VCO clock used, input clock is connected
  ///  - input frequency is 10.00 MHz
  ///  - configured system frequency is 66.00 MHz

  MAIN_vUnlockProtecReg();     // unlock write security

  MAIN_vChangeFreq();          // load PLL control register

  //   -----------------------------------------------------------------------
  //   Initialization of the Peripherals:
  //   -----------------------------------------------------------------------

  //   initializes the Parallel Ports
  IO_vInit();

  //   initializes the General Purpose Timer Unit (GPT1)
  GPT1_vInit();

  //   initializes the General Purpose Timer Unit (GPT2)
  GPT2_vInit();

  //   initializes the Capture / Compare Unit 63 (CCU63)
  CCU63_vInit();

  //   initializes the Analog / Digital Converter  (ADC0)
  ADC0_vInit();


  //   -----------------------------------------------------------------------
  //   Initialization of the Bank Select registers:
  //   -----------------------------------------------------------------------


  // USER CODE BEGIN (Init,3)

  // USER CODE END

  MAIN_vLockProtecReg();       // lock write security

  //   globally enable interrupts
  PSW_IEN        =  1;          

} //  End of function MAIN_vInit


//****************************************************************************
// @Function      void MAIN_vUnlockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to write one protected 
//                register.
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

// USER CODE BEGIN (UnlockProtecReg,1)

// USER CODE END

void MAIN_vUnlockProtecReg(void)
{
  uword uwPASSWORD;

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCU_SLC = 0x9600 | uwPASSWORD;      // command 2
    SCU_SLC = 0x0000;                   // command 3

} //  End of function MAIN_vUnlockProtecReg


//****************************************************************************
// @Function      void MAIN_vLockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to lock one protected 
//                register.
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

// USER CODE BEGIN (LockProtecReg,1)

// USER CODE END

void MAIN_vLockProtecReg(void)
{
  uword uwPASSWORD;

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCU_SLC = 0x9600 | uwPASSWORD;      // command 2
    SCU_SLC = 0x1800;                   // command 3; new PASSWOR is 0x00

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;
    SCU_SLC = 0x8E00 | uwPASSWORD;      // command 4

} //  End of function MAIN_vLockProtecReg


//****************************************************************************
// @Function      void MAIN_vChangeFreq(void) 
//
//----------------------------------------------------------------------------
// @Description   This function is used to select the external crystal and
//                configure the system frequency to 80Mhz/66Mhz.
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

// USER CODE BEGIN (ChangeFreq,1)

// USER CODE END

void MAIN_vChangeFreq(void)
{
  SCS_SwitchToHighPrecBandgap();

  //For application and internal application resets, the complete PLL configuration could be avoided
  //The entry from application resets and internal application reset is covered in the following differentiation
  //in int/ext clock in lock/unlocked state.

  if  ((SCU_PLLSTAT & 0x0004) == 0x0004)             // fR derived from Internal clock
        {
            //Normal startup state during boot and the clock
            //has to be in the next step configured on the external crystal
            //use XTAL/VCO, count XTAL clock

            SCS_StartXtalOsc(1);                     // Starts the crystal oscillator
            SCS_SwitchSystemClock(1);                // System clock is increased to target speed (80/66 MHz)

        }

  else                                               // fR derived from external crystal clock
        {
            if ((SCU_PLLSTAT & 0x1009) == 0x1009)    // fR derived from external crystal clock + VCO is locked
            {
               //usually after an application reset where clock need not be configured again.
               //check K2/P/N values and decide whether these values have to be adapted based on application needs.
               NOP();
               //usually the PLL losss of Lock TRAP schould be enabled here.
            }
            else                                     //fR derived from external crystal clock + VCO is not locked

            {
               //estimate the K1 value and the current frequency
               //reduce K2/P/N values in steps so that the frequency
               //jumps is limited to 20MHz or factor of 5 whichever is minimum
               NOP();
            }


        }

} //  End of function MAIN_vChangeFreq


//****************************************************************************
// @Function      void main(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
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

// USER CODE BEGIN (Main,1)

// USER CODE END

void main(void)
{
  // USER CODE BEGIN (Main,2)

  // USER CODE END

  MAIN_vInit();

  // USER CODE BEGIN (Main,3)

  ADC0_vStartSeq0ReqChNum(0,0,1,6);
  generateSinus();
  triangle_period = calculateTrianglePeriod(SWITCHING_FREQUENCY);
  CCU63_vSetTmrPeriod(CCU63_TIMER_12, triangle_period);
  CCU63_vEnableShadowTransfer(CCU63_TIMER_12);

  u_car = triangle_period/2;
  sinusOffset = u_car*TYLER;

  amplitude = calculateAmplitude(OUTPUT_FREQUENCY, u_car);
  sinusTimerPeriod = calculateTimerPeriod(OUTPUT_FREQUENCY);



  GPT1_vLoadTmr(GPT1_TIMER_3, sinusTimerPeriod);
  GPT1_vStartTmr(GPT1_TIMER_3);
  GPT1_vStartTmr(GPT1_TIMER_2);
  CCU63_vStartTmr(CCU63_TIMER_12);
  GPT1_vStartTmr(GPT1_TIMER_4);
  GPT2_vStartTmr(GPT2_TIMER_6);

  // USER CODE END

  while(1)
  {	

   // USER CODE BEGIN (Main,4)

    // Unterscheidung der Trajektorienabschnitte und geregeltem Betrieb (Getimed durch T6)
	switch(trajectory){
		case RISING_P:      // Rampe steigend rechtsdrehend
            direction = 0;
            f_target = counter/10;
            newFrequency = f_target;
		break;
        case HOLD_1:        // 4 Sekunden halten
             f_target = 50;
             newFrequency = f_target;
		break;
        case FALLING_P:     // Rampe fallend rechtsdrehend
            f_target = 50 - counter/10;
            newFrequency = f_target;
		break;
        case HOLD_2:        // 80 ms übergang von rechtsdrehend zu links drehend
            if(counter > 10){
                trajectory++;
                counter = 0;
            }
		break;
        case FALLING_N:     // Rampe steigend linksdrehend
            direction = 1;
            f_target = counter/10;
            newFrequency = f_target;
		break;
        case HOLD_3:        // 4 Sekunden halten
            f_target = 50;
            newFrequency = f_target;
		break;
        case RISING_N:      // Rampe fallend linksdrehend
            f_target = 50 - counter/10;
            newFrequency = f_target;
		break;
        case BRAKE:         // 4 Sekunden Gleichstrombremse
            DC_brake = 1;
            GPT1_vStopTmr(GPT1_TIMER_3);
        break;
        case CONTROL:       // Geregelter Modus mit Poti
            direction = 0;
            if(resultADC != readADC){
		        resultADC = readADC;
                f_target = calculateNewFrequency(resultADC);
		        newFrequency = PI_controller(f_target, omega_el);
            }
		break;
	}

   // Berechnen der neuen Interrupt-Zeit (sinusTimerPeriod) des GPT1_T3 und der Amplitude (U/f-Steuerung)
   if(DC_brake == 0){
		sinusTimerPeriod = calculateTimerPeriod(newFrequency);
   		amplitude = calculateAmplitude(newFrequency, u_car);
   }

   // USER CODE END

  }

} //  End of function main



// USER CODE BEGIN (MAIN_General,10)
	// Sinustabelle generieren
   	void generateSinus(){
   		unsigned int n = 0;
		float stepSize = 2*PI/TABLE_SIZE;
   		for(n = 0; n < TABLE_SIZE; n++){
			sinsuTableLongInt[n] = (long int)(TYLER*sin(n*stepSize) + (TYLER/6)* sin(3*n*stepSize));   // 3. Harmonische aufaddiert
   		}
   	}

	//  Registerwert der CCU63 je nach Schaltfrequenz berechnen
	unsigned int calculateTrianglePeriod(unsigned int frequency){
	 		return 1/(frequency*TIMER_STEP_CCU63*2);       // in Rechnung float ok, weil nur bei Initialisierung aufgerufen
	}

    // Registerwert für Sinus Timer berechnen
	unsigned int calculateTimerPeriod(unsigned int frequency){
		return TIMER_STEP_GPT1_INVERS/(frequency*TABLE_SIZE);	//TIMER_STEP_GPT1_INVERS um long int statt float
	}

    // Sollfrequenz aus ADC Wert berechnen
	unsigned int calculateNewFrequency(unsigned int ADC_value){
		unsigned int ADC_offset = 10;
		unsigned int ADC_max = 1000;
		unsigned int f_min = 1;
		unsigned int f_max = 50;

		if(ADC_value <= ADC_offset){				// ADC < 10 -->		Bremsen
			GPT1_vStopTmr(GPT1_TIMER_3);
			DC_brake = 1;
			return f_min;
		}

		if(DC_brake == 1){
		   GPT1_vStartTmr(GPT1_TIMER_3);
		   DC_brake = 0;	
		}

		if(ADC_value >= ADC_max){					// ADC > 1000 -->	50 Hz
		   return f_max;	
		}

		return f_min+(ADC_value-ADC_offset)*(f_max-f_min)/(ADC_max-ADC_offset);
	}


	// Amplitude des Referenzsinussignals berechnen
	unsigned int calculateAmplitude(unsigned int frequency, unsigned int u_car) {
		int boost_threshold = 14;
		unsigned int u_ref ;
		
		if ( frequency <= boost_threshold) {	 // Spannungsboost für niedrige Frequenzen
			frequency = boost_threshold;
		}
		else if (frequency >= F_Nenn) {			// u_ref auf max begrenzen
			frequency = F_Nenn;
		} 	

		u_ref = (unsigned int)frequency*u_car/F_Nenn;	

		return u_ref; 
	}

    // PI Regler
	unsigned int PI_controller(unsigned int f_target, unsigned int f_real){
		int controll_value = 1;
		int e_k = f_target-f_real;
		// Vorsteuerung
		int y_S = K_s*f_target;
		// P controller
		int y_P = K_p*e_k;
		// I controller
		int y_I = y_I_k_minus1+K_i*(e_k + e_k_minus1);
		// PI controller
		controll_value = y_P+y_I+y_S;
		if (controll_value > 60){		 // fmax urspruenglich 55
			controll_value = 60;         
			e_k_minus1 = e_k;
		}
		else if(controll_value <= 0){
			controll_value = 1;
			e_k_minus1 = e_k;
		}
		else {
		    y_I_k_minus1 = y_I; //Anti-Wind-Up für I-Anteil
		    e_k_minus1 = e_k;
		}
		return controll_value;

	}

	
// USER CODE END

