
/*******************************************************************
 * 
 * Written by Mithi Sevilla | Nov 30, 2015 | http://mithi.xyz
 * 
 *******************************************************************/

#include "utility_constants.h"

class DigitalOutput{
  int _pin;
  bool _state; 
  public:
  void Format(int p);
  void Set(bool s);
  void On();
  void Off();
  void Toggle();
  bool State();
};

class AnalogOutput{
  int _pin;
  int _state;
  public:
  void Format(int p);
  void Set(int b);
  int State();
};

class AnalogInput{
  int _pin;
  public:
  void Format(int p);
  int RawValue();
  int MappedValue(int mn, int mx);
};

class RGB{
  int _redPin;
  int _greenPin;
  int _bluePin;
  public:
  void Format(int r, int g, int b);
  void Red(int r);
  void Green(int g);
  void Blue(int b);
  void ColorRaw(int r, int g, int b);
  void Color(byte c);
};

class DigitalSensor{
  bool _state;
  bool _inverted;
  int _pin; 
  int _mode;
  public:
  void Format(int p, int m, bool i);
  int Pin();
  bool Value();
  bool State();
};

class AnalogSensor{
  bool _inverted;
  bool _state;
  int _pin;
  int _mode;
  int _threshold;
  float _M;
  float _B;
  public:
  void Format(int p, int m, int t, bool i, float cm, float cb);
  bool IsTrue();
  float ProcessedValue();
  int RawValue();
  int MappedRawValue(int mn, int mx);
};

/******
class Buzzer{
  int _wholeNotePeriod;
  int _pin;
  float _pauseScale;
  public:
  void Format(int p, int ps, int wnp);
  void PlayNote(int pitch, float duration);
  void Play(int freq, float period, int d);
  void Pause(float sp);
  float SoundPeriod(float sp);
  float PausePeriod(float sp);
};
***********/


class SevenSegment{
  int _pin[8];
  bool _isCommonCathode; // commonCathode = commonGround
  public:
  void Format(int p[], int c);
  void SetRaw(int n[]);
  void Display(byte n);
  private:
  void _set(int p, byte n);
};

class Sweeper{
  bool _dir;
  bool _type; 
  int _state;
  int _start;
  int _end;
  int _step;
  unsigned long _sweepsMade;
  public:
  void begin(int s, int e, int st, byte x);
  int next();
  unsigned long sweeps_made();
  void toggle_direction();
  void set_direction(bool d);
  private:
  void _forward();
  void _reverse();
  void _backAndForthForward();
  void _backAndForthReverse();
};

class Metronome{
  unsigned long _interval; 
  unsigned long _previousTime;
  unsigned long _currentTime;
  public:
  void begin(unsigned long t);
  bool tick();
  void set_interval(unsigned long t);
};

class LedsManager{
  int _brightness;
  int _pin[6];
  int _count;
  public:
  void Format(int p[]);
  void SetBrightness(int b);
  byte Walks(byte state);
  byte WalksUp(byte state);
  byte WalksDown(byte state);
  byte Stairs(byte state);
  byte StairsUp(byte state);
  byte StairsDown(byte state);
  void AllLeds(int b);
  private:
  void _stairsHelper(byte maxxer, byte state);
  void _led(int p, int b);
  void _singleLed(int p);
  byte _nextState(byte state, byte numberOfStates);
};

class Sequencer{
  byte _state;
  byte _type;
  LedsManager* ledsManager; 
  public:
  void Format(LedsManager* LM);
  void Update(bool itIsTime);
  void Start(byte type);
  private:
  void _selectSequence();
};


