import matplotlib.pyplot as plt


# Encoding Function for Manchester Standard
def ManchesterEncode(data):
    result = []
    wave = []

    for bit in data:
        if bit == '1':
            # 1 → Low to High (0 → 1)
            result.extend([0, 1])
            wave.extend([-1, 1])
        else:
            # 0 → High to Low (1 → 0)
            result.extend([1, 0])
            wave.extend([1, -1])

    return result, wave


# Decoding Function for Manchester Standard
def ManchesterDecode(encoded_data):
    result = ''

    # Looping through the encoded data 2 bits at a time
    for i in range(0, len(encoded_data), 2):
        first = encoded_data[i]  # first bit in pair
        second = encoded_data[i + 1]  # second bit in pair

        # Check the transition pattern
        if first == 0 and second == 1:
            result += '1'  # low to high → original bit was 1
        else:
            result += '0'  # high to low → original bit was 0

    return result


# Function to plot waveform
def WaveForm(signal):
    x = []
    y = []

    for i, level in enumerate(signal):
        x.extend([i, i + 1])
        y.extend([level, level])

    plt.figure(figsize=(12, 3))
    plt.title("Manchester Standard Encoding")
    plt.xlabel("Time")
    plt.ylabel("Voltage")
    plt.ylim(-2, 2)
    plt.grid(True)
    plt.plot(x, y, drawstyle='steps-post', linewidth=2)
    plt.show()


# Main Program
data = input("Enter binary data (e.g., 110011): ")

encoded, signal = ManchesterEncode(data)
print("Encoded Bit Pairs :", encoded)
print("Signal Levels     :", signal)
print("Decoded Data      :", ManchesterDecode(encoded))

WaveForm(signal)
