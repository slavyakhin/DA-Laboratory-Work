import sys
import random

def get_random_date():
    return f'{str(random.randint(1, 31))}.{str(random.randint(1, 12))}.{str(random.randint(0, 9999))}'

def get_random_ulint():
    return str(random.randint(0, 2 ** 64 - 1))

def main():
    input_list = [(get_random_date(), get_random_ulint()) for i in range(100)]

    fTestInput = open("input.txt", 'w')
    for KeyValuePair in input_list:
        fTestInput.write(f'{KeyValuePair[0]}\t{KeyValuePair[1]}\n')
    fTestInput.close()

    output_list = sorted(input_list, key=lambda x: tuple(map(int, x[0].split('.')))[::-1])

    fTestOutput = open("output.txt", 'w')
    for KeyValuePair in output_list:
        fTestOutput.write(f'{KeyValuePair[0]}\t{KeyValuePair[1]}\n')
    fTestOutput.close()


if __name__ == "__main__":
    main()