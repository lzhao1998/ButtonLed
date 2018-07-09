#include "LedController.h"
#include "Button.h"
#include "Led.h"


void turnOnLedIfButtonIsPressed(void)
{
  if(getButtonState() == 1)
  {
    turnLed(LED_ON);
  }
  else
  {
    turnLed(LED_OFF);
  }
}

void doLedForever()
{
  while(1)
  {
    turnOnLedIfButtonIsPressed();
  }
}

void tapTurnOnTapTurnOffLed(LedButtonInfo *info)
{
/*    LedState  currentButtonState   PreviousButton   LedOutput
      0                 0                 0              0
      0                 0                 1              0
      0                 1                 0              1       ------\
      0                 1                 1              0               010 and 101 is the major problem
      1                 0                 0              1
      1                 0                 1              0        -----/
      1                 1                 0              1
      1                 1                 1              1
  */
  ButtonState currentButtonState;
  currentButtonState = getButtonState();
  /*if(info->currentLedState == LED_OFF)  // when LED is off
  {
    //when button is press and previos button is released, turn on LED
    if(currentButtonState == BUTTON_PRESSED && info->previousButtonState == BUTTON_RELEASED)
    {
      info->currentLedState = LED_ON;
      turnLed(info->currentLedState);
      info->previousButtonState = currentButtonState;
    }
    else     //current button is released
    {
      info->previousButtonState = currentButtonState;
    }
  }
  else      //when button is released
  {
    //when button is released and previous button is press, turn off LED
    if(currentButtonState == BUTTON_RELEASED && info->previousButtonState == BUTTON_PRESSED)
    {
      info->currentLedState = LED_OFF;
      turnLed(info->currentLedState);
      info->previousButtonState = currentButtonState;
    }
    else     //current button is released
    {
      info->previousButtonState = currentButtonState;
    }
  }*/
  switch(info->currentLedState)
  {
    case 0:                                                    //When LED is OFF
      switch(currentButtonState)                              //When currentState = 1, previousState = 0  -> TURN ON LED
      {
        case 1:
          switch(info->previousButtonState)
          {
            case 0:
              info->currentLedState = LED_ON;
              turnLed(info->currentLedState);
              info->previousButtonState = currentButtonState;
              break;
            default:
              info->previousButtonState = currentButtonState;
              break;
          }
        default:
          info->previousButtonState = currentButtonState;
          break;
      }
      break;
    case 1:                                                   //When LED is ON
      switch(currentButtonState)                              //When currentState = 0, previousState = 1 -> TURN OFF LED
      {
        case 0:
          switch(info->previousButtonState)
          {
            case 1:
              info->currentLedState = LED_OFF;
              turnLed(info->currentLedState);
              info->previousButtonState = currentButtonState;
              break;
            default:
              info->previousButtonState = currentButtonState;
              break;
          }
        default:
          info->previousButtonState = currentButtonState;
          break;
      }
    default:
      info->previousButtonState = currentButtonState;
      break;
  }
}

void doTapTapLedController()
{
  LedState currentLedState;
  while(1)
  {
  //  tapTurnOnTapTurnOffLed(&currentLedState);
  }
}
