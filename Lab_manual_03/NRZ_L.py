
import matplotlib.pyplot as plt
from matplotlib.lines import drawStyles


def ToEncode(data):
    result=[]
    wave =[]

    for i in data:
        if i=='1':
            result.append(1)
            wave.append(1)
        else :
            result.append(0)
            wave.append(-1)

    return result,wave


def ToDecode(data):
    result =''
    for i in data:
        if(i==1):
            result+='1'
        else:
            result+='0'
    return result



def WaveForm(data):
    x = []
    y = []
    for i, level in enumerate(data):
        x.extend([i, i+1])
        y.extend([level, level])


    plt.figure(figsize=(10,2))
    plt.title("NRZ-L")
    plt.xlabel("Time")
    plt.ylabel("Voltage")
    plt.ylim(-2,2)
    plt.grid(True)
    plt.plot(x,y, drawstyle='steps-post',linewidth=2)
    plt.show()



data = input("enter : ")
encoded, signal = ToEncode(data)
print("Encoded Data : ",encoded)
print("Signal Data : ",signal)
print("Decoded Data :",ToDecode(encoded))
WaveForm(signal)
