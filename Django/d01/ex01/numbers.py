def main():
    file = open("numbers.txt")
    buffer = file.read()
    number = ''

    for char in buffer:
        if char == ',':
            print (number)
            number = ''
            continue
        number += char
    print(number)


if __name__ == '__main__':
    main()
