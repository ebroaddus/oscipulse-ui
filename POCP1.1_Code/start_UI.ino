void start_UI(){
ssd1306_clearScreen();
while (true){
  ssd1306_setFixedFont(ssd1306xled_font8x16);
  ssd1306_printFixed(10,  0, "MAIN INTERFACE", STYLE_NORMAL);
  ssd1306_setFixedFont(ssd1306xled_font6x8);

  //print speed value
  ssd1306_printFixed(0, 24, "Speed:", STYLE_NORMAL);
  printNum(motorSpeed,92,24,6);
  // print position value
  ssd1306_printFixed(0, 40, "Position:", STYLE_NORMAL);
  printNum(motorPosition,92,40,6);

  AState = digitalRead(bA);
    if (AState == LOW){
      Menu();
    }
}
}
