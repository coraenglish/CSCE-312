# Dictionary handles base cases of ISA
encode = {
    "halt": "00",
    "nop": "10",
    "irmovl": "20",
    "rmmovl": "30",
    "mrmovl": "40",
    # "OPq": "5fn",
    "addl": "50",
    "subl": "51",
    "andl": "52",
    "orl": "53",
    "xorl": "54",
    "mull": "55",
    # "jXX": "6fn",
    "jmp": "60",
    "jle": "61",
    "jl": "62",
    "je": "63",
    "jne": "64",
    "jge": "65",
    "jg": "66",
    "call": "70",
    "ret": "80",
    "pushl": "90",
    "popl": "A0",
    "%eax": "1",
    "%ecx": "2",
    "%edx": "3",
    "%ebx": "4",
    "%esp": "5",
    "%ebp": "6",
    "%esi": "7",
    "%edi": "8",
    "ff": "ff",
}

asmList = []
hexList = []

# Open the input file and read in files in the format:
# [ [line 1]
#   [line 2]
#   [line ...]
# ]
with open('input2.txt', 'r') as iF:
    for line in iF:
        contents = line.rstrip('\n').split(' ')
        for i in range(len(contents)):
            contents[i] = contents[i].rstrip(',')
        asmList.append(contents)


# Goes through line by line in the assembly list and converts ISA instructions to our specified encoding scheme
for line in asmList:
    if line[0] == "irmovl":
        hexList.append(encode[line[0]])
        if line[1][1:] == "ff" or len(line[1][1:]) > 1:
            hexList.append(line[1][1:])
        else:
            hexList.append('0' + line[1][1:])
        hexList.append(encode[line[2]] + '0')
    elif line[0] == "rmmovl":
        hexList.append(encode[line[0]])
        hexList.append(encode[line[1]] + encode[line[2][2:6]])
        hexList.append('0' + line[2][0])  # D = 0+offset
    elif line[0] == "mrmovl":
        hexList.append(encode[line[0]])
        hexList.append(encode[line[1][2:6]] + encode[line[2]])
        hexList.append('0' + line[1][0])  # D = 0+offset
    elif line[0] == "halt":
        hexList.append(encode[line[0]])
        hexList.append("00")
        hexList.append("00")
    elif line[0] == "nop":
        hexList.append(encode[line[0]])
        hexList.append("00")
        hexList.append("00")
    elif line[0][0] == "j":
        hexList.append(encode[line[0]])
        hexList.append(":" + line[1] + ":")  # calculate memory location
        hexList.append("00")
    elif line[0] == "call":
        hexList.append(encode[line[0]])
        hexList.append(":" + line[1] + ":")  # calculate memory location
        hexList.append("00")
    elif line[0] == "ret":
        hexList.append(encode[line[0]])
        hexList.append("00")
        hexList.append("00")
    elif line[0] == "pushl":
        hexList.append(encode[line[0]])
        hexList.append(encode[line[1]] + '0')
        hexList.append("00")
    elif line[0] == "popl":
        hexList.append(encode[line[0]])
        hexList.append(encode[line[1]] + '0')
        hexList.append("00")
    else:
        hexList.append(encode[line[0]])
        hexList.append(encode[line[1]] + encode[line[2]])
        hexList.append('00')

outFile = "rom2.txt"
origHexList = hexList

# Traverses hex list and writes results to file
with open(outFile, "w") as oF:
    oF.write("v2.0 raw\n")
    oF.write("0 0 0 ")
    oF.write(hexList[0])
    hexList.pop(0)
    oF.write(' ')
    oF.write(hexList[0])
    hexList.pop(0)
    oF.write(' ')
    oF.write(hexList[0])
    oF.write(' ')
    hexList.pop(0)
    oF.write(hexList[0])
    hexList.pop(0)
    oF.write(' ')
    oF.write(hexList[0])
    hexList.pop(0)
    oF.write(' ')
    oF.write('\n')
    while len(hexList) != 0:
        for i in range(8):
            if len(hexList) == 0:
                break
            oF.write(hexList[0])
            oF.write(' ')
            hexList.pop(0)
        oF.write('\n')
