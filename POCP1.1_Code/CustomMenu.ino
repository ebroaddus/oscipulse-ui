void CustomMenu(){
  // set background display for this menu (or initial state of the display)
  ssd1306_clearScreen();
  ssd1306_setFixedFont(ssd1306xled_font8x16);
  ssd1306_printFixed(2,  0, "CUSTOM SETTINGS", STYLE_NORMAL);
  ssd1306_setFixedFont(ssd1306xled_font6x8);
  ssd1306_printFixed(0, 24, "Speed: ", STYLE_NORMAL);
  printNum(motorSpeed,56,24,6);
  ssd1306_printFixed(0, 40, "Pos.: ", STYLE_NORMAL);
  printNum(motorPosition,56,40,6);
  
  while (true){
    CState = digitalRead(bC);
    if (CState == HIGH){
      break; }}

  counter = motorSpeed;
  while (true){ 
    wait(100);
    BState = digitalRead(bB);
    CState = digitalRead(bC);
    DState = digitalRead(bD);
    if (BState == LOW){
      counter--;} //decrease the counter by 1
    else if (CState == LOW){
      counter++;} //increase the counter by 1
    else if (DState == LOW){
      // prints value of motor speed once user confirms moving to next selection stage
      ssd1306_positiveMode();
      ssd1306_printFixed(56, 24, "   ", STYLE_NORMAL);
      printNum(counter,56,24,6);
      break;}
      
    ssd1306_printFixed(56, 24, "   ", STYLE_NORMAL);
    ssd1306_negativeMode();
    
    if ((counter > 0) && (counter < 256)){
      printNum(counter,56,24,6);}
    else if (counter == 0){
      counter=255;
      printNum(255,56,24,6);}
    else if (counter == 256){
      counter=1;
      printNum(1,56,24,6);}}
    motorSpeed=counter;
    // here we would add a conditional statement to realign counter step, but step is 1 so it doesnt matter

// creates pause while button is held down (aesthetic)
  while (true){
    wait(100);
    DState = digitalRead(bD);
    if (DState == HIGH){
      break;}}
    
// determining the position values
  counter = motorPosition;
  while (true){
    wait(100);
    BState = digitalRead(bB);
    CState = digitalRead(bC);
    DState = digitalRead(bD);
    if (BState == LOW){
      counter=counter-5;}
    else if (CState == LOW){
      counter=counter+5;}
    else if (DState == LOW){
      ssd1306_positiveMode();
      ssd1306_printFixed(56, 40, "   ", STYLE_NORMAL);
      printNum(counter,56,40,6);
      break;}
      
    ssd1306_printFixed(56, 40, "   ", STYLE_NORMAL);
    ssd1306_negativeMode();
    
    if ((counter > 9) && (counter < 271)){
      printNum(counter,56,40,6);}
    else if (counter == 5){
      counter=270;
      printNum(counter,56,40,6);}
    else if (counter == 275){
      counter=10;
      printNum(counter,56,40,6);}}
    motorPosition=counter;
}
