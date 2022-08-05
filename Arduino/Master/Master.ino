//-----------SLAVE-----------

String key = "EB682A13F0CD7954";
const int keyLength = 16;

String mac = "TD:2A:FC:1F:13:14";

String signatureGroup;
String decodedGroup1;
String decodedGroup2;
String encodedGroup1;
String encodedGroup2;
String encodedGroupTmp1;
String encodedGroupTmp2;
int keyGroup;


void setup(){
  Serial.begin(115200);
  signatureGroup = mac.substring(0,2);
  
  if (signatureGroup != "TD"){
    Serial.println("Invalid!");
    return;
  }
  
  decodedGroup1 = mac.substring(12,14);
  decodedGroup2 = mac.substring(6,8);
  encodedGroup1 = mac.substring(3,5);
  encodedGroup2 = mac.substring(9,11);
  keyGroup = mac.substring(15,17).toInt();

  key = key + key + key;  

  for(int i = 0; i < decodedGroup1.length(); i++) {
    encodedGroupTmp1 += key[key.indexOf(decodedGroup1[i])+keyGroup];
  }
  for(int i = 0; i < decodedGroup2.length(); i++) {
    encodedGroupTmp2 += key[key.indexOf(decodedGroup2[i])+keyGroup];
  }
  
  if (encodedGroupTmp1 != encodedGroup1
      || encodedGroupTmp2 != encodedGroup2){
    Serial.println("Invalid!");
    return;
  }
  
  Serial.println("Valid!");
}

void loop(){
}
