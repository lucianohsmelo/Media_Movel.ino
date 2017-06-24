#define n 50 //numero de pontos da média móvel

int original, filtered;
int numbers[n];
float temperatura;

long moving_avg();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  original = analogRead(A0);
  filtered = moving_avg(original);
  Serial.print(original);
  Serial.print(" ");
  Serial.print(filtered);
  Serial.print(" ");
  Serial.println(getTemp(filtered));
  delay(20);
}
float getTemp(int value){
  float temperature = (value * 285.0f) / 1023.0f;
  return temperature;
}

long moving_avg(int value){
  for(int i = n-1; i>0; i--){
    numbers[i] = numbers[i-1];
  }
  numbers[0] = value;
  long acc = 0;
  for (int i = 0; i < n; i++){
    acc += numbers[i];
  }
  return acc/n;
}

