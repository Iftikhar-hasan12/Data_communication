import matplotlib.pyplot as plt

def ToEncode(data):
    result = []
    signal = []
    current = 1  # starting level: +1

    for bit in data:
        if bit == '0':
            current = -current  # transition at beginning for 0

        signal.extend([current, -current])
        result.extend([1 if current == 1 else 0, 1 if -current == 1 else 0])

        current = -current  # mandatory mid-bit transition

    return result, signal


def ToDecode(encoded):
    result = ''
    for i in range(0, len(encoded), 2):
        # Check if there's a transition at the start of the bit period
        if encoded[i] != encoded[i - 1] if i > 0 else True:
            result += '0'
        else:
            result += '1'
    return result


def wave(signal):
    x = []
    y = []

    for i, level in enumerate(signal):
        x.extend([i, i + 1])
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


# Main
data = input("Enter Data: ")
encoded, signal = ToEncode(data)
print("Encoded Bits :", encoded)
print("Signal Levels:", signal)
print("Decoded Data :", ToDecode(encoded))
wave(signal)
