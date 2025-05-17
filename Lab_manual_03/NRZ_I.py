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
