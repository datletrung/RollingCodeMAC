//-----------SLAVE-----------

String key = "EB682A13F0CD7954";
const int keyLength = 16;

const String signatureGroup = "TD";
String decodedGroup1;
String decodedGroup2;
String encodedGroup1;
String encodedGroup2;
int keyGroup;

String mac;


void setup(){
  Serial.begin(115200);
  randomSeed(analogRead(0));
  
  keyGroup = random(1, keyLength);
  
  key = key + key + key;  
  for(int i = 0; i<2; i++) {
    decodedGroup1 += key[random(0, keyLength-1)];
  }
  for(int i = 0; i<2; i++) {
    decodedGroup2 += key[random(0, keyLength-1)];
  }
  
  for(int i = 0; i < decodedGroup1.length(); i++) {
    encodedGroup1 += key[key.indexOf(decodedGroup1[i])+keyGroup];
  }
  for(int i = 0; i < decodedGroup2.length(); i++) {
    encodedGroup2 += key[key.indexOf(decodedGroup2[i])+keyGroup];
  }
  
  mac = signatureGroup + ":"
        + encodedGroup1 + ":" + decodedGroup2 + ":"
        + encodedGroup2 + ":" + decodedGroup1 + ":"
        + (String(keyGroup).length() == 2 ? String(keyGroup) : "0" + String(keyGroup));

  Serial.println(mac);
}

void loop(){
}
