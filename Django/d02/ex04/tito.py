original_string = "This is a multiline\nstring with several\nnewlines."
modified_string = "\n".join([" " + line for line in original_string.split("\n")])
print(modified_string)
