// Slave Uno
#include <Wire.h>
void setup()
{
  Wire.begin(1); // Slave의 주소를 1번으로 지정해준다.
  Wire.onRequest(requestEvent); // 데이터 전송이 완료되면 실행
  Wire.onReceive(receiveEvent); // 전송받은 데이터를 읽을 때 사용
  Serial.begin(9600);
}

void loop()
{
  delay(500); // 0.5초마다 한번씩 반복한다.
}

void receiveEvent(int howMany){ // 
  while(Wire.available()>1){
    char ch=Wire.read(); // 1byte읽고 이를 ch에 저장해라
    Serial.print(ch); // ch를 시리얼 모니터에 출력해라(Master에서 보낸 데이터)
  }
  int x=Wire.read(); // 남은 데이터를 출력한다.(숫자를 읽어온다.)
  Serial.println(x);
}

void requestEvent(){
  Wire.write("ACK\n"); // 주소를 제대로 받았거나 데이터를 제대로 받았으면 ACK신호를 보낸다. 
} // Master의 모니터에 출력된다. ACK\n 이 4byte이기떄문에 Master에서 4byte를 받는것이다. 
