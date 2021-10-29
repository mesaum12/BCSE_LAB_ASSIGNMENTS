
# we will define all the codeword preparing algorithms here in this module and then use it
# as and whenever required

#the function returning the codeword for the vertical redundancy check
def VRC(data,packet_size):
    # packet_size = int(input("Enter the size of the packets "))
    temp = 0
    if (len(data) % packet_size != 0):
        temp = packet_size - (len(data) % packet_size)
    data += ('0' * temp)
    count_of_packets = len(data) // packet_size
    code_word,k= '',0

    for i in range(count_of_packets):
        count1 = 0
        for j in range(packet_size):
            if (data[k + j] == '1'):
                count1 += 1
        k += packet_size
        if (count1 % 2):
            code_word += '1'
        else:
            code_word += '0'
    return code_word

#the function returning the codeword for the longitudinal redundancy check
def LRC(data,packet_size):
    # packet_size = int(input("Enter the size of the packets "))
    temp = 0
    if (len(data) % packet_size != 0):
        temp = packet_size - (len(data) % packet_size)
    data += ('0' * temp)
    # print(len(data) % packet_size == 0)
    count_of_packets = len(data) // packet_size

    code_word = ''
    for i in range(packet_size):
        count1, k = 0, i
        for j in range(count_of_packets):
            if (data[k] == '1'): count1 += 1
            k += packet_size
        if (count1 % 2):
            code_word += '1'
        else:
            code_word += '0'
    return code_word

#the function returning the codeword for the checksum
def CHECKSUM(data,packet_size):
    # packet_size = int(input("Enter the size of the packets "))
    temp = 0
    if (len(data) % packet_size != 0):
        temp = packet_size - (len(data) % packet_size)
    data += ('0' * temp)
    # print(len(data) % packet_size == 0)
    count_of_packets = len(data) // packet_size

    # Now we need to prepare the code_word
    sum, k = 0, 0

    for i in range(count_of_packets):
        temp_str = data[k:k + packet_size]
        x = int(temp_str, 2)
        sum += x
        k += packet_size

    final_sum_string = bin(sum)[2:]
    diff = len(final_sum_string) - packet_size
    if (diff > 0):
        final_sum_string = bin(int(final_sum_string[diff:], 2) + int(final_sum_string[0:diff], 2))[2:]
    elif (diff < 0):
        final_sum_string = '0' * (-diff) + final_sum_string

    # print(final_sum_string)
    complemented_string = ''
    for x in final_sum_string:
        complemented_string += str((int(x) ^ 1))

    return complemented_string


# this is the code for the crc check we are going to use crc-10
def xor(string1, string2):
    result = ''
    for i in range(len(string1)):
        result += str(int(string1[i]) ^ int(string2[i]))
    return result

def CRC(dividend,divisor="11000110011"):
    dividend = dividend[0:] + ('0' * (len(divisor) - 1))
    i = len(divisor)
    temp = dividend[0:len(divisor)]

    while i < len(dividend):
        # print(f"i is {i} ")
        t = xor(temp, divisor)
        # print(f"t is {t} ")
        x = t.find('1')
        # print(f"x is {x}")
        if (x == -1): x = len(divisor)

        if (x != len(divisor)):
            temp = t[x:] + dividend[i:min(i + x, len(dividend))]
        else:
            temp = dividend[i:min(i + x, len(dividend))]

        # print(f"temp is {temp} ")
        i = min(i + x, len(dividend))

    diff = len(divisor) - len(temp)
    if(diff==0):
        code_word = xor(divisor, temp)[1:]
    else:
        code_word=('0' * (diff-1)) + temp
    return code_word


# dividend = "110001100111100011001111000110011000000011000110011000011000110011"
# print(CRC(dividend))
# print(bin(int("11000110011",2)*1897))


