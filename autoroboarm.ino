#include <Servo.h>

Servo nemo;
Servo flee;
Servo maxp;
Servo claw;

int CVmaxppos1 = 85;
int CVnemopos2 = 0;
int CVfleepos3 = 90;
int CVclawpos = 60;

int Fixedmaxppos1 = 85;
int Fixednemopos2 = 0;
int Fixedfleepos3 = 90;
int Fixedclawpos = 60;

char AutoServoPositioning[100];
int KArPos = 0;
int StepSize = 10;

int FVmaxppos1;
int FVnemopos2;
int FVfleepos3;
int FVclawpos;


int RotationDelay = 100;

void setup()
{
  Serial.begin(9600);
  nemo.attach(10);
  flee.attach(11);
  maxp.attach(9);
  claw.attach(6);
}

void loop()
{
  if (Serial.available())
  {
      char ch = Serial.read();
      
      if (ch == 'q')
      {
        AutoServoPositioning[KArPos] = 'q';
        KArPos++;
        FVmaxppos1 = CVmaxppos1 + StepSize;
        maxpfunc(FVmaxppos1);        
      }
      if (ch == 'a')
      {        
        AutoServoPositioning[KArPos] = 'a';
        KArPos++;
        FVmaxppos1 = CVmaxppos1 - StepSize;
        maxpfuncReverse(FVmaxppos1);        
      }
      //----------------------
      if (ch == 'd')
      {    
        AutoServoPositioning[KArPos] = 'd';
        KArPos++;
        FVnemopos2 = CVnemopos2 + StepSize;
        nemofuncReverse(FVnemopos2);        
      }
      if (ch == 'e')
      {
        AutoServoPositioning[KArPos] = 'e';
        KArPos++;
        FVnemopos2 = CVnemopos2 - StepSize;
        nemofunc(FVnemopos2);        
      }
      //-----------------------
      if (ch == 'w')
      {
        AutoServoPositioning[KArPos] = 'w';
        KArPos++;
        FVfleepos3 = CVfleepos3 + StepSize;
        fleefunc(FVfleepos3);        
      }
      if (ch == 's')
      {
        AutoServoPositioning[KArPos] = 's';
        KArPos++;
        FVfleepos3 = CVfleepos3 - StepSize;
        fleefuncReverse(FVfleepos3);        
      }
      //------------------------
      if ( ch == 'm')
      {
        AutoServoPositioning[KArPos] = 'm';
        KArPos++;
        FVclawpos = CVclawpos + StepSize;
        clawfunc(FVclawpos);        
      }
      if (ch == 'n')
      {
        AutoServoPositioning[KArPos] = 'n';
        KArPos++;
        FVclawpos = CVclawpos - StepSize;
        clawfuncReverse(FVclawpos);        
      }
      //-----------------------
      if (ch == 'R')
      {
        ResetServo();
      }
      //-----------------------
      if (ch == 'X')
      {
        AutoRoboArm();
      }
      if (ch == 'T')
      {
        ResetVariable();
      }
  }
  Serial.println(CVmaxppos1);
  Serial.println(CVnemopos2);
  Serial.println(CVfleepos3);
  Serial.println(CVclawpos);
  Serial.println("----------");
  Serial.println(AutoServoPositioning[KArPos-1]);
  Serial.println("----------");
  Serial.println(KArPos);
  Serial.println("----------");
  delay(300);
}


