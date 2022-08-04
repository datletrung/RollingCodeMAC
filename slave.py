import random

def main(key):
    def getRandomString(length):
        return ''.join(random.choice(key) for _ in range(length))

    signatureGroup = 'TD'

    keyGroup = random.randint(1, len(key))
    key += key*2

    decodedGroup1 = getRandomString(2)
    decodedGroup2 = getRandomString(2)

    encodedGroup1 = ''
    encodedGroup2 = ''

    for c in decodedGroup1:
        encodedGroup1 += key[key.index(c)+keyGroup]
        
    for c in decodedGroup2:
        encodedGroup2 += key[key.index(c)+keyGroup]

    return signatureGroup + ':' + encodedGroup1 + ':' + decodedGroup2 + ':' + encodedGroup2 + ':' + decodedGroup1 + ':' + (str(keyGroup) if len(str(keyGroup)) == 2 else '0'+str(keyGroup))

if __name__ == "__main__":
    key = 'EB682A13F0CD7954'
    print(main(key))
