#include "motor-controller.cpp"
#include "pid.cpp"
#include "gyro.cpp"
#include "regex"

// Define PID parameters
const double Kp = 10; //Proportional path weight
const double Ki = 20; //Integration path weight
const double Kd = 2; //Derivation path weight

const int maxPower = 50; //max power of motor
const int cutoffAngle = 35; //angle after which the motor gets disbaled

boolean enabled = true;
double output = 1500;

//PID settings
const double minOut = 1000 + (500 - 500*maxPower/100), maxOut = 2000 - (500 - 500*maxPower/100);
int sampleTime = 10;
double setPoint = 1.5;
float input_Angle;

// Define mqtt Variables
// Define gyro and PID control

PIDController pidController(Kp, Ki, Kd, minOut, maxOut, setPoint, sampleTime);
Gyro gyro;
MotorController motorController;

static unsigned long lastTime = 0;
static unsigned long currentTime = 0;

/**
 * Method that is called in the beginning of excecution for setup
*/
void setup() {
  Serial.begin(115200);

  gyro.setup();

  motorController.setupESC();
}


/**
 * Loop method that is used to run code in an infinite loop
*/
void loop() {
  gyro.loop();
  input_Angle = gyro.getRoll();

  output = pidRoll.compute((double)input_Angle);

  updateParamsIfAvailable();

  if(abs(input_Angle) > cutoffAngle) enabled = false;


  Serial.print(input_Angle);
  Serial.print(" ");
  Serial.print(output);
  Serial.print(" ");
  Serial.println(enabled);


  if(enabled) motorController.writeMicroseconds(output);
  else motorController.writeMicroseconds(1500);

  //printFreq();
}


void updateParamsIfAvailable(){
  if(Serial.available() > 0){
    String readString = Serial.readString();
    char *readChars;
    double parameters[3];
    readString.trim();

    readChars = new char[readString.length() + 1];
    strcpy(readChars, readString.c_str());

    if(!std::regex_match(readChars, std::regex(
      "\\d+\\.?\\d*,\\d+\\.?\\d*,\\d+\\.?\\d*"
    ))) {
      Serial.println("Invalid input !");
      return;
    }

    char *tokenStream = std::strtok(readChars, ",");
    for(int i = 0; i < 3 && tokenStream != NULL; i++) {
      parameters[i] = std::stod(tokenStream);
      tokenStream = std::strtok(NULL, ","); // next token
    } 

    Serial.print("Tuning to [");
    Serial.print(parameters[0]);
    Serial.print(", ");
    Serial.print(parameters[1]);
    Serial.print(", ");
    Serial.print(parameters[2]);
    Serial.println("]");

    //PIDRoll.setTunings(parameters[0], parameters[1], parameters[2]);
  }
}

void printFreq() {
  currentTime = micros();
  unsigned long loopTime = currentTime - lastTime;
  lastTime = currentTime;

  float frequency = 1000000.0 / loopTime; // Convert loop time to frequency in Hz

  Serial.print("Frequency: ");
  Serial.print(frequency);
  Serial.println(" Hz");
}
