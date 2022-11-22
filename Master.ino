// Master Uno
#include <Wire.h>
void setup()
{
  Wire.begin(); // Master로 지정해준다. 마스터는 주소를 지정해주지않는다. 
  Serial.begin(9600);
}

byte x=0; // loop 횟수를 세기위한 전역변수

void loop()
{
  Wire.beginTransmission(1); // 1번 슬레이브에 데이터 전송을 시작한다.(기기의 주소값을 알아야한다.)
  Wire.write("good "); // good이라는 문자열을 전송한다.
  Wire.write(x); // good 뒤에 번호를 써서 몇번 쓰는지 확인한다.
  Wire.endTransmission(); // 전송을 끝낸다.
  
  delay(500); // 0.5초 기다린다. 데이터를 전송하고 요청하는데 충돌이 일어나지않기위함.
  
  // 데이터를 보냈으면 잘 보냈다는 응답 신호를 slave에서 받아온다.(ACK)
  Wire.requestFrom(1,4); // 슬레이브 1번에서 4byte를 읽겠다고 요청한다.
  while(Wire.available()){ // 읽어올 데이터가 있으면
    char c=Wire.read(); // 1byte를 읽어서 c에 저장한다.
    Serial.print(c); // c를 시리얼 모니터에 출력한다.(ACK가 출력된다)
  }
  x++; // 전송하고 받아오는것을 한번하면 값을 하나 올린다.
  if(x==6)
    x=0; // 데이터를 6번 보내면 다시 초기화한다.
}
