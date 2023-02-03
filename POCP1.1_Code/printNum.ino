void printNum(int value,int x,int y,int xFont){
  
  // value == desired 3 digit number one wants to print
  // x position of print
  // y position of print
  // width of characters in font used
  hundsPlace = value/100;
  tensPlace = (value - (100*hundsPlace))/10;
  //tensPlace = holder/10;
  onesPlace = value-(100*hundsPlace)-(10*tensPlace);
  ssd1306_printFixed(x+(2*xFont), y, numArray[onesPlace], STYLE_NORMAL);
  if (hundsPlace>0){
    ssd1306_printFixed(x, y, numArray[hundsPlace], STYLE_NORMAL);
    ssd1306_printFixed(x+xFont, y, numArray[tensPlace], STYLE_NORMAL);}
  else if (hundsPlace==0 && tensPlace>0){
    ssd1306_printFixed(x+xFont, y, numArray[tensPlace], STYLE_NORMAL);}
}
