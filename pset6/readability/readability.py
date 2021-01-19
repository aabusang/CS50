from cs50 import get_string

# read input text
text = get_string("Text: ")

# calculate grade level
letter_count = 0
word_count = 1
sentence_count = 0

# L = averege no letter per 100 words
L = 0
# S = average sentences per 100 words
S = 0

for c in text:
    if c.isalpha():
        letter_count += 1
    elif c == " ":
        word_count += 1
    elif c == "!" or c == "?" or c == ".":
        sentence_count += 1
    else:
        continue
L = letter_count / word_count * 100
S = sentence_count / word_count * 100
print(L)
print(S)
index = round(0.0588 * L - 0.296 * S - 15.8)
# print grade level
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(index))