/* Nishank Kuppa and Adhithyan Vaiyapuri
 *  November 16, 2016
 *  ME 30 Homework 6
 */
 
// set pin numbers:
const int switch0 = 12;
const int switch1 = 8;
const int switch2 = 7;
const int switch3 = 4;
const int light_sensor = A2;
const int speaker = 5;

int scaled_val = 0; // plays frequecies after being mapped
int tonevalue = 0;  // reads the light sensor data
//buttonstates
int state0;
int state1;
int state2;
int state3;

// declare functions
void read_buttons( int *sw1, int *sw2, int *sw3, int *sw4 );  // read and store state of the four buttons
int tone_value(int notes[50]);                                // generates tone based on light sensor data
void clear_playlist( int *notes);                             // clears the frequencies stored in the array
void playback(int notes[50]);                                 // replay the recorded tone
int notes[50]={0};                                                // array for holding frequency values


void setup()
// set switches as inputs
{
  pinMode(switch0, INPUT_PULLUP); 
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(speaker, OUTPUT);
}
 
void loop() 
{
  int val;
  read_buttons(&state0, &state1, &state2, &state3);     // read the state of each button
  if (state0 == LOW)   // if the first switch is pressed
  {
    val=tone_value(); // go to the tone_value function
    if (state0 == LOW)
    {
      val=tone_value();
      store(val);
    }
  }
  else if (state1 == LOW)   // if the second switch is pressed
  {
    playback(notes);  // go to the playback function
  }
  else if (state2 == LOW)   // if the third switch is pressed
  {
    clear_playlist(notes); // go to the clear playlist function
  }
  else if (state3 == LOW)   // if the fourth switch is pressed
  {
    playback(notes);  // go to the playback function
  }
  else
  {
    digitalWrite(6,HIGH);
  }
    /*int tonevalue = analogRead(light_sensor);
    int scaled_val = map(tonevalue, 0, 20, 120, 3500); //170);
    tone(5, scaled_val);
    delay(1); 
  }  */
}

// function for reading and returning switches
void read_buttons( int *sw1, int *sw2, int *sw3, int *sw4 )
{
  *sw1 = digitalRead(switch0);
  *sw2 = digitalRead(switch1);
  *sw3 = digitalRead(switch2);
  *sw4 = digitalRead(switch3);
}

// generates tone based on light sensor data
int tone_value()
{
  //int i;
  //stores tones in notes[]
  
    tonevalue = analogRead(light_sensor);
    scaled_val = map(tonevalue,20,180, 120, 3500); //170); 
    //notes[i] = scaled_val;
    //check if note is stored
    tone(5,scaled_val);
   
  
  return scaled_val;
}

void store (int val)
{
  int i;
  for (i = 0; i < 50; i++)
  {
     notes[i] = val;
  }
}

// plays back stored frequencies
void playback(int notes[])
{
  int i;
  for(i=0; i<(sizeof(notes)/sizeof(int));++i)
  {
    tone(5, notes[i]);
    
  }
}

// Clears whatever was stored into the notes array
void clear_playlist(int *notes)
{
  //clear playlist
    for (int i = 0; i <(sizeof(notes)/sizeof(int)) ; i++)
  {
     notes[i] = 0;
  }
}


