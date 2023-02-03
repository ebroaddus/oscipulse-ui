void PresetMenu(){
  // setting background
  ssd1306_clearScreen();
  ssd1306_setFixedFont(ssd1306xled_font8x16);
  ssd1306_printFixed(2,  0, "PRESET SETTINGS", STYLE_NORMAL);
  ssd1306_setFixedFont(ssd1306xled_font6x8);
  ssd1306_printFixed(0, 24, "Speed: ", STYLE_NORMAL);
  ssd1306_printFixed(0, 40, "Pos.:  ", STYLE_NORMAL);
  printNum(speedOp1,40,24,6);
  printNum(speedOp2,72,24,6);
  printNum(speedOp3,104,24,6);
  printNum(posOp1,40,40,6);
  printNum(posOp2,72,40,6);
  printNum(posOp3,104,40,6);
  
  while (true){
  BState = digitalRead(bB);
  if (BState == LOW){
    continue; }
  else if (BState == HIGH){
    break; }}
 
  counter = 1;
  while (true){
    wait(100);
    BState = digitalRead(bB);
    CState = digitalRead(bC);
    DState = digitalRead(bD);
    if (BState == LOW){
      counter--; }
    else if (CState == LOW){
      counter++; }
    else if (DState == LOW){
      ssd1306_positiveMode();
      printNum(speedOp1,40,24,6);
      printNum(speedOp2,72,24,6);
      printNum(speedOp3,104,24,6);
      break;}

    ssd1306_negativeMode();
    // another if statement for scroll through and speed value assignment
    if (counter == 0){
      printNum(speedOp3,104,24,6);
      counter = 3; // shift all the way to right hand side
      motorSpeed = speedOp3;
      ssd1306_positiveMode();
      printNum(speedOp1,40,24,6);
      printNum(speedOp2,72,24,6);}
    else if (counter == 1){
      printNum(speedOp1,40,24,6);
      motorSpeed = speedOp1;
      ssd1306_positiveMode();
      printNum(speedOp2,72,24,6);
      printNum(speedOp3,104,24,6);}
    else if (counter == 2){
      printNum(speedOp2,72,24,6);
      motorSpeed = speedOp2;
      ssd1306_positiveMode();
      printNum(speedOp1,40,24,6);
      printNum(speedOp3,104,24,6);}
    else if (counter == 3){
      printNum(speedOp3,104,24,6);
      motorSpeed = speedOp3;
      ssd1306_positiveMode();
      printNum(speedOp1,40,24,6);
      printNum(speedOp2,72,24,6);}
    else if (counter == 4){
      printNum(speedOp1,40,24,6);
      counter = 1; 
      motorSpeed = speedOp1;
      ssd1306_positiveMode(); //switch to positive printing
      printNum(speedOp2,72,24,6);
      printNum(speedOp3,104,24,6);}}

// creates pause while button is held down (aesthetic)
  while (true){
    DState = digitalRead(bD);
    if (DState == LOW){
      continue; }
    else if (DState == HIGH){
      break; }}
  
// determining the position values
  counter = 1;
  while (true){
    wait(100);
    BState = digitalRead(bB);
    CState = digitalRead(bC);
    DState = digitalRead(bD);
    if (BState == LOW){
      counter--; }
    else if (CState == LOW){
      counter++; }
    else if (DState == LOW){
      break; }
    
    // setting background
    ssd1306_negativeMode();
    // another if statement for scroll through and speed value assignment
    if (counter == 0){
      printNum(posOp3,104,40,6);
      counter = 3; // shift all the way to right hand side
      motorPosition = posOp3;
      ssd1306_positiveMode();
      printNum(posOp1,40,40,6);
      printNum(posOp2,72,40,6);}
    else if (counter == 1){
      printNum(posOp1,40,40,6);
      motorPosition = posOp1;
      ssd1306_positiveMode();
      printNum(posOp2,72,40,6);
      printNum(posOp3,104,40,6);}
    else if (counter == 2){
      printNum(posOp2,72,40,6);
      motorPosition = posOp2;
      ssd1306_positiveMode();
      printNum(posOp1,40,40,6);
      printNum(posOp3,104,40,6);}
    else if (counter == 3){
      printNum(posOp3,104,40,6);
      motorPosition = posOp3;
      ssd1306_positiveMode();
      printNum(posOp1,40,40,6);
      printNum(posOp2,72,40,6);}
    else if (counter == 4){
      printNum(posOp1,40,40,6);
      counter = 1; 
      motorPosition = posOp1;
      ssd1306_positiveMode(); //switch to positive printing
      printNum(posOp2,72,40,6);
      printNum(posOp3,104,40,6);}}
}
