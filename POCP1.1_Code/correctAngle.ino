float correctAngle(float input){
  if (((input/0.082)-floor(input/0.082))!=0){
    integer=floor(input/0.082);
    if (((input/0.082)-floor(input/0.082))>=0.5){
      integer++;}
    output=integer*0.082;
    return output;}
  else{
    return input;}}