//--------------------------------------------------------
void nemofunc(int FinalNemoPosition)
{
  for(int i = CVnemopos2; i<=FinalNemoPosition; i++)
  {
    nemo.write(145-i);
    delay(RotationDelay);
  }
  CVnemopos2 = FinalNemoPosition;
}
//--------------------------------------------------------
void maxpfunc(int FinalMaxpPosition)
{
  for(int i = CVmaxppos1; i<=FinalMaxpPosition; i++)
  {
    maxp.write(i);
    delay(RotationDelay);
  }
  CVmaxppos1 = FinalMaxpPosition;
}
//--------------------------------------------------------
void fleefunc(int FinalFleePosition)
{
  for(int i = CVfleepos3; i<=FinalFleePosition; i++)
  {
    flee.write(i);
    delay(RotationDelay);
  }
  CVfleepos3 = FinalFleePosition;
}
//--------------------------------------------------------
void nemofuncReverse(int FinalNemoPosition)
{
  for(int i = CVnemopos2; i>=FinalNemoPosition; i--)
  {
    nemo.write(145-i);
    delay(RotationDelay);
  }
  CVnemopos2 = FinalNemoPosition;
}
//--------------------------------------------------------
void maxpfuncReverse(int FinalMaxpPosition)
{
  for(int i = CVmaxppos1; i>=FinalMaxpPosition; i--)
  {
    maxp.write(i);
    delay(RotationDelay);
  }
  CVmaxppos1 = FinalMaxpPosition;
}
//--------------------------------------------------------
void fleefuncReverse(int FinalFleePosition)
{
  for(int i = CVfleepos3; i>=FinalFleePosition; i--)
  {
    flee.write(i);
    delay(RotationDelay);
  }
  CVfleepos3 = FinalFleePosition;
}
//--------------------------------------------------------
void clawfunc(int FinalClawPosition)
{
  for (int i = CVclawpos; i<=FinalClawPosition; i++)
  {
    claw.write(i);
    delay(RotationDelay);
  }
  CVclawpos = FinalClawPosition;
}
//--------------------------------------------------------
void clawfuncReverse(int FinalClawPosition)
{
  for (int i = CVclawpos; i>=FinalClawPosition; i--)
  {
    claw.write(i);
    delay(RotationDelay);
  }
  CVclawpos = FinalClawPosition;
}
//--------------------------------------------------------
void ResetServo()
{
  if (CVnemopos2 - Fixednemopos2 >0)
   {
    for (int i = CVnemopos2; i>=Fixednemopos2;i--)
    {
      nemo.write(145-i);
      delay(RotationDelay);
    }
    CVnemopos2 = Fixednemopos2;
   }
  else
  {
    for (int i = CVnemopos2; i<=Fixednemopos2;i++)
    {
      nemo.write(145-i);
      delay(RotationDelay);
    }
    CVnemopos2 = Fixednemopos2;
  }
  //----------------------
  if (CVmaxppos1 - Fixedmaxppos1 >0)
   {
    for (int i = CVmaxppos1; i>=Fixedmaxppos1;i--)
    {
      maxp.write(i);
      delay(RotationDelay);
    }
    CVmaxppos1 = Fixedmaxppos1;
   }
  else
  {
    for (int i = CVmaxppos1; i<=Fixedmaxppos1;i++)
    {
      maxp.write(i);
      delay(RotationDelay);
    }
    CVmaxppos1 = Fixedmaxppos1;
  }
  //----------------------
  if (CVfleepos3 - Fixedfleepos3 >0)
   {
    for (int i = CVfleepos3; i>=Fixedfleepos3;i--)
    {
      flee.write(i);
      delay(RotationDelay);
    }
    CVfleepos3 = Fixedfleepos3;
   }
  else
  {
    for (int i = CVfleepos3; i<=Fixedfleepos3;i++)
    {
      flee.write(i);
      delay(RotationDelay);
    }
    CVfleepos3 = Fixedfleepos3;
  }
  //----------------------
  if (CVclawpos - Fixedclawpos >0)
   {
    for (int i = CVclawpos; i>=Fixedclawpos;i--)
    {
      claw.write(i);
      delay(RotationDelay);
    }
    CVclawpos = Fixedclawpos;
   }
  else
  {
    for (int i = CVclawpos; i<=Fixedclawpos;i++)
    {
      claw.write(i);
      delay(RotationDelay);
    }
    CVclawpos = Fixedclawpos;
  }
  //-------------------------

}
//--------------------------------------------------------
void AutoRoboArm()
{
  ResetServo();
  for (int i = 0; i < KArPos; i++) {
    if (AutoServoPositioning[i] == 'q')
      {
        FVmaxppos1 = CVmaxppos1 + StepSize;
        maxpfunc(FVmaxppos1);
      }
    if (AutoServoPositioning[i] == 'a')
      {
        FVmaxppos1 = CVmaxppos1 - StepSize;
        maxpfuncReverse(FVmaxppos1);
      }
      //----------------------
    if (AutoServoPositioning[i] == 'd')
      {
        FVnemopos2 = CVnemopos2 + StepSize;
        nemofuncReverse(FVnemopos2);
      }
    if (AutoServoPositioning[i] == 'e')
      {
        FVnemopos2 = CVnemopos2 - StepSize;
        nemofunc(FVnemopos2);
      }
      //-----------------------
    if (AutoServoPositioning[i] == 'w')
      {
        FVfleepos3 = CVfleepos3 + StepSize;
        fleefunc(FVfleepos3);
      }
    if (AutoServoPositioning[i] == 's')
      {
        FVfleepos3 = CVfleepos3 - StepSize;
        fleefuncReverse(FVfleepos3);
      }
      //------------------------
    if (AutoServoPositioning[i] == 'm')
      {
        FVclawpos = CVclawpos + StepSize;
        clawfunc(FVclawpos);
      }
    if (AutoServoPositioning[i] == 'n')
      {
        FVclawpos = CVclawpos - StepSize;
        clawfuncReverse(FVclawpos);
      }
      //-----------------------
    if (AutoServoPositioning[i] == 'R')
      {
        ResetServo();
      }
  }

}

void ResetVariable()
{
  for (int i = 0; i < KArPos; i++)
  {
    AutoServoPositioning[i] = (char)0;
  }
  KArPos = 0;
}
