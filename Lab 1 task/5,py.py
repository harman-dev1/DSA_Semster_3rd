def StringReverse(str_word, starting, ending):   
    if starting > ending or starting < 0 or ending >= len(str_word):
        return ""
    return str_word[ending] + StringReverse(str_word, starting, ending - 1)

s = "University of Engineering and Technology Lahore"
print(StringReverse(s, 0, 4))