void Menu(){
  start: // jump back here after exiting PresetMenu and CustomMenu
  ssd1306_clearScreen(); //clears screen
  ssd1306_setFixedFont(ssd1306xled_font8x16); //set larger font for page heading
  ssd1306_printFixed(32,  0, "SETTINGS", STYLE_NORMAL); //create heading
  ssd1306_setFixedFont(ssd1306xled_font6x8); //return to smaller size
  // printing options for user:
  ssd1306_printFixed(0,  16, "Preset Settings (B)", STYLE_NORMAL);
  ssd1306_printFixed(0,  24, "Custom Settings (C)", STYLE_NORMAL);
  ssd1306_printFixed(0,  32, "Exit            (D)", STYLE_NORMAL);

  // hold code from running further if button pressed to get to Menu page is continuous
  while (true){
    AState = digitalRead(bA);
    DState = digitalRead(bD);
    if ((AState == HIGH) && (DState == HIGH)){
      break; }}
      
  // main loop in the function: continually reads button state to see if user wants to change pages
  // --> if button is not pressed, the loop simply continues until user intervention
  while (true){
    wait(100);
    BState = digitalRead(bB);
    CState = digitalRead(bC);
    DState = digitalRead(bD);

    if (BState == LOW){
      PresetMenu();
      goto start; }
    else if (CState == LOW){
      CustomMenu();
      goto start; }
    else if (DState == LOW){
      ssd1306_clearScreen();
      break; }
  }
}
