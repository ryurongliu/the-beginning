#include <Adafruit_NeoPixel.h>
#define SPIN 8
//sp tier 1: 4567
//sp tier 2: 0123
//sp tier 3: 89 10 11
//sp tier 4: 12 13 14 15
#define TPIN 10
#define SNUMPIXELS 16
#define TNUMPIXELS 33

int t_0[] = {0, 1, 2};

int t_1_all[] = {3, 4, 5, 6, 7, 8, 9, 10, 11};
int t_1[][3] = {{3, 4, 5}, {6, 7, 8}, {9, 10, 11}};

int t_2_all[] = {12, 13, 14, 15, 16, 17, 18, 19, 20}; 
int t_2[][3] = {{12, 13, 14}, {15, 16, 17}, {18, 19, 20}};

int t_3_all[] = {21, 22, 23, 24, 25, 26, 27, 28, 29};
int t_3[][3] = {{21, 22, 23}, {24, 25, 26}, {27, 28, 29}};

int t_4[] = {30, 31, 32};


int t_front[] = {0, 3, 4, 5, 12, 13, 14, 21, 22, 23, 30};
int t_right[] = {1, 6, 7, 8, 15, 16, 17, 24, 25, 26, 31};
int t_left[] = {2, 9, 10, 11, 18, 19, 20, 27, 28, 29, 32};

//front left, front middle, front right, etc. for all triangles together (vertical groupings)
int t_fl[] = {3, 12, 21};
int t_fm[] = {0, 4, 13, 22, 30};
int t_fr[] = {5, 14, 23};

int t_rl[] = {6, 15, 24};
int t_rm[] = {1, 7, 16, 25, 31}; 
int t_rr[] = {8, 17, 26};

int t_ll[] = {9, 18, 27};
int t_lm[] = {2, 10, 19, 28, 32};
int t_lr[] = {11, 20, 29};


int s_0_all[] = {6, 5, 7, 4};
int s_0[][2] = {{6, 5}, {7, 4}};

int s_1_all[] = {2, 1, 3, 0}; 
int s_1[][2] = {{2, 1}, {3, 0}};

int s_2_all[] = {10, 9, 11, 8};
int s_2[][2] = {{10, 9}, {11, 8}};

int s_3_all[] = {14, 13, 15, 12};
int s_3[][2] = {{14, 13}, {15, 12}};

int s_left[] = {6, 5, 2, 1, 10, 9, 14, 13};
int s_right[] = {7, 4, 3, 0, 11, 8, 15, 12};

//vertical groupings
int s_lt[] = {6, 2, 10, 14};
int s_lb[] = {5, 1, 9, 13};
int s_rt[] = {7, 3, 11, 8};
int s_rb[] = {4, 0, 8, 12};

