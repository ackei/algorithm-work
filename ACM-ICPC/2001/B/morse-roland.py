char2morse = {
    "A": ".-",
    "B": "-...",
    "C": "-.-.",
    "D": "-..",
    "E": ".",
    "F": "..-.",
    "G": "--.",
    "H": "....",
    "I": "..",
    "J": ".---",
    "K": "-.-",
    "L": ".-..",
    "M": "--",
    "N": "-.",
    "O": "---",
    "P": ".--.",
    "Q": "--.-",
    "R": ".-.",
    "S": "...",
    "T": "-",
    "U": "..-",
    "V": "...-",
    "W": ".--",
    "X": "-..-",
    "Y": "-.--",
    "Z": "--..",
    "_": "..--",
    ",": ".-.-",
    ".": "---.",
    "?": "----"
}

morse2char = {
    ".-": "A",
    "-...": "B",
    "-.-.": "C",
    "-..": "D",
    ".": "E",
    "..-.": "F",
    "--.": "G",
    "....": "H",
    "..": "I",
    ".---": "J",
    "-.-": "K",
    ".-..": "L",
    "--": "M",
    "-.": "N",
    "---": "O",
    ".--.": "P",
    "--.-": "Q",
    ".-.": "R",
    "...": "S",
    "-": "T",
    "..-": "U",
    "...-": "V",
    ".--": "W",
    "-..-": "X",
    "-.--": "Y",
    "--..": "Z",
    "..--": "_",
    ".-.-": ",",
    "---.": ".",
    "----": "?"
}

def decode(message):

    numbers = []
    morse = ""
    for character in message:
        morse += char2morse[character]
        numbers.append(len(char2morse[character]))
    numbers = reversed(numbers)

    decoded = ""
    for number in numbers:
        code = morse[:number]
        character = morse2char[code]
        morse = morse[number:]
        decoded += character

    return decoded

def main():

    with open("morse.in") as fh:
        lines = list(fh)

    n = int(lines[0])
    lines = lines[1:]

    for i, line in enumerate(lines, start=1):
        message = decode(line.strip())
        print("{i}: {message}".format(**locals()))

if __name__ == "__main__":
    main()
