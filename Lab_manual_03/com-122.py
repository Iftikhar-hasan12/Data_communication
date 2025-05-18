#--NRZ-i
import matplotlib.pyplot as plt

def ToEncoded(data):
    result = []
    signal = []
    level =1
    for i in data:
        if i=='1':
            level = -level
        signal.append(level)
        if level==1:
            result.append(1)
        else:
            result.append(0)
    return result, signal


def ToDecoded(data):
    result  = ''
    current = 1
    for i in data:
        if current != i:
            result = result+'1'
        else:
            result = result+'0'
        current = i
    return result



def plot(data):
    x=[]
    y=[]

    for i, level in enumerate(data):

        x.extend([i,i+1])
        y.extend([level, level])

    plt.figure(figsize=(10,2))
    plt.title("NRZ-I")
    plt.xlabel("Time")
    plt.ylabel("Voltage")
    plt.yticks([-1, 1], ['Low', 'High'])

    plt.ylim(-2,2)
    plt.plot(x,y)
    plt.show()


data = input("Enter Data : ")
Encoded, signal = ToEncoded(data)
print(Encoded)
print(signal)
origin = ToDecoded(Encoded)
print(origin)
plot(signal)

#-----------------------

#---NRZ-L


import matplotlib.pyplot as plt



def ToEncode(data):
    signal =[]
    result =[]
    for i in data:
        if(i=='1'):
            result.append(1)
            signal.append(1)
        else:
            result.append(0)
            signal.append(-1)
    return  result, signal



def ToDecode(data):
    result=''

    for i in data:
        if (i==1):

            result = result+'1'
        else :
            result = result+'0'
    return  result





def plot(data):
    x=[]
    y=[]

    for i, level in  enumerate(data):
        x.extend([i, i+1])
        y.extend([level,level])

    plt.figure(figsize=(10,5))
    plt.title("NRZ_L")
    plt.xlabel("Time")
    plt.ylabel("Voltage")
    plt.ylim(-2,2)
    plt.grid(True)
    plt.plot(x, y)
    plt.show()


data = input("Enter Data : ")
Encoded, signal= ToEncode(data)
print(Encoded)
Decoded = ToDecode(Encoded)
print(Decoded)
plot(signal)

#---Man-Stand
import matplotlib.pyplot as plt







def ToEncode(data):
    result =[]
    signal = []

    for i in data :
        if i=='1':
            result.extend([0,1])
            signal.extend([-1,1])
        else:
            result.extend([1, 0])
            signal.extend([1, -1])
    return result, signal

def ToDecode(data):

    result=''
    for i in range(0, len(data),2):

        if data[i] == 1 and  data[i+1]==0 :
            result+='0'
        else:
            result+='1'
    return result






def wave(data):

    x=[]
    y=[]
    for i , level in enumerate(data):
        x.extend([i, i+1])
        y.extend([level, level])

    plt.figure(figsize=(10,2))
    plt.title("Man_Standard")
    plt.xlabel("Time")
    plt.ylabel("Voltage")
    plt.ylim(-2,2)
    plt.yticks([1,-1],['High','Low'])
    plt.plot(x,y)
    plt.show()






data = input("Enter Data : ")
encoded,signal = ToEncode(data)
print(encoded)
print(signal)
print("Decoded Data : ", ToDecode(encoded))
wave(signal)
#--Mandif------------------------
import matplotlib.pyplot as plt

def ToEncode(data):
    result = []
    signal = []
    current = 1  # starting level: +1

    for bit in data:
        if bit == '0':
            current = -current  # transition at beginning for 0

        # Add signal levels for plotting
        signal.extend([current, -current])

        # Simple binary encoding
        if current == 1:
            result.extend([1, 0])
        elif current == -1:
            result.extend([0, 1])

        current = -current  # mandatory mid-bit transition

    return result, signal


def ToDecode(encoded):
    result = ''
    for i in range(0, len(encoded), 2):
        if i > 0:
            if encoded[i] != encoded[i - 1]:
                result += '0'
            else:
                result += '1'
        else:
            # First bit, assume it's always a '0' due to transition
            result += '0'
    return result


def wave(signal):
    x = []
    y = []
    time_unit =0.5
    for i, level in enumerate(signal):
        #x.extend([i, i + 1])
        x.extend([i * time_unit, (i + 1) * time_unit])
        y.extend([level, level])

    plt.figure(figsize=(10, 2))
    plt.title("Differential Manchester Encoding")
    plt.xlabel("Time")
    plt.ylabel("Voltage")
    plt.ylim(-2, 2)
    plt.yticks([1, -1], ['High', 'Low'])
    plt.grid(True)
    plt.plot(x, y, drawstyle='steps-post', linewidth=2)
    plt.show()


# Main program
data = input("Enter Data (e.g., 10110): ")
encoded, signal = ToEncode(data)
print("Encoded Bits :", encoded)
print("Signal Levels:", signal)
print("Decoded Data :", ToDecode(encoded))
wave(signal)
