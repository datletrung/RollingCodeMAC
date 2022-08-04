import sys

def main(key, mac):
    try:
        mac = mac.split(':')
    except:
        return False
    

    if len(mac) != 6 or mac[0] != 'TD':
        return False
    
    key += key*2
    keyGroup = int(mac[5])
    decodedGroup1 = mac[4]
    decodedGroup2 = mac[2]
    encodedGroup1 = mac[1]
    encodedGroup2 = mac[3]
    
    encodedGroupTmp1 = ''
    encodedGroupTmp2 = ''

    for c in decodedGroup1:
        encodedGroupTmp1 += key[key.index(c)+keyGroup]
        
    for c in decodedGroup2:
        encodedGroupTmp2 += key[key.index(c)+keyGroup]

    if encodedGroupTmp1 != encodedGroup1 or encodedGroupTmp2 != encodedGroup2:
        return False
    
    return True
    
    
if __name__ == "__main__":
    key = 'EB682A13F0CD7954'
    mac = 'TD:C1:3E:FB:0A:01'
    print(main(key, mac))