Adafruit_NeoPixel spixels(SNUMPIXELS, SPIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel tpixels(TNUMPIXELS, TPIN, NEO_RGB + NEO_KHZ800);

//USB color, 2 2 1 (scale 100)
//M color, 1 0 0 (scale 200)
//G color, 3 1 0 (scale 75)

void setup() {
  // put your setup code here, to run once:

  // int a = 200;
  // int b = 75;
  // int c = 100; 
  spixels.begin();
  spixels.clear(); 

  // spixels.fill(spixels.Color(2*c, 2*c, 1*c)); // breath color

  spixels.show();

  tpixels.begin();
  tpixels.clear();

  // //universe color
  // for (int i = 0; i < 6; i ++){
  //   tpixels.setPixelColor(universepix[i], 2*c, 2*c, 1*c);
  // }

  // //machine color
  // for (int i = 0; i < 9; i++){
  //   tpixels.setPixelColor(t_2_all[i], 1*a, 0*a, 0*a);
  // }

  // //speech color
  // for (int i = 0; i < 9; i ++ ){
  //   tpixels.setPixelColor(t_1_all[i], 2*c, 2*c, 1*c);
  // }

  // //god color
  // for (int i = 0; i < 9; i ++){
  //   tpixels.setPixelColor(t_3_all[i], 3*b, 1*b, 0*b);
  // }

  tpixels.show();

  Serial.begin(9600);
  Serial.setTimeout(10);

}

void setAlien(int val){
  //1 2 3 4 5 6, bottom / top and up speaker tower bottoms 
  int fill = 10;
  if (val == 1){
    //t bottom
    for (int i = 0; i < 3; i++){
      tpixels.setPixelColor(t_4[i], 0, fill, 0);
    }
  }

  else if (val == 2){
    spixels.setPixelColor(12, 0, fill, 0);
    spixels.setPixelColor(13, 0, fill, 0);
    spixels.setPixelColor(14, 0, fill, 0);
    spixels.setPixelColor(15, 0, fill, 0);
    tpixels.setPixelColor(22, 0, fill, 0);
  }

  else if (val == 3){
    spixels.setPixelColor(9, 0, fill, 0);
    spixels.setPixelColor(8, 0, fill, 0);
    spixels.setPixelColor(10, 0, fill, 0);
    spixels.setPixelColor(11, 0, fill, 0);
    tpixels.setPixelColor(13, 0, fill, 0);
  }

  else if (val == 4){
    spixels.setPixelColor(1, 0, fill, 0);
    spixels.setPixelColor(0, 0, fill, 0);
    spixels.setPixelColor(2, 0, fill, 0);
    spixels.setPixelColor(3, 0, fill, 0);
    tpixels.setPixelColor(4, 0, fill, 0);
  }

  else if (val == 5){
    spixels.setPixelColor(5, 0, fill, 0);
    spixels.setPixelColor(4, 0, fill, 0);
    spixels.setPixelColor(6, 0, fill, 0);
    spixels.setPixelColor(7, 0, fill, 0);
  }

  else if (val == 6){
    //t top
    for (int i = 0; i < 3; i++){
      tpixels.setPixelColor(t_0[i], 0, fill, 0);
    }
  }
  
}

void setMachine(int val){
  //color 1 0 0 (scale 200)
    for (int i = 0; i < 9; i ++){
    tpixels.setPixelColor(t_2_all[i], 1*val, 0*val, 0*val);
  }
}

void setHumThree(int val, int sel){

  val = 10;
  //val = max(val, 1);
  if (sel == 6){
    tpixels.setPixelColor(sel+11, 2*val, 2*val, 1*val);
    tpixels.setPixelColor(sel+14, 2*val, 2*val, 1*val);
  }
  else if (sel == 8){
    tpixels.setPixelColor(sel+7, 2*val, 2*val, 1*val);
    tpixels.setPixelColor(sel+10, 2*val, 2*val, 1*val);
  }
  else if (sel == 7){
    tpixels.setPixelColor(sel+9, 2*val, 2*val, 1*val);
    tpixels.setPixelColor(sel+12, 2*val, 2*val, 1*val);
  }

  tpixels.setPixelColor(sel, 2*val, 2*val, 1*val);
  tpixels.setPixelColor(sel+3, 2*val, 2*val, 1*val);
  tpixels.setPixelColor(sel+18, 2*val, 2*val, 1*val);
  tpixels.setPixelColor(sel+18+3, 2*val, 2*val, 1*val);

}

void setSpeechColorsThree(int val){
  //all three central tower tiers
  //audioreactive

  int fill2 = max(val-2, 1);
  int fill3 = max(val-4, 1); 

  for (int i = 0; i < 3; i ++ ){
    tpixels.setPixelColor(t_1[0][i], 2*val, 2*val, 1*val);
    tpixels.setPixelColor(t_2[0][i], 2*fill2, 2*fill2, 1*fill2);
    tpixels.setPixelColor(t_3[0][i], 2*fill2, 2*fill2, 1*fill2);
  }
  
  for (int i = 3; i < 9; i ++){
    tpixels.setPixelColor(t_1_all[i], 2, 2, 1);
    tpixels.setPixelColor(t_2_all[i], 2, 2, 1);
    tpixels.setPixelColor(t_3_all[i], 2, 2, 1);
  }

}

void setBreathColorsBoth(int val, int r, int g, int b){ //breath using all speaker lights 
  spixels.fill(spixels.Color(val*r, val*g, val*b));
}

void setSpeechC3(int val, int r, int g, int b){
  //speech from bottom up, entire tower
  tpixels.fill(tpixels.Color(val*r, val*g, val*b));
}

void setGodColors(int val){
  //center-bottom tier
    // //god color
  for (int i = 0; i < 9; i ++){
    tpixels.setPixelColor(t_3_all[i], 3*val, 1*val, 0*val);
  }


}

void setUniverseColors(int val){
  //top and bottom of tower
  //color 2 2 1 
  //audio reactive (for now) 

  int pix[] = {0, 1, 2, 30, 31, 32};
  
  for (int i = 0; i < 6; i++){
    tpixels.setPixelColor(pix[i], tpixels.Color(2*val, 2*val, val));
  }
}

void checkMainSerialInput() //command handler
{
  char CMD= Serial.read();

  if (CMD == 'A'){ //SBU

    int Sval = Serial.parseInt();
    int Bval = Serial.parseInt();
    int Uval = Serial.parseInt();

    setSpeechColorsThree(Sval);
    setBreathColorsBoth(Bval, 2, 2, 1);
    setUniverseColors(Uval);
  }

  else if (CMD == 'B'){//AHSBU

    int Aval = Serial.parseInt();
    int Hval = Serial.parseInt();
    int Hsel = Serial.parseInt(); 
    int Sval = Serial.parseInt();
    int Bval = Serial.parseInt(); 
    int Uval = Serial.parseInt(); 

    setSpeechColorsThree(Sval);
    setBreathColorsBoth(Bval, 2, 2, 1);
    
    if (Hsel != 0){
      setHumThree(Hval, Hsel);
    }
    
    setUniverseColors(Uval);
    
    //handle A last
    if (Aval != 0){
      setAlien(Aval);
    }
  }

  else if (CMD == 'C'){//AHSBGU
    
    int Aval = Serial.parseInt();
    int Hval = Serial.parseInt();
    int Hsel = Serial.parseInt(); 
    int Sval = Serial.parseInt();
    int Bval = Serial.parseInt(); 
    int Gval = Serial.parseInt();
    int Uval = Serial.parseInt();

   //handle A//
    setSpeechColorsThree(Sval);
    setBreathColorsBoth(Bval, 2, 2, 1);
    
    if (Gval != 0){
      setGodColors(Gval); 
    }

    if (Hsel != 0){
      setHumThree(Hval, Hsel);
    }

    setUniverseColors(Uval);

    if (Aval != 0){
      setAlien(Aval);
    }
  }

  else if (CMD == 'D'){//MHSBGU
    
    int Mval = Serial.parseInt(); 
    int Hval = Serial.parseInt();
    int Hsel = Serial.parseInt(); 
    int Sval = Serial.parseInt();
    int Bval = Serial.parseInt(); 
    int Gval = Serial.parseInt();
    int Uval = Serial.parseInt();

    setSpeechColorsThree(Sval);
    setBreathColorsBoth(Bval, 2, 2, 1);
    
    if (Gval != 0){
      setGodColors(Gval); 
    }

    if (Mval != 0){
      setMachine(Mval);
    }

    if (Hsel != 0){
      setHumThree(Hval, Hsel);
    }

    setUniverseColors(Uval);


  }

  else if (CMD == 'E'){//SB (C3)

    int Sval = Serial.parseInt();
    int Bval = Serial.parseInt(); 

    setSpeechC3(Sval, 1, 0, 0); // red 
    setBreathColorsBoth(Bval, 1, 0, 0); //red
  }

  else if (CMD == 'H'){//SB (D3)

    int Aval = Serial.parseInt();
    int Sval = Serial.parseInt();
    int Bval = Serial.parseInt(); 

    setSpeechC3(Sval, 2, 2, 1); //should be humancolor 
    setBreathColorsBoth(Bval, 2, 2, 1); //should be humancolor

    if (Aval != 0){
      setAlien(Aval);
    }
  }

  else if (CMD == 'I'){//ASBU
    int Aval = Serial.parseInt();
    int Sval = Serial.parseInt();
    int Bval = Serial.parseInt(); 
    int Uval = Serial.parseInt();

    //handle A//
    setSpeechColorsThree(Sval);
    setBreathColorsBoth(Bval, 2, 2, 1); //should be humancolor
    setUniverseColors(Uval);

    if (Aval != 0){
      setAlien(Aval);
    }


  }

  else if (CMD == 'X'){
    //clear all
    spixels.clear();
    tpixels.clear();
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available() > 0){
    checkMainSerialInput();
  }

  tpixels.show();
  spixels.show();
  

}
