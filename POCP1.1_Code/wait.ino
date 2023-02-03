void wait(int mills){
    prevTime = millis();
    while (true){
      currTime = millis();
      if (currTime - prevTime >= mills){
        break;}}}
