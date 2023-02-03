void moveToAngle(float tarAngle,int motorSpeed){
  compressStart=millis();
  //while ((angle!=tarAngle)&&((millis()-compressStart)<2500){ //might want to get rid of time conditional
  while ((millis()-compressStart)<2000){
    readEncoder();
    if (angle<tarAngle){
      analogWrite(IN1,motorSpeed);
      digitalWrite(IN2,LOW);}
    else if (angle>tarAngle){
      analogWrite(IN2,motorSpeed);
      digitalWrite(IN1,LOW);}}
  digitalWrite(IN1,LOW); // reset pin to not running at all
  digitalWrite(IN2,LOW);} // rest pin to not running at all
