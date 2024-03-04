import sys

class   Atom():
    def __init__(self, name="", position="", number="", small="", molar="", electron=""):
        self.name = name
        self.position = position
        self.number = number
        self.small = small
        self.molar = molar
        self.electron = electron

    def print_atom(self):
        print(self.name)
        print(self.position)
        print(self.number)
        print(self.small)
        print(self.molar)
        print(self.electron)

def parse_line(line):
    if line == "":
        return
    first = line.split('=')
    second = first[1].split(',')

    name = first[0].strip()
    position = second[0].split(':')[1].strip()
    number = second[1].split(':')[1].strip()
    small = second[2].split(':')[1].strip()
    molar = second[3].split(':')[1].strip()
    electron = second[4].split(':')[1].strip('\n')
    return (Atom(name, position, number, small, molar, electron))

def generate_begining_html(o_file):
    o_file.write("<!DOCTYPE html>\n")
    o_file.write("<html>\n")
    o_file.write("<head>\n")
    o_file.write(" <meta charset=\"UTF-8\">\n")
    o_file.write(" <title>Ex07</title>\n")
    o_file.write("</head>\n")
    o_file.write("<body>\n")
    o_file.write(" <table>\n")

def generate_end_html(o_file):
    o_file.write(" </table>\n")
    o_file.write("</body>\n")
    o_file.write("</html>\n")

def generate_html_block(atom):
    block = ""
    block += "   <td>\n"
    if (atom.name == ""):
        block += f"    <h4> </h4>\n"
        block += "    <ul style=\"list-style-type: none\">\n"
        block += f"     <li></li>\n"
        block += f"     <li></li>\n"
        block += f"     <li></li>\n"
        block += f"     <li></li>\n"
    else:
        block += f"    <h4>{atom.name}</h4>\n"
        block += "    <ul style=\"list-style-type: none\">\n"
        block += f"     <li>No {atom.number}</li>\n"
        block += f"     <li>{atom.small}</li>\n"
        block += f"     <li>{atom.molar}</li>\n"
        block += f"     <li>electron {atom.electron}</li>\n"
    block += "    </ul>\n"
    block += "   </td>\n"
    return block

def generate_table(input, output):
    line = input.readline()
    atom = parse_line(line)
    block = ""
    while (line):
        block = ""
        block += "  <tr>\n"
        for i in range (0, 18):
            if atom.position == str(i):
                block += generate_html_block(atom)
                line = input.readline()
                atom = parse_line(line)
            else:
                block += generate_html_block(Atom())
        block += "  </tr>\n"
        output.write(block)

def main():
    output = open("periodic_table.html", "w")
    input = open("periodic_table.txt", "r")
    generate_begining_html(output)
    generate_table(input, output)
    generate_end_html(output)

if __name__ == '__main__':
    main()
