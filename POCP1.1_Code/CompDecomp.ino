void CompDecomp(){
  readEncoder();
  // wait(5000); this might have to be reincluded, not entirely sure yet
  //holdPosition=angle; this is no longer needed
  holdPosition=correctAngle(angle);
  moveToAngle(holdPosition+motorPosition,motorSpeed); //ask alex: can input be greater than 360 degrees? i.e 370 = 10
  wait(100); //slight wait between compress and decompress
  moveToAngle(holdPosition,motorSpeed);}

  //new function
//void CompDeComp(){
  correctAngle(motorPosition)
